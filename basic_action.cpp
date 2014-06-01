#include "basic_action.h"
#include<iostream>

int basic_action::instanceCount = 0;

basic_action::basic_action()
{
    std::cout<<"basic_action ctor"<<std::endl;
    instanceCount++;
}
basic_action::basic_action(std::string n,action_connection_manager_iface* mgr):name(n),next(0),conManager(mgr),parameter()
{
    std::cout<<"basic_action ctor. Name: "<<name<<" Instance count: "<<instanceCount<<std::endl;
    instanceCount++;
}
void basic_action::addParameter(std::string name, point_3d_list::parameterTypes type)
{
    this->parameter.push_front(new point_3d_list(name,type));
}
