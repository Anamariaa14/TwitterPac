#pragma once

#include <QWidget>
#include "ui_ScrollArea.h"

class ScrollArea : public QWidget
{
	Q_OBJECT

public:
	ScrollArea(QWidget *parent = Q_NULLPTR);
	QVBoxLayout* GetVerticalLayout();
	~ScrollArea();

private:
	Ui::ScrollArea ui;
};
