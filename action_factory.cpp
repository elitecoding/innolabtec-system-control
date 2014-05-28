#include "action_factory.h"
#include "action_open_gripper.h"

action_factory::action_factory():factory()
{
   this->factory["Open Gripper"] = action_open_gripper::create;
}
action_iface* action_factory::create(std::string name,action_connection_manager_iface* con)
{
   return (this->factory[name])(con);
}
