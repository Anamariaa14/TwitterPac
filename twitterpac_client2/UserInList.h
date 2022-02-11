#pragma once

#include <QWidget>
#include "ui_UserInList.h"

class UserInList : public QWidget
{
	Q_OBJECT

public:
	UserInList(QWidget* parent = Q_NULLPTR);
	void SetButtonToFollowing();
	void SetName(QString name);
	void SetUsername(QString username);
	~UserInList();

public slots:
	void on_pushButton_follow_clicked();

private:
	Ui::UserInList ui;
	bool isFollowing=false;
};
