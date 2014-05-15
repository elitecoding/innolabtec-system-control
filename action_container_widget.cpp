#include "action_container_widget.h"

action_container_widget::action_container_widget(QWidget *parent) :
    QWidget(parent)
{
    this->drawConnection = false;
    this->connectionStarted = false;
    basic_action_widget* action = new basic_action_widget(this,"Action 1",this);
    action->move(100,100);
}
void action_container_widget::attacheConnection(basic_action *action)
{
    //action->next =
}
void action_container_widget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    if(this->drawConnection)
    {
        paint.drawLine(startPoint,stopPoint);
    }

    std::list<action_connector_widget*>::iterator iter;

    for(iter = this->connections.begin();iter != this->connections.end();iter++)
    {
        action_connector_widget* con = (action_connector_widget*)(*iter);
        paint.drawLine(con->getFrom(),con->getTo());
    }
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
    if(drawConnection)
    {
        drawConnection = false;
        this->stopPoint = event->pos();
        action_connector_widget* con = new action_connector_widget(this,this->startPoint,this->stopPoint);
        this->connections.push_back(con);
        this->update();
    }else
    {
        this->startPoint = event->pos();
        this->drawConnection = true;
    }
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
void action_container_widget::stopConnection(action_iface* to)
{
    if(this->pendingConnection!=0)
    {
        this->pendingConnection->setTo(to);
        this->pendingConnection->getFrom()->setNext(this->pendingConnection);
    }
}
void action_container_widget::startConnection(action_iface* from)
{
    this->pendingConnection = new action_connector();
    this->pendingConnection->setFrom(from);
}
void action_container_widget::connect(action_iface* action)
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
