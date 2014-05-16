#include "basic_action.h"
#include<iostream>

basic_action::basic_action()
{
    std::cout<<"basic_action ctor"<<std::endl;
}
basic_action::basic_action(std::string n,action_connection_manager_iface* mgr,actionPtr ptr):name(n),next(0),conManager(mgr),action(ptr)
{
    std::cout<<"basic_action ctor. Name: "<<name<<std::endl;
}
void basic_action::execute()
{
    std::cout<<"executing basic action"<<std::endl;
    this->action();
}
