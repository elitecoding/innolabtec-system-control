#include "basic_action_widget.h"
#include <QPainter>
#include <iostream>
#include "action_connection_manager_iface.h"
#include "action_connector_widget.h"
#include <sstream>


basic_action_widget::basic_action_widget(QWidget *parent,std::string n,action_connection_manager_iface* conmgr):
    qt_action(n,parent),basic_action(n,conmgr),from(0),to(0)
{
    std::stringstream ss;
    ss << this->instanceCount;
    std::string str = ss.str();

    this->qlName.setText((n+" "+str).c_str());
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

        if(this->from)
            this->from->onActionMoved();
        if(this->to)
            this->to->onActionMoved();
    }
}

