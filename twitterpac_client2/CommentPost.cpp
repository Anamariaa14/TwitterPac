#include "CommentPost.h"

CommentPost::CommentPost(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

CommentPost::~CommentPost()
{
}

void CommentPost::SetName(QString name)
{
	ui.name->setText(name);
}

void CommentPost::SetUsername(QString username)
{
	ui.username->setText(username);
}

void CommentPost::SetDate(QString date)
{
	ui.date->setText(date);
}

void CommentPost::SetCommentText(QString text)
{
	ui.comment->setText(text);
}
