#include "Search.h"
#include"UserInList.h"
#include "Post.h"
#include "../Network/TcpSocket.h"
#include "../Network/XMLParsing.h"
#include <array>
#include <algorithm>
#include "SearchBar.h"
#include <sstream>
Search::Search(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Search::~Search()
{
}

void Search::on_pushButton_search_clicked()
{
	QString currentTabName = ui.tabWidget->currentWidget()->objectName();
	std::string currentTab = currentTabName.toStdString();
	QString s = ui.textEdit->toPlainText();
	//std::string input = s.toStdString();
	//SearchBar algorithm;

		//TcpSocket socket;
		//socket.Connect("127.0.0.1", 27015);
	if (currentTab == "people")
	{
	/*	XMLParsing document;
		std::string message = "UserSearch";
		document.load("../date.xml");
		document.setAction("UserSearch");
		document.save("../date.xml");
		socket.Send(message.c_str(), message.size());
		int noOfUsers = 0;
		std::vector<std::pair<int,std::string>> users;
		document.load("../date.xml");
		std::string user = document.getUsername();
		std::istringstream iss(user);
		do
		{	
		std::string iterator;
			iss >> iterator;
		users.push_back(std::make_pair(-1,iterator ));
				users.push_back(std::make_pair( -1,user.substr(0, user.find_first_of(" "))));
				if (user.find_first_of(" ") == user.size() - 1)
					break;
				user=user.substr(user.find_first_of(" ") + 1);
		} while (iss);
		for (int i = 0; i < users.size(); i++)
		{
			users[i].first=algorithm.levDistance(input,users[i].second);
		}
		std::sort(users.begin(), users.end(), comparator);
		for (int i = 0; i < users.size(); i++)
		{
			auto user1 = new UserInList(this);
			user1->SetName(QString::fromStdString(users[i].second));
			user1->SetUsername(QString::fromStdString("@"+users[i].second));
			ui.verticalLayout_people->addWidget(user1);
		}*/
		auto user1 = new UserInList(this);
		user1->SetName("andreea");
		user1->SetUsername("@andrea78");
		ui.verticalLayout_people->addWidget(user1);
		user1 = new UserInList(this);
		user1->SetName("andree");
		user1->SetUsername("@andrea97");
		user1 = new UserInList(this);
		user1->SetName("andrei");
		user1->SetUsername("@andreiPopescu");
		ui.verticalLayout_people->addWidget(user1);
		/*while (noOfUsers < 5) {
			auto user = new UserInList(this);
			ui.verticalLayout_people->addWidget(user);
			noOfUsers++;
		}*/
	}
	else if (currentTab == "tweets")
	{

		

		int noOfPosts = 0;
		while (noOfPosts < 5) {
			auto post = new Post(this);
			ui.verticalLayout_tweets->addWidget(post);
			noOfPosts++;
		}
	}


	
}

bool comparator(const std::pair<int, std::string>& pereche1, const std::pair<int, std::string>& pereche2)
{
	return pereche1.first<pereche2.first;
}
