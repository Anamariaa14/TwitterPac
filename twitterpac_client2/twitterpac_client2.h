#pragma once

#include <QtWidgets/QWidget>
#include "ui_twitterpac_client2.h"
#include "SideBarMenu.h"

//#include "Credentials.h"
class twitterpac_client2 : public QWidget
{
    Q_OBJECT

public:
    twitterpac_client2(QWidget* parent = Q_NULLPTR);
    //Credentials getData();
private:
    Ui::twitterpac_client2Class ui;
    SideBarMenu sidebar;
    //Credentials data;
private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_register_clicked();
    void on_pushButton_returnTo_login_clicked();
    void on_pushButton_submit_registration_clicked();
};