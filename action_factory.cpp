#include "action_factory.h"
#include "action_open_gripper.h"

action_factory::action_factory():factory()
{
   this->factory["OpenGripper"] = action_open_gripper::create;
}
basic_action_widget* action_factory::create(std::string name,QWidget* parent,action_connection_manager_iface* con)
{
   return (this->factory[name])(parent,con);
}
std::list<std::string> action_factory::getActionList()
{
    std::map<std::string,createPtr>::iterator start;
    std::list<std::string> ret;
    for(start=this->factory.begin();start!=this->factory.end();start++)
    {
        ret.push_back((*start).first);
    }

    return ret;
}
