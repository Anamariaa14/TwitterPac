#include "Retweet.h"

Retweet::Retweet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void Retweet::SetName(QString name)
{
	ui.name->setText(name);
}

void Retweet::SetUsername(QString username)
{
	ui.username->setText(username);
}

void Retweet::SetDate(QString date)
{
	ui.date->setText(date);
}

void Retweet::SetTweetText(QString text)
{
	ui.tweet->setText(text);
}

void Retweet::SetRefName(QString name)
{
	ui.name_2->setText(name);
}

void Retweet::SetRefUsername(QString username)
{
	ui.username_2->setText(username);
}

void Retweet::SetRefDate(QString date)
{
	ui.date_2->setText(date);
}

void Retweet::SetRefTweetText(QString text)
{
	ui.tweet_2->setText(text);
}

void Retweet::SetRetweets(QString noOfRetweets)
{
	ui.pushButton_retweet->setText(noOfRetweets);
	ui.pushButton_retweet->update();
}

void Retweet::SetReplies(QString noOfReplies)
{
	ui.pushButton_reply->setText(noOfReplies);
	ui.pushButton_reply->update();
}

void Retweet::SetLikes(QString noOfLikes)
{
	ui.pushButton_like->setText(noOfLikes);
	ui.pushButton_like->update();
}

void Retweet::SetDislikes(QString noOfDisLikes)
{
	ui.pushButton_dislike->setText(noOfDisLikes);
	ui.pushButton_dislike->update();
}
void Retweet::on_pushButton_goToRef_clicked()
{

	if (goToRef==false) {
		auto ref_tweet = new Post(this);
		ui.verticalLayout_retweet->addWidget(ref_tweet);
		ref_tweet->SetName(ui.name_2->text());
		ref_tweet->SetUsername(ui.username_2->text());
		ref_tweet->SetDate(ui.date_2->text());
		ref_tweet->SetTweetText(ui.tweet_2->text());
		ref_tweet->SetReplies("1700");
		ref_tweet->SetRetweets("666");
		ref_tweet->SetLikes("777");
		ref_tweet->SetDislikes("999");
		ref_tweet->update();
		goToRef = true;
	
	}
}
void Retweet::on_pushButton_reply_clicked()
{
	if (!goToComments) {
		auto view = new SeeComments(this);
		ui.verticalLayout_retweet->addWidget(view);
		QString s = ui.pushButton_reply->text();
		int no = s.toInt();
		no++;
		s = QString::number(no);
		ui.pushButton_reply->setText(s);
		ui.pushButton_reply->update();
		goToRef = true;
	}
}

/*void Post::on_pushButton_retweet_clicked()
{
	QString s = ui.pushButton_retweet->text();
	int no = s.toInt();
	no++;
	s = QString::number(no);
	ui.pushButton_retweet->setText(s);
	ui.pushButton_retweet->update();
}
*/
void Retweet::on_pushButton_like_clicked()
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

void Retweet::on_pushButton_dislike_clicked()
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

Retweet::~Retweet()
{
}
