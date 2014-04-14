#include "basic_action_widget.h"

basic_action_widget::basic_action_widget(QWidget *parent,std::string n):
    QWidget(parent),basic_action(n)
{
    this->qlName = new QLabel(this);
    this->qlName->setText("Basic Action");
}
/*
void basic_action_widget::paintEvent(QPaintEvent *event)
{

}
*/
