#include "action_load_sample.h"
#include <iostream>
#include "parameter_dock.h"
#include "innox.h"
#include "point_3d.h"
#include "parameter_widget.h"

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
    parameter_dock* pFrom = this->parameter["from"];
    parameter_dock* pTo = this->parameter["to"];

    point_3d_list* to = pTo->getParam();
    point_3d_list* from = pFrom->getParam();

    point_3d pointFrom =from->getParam();
    point_3d pointTo = to->getParam();

    std::cout<<"loading sample from "<<pointFrom<<" to "<<pointTo<<std::endl;
    innox::moveSampleTo(pointFrom.getName(),pointTo.getName());
}

