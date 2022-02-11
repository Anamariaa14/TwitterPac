#include "SideBarMenu.h"


SideBarMenu::SideBarMenu(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    auto scroll_area = new ScrollArea(this);
    auto vertical_layout = scroll_area->GetVerticalLayout();
    auto post = new Post(this);

    ui.stackedWidget_feed->addWidget(scroll_area);
    vertical_layout->addWidget(post);
    ui.stackedWidget_feed->setCurrentIndex(0);

    ui.stackedWidget_2->insertWidget(1, &tweet);
    ui.stackedWidget_2->insertWidget(2, &profile);
    ui.stackedWidget_2->insertWidget(3, &searchBar);

}
SideBarMenu::~SideBarMenu()
{
}

void SideBarMenu::on_pushButton_clicked()
{
    ui.stackedWidget_2->setCurrentIndex(0);
}

void SideBarMenu::on_pushButton_2_clicked()
{
    ui.stackedWidget_2->setCurrentIndex(1);//goto -> indexed element
}

void SideBarMenu::on_pushButton_3_clicked()
{
    ui.stackedWidget_2->setCurrentIndex(2);
}

void SideBarMenu::on_pushButton_8_clicked()
{
    ui.stackedWidget_2->setCurrentIndex(3);
}

void SideBarMenu::on_pushButton_9_clicked()
{
    ui.stackedWidget->setCurrentIndex(0);
}

void SideBarMenu::on_next_clicked()
{
    auto scroll_area = new ScrollArea(this);
    auto vertical_layout = scroll_area->GetVerticalLayout();
    ui.stackedWidget_feed->addWidget(scroll_area);

    if (ui.stackedWidget_feed->currentIndex() % 2 == 0) {
        auto next_retweet = new Retweet (this);
        vertical_layout->addWidget(next_retweet);
        next_retweet->SetReplies("70");
        next_retweet->SetRetweets("66");
        next_retweet->SetLikes("77");
        next_retweet->SetDislikes("99");

    }
    else {
        auto next_tweet = new Post(this);
        //pushButton_retweet = next_tweet->GetRetweetButton();
        vertical_layout->addWidget(next_tweet);
        next_tweet->SetName("test");
        next_tweet->SetUsername("@test");
        next_tweet->SetDate("Jan 14");
        next_tweet->SetTweetText("Test text :)");
        next_tweet->SetReplies("1700");
        next_tweet->SetRetweets("666");
        next_tweet->SetLikes("777");
        next_tweet->SetDislikes("999");
    }
    ui.stackedWidget_feed->setCurrentIndex(ui.stackedWidget_feed->currentIndex() + 1);
    
}

void SideBarMenu::on_prev_clicked()
{
    ui.stackedWidget_feed->setCurrentIndex(ui.stackedWidget_feed->currentIndex() - 1);
}



