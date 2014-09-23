#ifndef ACTION_CONNECTOR_WIDGET_H
#define ACTION_CONNECTOR_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QSize>
#include <QMouseEvent>
class basic_action_widget;
#include "markable_iface.h"
#include "qt_arrow.h"
#include "action_connection_manager_iface.h"

class action_connector_widget: public qt_arrow, public markable_iface
{


    basic_action_widget* from;
    basic_action_widget* to;

public:

    action_connector_widget(QWidget* parent =0);
    explicit action_connector_widget(QWidget* parent,action_connection_manager_iface*,basic_action_widget* from,basic_action_widget* to);
    inline void setFrom(basic_action_widget* p){this->from=p;this->widgetFrom=(QWidget*)p;}
    inline void setTo(basic_action_widget* p){this->to=p;this->widgetTo=(QWidget*)p;}
    inline basic_action_widget* getFrom() const {return this->from;}
    inline basic_action_widget* getTo() const {return this->to;}

    void deleteConnection();

    void onActionMoved();

    void mousePressEvent(QMouseEvent *);

    action_connection_manager_iface* mgr;

    // markable_iface interface
public:
    void unmarkItem();
    void deleteItem();
};

#endif // ACTION_CONNECTOR_WIDGET_H
