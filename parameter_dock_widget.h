#ifndef PARAMETER_DOCK_WIDGET_H
#define PARAMETER_DOCK_WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QSize>
#include <QPainter>

#include <string>


class basic_action_widget;
class parameter_widget;
#include "parameter_dock.h"

class parameter_dock_widget : public QWidget,public parameter_dock
{
    Q_OBJECT

public:

    explicit parameter_dock_widget(basic_action_widget *parent,std::string);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    QSize sizeHint() const;

    inline void setParameter(parameter_widget* p){this->param = (point_3d_list*)p;}
    inline parameter_widget* getParameter(){return (parameter_widget*)this->param;}

signals:

public slots:

private:

};

#endif // PARAMETER_DOCK_WIDGET_H
