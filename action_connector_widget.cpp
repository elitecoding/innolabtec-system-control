#include "action_connector_widget.h"
#include <iostream>
action_connector_widget::action_connector_widget(QWidget *parent) : QWidget(parent),action_connector()
{

}
action_connector_widget::action_connector_widget(QWidget *parent,QPoint from,QPoint to):QWidget(parent),action_connector(),from(from),to(to)
{
    std::cout<<"action_connector_widget ctor"<<std::endl;
}


