#ifndef BASIC_ACTION_H
#define BASIC_ACTION_H

#include"action_iface.h"
#include<QWidget>
#include<string>
#include "action_connection_manager_iface.h"


class basic_action: public action_iface
{
    std::string name;
    action_iface* next;
    action_connection_manager_iface* conManager;

public:
    basic_action();
    basic_action(std::string,action_connection_manager_iface*);

    void execute();

    inline void setNext(action_iface* next){this->next = next;}
    inline std::string getName(){return name;}
    inline action_connection_manager_iface* getConnectionManager(){return conManager;}
};

#endif // BASIC_ACTION_H
