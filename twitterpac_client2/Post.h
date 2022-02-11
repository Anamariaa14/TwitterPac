#pragma once

#include <QWidget>
#include "ui_Post.h"
#include<qpushbutton.h>
#include<qtextedit.h>

class Post : public QWidget
{
	Q_OBJECT

public:
	Post(QWidget *parent = Q_NULLPTR);
	~Post();
	void SetName(QString name);
	void SetUsername(QString username);
	void SetDate(QString date);
	void SetTweetText(QString text);
	void SetRetweets(QString noOfRetweets);
	void SetReplies(QString noOfReplies);
	void SetLikes(QString noOfLikes);
	void SetDislikes(QString noOfDisLikes);
	QPushButton* GetRetweetButton();



public slots:
	void on_pushButton_reply_clicked();
	void on_pushButton_retweet_clicked();
	void on_pushButton_like_clicked();
	void on_pushButton_dislike_clicked();
	void on_pushButton_retweetPref();
	void on_pushButton_Send();
private:
	Ui::Post ui;
	bool isLike = false, isDislike = false;
	QPushButton* pushButton_retweetPref = new QPushButton();
	QPushButton* pushButton_Send = new QPushButton();
	QTextEdit* textEdit_retweet = new QTextEdit();
};
