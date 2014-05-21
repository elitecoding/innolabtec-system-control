#include "basic_action_widget.h"
#include<QPainter>
#include <iostream>
#include "action_connection_manager_iface.h"

basic_action_widget::basic_action_widget(QWidget *parent,std::string n,action_connection_manager_iface* conmgr,actionPtr ptr):
    qt_action(n,parent),basic_action(n,conmgr,ptr)
{

}
void basic_action_widget::mouseReleaseEvent(QMouseEvent * event)
{
    std::cout<<"mouse release on action: "<<getName()<<std::endl;

    if(this->rect().contains(event->pos())&&!this->isDragging)
    {
        this->getConnectionManager()->connect(this);
    }

    this->isDragging = false;
}
void basic_action_widget::mousePressEvent(QMouseEvent * event)
{
    this->dragStart = event->pos();
    std::cout<<"mouse press on action: "<<getName()<<std::endl;
}
void basic_action_widget::mouseMoveEvent(QMouseEvent* event)
{
    if((event->pos()-this->dragStart).manhattanLength()>10)
    {
       this->isDragging = true;
    }
    if(isDragging)
    {
        QPoint moveTo = this->mapToParent(event->pos());
        moveTo-=this->dragStart;
        this->move(moveTo);
        this->parentWidget()->update();
    }
}

