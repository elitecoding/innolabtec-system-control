#include "basic_action_widget.h"
#include<QPainter>

basic_action_widget::basic_action_widget(QWidget *parent,std::string n):
    QWidget(parent),basic_action(n)
{
    this->qlName = new QLabel(this);
    this->qlName->setText("Basic Action");
}

void basic_action_widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    QRect r(rect().left()+5,rect().top()+5,rect().width()-10,rect().height()-10);
    //painter.drawText(, Qt::AlignCenter, "Qt");
    painter.setFont(QFont("Arial", 30));
   // painter.setPen(QColor);
    painter.drawRect(r);
}

QSize basic_action_widget::sizeHint(void) const
{
    return QSize(100,100);
}

