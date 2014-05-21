#include "action_connector_widget.h"
#include <iostream>
action_connector_widget::action_connector_widget()
{

}
action_connector_widget::action_connector_widget(basic_action_widget* from,basic_action_widget* to):from(from),to(to)
{
    std::cout<<"action_connector_widget ctor"<<std::endl;
}


