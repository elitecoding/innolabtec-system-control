#ifndef ACTION_FACTORY_H
#define ACTION_FACTORY_H

#include <map>
#include <string>
#include <list>
#include "action_connection_manager_iface.h"
#include "basic_action_widget.h"

typedef basic_action_widget* (*createPtr)( QWidget* parent,action_connection_manager_iface* );

class action_factory
{
    std::map<std::string,createPtr> factory;
    //std::map<std::string,createParameterPtr> parameterFactory;
public:
    action_factory();
    basic_action_widget* create(std::string name,QWidget* parent,action_connection_manager_iface*);
    std::list<std::string> getActionList();

};

#endif // ACTION_FACTORY_H
