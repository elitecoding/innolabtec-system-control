#ifndef BASIC_ACTION_H
#define BASIC_ACTION_H

#include"action_iface.h"
#include<QWidget>
#include<string>
#include "action_connection_manager_iface.h"

typedef void (*actionPtr)(void);

class basic_action: public action_iface
{
    std::string name;
    action_iface* next;
    action_connection_manager_iface* conManager;
    actionPtr action;

public:
    basic_action();
    basic_action(std::string,action_connection_manager_iface*,actionPtr);
    void execute();
    inline void setNext(action_iface* next){this->next = next;}
    inline std::string getName(){return name;}
    inline action_connection_manager_iface* getConnectionManager(){return conManager;}
};

#endif // BASIC_ACTION_H
