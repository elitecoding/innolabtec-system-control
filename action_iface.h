#ifndef ACTION_IFACE_H
#define ACTION_IFACE_H

#include <list>
#include "point_3d_list.h"

class action_iface
{
public:
    virtual void execute() = 0;
    virtual void setNext(action_iface* next) = 0;
    virtual std::list<point_3d_list*>* getParameterList() = 0;
};

#endif // ACTION_IFACE_H
