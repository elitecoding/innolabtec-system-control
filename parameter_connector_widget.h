#ifndef PARAMETER_CONNECTION_WIDGET_H
#define PARAMETER_CONNECTION_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QSize>
#include <QMouseEvent>
#include "markable_iface.h"
#include "qt_arrow.h"
#include "action_connection_manager_iface.h"

class parameter_dock_widget;
class parameter_widget;

class parameter_connector_widget : public qt_arrow, public markable_iface
{

    action_connection_manager_iface* mgr;

public:

    parameter_connector_widget(QWidget* parent =0);
    explicit parameter_connector_widget(QWidget* parent,action_connection_manager_iface* m,parameter_widget* from,parameter_dock_widget* to);

    inline void setTo(parameter_dock_widget* p){this->widgetTo=(QWidget*)p;}

    inline parameter_dock_widget* getTo(){return (parameter_dock_widget*)this->widgetTo;}
    inline parameter_widget* getFrom(){return (parameter_widget*)this->widgetFrom;}

    void deleteConnection();

    void onActionMoved();
    void mousePressEvent(QMouseEvent *e);

    // markable_iface interface
public:
    void unmarkItem();
    void deleteItem();
};

#endif // PARAMETER_CONNECTION_WIDGET_H
