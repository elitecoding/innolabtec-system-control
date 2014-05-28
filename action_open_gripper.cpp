#include "action_open_gripper.h"

action_open_gripper::action_open_gripper(action_connection_manager_iface* con):basic_action("Open Gripper",con)
{
}
action_iface* action_open_gripper::create(action_connection_manager_iface * con)
{
    return new action_open_gripper(con);
}
