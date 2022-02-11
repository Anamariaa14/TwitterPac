#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <array>
#include <sstream>
#include "../Network/TcpSocket.h"
#include "../Network/XMLParsing.h"
#include "Database.h"
enum action
{
		Login,
		Register,
		Tweet,
		UserSearch,
		No_action
};
action convert(std::string& str)
{
	if (str == "Login") return Login;
	else if (str == "Register") return Register;
	else if (str == "Tweet") return Tweet;
	else if (str == "UserSearch") return UserSearch;
	else return No_action;
}

//class ServerToClient
//{
//private:
//	TcpSocket m_listener;
//	TcpSocket m_client;
//public:
//	ServerToClient()
//	{
//
//	}
//	void Listen()
//	{
//		std::cout << "Starting server" << std::endl;
//		m_listener.Listen(27015);
//
//		std::cout << "Waiting for client to connect" << std::endl;
//		m_client = m_listener.Accept();
//	}
//	void Receive(std::array<char, 512>& receiveBuffer, int& revieved)
//	{
//		m_client.Receive(receiveBuffer.data(), receiveBuffer.size(), revieved);
//		std::cout << revieved << " nr cuv\n";
//	}
//	void MessageCase(const action& uAction, const Database& database, const char* dir, std::stringstream& stream)
//	{
//		XMLParsing document;
//		switch (uAction)
//		{
//		case Login:
//		{
//			database.selectData(dir);
//			document.load("../date.xml");
//			if (document.getUsername().empty() || document.getPassword().empty())
//				stream << "Empty_fields";
//			else if (document.getField() == true)
//				stream << "Correct_credentials";
//			else if (document.getField() == false)
//				stream << "Incorrect_credentials";
//			break;
//		}
//		case Register:
//		{
//			database.selectData(dir);
//			document.load("../date.xml");
//			if (document.getUsername().empty() || document.getPassword().empty() || document.getFirstName().empty() || document.getLastName().empty())
//			{
//				stream << "Empty fields";
//				break;
//			}
//			else if (document.getField() == true)
//			{
//				stream << "User_already_registered";
//				break;
//			}
//			database.insertData(dir);
//			stream << "Register_successfull";
//			break;
//		}
//		default:
//		{
//			stream << "Nothing";
//			break;
//		}
//		}
//	}
//	void Send(const std::stringstream& stream)
//	{
//		std::string message = stream.str();
//		m_client.Send(message.c_str(), message.size());
//	}
//};
int main()
{
	while (true)
	{
		//ServerToClient data;
		TcpSocket listener;
		Database db;
		std::array<char, 512> receiveBuffer;
		int revieved;
		XMLParsing document;
		std::cout << "Starting server" << std::endl;
		listener.Listen(27015);

		std::cout << "Waiting for client to connect" << std::endl;
		TcpSocket client = listener.Accept();
		//data.Listen();
		client.Receive(receiveBuffer.data(), receiveBuffer.size(), revieved);
		//data.Receive(receiveBuffer,revieved);
		std::cout << "Received: ";
		std::string buffContent;
		for (std::array<char, 512>::iterator i = receiveBuffer.begin(); i != receiveBuffer.begin() + revieved; i++)
			buffContent += *i;
		std::cout << buffContent;
		const char* dir = R"(C:\DatabasePAC\Database.db)";
		db.createDB(dir);
		db.createTable(dir);
		std::stringstream stream;
		action uAction = convert(buffContent);
		//data.MessageCase(uAction, db, dir, stream);
		switch (uAction)
		{
		case Login:
		{
			db.selectData(dir);
			document.load("../date.xml");
			if (document.getUsername().empty()||document.getPassword().empty())
				stream << "Empty_fields";
			else if (document.getField() == true)
				stream << "Correct_credentials";
			else if (document.getField() == false)
				stream << "Incorrect_credentials";
			break;
		}
		case Register:
		{
			db.selectData(dir);
			document.load("../date.xml");
			if (document.getUsername().empty() || document.getPassword().empty() || document.getFirstName().empty() || document.getLastName().empty())
			{
				stream << "Empty fields";
				break;
			}
			else if (document.getField() == true)
			{
				stream << "User_already_registered";
				break;
			}
			db.insertData(dir);
			stream << "Register_successfull";
			break;
		}
		case Tweet:
		{
			document.load("../date.xml");
			db.insertData(dir);
			break;

		}
		case UserSearch:
		{
			document.load("../date.xml");
			document.setField(false);
			db.selectData(dir);
			break;
		}
		default:
		{
			stream << "Nothing";
			break;
		}
		}
		std::string message = stream.str();
		client.Send(message.c_str(), message.size());
		//data.Send(stream);
	}
	return 0;
}