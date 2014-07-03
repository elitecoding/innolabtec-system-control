#ifndef ACTION_CONNECTOR_WIDGET_H
#define ACTION_CONNECTOR_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QSize>
#include <QMouseEvent>
class basic_action_widget;
#include "qt_arrow.h"

class action_connector_widget: public qt_arrow
{

public:

    action_connector_widget(QWidget* parent =0);
    explicit action_connector_widget(QWidget* parent,basic_action_widget* from,basic_action_widget* to);
    inline void setFrom(basic_action_widget* p){this->widgetFrom=(QWidget*)p;}
    inline void setTo(basic_action_widget* p){this->widgetTo=(QWidget*)p;}
    inline basic_action_widget* getFrom() const {return (basic_action_widget*)this->widgetFrom;}
    inline basic_action_widget* getTo() const {return (basic_action_widget*)this->widgetTo;}

    void deleteConnection();

    void onActionMoved();


};

#endif // ACTION_CONNECTOR_WIDGET_H
