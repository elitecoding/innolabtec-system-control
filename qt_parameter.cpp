#include "qt_parameter.h"

qt_parameter::qt_parameter(std::string name,QWidget* parent):QWidget(parent),qlName(name.c_str()),qvContainer(this)
{
    this->qvContainer.addWidget(&qlName);
}
void qt_parameter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect r(5,5,90,90);
    painter.drawArc(r,0,16*360);
}
void qt_parameter::mousePressEvent(QMouseEvent *event)
{
    std::cout<<"qt_parameter: mouse pressed!"<<std::endl;
}
QSize qt_parameter::sizeHint(void) const
{
    return QSize(100,100);
}
