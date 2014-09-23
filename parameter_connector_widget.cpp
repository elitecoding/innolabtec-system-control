#include "parameter_connector_widget.h"
#include "parameter_dock_widget.h"
#include "parameter_widget.h"
#include <iostream>

parameter_connector_widget::parameter_connector_widget(QWidget* parent):qt_arrow(0,0,parent)
{

}
parameter_connector_widget::parameter_connector_widget(QWidget* parent,action_connection_manager_iface* m,parameter_widget* from,parameter_dock_widget* to):qt_arrow((QWidget*)from,(QWidget*)to,parent),mgr(m)
{
    std::cout<<"parameter_connector_widget ctor"<<std::endl;
    this->onActionMoved();

}
void parameter_connector_widget::onActionMoved()
{
    QPoint upperPoint;
    QPoint lowerPoint;

    QPoint wpFrom = this->widgetFrom->pos();
    QPoint wpTo = this->widgetTo->pos();


    QPoint pParentTo = this->widgetTo->mapToGlobal(QPoint(0,0));
    //pParentTo = this->mapFromGlobal(pParentTo);

    QPoint pParentFrom = this->widgetFrom->mapToGlobal(QPoint(0,0));
    //pParentFrom = this->mapFromGlobal(pParentFrom);

    if(pParentFrom.y()<pParentTo.y())
    {
        upperPoint = pParentFrom;
        lowerPoint = pParentTo;
    }else
    {
        upperPoint = pParentTo;
        lowerPoint = pParentFrom;
    }

    QPoint dir = pParentFrom;
    dir -= pParentTo;
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

    this->move(this->parentWidget()->mapFromGlobal(this->upperLeft)-QPoint(30,30));

    wpFrom = this->widgetFrom->pos();
    wpTo = this->widgetTo->pos();


    pParentTo = this->widgetTo->mapToGlobal(QPoint(0,0));
    pParentTo = this->mapFromGlobal(pParentTo);

    pParentFrom = this->widgetFrom->mapToGlobal(QPoint(0,0));
    pParentFrom = this->mapFromGlobal(pParentFrom);

    dir = pParentFrom-pParentTo;


    int px = dir.x();
    dir.setX(dir.y());
    dir.setY(-px);

    QVector2D dirVect(dir);
    dirVect.normalize();
    dirVect*=20;
    dir = dirVect.toPoint();
    QPoint p1 = pParentFrom+dir;
    QPoint p2 = pParentFrom-dir;
    QPoint p3 = pParentTo+dir;
    QPoint p4 = pParentTo-dir;

    QVector<QPoint> points;
    points.append(p1);
    points.append(p2);
    points.append(p4);
    points.append(p3);


    QPolygon poli(points);

    this->mask = poli;

    QRegion mask(poli);
    this->setMask(mask);
}

void parameter_connector_widget::unmarkItem()
{
    this->marked=false;
    this->update();
}
void parameter_connector_widget::deleteItem()
{
    this->getTo()->setConnector(0);
    this->getFrom()->setConnector(0);
    delete this;
}
void parameter_connector_widget::mousePressEvent(QMouseEvent *e)
{
    this->mgr->mark(this);
    qt_arrow::mousePressEvent(e);
}

void parameter_connector_widget::deleteConnection()
{
    delete this;
}
