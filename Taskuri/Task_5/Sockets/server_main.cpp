#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

/* Client will send an int to the server. Server will calculate its cube, will print it in a file and then will return the initial value to the client.
Once client receives it, it calculates its square and prints it in a file, then end.*/

int main ()
{
  std::cout << "Server started....." << std::endl;

  try
    {
      // Create the socket
      ServerSocket server(30000);

      while ( true )
	  {

	    ServerSocket new_sock;
	    server.accept(new_sock);
        std::string data;

	    try
	    {
	      while ( true )
		  {
		    new_sock >> data;

            server.open_file();
            server.write_in(data);
            server.close_file();

	        new_sock << data;
		  }
	    }
	    catch ( SocketException& ) {}
	  }
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}