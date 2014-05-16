#ifndef BASIC_ACTION_WIDGET_H
#define BASIC_ACTION_WIDGET_H

#include <stdio.h>
#include <string>
#include "basic_action.h"
#include "qt_action.h"

class action_connection_manager_iface;

class basic_action_widget : public qt_action, public basic_action
{
public:
    basic_action_widget(QWidget* parent,std::string name,action_connection_manager_iface*, actionPtr);
    void mouseReleaseEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);

};

#endif // BASIC_ACTION_WIDGET_H
