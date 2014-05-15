#ifndef ACTION_CONNECTOR_WIDGET_H
#define ACTION_CONNECTOR_WIDGET_H

#include <QWidget>
#include <QPainter>
#include "action_connector.h"

class action_connector_widget : public QWidget,action_connector
{
    Q_OBJECT

    QPoint from;
    QPoint to;

public:
    explicit action_connector_widget(QWidget *parent = 0);
    explicit action_connector_widget(QWidget *parent,QPoint from,QPoint to);
    inline void setFrom(QPoint p){this->from=p;}
    inline void setTo(QPoint p){this->to=p;}
    inline QPoint getFrom() const {return this->from;}
    inline QPoint getTo() const {return this->to;}
signals:

public slots:

};

#endif // ACTION_CONNECTOR_WIDGET_H
