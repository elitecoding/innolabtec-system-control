#ifndef ACTION_CONNECTOR_WIDGET_H
#define ACTION_CONNECTOR_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QSize>
#include <QMouseEvent>
#include "basic_action_widget.h"

class action_connector_widget: public QWidget
{
    Q_OBJECT

    basic_action_widget* from;
    basic_action_widget* to;
    QPolygon mask;
    QPoint upperLeft;
    bool marked;

public:

    action_connector_widget(QWidget* parent);
    explicit action_connector_widget(QWidget* parent,basic_action_widget* from,basic_action_widget* to);
    inline void setFrom(basic_action_widget* p){this->from=p;}
    inline void setTo(basic_action_widget* p){this->to=p;}
    inline basic_action_widget* getFrom() const {return this->from;}
    inline basic_action_widget* getTo() const {return this->to;}

    void deleteConnection();

    void onActionMoved();

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    QSize sizeHint() const;

signals:

public slots:

};

#endif // ACTION_CONNECTOR_WIDGET_H
