#include "basic_action.h"
#include<iostream>

basic_action::basic_action()
{
    std::cout<<"basic_action ctor"<<std::endl;
}
basic_action::basic_action(std::string n):name(n)
{
    std::cout<<"basic_action ctor. Name: "<<name<<std::endl;
}
void basic_action::execute()
{
    std::cout<<"executing basic action"<<std::endl;
}