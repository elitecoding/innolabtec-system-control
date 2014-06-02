#include "parameter_dock_widget.h"
#include <iostream>
#include <QSizePolicy>
parameter_dock_widget::parameter_dock_widget(basic_action_widget *parent) :
    QWidget(0)
{
    QSizePolicy spol;
    this->setSizePolicy(spol);
}
void parameter_dock_widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRect r(1,1,8,8);
    painter.drawRect(r);
}
void parameter_dock_widget::mousePressEvent(QMouseEvent *)
{
    std::cout<<"dock: mouse press on"<<std::endl;
}
QSize parameter_dock_widget::sizeHint() const
{
    return QSize(10,10);
}
