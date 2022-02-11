#include "SeeComments.h"
#include"CommentPost.h"

SeeComments::SeeComments(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    auto comment1 = new CommentPost(this);
    auto comment2 = new CommentPost(this);

    ui.verticalLayout->insertWidget(1,comment1);
    comment1->SetName("test");
    comment1->SetUsername("@test");
    comment1->SetDate("Jan 14");

    ui.verticalLayout->insertWidget(2,comment2);
    comment2->SetName("t");
    comment2->SetUsername("@t");
    comment2->SetDate("Jan 1");
}

SeeComments::~SeeComments()
{
}

QPushButton* SeeComments::GetSendButton()
{
    return ui.pushButton_Send;
}

void SeeComments::on_pushButton_Send_clicked()
{
    auto post = new CommentPost(this);
    ui.verticalLayout->insertWidget(0, post);
    post->SetName("TEST");
    post->SetUsername("@test");
    post->SetDate("Jan 14");
    QString s = ui.textEdit->toPlainText();
    post->SetCommentText(s);
    ui.textEdit->clear();

}
