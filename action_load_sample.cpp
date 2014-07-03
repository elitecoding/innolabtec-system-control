#include "action_load_sample.h"
#include <iostream>
#include <parameter_dock.h>

action_load_sample::action_load_sample(QWidget* parent,action_connection_manager_iface* con):
    basic_action_widget(parent,"load sample",con)
{
    this->addParameter("from",point_3d_list::List);
    this->addParameter("to",point_3d_list::Single);
}
basic_action_widget* action_load_sample::create(QWidget* parent,action_connection_manager_iface * con)
{
    return new action_load_sample(parent,con);
}
void action_load_sample::execute()
{
    std::cout<<"loading sample"<<std::endl;
    point_3d_list* pFrom = this->parameter["from"]->getParam();
    point_3d_list* pTo = this->parameter["from"]->getParam();

    point_3d to = pTo->getParam();

    while(pFrom->hasParameter())
    {
        point_3d curr = pFrom->getParam();
        std::cout<<"loading sample from "<<curr<<" to "<<to<<std::endl;
    }
}

