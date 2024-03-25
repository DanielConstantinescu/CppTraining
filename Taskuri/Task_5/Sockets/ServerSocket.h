#include "Socket.h"
#include <fstream>
#include <iostream>

#define FILENAME "server_file.txt"

class ServerSocket : Socket
{
private:
    std::ofstream server_file;
public:
  // Constructors
  ServerSocket(int port);
  ServerSocket() {};

  // Send - receive operators
  const ServerSocket& operator << ( const std::string& ) const;
  const ServerSocket& operator >> ( std::string& ) const;

  void accept(ServerSocket&);

  // File manipulation
  void open_file() { this->server_file.open(FILENAME, std::ios::app); }
  void close_file() { this->server_file.close(); }
  void write_in (const std::string& s);
  int calculate_cube(const int x) { return x*x*x; }

  virtual ~ServerSocket() {};

};