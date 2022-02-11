#include "Post.h"
#include"SeeComments.h"
#include"RetweetPreface.h"
#include"Retweet.h"

Post::Post(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
}

Post::~Post()
{
}

void Post::SetName(QString name)
{
	ui.name->setText(name);
}

void Post::SetUsername(QString username)
{
	ui.username->setText(username);
}

void Post::SetDate(QString date)
{
	ui.date->setText(date);
}

void Post::SetTweetText(QString text)
{
	ui.tweet->setText(text);
}

void Post::SetRetweets(QString noOfRetweets)
{
	ui.pushButton_retweet->setText(noOfRetweets);
	ui.pushButton_retweet->update();
}

void Post::SetReplies(QString noOfReplies)
{
	ui.pushButton_reply->setText(noOfReplies);
	ui.pushButton_reply->update();
}

void Post::SetLikes(QString noOfLikes)
{
	ui.pushButton_like->setText(noOfLikes);
	ui.pushButton_like->update();
}

void Post::SetDislikes(QString noOfDisLikes)
{
	ui.pushButton_dislike->setText(noOfDisLikes);
	ui.pushButton_dislike->update();
}

QPushButton* Post::GetRetweetButton()
{
	return ui.pushButton_retweet;
}


void Post::on_pushButton_reply_clicked()
{
	auto view = new SeeComments(this);
	ui.verticalLayout->addWidget(view);
	pushButton_Send = view->GetSendButton();
	connect(pushButton_Send, SIGNAL(clicked()), this, SLOT(on_pushButton_Send()));
}

void Post::on_pushButton_retweet_clicked()
{
	auto retweetPref = new RetweetPreface(this);
	ui.verticalLayout->addWidget(retweetPref);
	pushButton_retweetPref = retweetPref->GetRetweetPrefButton();
	connect(pushButton_retweetPref, SIGNAL(clicked()), this, SLOT(on_pushButton_retweetPref()));
	textEdit_retweet = retweetPref->GetTextEditRetweetPref();
	/*QString s = ui.pushButton_retweet->text();
	int no = s.toInt();
	no++;
	s = QString::number(no);
	ui.pushButton_retweet->setText(s);
	ui.pushButton_retweet->update();*/
}

void Post::on_pushButton_like_clicked()
{
	QString s = ui.pushButton_like->text();
	int no = s.toInt();
	if (isLike == false)
	{
		no++;
		isLike = true;
	}
	else {
		no--;
		isLike = false;
	}

	s = QString::number(no);
	ui.pushButton_like->setText(s);
	ui.pushButton_like->update();
}

void Post::on_pushButton_dislike_clicked()
{
	QString s = ui.pushButton_dislike->text();
	int no = s.toInt();
	if (isDislike == false)
	{
		no++;
		isDislike = true;
	}
	else {
		no--;
		isDislike = false;
	}

	s = QString::number(no);
	ui.pushButton_dislike->setText(s);
	ui.pushButton_dislike->update();
}

void Post::on_pushButton_retweetPref()
{

	auto retweet = new Retweet(this);
	QString s =textEdit_retweet->toPlainText();
	textEdit_retweet->clear();
	retweet->SetName("Current User");
	//retweet->SetUsername("username");
	retweet->SetDate("Current date");
	retweet->SetTweetText(s);
	retweet->SetRefName(ui.name->text());
	retweet->SetRefUsername(ui.username->text());
	retweet->SetRefDate(ui.date->text());
	retweet->SetRefTweetText(ui.tweet->text());
	retweet->SetRetweets("0");
	retweet->SetReplies("0");
	retweet->SetLikes("0");
	retweet->SetDislikes("0");

	//delete ui.verticalLayout->takeAt(0);
	ui.verticalLayout->update();
	ui.verticalLayout->addWidget( retweet);
	

}

void Post::on_pushButton_Send()
{
	QString count = ui.pushButton_reply->text();
	int no = count.toInt();
	no++;
	count = QString::number(no);
	ui.pushButton_reply->setText(count);
	ui.pushButton_reply->update();
}
