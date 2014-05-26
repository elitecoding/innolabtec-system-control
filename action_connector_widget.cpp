#include "action_connector_widget.h"
#include <iostream>
#include <QRegion>
#include <QVector>
#include <QPolygon>
#include <QPen>
#include <math.h>
#include <QVector2D>

action_connector_widget::action_connector_widget(QWidget* parent):QWidget(parent)
{

}
action_connector_widget::action_connector_widget(QWidget* parent,basic_action_widget* from,basic_action_widget* to):QWidget(parent),from(from),to(to),marked(false)
{
    std::cout<<"action_connector_widget ctor"<<std::endl;
    this->onActionMoved();
}
void action_connector_widget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    if(marked)
    {
      QPen pen = paint.pen();
      pen.setWidth(5);
      paint.setPen(pen);
    }

    QPoint dir = this->mapFromParent( this->from->pos()) - this->mapFromParent(this->to->pos());
    QVector2D dirVect(dir);

    dirVect.normalize();

    QVector2D arrowVect(0.707f*dirVect.x()-0.707f*dirVect.y(),0.707f*dirVect.x()+0.707f*dirVect.y());
    arrowVect.normalize();
    arrowVect *= 10;
    QVector2D arrowVect2(0.707f*dirVect.x()+0.707f*dirVect.y(),-0.707f*dirVect.x()+0.707f*dirVect.y());
    arrowVect2.normalize();
    arrowVect2 *= 10;

    paint.drawLine(this->mapFromParent( this->from->pos()),this->mapFromParent(this->to->pos()));
    paint.drawLine(this->mapFromParent(this->to->pos())+arrowVect.toPoint(),this->mapFromParent(this->to->pos()));
    paint.drawLine(this->mapFromParent(this->to->pos())+arrowVect2.toPoint(),this->mapFromParent(this->to->pos()));

}
QSize action_connector_widget::sizeHint() const
{
    QPoint dir = this->from->pos();
    dir-=this->to->pos();
    QSize s(abs(dir.x())+10,abs(dir.y())+10);
    return s;
}
void action_connector_widget::mousePressEvent(QMouseEvent *)
{
    this->marked = true;
    this->update();
}
void action_connector_widget::mouseReleaseEvent(QMouseEvent *)
{

}
void action_connector_widget::onActionMoved()
{
    QPoint upperPoint;
    QPoint lowerPoint;

    if(this->from->pos().y()<this->to->pos().y())
    {
        upperPoint = this->from->pos();
        lowerPoint = this->to->pos();
    }else
    {
        upperPoint = this->to->pos();
        lowerPoint = this->from->pos();
    }

    QPoint dir = this->from->pos();
    dir-=this->to->pos();
    QSize s(abs(dir.x())+60,abs(dir.y())+60);
    this->resize(s);

    //Case 1: upper point is upper left corner of widget
    if(upperPoint.x()<lowerPoint.x())
    {
        this->upperLeft = upperPoint;
    }else
    {
        //Case 2: compute upper left corner of widget
        QPoint upperLeftCorner;
        upperLeftCorner.setX(lowerPoint.x());
        upperLeftCorner.setY(upperPoint.y());
        this->upperLeft = upperLeftCorner;
    }

    this->move(this->upperLeft-QPoint(30,30));

    dir = this->from->pos()-this->to->pos();


    int px = dir.x();
    dir.setX(dir.y());
    dir.setY(-px);

    QVector2D dirVect(dir);
    dirVect.normalize();
    dirVect*=20;
    dir = dirVect.toPoint();
    QPoint p1 = this->from->pos()+dir;
    QPoint p2 = this->from->pos()-dir;
    QPoint p3 = this->to->pos()+dir;
    QPoint p4 = this->to->pos()-dir;

    QVector<QPoint> points;
    points.append(this->mapFromParent(p1));
    points.append(this->mapFromParent(p2));
    points.append(this->mapFromParent(p4));
    points.append(this->mapFromParent(p3));


    QPolygon poli(points);

    this->mask = poli;

    QRegion mask(poli);
    this->setMask(mask);
}

