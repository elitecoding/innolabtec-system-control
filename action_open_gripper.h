#ifndef ACTION_OPEN_GRIPPER_H
#define ACTION_OPEN_GRIPPER_H

#include <string>
#include "basic_action.h"

class action_open_gripper : public basic_action
{
public:
    action_open_gripper(action_connection_manager_iface*);
    static action_iface* create(action_connection_manager_iface*);
};

#endif // ACTION_OPEN_GRIPPER_H
