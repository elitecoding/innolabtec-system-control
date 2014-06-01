#ifndef ACTION_OPEN_GRIPPER_H
#define ACTION_OPEN_GRIPPER_H

#include <string>
#include "basic_action_widget.h"

class action_open_gripper : public basic_action_widget
{
public:
    action_open_gripper(QWidget*,action_connection_manager_iface*);
    void execute();
    static basic_action_widget* create(QWidget* parent,action_connection_manager_iface * con);
};

#endif // ACTION_OPEN_GRIPPER_H
