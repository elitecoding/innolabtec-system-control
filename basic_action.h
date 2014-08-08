#ifndef BASIC_ACTION_H
#define BASIC_ACTION_H

#include"action_iface.h"
#include <QWidget>
#include <string>
#include "action_connection_manager_iface.h"
#include "parameter_dock.h"
#include "parameter_dock_widget.h"
#include <map>
#include <QMouseEvent>

class basic_action: public action_iface
{
protected:
    std::string name;
    action_iface* next;
    action_connection_manager_iface* conManager;
    std::map<std::string,parameter_dock*> parameter;
    static int instanceCount;

public:
    basic_action();
    basic_action(std::string,action_connection_manager_iface*);

    inline void setNext(action_iface* next){this->next = next;}
    inline std::string getName(){return name;}
    inline action_connection_manager_iface* getConnectionManager(){return conManager;}
    inline std::map<std::string,parameter_dock*>* getParameterList(){return &parameter;}
    virtual void addParameter(parameter_dock*);
    void mouseMoveEvent(QMouseEvent * event);
};

#endif // BASIC_ACTION_H
