#pragma once

#include <QWidget>
#include "ui_SeeComments.h"

class SeeComments : public QWidget
{
	Q_OBJECT

public:
	SeeComments(QWidget *parent = Q_NULLPTR);
	~SeeComments();
	QPushButton* GetSendButton();

public slots:
	void on_pushButton_Send_clicked();

private:
	Ui::SeeComments ui;
};
