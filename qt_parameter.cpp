#include "qt_parameter.h"

qt_parameter::qt_parameter(std::string name,QWidget* parent):qt_action(name,parent)
{

}
void qt_parameter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect r(0,0,100,100);
    painter.drawArc(r,0,16*360);
}

QSize qt_parameter::sizeHint(void) const
{
    return QSize(100,100);
}
