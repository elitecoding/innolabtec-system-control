#ifndef ACTION_IFACE_H
#define ACTION_IFACE_H

#include <map>
#include "parameter_dock.h"

class action_iface
{
public:
    virtual void execute() = 0;
    virtual void setNext(action_iface* next) = 0;
    virtual std::map<std::string,parameter_dock*>* getParameterList() = 0;
};

#endif // ACTION_IFACE_H
