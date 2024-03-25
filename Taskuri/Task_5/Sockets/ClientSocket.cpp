#include "ClientSocket.h"
#include "SocketException.h"

ClientSocket::ClientSocket(std::string host, int port)
{
  if (!create())
  {
    throw SocketException("Client: Failed to create socket."); 
  }

  if (!connect(host, port))
  {
    throw SocketException("Client: Failed to bind.");
  }
}

const ClientSocket& ClientSocket::operator << (const std::string& s) const
{
  if (!Socket::send(s))
    {
      throw SocketException("Could not write to socket.");
    }

  return *this;
}


const ClientSocket& ClientSocket::operator >> (std::string& s) const
{
  if (! Socket::recv(s))
    {
      throw SocketException ("Could not read from socket.");
    }

  return *this;
}

void ClientSocket::write_in(const std::string &s)
{
    std::cout << "Received " << s << " from server." << std::endl;
    int recv = stoi(s);
    int result = calculate_square(recv);
    client_file << s << " * " << s << " = " << std::to_string(result) << "\n";
    std::cout << "Wrote the result " << std::to_string(result) << " in the client file" << std::endl;
}
