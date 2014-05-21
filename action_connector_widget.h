#ifndef ACTION_CONNECTOR_WIDGET_H
#define ACTION_CONNECTOR_WIDGET_H

#include <QWidget>
#include <QPainter>
#include "basic_action_widget.h"

class action_connector_widget
{

    basic_action_widget* from;
    basic_action_widget* to;

public:
    action_connector_widget();
    explicit action_connector_widget(basic_action_widget* from,basic_action_widget* to);
    inline void setFrom(basic_action_widget* p){this->from=p;}
    inline void setTo(basic_action_widget* p){this->to=p;}
    inline basic_action_widget* getFrom() const {return this->from;}
    inline basic_action_widget* getTo() const {return this->to;}
};

#endif // ACTION_CONNECTOR_WIDGET_H
