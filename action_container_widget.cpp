#include "action_container_widget.h"
#include <math.h>
action_container_widget::action_container_widget(QWidget *parent) :
    QWidget(parent)
{
    this->drawConnection = false;
    this->connectionStarted = false;

    basic_action_widget* action = new basic_action_widget(this,"Action 1",this,&innox::closeGripper);
    basic_action_widget* action2 = new basic_action_widget(this,"Action 1",this,&innox::openGripper);
    action->execute();
    action->move(100,100);
    action2->move(400,100);
}
void action_container_widget::attacheConnection(basic_action_widget *action)
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
        paint.drawLine(con->getFrom()->pos(),con->getTo()->pos());
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
    /*
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
    }*/
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
        this->pendingConnection->setTo(to);
        this->pendingConnection->getFrom()->setNext(to);
        QPoint dir = to->pos()-this->startPoint;
        dir = dir/sqrt( pow(dir.x(),2)+pow(dir.y(),2));
        this->startPoint-=dir;

        QPoint sub(to->width()/2,to->height()/2);
        //Why not just keep the references in the actions and while rendering just process all actions and draw each connection?
        //this->connections.push_back(new action_connector_widget(0,this->startPoint,to->pos()-dir+sub));
        this->connections.push_back(new action_connector_widget(this->pendingConnection->getFrom(),to));
        this->update();
    }
}
void action_container_widget::startConnection(basic_action_widget* from)
{
    this->pendingConnection = new action_connector_widget();
    this->pendingConnection->setFrom(from);

    this->startPoint = from->pos();
    QPoint sub(from->width()/2,from->height()/2);
    this->startPoint+=sub;
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
