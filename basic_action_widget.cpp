#include "basic_action_widget.h"
#include<QPainter>
#include <iostream>
#include "action_container_widget.h"

basic_action_widget::basic_action_widget(QWidget *parent,std::string n,action_connection_manager_iface* conmgr):
    qt_action(parent),basic_action(n,conmgr)
{

}
void basic_action_widget::mouseReleaseEvent(QMouseEvent * event)
{
    std::cout<<"mouse release on action: "<<getName()<<std::endl;
    this->getConnectionManager()->connect(this);
}
void basic_action_widget::mousePressEvent(QMouseEvent * event)
{
    std::cout<<"mouse press on action: "<<getName()<<std::endl;
}


