#include "qt_arrow.h"

qt_arrow::qt_arrow(QWidget *from,QWidget *to,QWidget *parent) :
   QWidget(parent), widgetFrom(from),widgetTo(to)
{
}
void qt_arrow::paintEvent(QPaintEvent * e)
{
    QPainter paint(this);
    if(marked)
    {
      QPen pen = paint.pen();
      pen.setWidth(5);
      paint.setPen(pen);
    }

    QPoint wpFrom = this->widgetFrom->pos();
    QPoint wpTo = this->widgetTo->pos();


    QPoint pParentTo = this->widgetTo->mapToGlobal(QPoint(0,0));
    pParentTo = this->mapFromGlobal(pParentTo);

    QPoint pParentFrom = this->widgetFrom->mapToGlobal(QPoint(0,0));
    pParentFrom = this->mapFromGlobal(pParentFrom);

    QPoint dir = pParentFrom - pParentTo;
    QVector2D dirVect(dir);

    dirVect.normalize();

    QVector2D arrowVect(0.707f*dirVect.x()-0.707f*dirVect.y(),0.707f*dirVect.x()+0.707f*dirVect.y());
    arrowVect.normalize();
    arrowVect *= 10;
    QVector2D arrowVect2(0.707f*dirVect.x()+0.707f*dirVect.y(),-0.707f*dirVect.x()+0.707f*dirVect.y());
    arrowVect2.normalize();
    arrowVect2 *= 10;



    paint.drawLine(pParentFrom,pParentTo);
    paint.drawLine(pParentTo+arrowVect.toPoint(),pParentTo);
    paint.drawLine(pParentTo+arrowVect2.toPoint(),pParentTo);

}
QSize qt_arrow::sizeHint() const
{
    QPoint dir = this->widgetFrom->pos();
    dir-=this->widgetTo->pos();
    QSize s(abs(dir.x())+10,abs(dir.y())+10);
    return s;
}
void qt_arrow::mousePressEvent(QMouseEvent *)
{
    this->marked = true;
    this->update();
}
void qt_arrow::mouseReleaseEvent(QMouseEvent *)
{

}
