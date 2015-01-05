#include "innox.h"
#include <iostream>

#include <QHostAddress>
#include <QMessageBox>
QTcpSocket innox::socket;

bool innox::connect()
{
   QHostAddress addr("10.0.0.1");
   socket.connectToHost(addr,port);
   if(!socket.waitForConnected(10000))
   {
        std::cout << "Error: " << socket.errorString().toStdString()<<std::endl;
        return false;
   }else
   {
       std::cout<<"Connection established!"<<std::endl;
   }

   return true;
}

void innox::closeGripper()
{
    if(connect())
    {
        std::cout<<"closing gripper"<<std::endl;
        char data[1];
        data[0] = 106;
        socket.write(data,1);
        socket.waitForBytesWritten();
        socket.close();
    }
}

void innox::openGripper()
{
    if(connect())
    {
        std::cout<<"opening gripper"<<std::endl;
        char data[1];
        data[0] = 105;
        socket.write(data,1);
        socket.waitForBytesWritten();
        socket.close();
    }
}

void innox::moveSampleTo(std::string from, std::string to)
{
   if(connect())
   {



       std::cout<<"moving sample from "<<from<<" to "<<to<<std::endl;
       char data[1];

       data[0] = 201;

       socket.write(data,1);

       QString f("01");

       socket.write(f.toUtf8().append('\r'));
       socket.waitForBytesWritten();

       socket.close();
   }
}
