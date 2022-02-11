#include "UserProfile.h"
#include "../Network/XMLParsing.h"

UserProfile::UserProfile(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    XMLParsing p;
    p.load("../date.xml");
   
    ui.name->setText(QString::fromStdString(p.getUsername()));

    auto next_page = new Post(this);
    auto next_page1 = new Post(this);
    auto next_page2 = new Post(this);

    ui.verticalLayout_3->addWidget(next_page);

    next_page->SetTweetText("Test text :)");
    next_page->SetReplies("1700");
    next_page->SetRetweets("666");
    next_page->SetLikes("777");
    next_page->SetDislikes("999");

    ui.verticalLayout_3->addWidget(next_page1);


    next_page1->SetTweetText("Test :)");
    next_page1->SetReplies("17");
    next_page1->SetRetweets("6");
    next_page1->SetLikes("7");
    next_page1->SetDislikes("9");

    ui.verticalLayout_3->addWidget(next_page2);


    next_page2->SetDate("Jan 1");
    next_page2->SetTweetText("Test :)");
    next_page2->SetReplies("17");
    next_page2->SetRetweets("6");
    next_page2->SetLikes("7");
    next_page2->SetDislikes("9");

    auto user1 = new UserInList(this);
    user1->SetButtonToFollowing();
    auto user2 = new UserInList(this);
    auto user3 = new UserInList(this);
    user2->SetButtonToFollowing(); user3->SetButtonToFollowing();

    ui.verticalLayout_friends->addWidget(user1);
    ui.verticalLayout_friends->addWidget(user2);
    ui.verticalLayout_friends->addWidget(user3);

}

UserProfile::~UserProfile()
{
}

void UserProfile::on_label_no_of_friends()
{
	//select no_of_friends from user where username=' '
	int no_of_friends = 0;
	std::string s = std::to_string(no_of_friends);
	QString text = QString::fromStdString(s);
	ui.label_no_of_friends->setText(text);

}