#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <boost/asio.hpp>

#define FILENAME "client_file.txt"

int main()
{
    using boost::asio::ip::tcp;

    /* Create an io_context, a socket and a resolver to establish the connection */
    boost::asio::io_context io_context;
    tcp::socket socket(io_context);
    tcp::resolver resolver(io_context);

    /* Connect to server using the same port */
    boost::asio::connect(socket, resolver.resolve("127.0.0.1", "25000"));
    
    /* We define the data and send it to the client */
    std::string data_sent{"42"};
    auto result = boost::asio::write(socket, boost::asio::buffer(data_sent));
    std::cout << "Sent " << data_sent << " to server." << std::endl;

    /* Read the response from the server */
    boost::asio::streambuf buffer;
    boost::system::error_code ec;
    boost::asio::read(socket, buffer,ec);

    if (!ec || ec == boost::asio::error::eof) {
        std::string data{
            std::istreambuf_iterator<char>(&buffer), 
            std::istreambuf_iterator<char>() 
        };

        /* Take the number sent as reponse, calculate the square and write it in the client file */
        std::ofstream client_file;
        client_file.open(FILENAME, std::ios::app);
        std::cout << "Received " << data << " from client." << std::endl;
        int recv = stoi(data);
        int res = recv * recv;

        time_t i = 0;
        time_t now = time(&i); // Get current time for printing
        char* date_time = ctime(&now);

        client_file << date_time << recv << " * " << recv << " = " << std::to_string(res) << "\n\n";


        std::cout << "Wrote the result " << std::to_string(res) << " in the client file" << std::endl;
        client_file.close();
    } else {
        std::cout << "error: " << ec << std::endl;;
    }

    /* Close the connection */
    socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
    socket.close();

    return 0;
}