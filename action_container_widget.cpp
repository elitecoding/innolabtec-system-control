#include "action_container_widget.h"
#include <math.h>
#include <iostream>

action_container_widget::action_container_widget(QWidget *parent) :
    QWidget(parent)
{
    this->drawConnection = false;
    this->connectionStarted = false;

    /*
    basic_action_widget* action = new basic_action_widget(this,"Action 1",this);
    basic_action_widget* action2 = new basic_action_widget(this,"Action 1",this);
    action->execute();
    action->move(100,100);
    action2->move(400,100);
    */

}
void action_container_widget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    if(this->drawConnection)
    {
        paint.drawLine(startPoint,stopPoint);
    }

    /*
    std::list<action_connector_widget*>::iterator iter;

    for(iter = this->connections.begin();iter != this->connections.end();iter++)
    {
        action_connector_widget* con = (action_connector_widget*)(*iter);
        paint.drawLine(con->getFrom()->pos(),con->getTo()->pos());
    }*/
}

void action_container_widget::mouseMoveEvent(QMouseEvent *event)
{
    //std::cout<<"mose move event"<<std::endl;
    if(this->drawConnection)
    {
        this->stopPoint = event->pos();
        this->update();
        //std::cout<<"mose move event ann mouse was pressed"<<std::endl;
    }
}
void action_container_widget::mousePressEvent(QMouseEvent *event)
{
    this->pendingConnection = 0;
    this->connectionStarted = false;
}
/*
void action_container_widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(drawConnection)
    {
        drawConnection = false;
        this->stopPoint = event->pos();
        action_connector_widget* con = new action_connector_widget(this,this->startPoint,this->stopPoint);
        this->connections.push_back(con);
        this->update();
    }else
    {

    }
}*/
void action_container_widget::stopConnection(basic_action_widget* to)
{
    if(this->pendingConnection!=0)
    {
        this->pendingConnection->getFrom()->setNext(to);

        action_connector_widget* con = new action_connector_widget(this,this->pendingConnection->getFrom(),to);
        to->setFrom(con);
        this->pendingConnection->getFrom()->setTo(con);

        this->connections.push_back(con);

        delete this->pendingConnection;
        this->pendingConnection = 0;
        this->connectionStarted = false;

        con->show();
        this->update();
    }
}
void action_container_widget::startConnection(basic_action_widget* from)
{
    this->pendingConnection = new action_connector_widget(this);
    this->pendingConnection->setFrom(from);
}
void action_container_widget::connect(basic_action_widget* action)
{
    if(connectionStarted)
    {
        stopConnection(action);
        connectionStarted = false;
    }else
    {
        startConnection(action);
        connectionStarted = true;
    }
}
void action_container_widget::execute()
{

    std::list<action_connector_widget*>::iterator iter;
    basic_action_widget* entry;
    for(iter = this->connections.begin();iter != this->connections.end();iter++)
    {
        action_connector_widget* con = (action_connector_widget*)(*iter);
        if(con->getFrom()->getFrom() == 0)
        {
            std::cout<<"Entry point found: "<<con->getFrom()->getName()<<std::endl;
            entry=con->getFrom();
            break;
        }
    }
    entry->execute();

    while(entry->getTo()!=0)
    {
        if(entry->getTo()->getTo()!=0)
        {
            entry = entry->getTo()->getTo();
        }else
        {
            break;
        }

        entry->execute();
    }

    std::cout<<"Programm terminated!"<<std::endl;
}
