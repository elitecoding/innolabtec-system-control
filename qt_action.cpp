#include "qt_action.h"
#include <iostream>
#include <QString>
qt_action::qt_action(std::string name,QWidget *parent) :
    QWidget(parent),qlName(name.c_str()),qvContainer(this)
{
    this->qvContainer.addWidget(&qlName);
}
void qt_action::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect r(5,5,90,90);
    painter.drawRect(r);
}
void qt_action::mousePressEvent(QMouseEvent *event)
{
    std::cout<<"qt_action: mouse pressed!"<<std::endl;
}
QSize qt_action::sizeHint(void) const
{
    return QSize(100,100);
}


