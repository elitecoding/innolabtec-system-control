#include "action_container_widget.h"

#include <math.h>
#include <iostream>

action_container_widget::action_container_widget(QWidget *parent) :
    QWidget(parent),pendingConnection(0),pendingParameter(0),currentMarkedItem(0)
{
    this->drawConnection = false;
    this->connectionStarted = false;
    this->activateWindow();
    this->grabKeyboard();

    /*
    basic_action_widget* action = new basic_action_widget(this,"Action 1",this);
    basic_action_widget* action2 = new basic_action_widget(this,"Action 1",this);
    action->execute();
    action->move(100,100);
    action2->move(400,100);
    */

}
void action_container_widget::keyPressEvent(QKeyEvent * k)
{
    std::cout<<"key press: "<<k->key()<<std::endl;

    if(k->key() == 16777223) //Entf
    {
        if(this->currentMarkedItem!=0)
        {
            this->currentMarkedItem->deleteItem();
            this->currentMarkedItem = 0;
        }
    }
}

void action_container_widget::mark(markable_iface* m)
{
    if(this->currentMarkedItem!=0)
    {
        if(this->currentMarkedItem!=m)
        {
            this->currentMarkedItem->unmarkItem();
        }


    }

    this->currentMarkedItem = m;
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
    std::cout<<"Container: mouse press"<<std::endl;
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
    if(this->pendingConnection!=0 && to != this->pendingConnection)
    {

        /* check for a bi-directional connection */
        if(to->getTo()!=0)
        {
            if( to->getTo()->getTo() == this->pendingConnection )
            {
                /* prevent loop */
                std::cout<<"You can not from a bi-directional link!"<<std::endl;
                return;
            }
        }

        /* delete former connection pointing to "to" */
        if(to->getFrom() != 0)
        {
            to->getFrom()->deleteConnection();
        }

        /* delete former outgoing connection of "from" */
        if(this->pendingConnection->getTo() != 0)
        {
            this->pendingConnection->getTo()->deleteConnection();
        }

        /* Next pointer is not used... */
        this->pendingConnection->setNext(to);

        action_connector_widget* con = new action_connector_widget(this,this,this->pendingConnection,to);
        to->setFrom(con);
        this->pendingConnection->setTo(con);

        this->connections.push_back(con);

        this->pendingConnection = 0;
        this->connectionStarted = false;

        con->show();
        this->update();
    }
}
void action_container_widget::startConnection(basic_action_widget* from)
{
    this->pendingConnection=from;
}
void action_container_widget::connect(basic_action_widget* action)
{
    if(connectionStarted)
    {
        if(this->pendingConnection != action)
        {
            stopConnection(action);
            connectionStarted = false;
        }
    }else
    {
        startConnection(action);
        connectionStarted = true;
    }
}
void action_container_widget::connect(parameter_widget* param)
{
    if(connectionStarted)
    {

    }else
    {
        pendingParameter = param;
        connectionStarted=true;
    }
}
void action_container_widget::connect(parameter_dock_widget* param)
{
    if(connectionStarted && pendingParameter!=0)
    {
        param->setParameter(pendingParameter->getParam());

        parameter_dock_widget* p = param;
        parameter_dock* d = p;
        QWidget* w = (QWidget*)d;
        parameter_dock_widget* p2 = (parameter_dock_widget*)d;
        QWidget* w2 = (QWidget*)p2;

        parameter_connector_widget* con = new parameter_connector_widget(this,this,pendingParameter,param);
        param->setConnector(con);
        pendingParameter->setConnector(con);
        con->show();
        this->update();
        pendingParameter = 0;
        connectionStarted = false;
    }else
    {

    }
}
void action_container_widget::execute()
{

    std::list<action_connector_widget*>::iterator iter;
    basic_action_widget* entry = 0;
    for(iter = this->connections.begin();iter != this->connections.end();iter++)
    {
        action_connector_widget* con = (action_connector_widget*)(*iter);
        if(con->getFrom()!=0)
        {
            if(con->getFrom()->getFrom() == 0)
            {
                std::cout<<"Entry point found: "<<con->getFrom()->getName()<<std::endl;
                entry=con->getFrom();
                break;
            }
        }
    }
    if(entry == 0)
    {
        std::cout<<"No entry point found! Make sure to have one action with only an outgoing connection."<<std::endl;
        return;
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
