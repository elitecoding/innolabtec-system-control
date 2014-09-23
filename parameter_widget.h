#ifndef PARAMETER_WIDGET_H
#define PARAMETER_WIDGET_H

#include "qt_parameter.h"
#include "point_3d_list.h"
#include "action_connection_manager_iface.h"
#include "parameter_connector_widget.h"

class parameter_widget:public qt_parameter
{
    action_connection_manager_iface* connectionManager;
    parameter_connector_widget* connector;
    point_3d_list* parameter;

public:
    parameter_widget(point_3d_list* p,QWidget* parent,action_connection_manager_iface*);

    inline point_3d_list* getParam(){return parameter;}
    void mouseReleaseEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent * event);

    inline void setConnector(parameter_connector_widget* c){this->connector = c;}
};

#endif // PARAMETER_WIDGET_H
