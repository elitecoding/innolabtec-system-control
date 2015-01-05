#ifndef INNOX_H
#define INNOX_H

#include <QtNetwork/QTcpSocket>
#include <string>

class innox
{
    Q_OBJECT

    static const int port = 7787;
    static QTcpSocket socket;
public:

    static void openGripper();
    static void closeGripper();
    static void moveSampleTo(std::string from, std::string to);

private:
    static bool connect();

};

#endif // INNOX_H
