#pragma once

#include <QWidget>
#include "ui_Search.h"
bool comparator(const std::pair<int, std::string>& pereche1, const std::pair<int, std::string>& pereche2);
class Search : public QWidget
{
	Q_OBJECT

public:
	Search(QWidget *parent = Q_NULLPTR);
	~Search();
public slots:
	void on_pushButton_search_clicked();

private:
	Ui::Search ui;
};
