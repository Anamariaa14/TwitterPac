#pragma once

#include <QWidget>
#include "ui_RetweetPreface.h"

class RetweetPreface : public QWidget
{
	Q_OBJECT

public:
	RetweetPreface(QWidget *parent = Q_NULLPTR);
	~RetweetPreface();

	QPushButton* GetRetweetPrefButton();
	QTextEdit* GetTextEditRetweetPref();
	void on_pushButton_retweetPref_clicked();
private:
	Ui::RetweetPreface ui;
};
