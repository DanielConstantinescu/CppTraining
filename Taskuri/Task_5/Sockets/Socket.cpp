#include "Socket.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <iostream>

/* Default constructor */
Socket::Socket() : m_sock ( -1 )
{
  memset(&m_addr, 0, sizeof(m_addr));
}

/* Destructor */
Socket::~Socket()
{
  if (is_valid())
    close(m_sock);
}

/* Creates socket */
bool Socket::create()
{
  // Socket constructor provided (domain, type, protocol) -> domain: AF_INET for communication between processes, type SOCK_STREAM for TCP, protocol 0 for IP
  m_sock = socket(AF_INET, SOCK_STREAM, 0);

  if (!is_valid())
        return false;

  // Set socket options to make sure we can reuse address. Params: (socket, level, option_name, option_valuea, option_len). Also checks if socket was created
  int on = 1;
  if (setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (const char*) &on, sizeof (on)) == -1)
    return false;


  return true;
}

/* Bind a name to a socket using the C++ bind function */
bool Socket::bind(const int port)
{
  if (!is_valid())
    return false;

  m_addr.sin_family = AF_INET;         // Set domain
  m_addr.sin_addr.s_addr = INADDR_ANY; // Set IP address to any
  m_addr.sin_port = htons(port);       // Set port to the given port

  // Bind the name to a socket. Params(socket, socket address, socket address length). Returns -1 on error
  int bind_return = ::bind(m_sock, (struct sockaddr*) &m_addr, sizeof(m_addr));

  if ( bind_return == -1 )
    return false;

  return true;
}

/* Wait for client connections */
bool Socket::listen() const
{
  if (!is_valid())
    return false;

  // Listen for an incoming connection. Params (socket, backlog_connections_queue_size). Return -1 on error
  int listen_return = ::listen(m_sock, MAXCONNECTIONS);

  if (listen_return == -1)
    return false;

  return true;
}

/* Accepts the first connection from the queue */
bool Socket::accept(Socket& new_socket) const
{
  int addr_length = sizeof(m_addr);
  
  // accept a new connection on a socket. Params (socket, socket_address, socket_address_length). Return -1 on error
  new_socket.m_sock = ::accept(m_sock, (sockaddr *) &m_addr, (socklen_t *) &addr_length);

  if (new_socket.m_sock <= 0)
    return false;
    
  return true;
}

/* Establish connection between two sockets */
bool Socket::connect(const std::string host, const int port)
{
  if (!is_valid()) 
    return false;

  m_addr.sin_family = AF_INET;     // Set domain
  m_addr.sin_port = htons (port);  // Set port

  // convert IP from IPv4 to IPv6. If not supported, return false
  int status = inet_pton(AF_INET, host.c_str(), &m_addr.sin_addr);

  if (errno == EAFNOSUPPORT) 
    return false;

  // Establish connection. Params (socket, socket_address, socket_address_length)
  status = ::connect ( m_sock, ( sockaddr * ) &m_addr, sizeof ( m_addr ) );

  if ( status == -1 )
    return false;

  return true;
}

/* Send a message */
bool Socket::send(const std::string s) const
{
  // Sends a message. Params (socket, buffer_to_send, size_of_buffer, flags)
  int status = ::send ( m_sock, s.c_str(), s.size(), MSG_NOSIGNAL);
  
  if ( status == -1 )
      return false;
  
  return true;
}

/* Receive a message */
int Socket::recv(std::string& s) const
{
  char buf[MAXRECV+1];

  s = "";

  memset(buf, 0, MAXRECV+1);

  // Receive a message. Params (socket, buffer_sent, size_of_buffer, flags). Returns 0 on peer shutdown and -1 on error.
  int status = ::recv(m_sock, buf, MAXRECV, 0);

  if ( status == -1 )
    {
      std::cout << "status == -1   errno == " << errno << "  in Socket::recv" << std::endl;
      return 0;
    }
  else if ( status == 0 )
    {
      return 0;
    }
  else
    {
      s = buf;
      return status;
    }
}