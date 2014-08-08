#ifndef PARAMETER_DOCK_WIDGET_H
#define PARAMETER_DOCK_WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QSize>
#include <QPainter>
#include <QVBoxLayout>
#include <QLabel>

#include <string>


class basic_action_widget;
class parameter_widget;
class parameter_connector_widget;
#include "parameter_dock.h"

class parameter_dock_widget : public QWidget,public parameter_dock
{
    Q_OBJECT
    QVBoxLayout layoutContainer;
    QLabel labelName;
    parameter_connector_widget* connector;

public:

    explicit parameter_dock_widget(basic_action_widget *parent,std::string);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

    QSize sizeHint() const;

    inline void setParameter(parameter_widget* p){this->param = (point_3d_list*)p;}
    inline parameter_widget* getParameter(){return (parameter_widget*)this->param;}
    inline void setConnector(parameter_connector_widget* c){this->connector = c;}
    inline parameter_connector_widget* getConnector(){return this->connector;}

signals:

public slots:

private:

};

#endif // PARAMETER_DOCK_WIDGET_H
