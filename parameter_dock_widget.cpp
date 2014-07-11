#include "parameter_dock_widget.h"
#include "basic_action_widget.h"

#include <iostream>
#include <QSizePolicy>

parameter_dock_widget::parameter_dock_widget(basic_action_widget *parent,std::string name) :
    QWidget(0),parameter_dock(name),layoutContainer(this),labelName(name.c_str())
{
    QSizePolicy spol;
    layoutContainer.addWidget(&labelName);

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
    std::cout<<"dock: mouse press"<<std::endl;
}
void parameter_dock_widget::mouseReleaseEvent(QMouseEvent *)
{
    std::cout<<"dock: mouse release"<<std::endl;
    ((basic_action_widget*)this->parent())->getConnectionManager()->connect(this);
}
QSize parameter_dock_widget::sizeHint() const
{
    return QSize(20,20);
}
