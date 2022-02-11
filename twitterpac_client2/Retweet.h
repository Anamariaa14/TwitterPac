#pragma once

#include <QWidget>
#include "ui_Retweet.h"
#include "Post.h"
#include "SeeComments.h"

class Retweet : public QWidget
{
	Q_OBJECT

public:
	Retweet(QWidget *parent = Q_NULLPTR);
	void SetName(QString name);
	void SetUsername(QString username);
	void SetDate(QString date);
	void SetTweetText(QString text);
	void SetRefName(QString name);
	void SetRefUsername(QString username);
	void SetRefDate(QString date);
	void SetRefTweetText(QString text);
	void SetRetweets(QString noOfRetweets);
	void SetReplies(QString noOfReplies);
	void SetLikes(QString noOfLikes);
	void SetDislikes(QString noOfDisLikes);
	~Retweet();
public slots:
	void on_pushButton_goToRef_clicked();
	void on_pushButton_reply_clicked();
	//void on_pushButton_retweet_clicked();
	void on_pushButton_like_clicked();
	void on_pushButton_dislike_clicked();

private:
	Ui::Retweet ui;
	bool isLike = false, isDislike = false, goToRef = false, goToComments = false;
};
