#pragma once

#include <QWidget>
#include<qpushbutton.h>
#include "ui_SideBarMenu.h"
#include "TweetPost.h"
#include "UserProfile.h"
#include "Search.h"
#include"Post.h"
#include"Retweet.h"
#include"ScrollArea.h"
#include "RetweetPreface.h"
#include <qlabel.h>

class SideBarMenu : public QWidget
{
	Q_OBJECT

public:
	SideBarMenu(QWidget* parent = Q_NULLPTR);
	~SideBarMenu();
public slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_8_clicked();
	void on_pushButton_9_clicked();
	void on_next_clicked();
	void on_prev_clicked();
	
private:
	Ui::SideBarMenu ui;
	TweetPost m_tweet;
	UserProfile m_profile;
	Search m_searchBar;
	QPushButton* pushButton_retweet=new QPushButton();
	QPushButton* pushButton_retweetPref=new QPushButton();
};
