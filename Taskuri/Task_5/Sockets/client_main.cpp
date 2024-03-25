#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

/* Client will send an int to the server. Server will calculate its cube, will print it in a file and then will return the initial value to the client.
Once client receives it, it calculates its square and prints it in a file, then end.*/

int main()
{
  try
    {
      // Client socket
      ClientSocket client_socket("localhost", 30000);
      std::string reply = "42";

      try
	  {
	    client_socket << reply;
	    client_socket >> reply;
	  }
      catch ( SocketException& ){}

      client_socket.open_file();
      client_socket.write_in(reply);
      client_socket.close_file();
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}