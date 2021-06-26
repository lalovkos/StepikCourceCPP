#pragma once
#include <chrono>
#include <functional>
#include <thread>
#include <fstream>
#include <iostream>

//For work need to link Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
#include <WinSock2.h>

#define DEBUG_MODE true



namespace TCPProject {
	
	uint16_t constexpr DEFAULT_PORT = 27015;
	uint16_t constexpr SERVER_BUFFER_SIZE = 4096;

	//TODO: change numbers
	enum class server_status : uint16_t {
		created = -2,
		started = -1,
		listening = 0,
		err_socket_init = 1,
		err_socket_bind = 2,
		err_socket_listening = 3,
		closed = 4,
		bound = 5
	};

	class TCPServer {
		
	private:
		uint16_t			 port_;
		server_status		 status_;
		SOCKET				 socket_;
		WSAData				 w_data_;

	public:

		//Constructors and Destructor
		TCPServer(const uint16_t port);
		TCPServer();
		
		//Setters and Getters
		virtual uint16_t port() const;
		virtual server_status status() const;
		virtual uint16_t buffer_size() const;

		//Other
		server_status Start(const int port = DEFAULT_PORT);
		server_status BindServerToPort(const int port = DEFAULT_PORT);
		server_status StartListen();
		

	};

	class TCPClient {
	private:
		SOCKET   socket_;
		uint16_t port_;


	public:

	};

}
