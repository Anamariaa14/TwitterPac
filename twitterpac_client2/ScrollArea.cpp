#include "ScrollArea.h"

ScrollArea::ScrollArea(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

QVBoxLayout* ScrollArea::GetVerticalLayout()
{
	return ui.verticalLayout;
}

ScrollArea::~ScrollArea()
{
}
