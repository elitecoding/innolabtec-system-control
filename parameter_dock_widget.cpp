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
    QRect r(5,5,5,5);
    painter.drawRect(r);
}
void parameter_dock_widget::mousePressEvent(QMouseEvent *)
{
    std::cout<<"mouse press on dock"<<std::endl;
}
QSize parameter_dock_widget::sizeHint() const
{
    return QSize(10,10);
}
