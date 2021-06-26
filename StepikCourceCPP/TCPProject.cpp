#include "TCPProject.h"

namespace TCPProject {
	TCPServer::TCPServer(const uint16_t port): port_{port}, status_{server_status::created}, socket_{INVALID_SOCKET} {}

	TCPServer::TCPServer() : port_{ DEFAULT_PORT }, status_{ server_status::created }, socket_{INVALID_SOCKET}  {}

	uint16_t TCPServer::port() const {
		return port_;
	}

	server_status TCPServer::status() const {
		return status_;
	}

	uint16_t TCPServer::buffer_size() const {
		return SERVER_BUFFER_SIZE;
	}

	server_status TCPServer::Start(const int port) {

		if ( BindServerToPort(port) != server_status::bound) {
			return status_;
		}
		
		return StartListen();
	}

	server_status TCPServer::BindServerToPort(const int port) {

		//WSA startup
		const int wsa_startup_result = WSAStartup(MAKEWORD(2, 2), &w_data_);
		if (wsa_startup_result) {
			std::cout << "WSA startup failed" << std::endl;
			return server_status::closed;
		}

		//Checking default port changed
		//TODO: check this
		if (port != DEFAULT_PORT) {
			port_ = port;
		}
		
		//Address preferences
		SOCKADDR_IN address;
		address.sin_addr.S_un.S_addr = INADDR_ANY;
		address.sin_port = htons(static_cast<u_short>(port_));
		address.sin_family = AF_INET;

		//initializing
		socket_ = socket(AF_INET, SOCK_STREAM, 0);
		if (static_cast<int>(socket_) == SOCKET_ERROR) {

			std::cout << "Socket init error: " << WSAGetLastError() << std::endl;
			return status_ = server_status::err_socket_init;

		}

		if (DEBUG_MODE) {
			std::cout << "Server socket initialized" << std::endl;
		}
	
		//binding
		const int bind_socket_result = bind(socket_, reinterpret_cast<sockaddr*>(&address), sizeof(address));
		if (bind_socket_result == SOCKET_ERROR) {
			std::cout << "Socket bind error: " << WSAGetLastError() << std::endl;
			return status_ = server_status::err_socket_bind;
		}

		if (DEBUG_MODE) {
			std::cout << "Server bound to port" << std::endl;
		}
		status_ = server_status::bound;
		return status_;
	}

	server_status TCPServer::StartListen() {

		//listening
		const int listen_socket_result = listen(socket_, SOMAXCONN);
		if (listen_socket_result == SOCKET_ERROR) {
			std::cout << "Socket listen error: " << WSAGetLastError() << std::endl;
			return status_ = server_status::err_socket_listening;
		}
		status_ = server_status::listening;

		if (DEBUG_MODE) {
			std::cout << "Server port: " << port_ << std::endl
					  << "Server listening..." << std::endl;
					  
		}

		// Receive until the peer shuts down the connection
		do {
			iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
			if (iResult > 0) {
				printf("Bytes received: %d\n", iResult);

				// Echo the buffer back to the sender
				iSendResult = send(ClientSocket, recvbuf, iResult, 0);
				if (iSendResult == SOCKET_ERROR) {
					printf("send failed with error: %d\n", WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();
					return 1;
				}
				printf("Bytes sent: %d\n", iSendResult);
			}
			else if (iResult == 0)
				printf("Connection closing...\n");
			else {
				printf("recv failed with error: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}

		} while (iResult > 0);
		
		return status_;
	}
}
