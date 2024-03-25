#include "ServerSocket.h"
#include "SocketException.h"

/* Parameterized constructor */
ServerSocket::ServerSocket(int port)
{
  if (!create())
    {
      throw SocketException("Server: Failed to create socket.");
    }

  if (!bind(port))
    {
      throw SocketException ("Server: Failed to bind.");
    }

  if (!listen())
    {
      throw SocketException ("Server: Failed to listen.");
    }
}

void ServerSocket::accept(ServerSocket& sock)
{
  if(!Socket::accept(sock))
  {
    throw SocketException("Server: Failed to accept socket.");
  }
}

void ServerSocket::write_in(const std::string &s)
{
    std::cout << "Received " << s << " from client." << std::endl;
    int recv = stoi(s);
    int result = calculate_cube(recv);
    server_file << s << " * " << s  << " * " << s << " = " << std::to_string(result) << "\n";
    std::cout << "Wrote the result " << std::to_string(result) << " in the server file" << std::endl;
}

const ServerSocket& ServerSocket::operator << (const std::string& s) const
{
  if (!Socket::send(s))
  {
    throw SocketException("Could not write to socket.");
  }

  return *this;

}

const ServerSocket& ServerSocket::operator >> (std::string& s) const
{
  if(!Socket::recv(s))
  {
    throw SocketException("Could not read from socket.");
  }

  return *this;
}