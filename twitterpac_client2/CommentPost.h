#pragma once

#include <QWidget>
#include "ui_CommentPost.h"

class CommentPost : public QWidget
{
	Q_OBJECT

public:
	CommentPost(QWidget *parent = Q_NULLPTR);
	~CommentPost();
	void SetName(QString name);
	void SetUsername(QString username);
	void SetDate(QString date);
	void SetCommentText(QString text);

private:
	Ui::CommentPost ui;
};
