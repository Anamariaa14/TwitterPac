#include "twitterpac_client2.h"
#include <QMessageBox>
#include "../Network/XMLParsing.h"
#include <array>
#include "../Network/TcpSocket.h"
#pragma comment(lib, "Ws2_32.lib")	///  indicates to the linker that the Ws2_32.lib
enum action
{
		Incorect_credentials,
        Correct_credentials,
		User_already_registered,
        Register_successfull,
		No_action
};
action convert(std::string& str)
{
	if (str == "Incorrect_credentials") return Incorect_credentials;
    if (str == "Correct_credentials") return Correct_credentials;
    else if (str == "User_already_registered") return User_already_registered;
    else if (str == "Register_successfull") return Register_successfull;
	else return No_action;
}
twitterpac_client2::twitterpac_client2(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    ui.stackedWidget->insertWidget(1, &sidebar);
}
void twitterpac_client2::on_pushButton_login_clicked()
{
    XMLParsing document;
    std::string buffContent;
        QString username = ui.lineEdit_username->text();
        QString password = ui.lineEdit_password->text();
        document.setUsername(username.toStdString());
        document.setPassword(password.toStdString());
        document.setField(false);
        document.setAction("Login");
        document.save("../date.xml");
    TcpSocket socket;
    socket.Connect("127.0.0.1", 27015);
        std::string message = "Login";
        socket.Send(message.c_str(), message.size());

        std::array<char, 512> receiveBuffer;
        int revieved;
        socket.Receive(receiveBuffer.data(), receiveBuffer.size(), revieved);
        for (std::array<char, 512>::iterator i = receiveBuffer.begin(); i != receiveBuffer.begin() + revieved; i++)
            buffContent += *i;
        action uAction = convert(buffContent);
        switch (uAction)
        {
        case Correct_credentials:
            QMessageBox::information(this, "Login", "Login successful!");
            ui.stackedWidget->setCurrentIndex(1);
            break;
        case Incorect_credentials:
            QMessageBox::warning(this, "Login", "The credentials you entered are incorrect!");
            break;
        default:
            QMessageBox::information(this, "Login", "Please enter credentials in !");
            break;
        }        
}

void twitterpac_client2::on_pushButton_register_clicked()
{
    ui.stackedWidget->setCurrentIndex(2);
}

void twitterpac_client2::on_pushButton_returnTo_login_clicked()
{
    ui.stackedWidget->setCurrentIndex(0);
}

void twitterpac_client2::on_pushButton_submit_registration_clicked()
{
    XMLParsing document;
    std::string userInformation;

    QString username_r = ui.lineEdit->text();
    QString password_r = ui.lineEdit_2->text();
    QString first_name_r = ui.lineEdit_3->text();
    QString last_name_r = ui.lineEdit_4->text();

    document.setUsername(username_r.toStdString());
    document.setPassword(password_r.toStdString());
    document.setFirstName(first_name_r.toStdString());
    document.setLastName(last_name_r.toStdString());
    document.setAction("Register");
    document.setField(false);
    document.save("../date.xml");

    TcpSocket socket;
   
    socket.Connect("127.0.0.1", 27015);
    
    std::string message = "Register";
    
    socket.Send(message.c_str(), message.size());

    std::array<char, 512> receiveBuffer;
    int revieved;
    socket.Receive(receiveBuffer.data(), receiveBuffer.size(), revieved);
    for (std::array<char, 512>::iterator i = receiveBuffer.begin(); i != receiveBuffer.begin() + revieved; i++)
        userInformation += *i;
    action uAction = convert(userInformation);
    switch (uAction)
    {
    case Register_successfull:
        QMessageBox::information(this, "Registration", "Registration complete!");
        ui.stackedWidget->setCurrentIndex(0);
        break;
    case User_already_registered:
        QMessageBox::warning(this, "Registration", "This username is already taken");
        break;
    default:
        QMessageBox::information(this, "Registration", "Please fill out the registration form properly");
        break;
    }
    userInformation.clear();
}
