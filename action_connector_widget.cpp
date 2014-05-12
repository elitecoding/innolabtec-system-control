#include "action_connector_widget.h"

action_connector_widget::action_connector_widget(QWidget *parent) : QWidget(parent),action_connector()
{

}
action_connector_widget::action_connector_widget(QWidget *parent,QPoint from,QPoint to):QWidget(parent),action_connector(),from(from),to(to)
{

}
void action_connector_widget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    paint.drawLine(from,to);
}
