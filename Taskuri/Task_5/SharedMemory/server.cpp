#include <iostream>
#include <string>
#include <fstream>
#include <boost/asio.hpp>
#include <boost/program_options.hpp>
using boost::asio::ip::tcp;

#define FILENAME "server_file.txt"

/* Session class using shared pointers */
class session : public std::enable_shared_from_this<session> {
public:
    /* Session holds the socket */
    session(tcp::socket socket) : m_socket(std::move(socket)) {}

    void run() { wait_for_request(); }

private:
    void wait_for_request() {
        auto self(shared_from_this());

        /* Lambda function is called once data arrives */
        boost::asio::async_read_until(m_socket, m_buffer, "\0", [this, self](boost::system::error_code ec, std::size_t /*length*/) {
            if (!ec)  {
                std::string data{
                    std::istreambuf_iterator<char>(&m_buffer), 
                    std::istreambuf_iterator<char>() 
                };

                /* We open the server file, calculate the cube and write into it and then close it */
                std::ofstream server_file;
                server_file.open(FILENAME, std::ios::app);
                std::cout << "Received " << data << " from client." << std::endl;
                int recv = stoi(data);
                int result = recv * recv * recv;
                server_file << recv << " * " << recv  << " * " << recv << " = " << std::to_string(result) << "\n";
                std::cout << "Wrote the result " << std::to_string(result) << " in the server file" << std::endl;
                server_file.close();

                /* We send the same data back to client */
                auto res = boost::asio::write(m_socket, boost::asio::buffer(data));
                std::cout << "Sent " << data << " to client." << std::endl;

            } else {
                std::cout << "error: " << ec << std::endl;;
            }
        });

    }

private:
    tcp::socket m_socket;
    boost::asio::streambuf m_buffer;
};

class server {
public:
    /* Provide the io_context and the port where the server will listen */
    server(boost::asio::io_context& io_context, short port) : m_acceptor(io_context, tcp::endpoint(tcp::v4(), port)) {
        do_accept();
    }

private:
    void do_accept() {
        /* Async accept. The lambda function will be called when the client connects.
        The server will disconnect after the communication is done. */
        m_acceptor.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec) {
                /* Create a session and call the run function from class session */
                std::make_shared<session>(std::move(socket))->run();
            } else {
                std::cout << "error: " << ec.message() << std::endl;
            }
        });
    }
    
private:
    tcp::acceptor m_acceptor;
};

int main()
{
    /* Create an io_context, use a random port and run */
    boost::asio::io_context io_context;
    server s(io_context, 25000);
    io_context.run();

    return 0;
}