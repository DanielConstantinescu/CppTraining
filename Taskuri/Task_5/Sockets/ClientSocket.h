#include "Socket.h"
#include <string>
#include <fstream>
#include <iostream>

#define FILENAME "client_file.txt"

class ClientSocket : Socket
{
private:
    std::ofstream client_file;
public:
  ClientSocket (std::string host, int port);
  virtual ~ClientSocket() {};

  // Send - receive operators
  const ClientSocket& operator << ( const std::string& ) const;
  const ClientSocket& operator >> ( std::string& ) const;

// File manipulation
  void open_file() { this->client_file.open(FILENAME, std::ios::app); }
  void close_file() { this->client_file.close(); }
  void write_in (const std::string& s);
  int calculate_square(const int x) { return x*x; }
};