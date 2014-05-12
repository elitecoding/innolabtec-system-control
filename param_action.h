#ifndef PARAM_ACTION_H
#define PARAM_ACTION_H

#include "action_param_iface.h"
#include "basic_action.h"
#include "point_3d.h"

class param_action : public basic_action
{

    action_param_iface<point_3d>* data;

public:
    param_action();
    action_param_iface<point_3d>* getParam(){return data;}
};

#endif // PARAM_ACTION_H
