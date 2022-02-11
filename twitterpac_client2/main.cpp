#include "twitterpac_client2.h"
#include <QtWidgets/QApplication>
#include"../Logger/Logger.h"
#include <array>
#include "../Network/TcpSocket.h"
#include "../Network/XMLParsing.h"
int main(int argc, char *argv[])
{
	if (argc != 2) {
		
		return 1;
	}
    QApplication a(argc, argv);
    twitterpac_client2 w;
    w.show();
    return a.exec();
}