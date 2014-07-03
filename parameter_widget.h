#ifndef PARAMETER_WIDGET_H
#define PARAMETER_WIDGET_H

#include "qt_parameter.h"
#include "point_3d_list.h"
#include "action_connection_manager_iface.h"

class parameter_widget:public qt_parameter,public point_3d_list
{
    action_connection_manager_iface* connectionManager;
public:
    parameter_widget(std::string name,QWidget* parent,action_connection_manager_iface*);

    void mouseReleaseEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent * event);
};

#endif // PARAMETER_WIDGET_H
