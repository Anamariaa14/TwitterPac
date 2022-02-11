#pragma once

#include <QWidget>
#include <QMessageBox>
#include <string>
#include "Tweet.h"
#include "ui_TweetPost.h"
#include "../Network/XMLParsing.h"
#include "../Network/TcpSocket.h"
#include <array>
#include <vector>
#include "Comment.h"

class TweetPost : public QWidget
{
	Q_OBJECT

public:
	TweetPost(QWidget *parent = Q_NULLPTR);
	~TweetPost();

private:
	Ui::TweetPost ui;

private slots:
	void on_tweet_clicked();
};
