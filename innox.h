#ifndef INNOX_H
#define INNOX_H

#include <QtNetwork/QTcpSocket>
#include <string>

class innox
{

    static const int port = 7787;
    static QTcpSocket socket;
public:

    static void connect();

    static void openGripper();
    static void closeGripper();
    static void moveSampleTo(std::string from, std::string to);

};

#endif // INNOX_H
