#ifndef BASIC_ACTION_WIDGET_H
#define BASIC_ACTION_WIDGET_H

#include <stdio.h>
#include <string>
#include "basic_action.h"
#include "qt_action.h"

class action_connection_manager_iface;
class action_connector_widget;

class basic_action_widget : public qt_action, public basic_action
{
    bool isDragging;
    QPoint dragStart;

    action_connector_widget* from;
    action_connector_widget* to;


public:
    basic_action_widget(QWidget* parent,std::string name,action_connection_manager_iface*);
    inline action_connector_widget* getFrom() const {return from;}
    inline action_connector_widget* getTo() const  {return to;}
    inline void setTo(action_connector_widget* pTo){to = pTo;}
    inline void setFrom(action_connector_widget* pFrom){from = pFrom;}
    inline void deleteFrom(){from=0;}
    inline void deleteTo(){to=0;}
    void mouseReleaseEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

};

#endif // BASIC_ACTION_WIDGET_H
