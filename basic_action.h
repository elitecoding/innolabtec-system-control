#ifndef BASIC_ACTION_H
#define BASIC_ACTION_H

#include"action_iface.h"
#include<QWidget>
#include<string>
#include "action_connection_manager_iface.h"


class basic_action: public action_iface
{
protected:
    std::string name;
    action_iface* next;
    action_connection_manager_iface* conManager;
    std::list<point_3d_list*> parameter;
    static int instanceCount;

public:
    basic_action();
    basic_action(std::string,action_connection_manager_iface*);

    inline void setNext(action_iface* next){this->next = next;}
    inline std::string getName(){return name;}
    inline action_connection_manager_iface* getConnectionManager(){return conManager;}
    inline std::list<point_3d_list*>* getParameterList(){return &parameter;}
    void addParameter(std::string,point_3d_list::parameterTypes);
};

#endif // BASIC_ACTION_H
