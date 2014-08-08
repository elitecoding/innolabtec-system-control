#include "innox.h"
#include <iostream>


QTcpSocket innox::socket;

void innox::connect()
{
   socket.connectToHost("loaclhost",port);
   if(!socket.waitForConnected(5000))
   {
        std::cout << "Error: " << socket.errorString().toStdString()<<std::endl;
   }
}

void innox::closeGripper()
{
    std::cout<<"closing Gripper"<<std::endl;
}
void innox::openGripper()
{
    std::cout<<"opening Gripper"<<std::endl;
}
void innox::moveSampleTo(std::string from, std::string to)
{
   char data[1];
   data[0] = 200;
   socket.write(data,1);

   QString f(from.c_str());
   f+=" ";
   QString t(to.c_str());
   f+=t;

   socket.write(f.toUtf8().append('\r'));
   socket.waitForBytesWritten();
}
