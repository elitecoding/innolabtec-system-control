#include "action_open_gripper.h"
#include <iostream>

action_open_gripper::action_open_gripper(QWidget* parent,action_connection_manager_iface* con):
    basic_action_widget(parent,"Open Gripper",con)
{
}
basic_action_widget* action_open_gripper::create(QWidget* parent,action_connection_manager_iface * con)
{
    return new action_open_gripper(parent,con);
}
void action_open_gripper::execute()
{
    std::cout<<"Opening gripper"<<std::endl;

}
