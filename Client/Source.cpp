#include <iostream>
#include <array>
#include "../Network/TcpSocket.h"
int main(int argc, char* argv[]) 
{
	// Validate the parameters
	if (argc != 2) {
		std::cerr << "usage: " << argv[0] << " server-name" << std::endl;
		return 1;
	}

	std::cout << "Starting client" << std::endl;

	TcpSocket socket;
	std::cout << "Connecting to server at: " << argv[1] << std::endl;
	socket.Connect(argv[1], 27015);

	std::string message = "this is a test";
	std::cout << "Sending message: " << message << std::endl;
	socket.Send(message.c_str(), message.size());

	std::array<char, 512> receiveBuffer;
	int revieved;
	socket.Receive(receiveBuffer.data(), receiveBuffer.size(), revieved);
	std::cout << "Received: ";
	std::copy(receiveBuffer.begin(), receiveBuffer.begin() + revieved, std::ostream_iterator<char>(std::cout, ""));
	std::cout << std::endl;

	return 0;
}