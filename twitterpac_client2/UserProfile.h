#pragma once

#include <QWidget>
#include "ui_UserProfile.h"
#include"Post.h"
#include"UserInList.h"

class UserProfile : public QWidget
{
	Q_OBJECT

public:
	UserProfile(QWidget *parent = Q_NULLPTR);
	~UserProfile();

public slots:
	void on_label_no_of_friends();

private:
	Ui::UserProfile ui;
};
