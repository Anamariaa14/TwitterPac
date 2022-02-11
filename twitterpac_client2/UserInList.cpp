#include "UserInList.h"

UserInList::UserInList(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void UserInList::SetButtonToFollowing()
{
	{
		ui.pushButton_follow->setText("Following");
		ui.pushButton_follow->setStyleSheet("QPushButton{background-color: rgb(255, 255, 255); color: rgb(0,0,0); border-radius: 15px; border: 2px solid grey;}");
		isFollowing = true;
	}
	update();
}

void UserInList::on_pushButton_follow_clicked()
{
	if(isFollowing==false)
		SetButtonToFollowing();
	else {
		ui.pushButton_follow->setText("Follow");
		ui.pushButton_follow->setStyleSheet("QPushButton{background-color: rgb(0, 0, 0); color: rgb(255, 255, 255); border-radius:15px;}\
			                                QPushButton:hover{background-color: rgb(15, 20, 25); color:rgb(255, 255, 255); border-radius:15px;}");
		isFollowing = false;
	}

	update();
}

void UserInList::SetName(QString name)
{
	ui.name->setText(name);
}

void UserInList::SetUsername(QString username)
{
	ui.username->setText(username);
}

UserInList::~UserInList()
{
}

