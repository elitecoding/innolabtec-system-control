#ifndef ACTION_FACTORY_H
#define ACTION_FACTORY_H

#include <map>
#include <string>
#include "action_connection_manager_iface.h"
#include "action_iface.h"

typedef action_iface* (*createPtr)( action_connection_manager_iface* );

class action_factory
{
    std::map<std::string,createPtr> factory;
public:
    action_factory();
    action_iface* create(std::string name,action_connection_manager_iface*);

};

#endif // ACTION_FACTORY_H
