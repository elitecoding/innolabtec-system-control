#ifndef ACTION_LOAD_SAMPLE_H
#define ACTION_LOAD_SAMPLE_H

#include "basic_action_widget.h"

class action_load_sample : public basic_action_widget
{
public:
    action_load_sample(QWidget*,action_connection_manager_iface*);
    void execute();
    static basic_action_widget* create(QWidget* parent,action_connection_manager_iface * con);
};

#endif // ACTION_LOAD_SAMPLE_H
