#include "qt_action.h"
#include <iostream>
#include <QString>

qt_action::qt_action(std::string name,QWidget *parent) :
    QWidget(parent),qlName(name.c_str()),qvContainer(this),qhContainer(0)
{

    this->qvContainer.addWidget(&qlName);
    this->qvContainer.addLayout(&this->qhContainer);
}
void qt_action::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect r(5,5,90,90);
    painter.drawRect(r);
}
void qt_action::mousePressEvent(QMouseEvent *event)
{
    std::cout<<"qt_action::mousePressEvent"<<std::endl;
    this->dragStart = event->pos();
}
void qt_action::mouseReleaseEvent(QMouseEvent * event)
{
    std::cout<<"qt_action::mouseReleaseEvent"<<std::endl;
    this->isDragging = false;
}
QSize qt_action::sizeHint(void) const
{
    return QSize(100,100);
}
void qt_action::addParameterDock(parameter_dock_widget* dock)
{
    this->qhContainer.addWidget(dock);
}
void qt_action::mouseMoveEvent(QMouseEvent* event)
{
    if((event->pos()-this->dragStart).manhattanLength()>10)
    {
       this->isDragging = true;
       QPoint moveTo = this->mapToParent(event->pos());
       moveTo-=this->dragStart;
       this->move(moveTo);
    }
}
