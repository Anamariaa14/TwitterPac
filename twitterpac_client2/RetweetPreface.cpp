#include "RetweetPreface.h"
#include "Retweet.h"

RetweetPreface::RetweetPreface(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

RetweetPreface::~RetweetPreface()
{
}

QPushButton* RetweetPreface::GetRetweetPrefButton()
{
    return ui.pushButton_retweetPref;
}

QTextEdit* RetweetPreface::GetTextEditRetweetPref()
{
    return ui.textEdit;
}

void RetweetPreface::on_pushButton_retweetPref_clicked()
{
    /*auto post = new Retweet(this);
    ui.verticalLayout->insertWidget(0, post);
    post->SetName("TEST");
    post->SetUsername("@test");
    post->SetDate("Jan 14");
    QString s = ui.textEdit->toPlainText();
    post->SetCommentText(s);
    ui.textEdit->clear();*/
}
