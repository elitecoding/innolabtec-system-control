#ifndef BASIC_ACTION_WIDGET_H
#define BASIC_ACTION_WIDGET_H

#include<QWidget>
#include<QLabel>
#include<stdio.h>
#include<string>
#include "basic_action.h"

class basic_action_widget : public QWidget,public basic_action
{
    Q_OBJECT

    QLabel* qlName;

public:
    explicit basic_action_widget(QWidget *parent = 0,std::string="");
protected:
    //void paintEvent(QPaintEvent *event);

signals:

public slots:

};

#endif // ACTION_WIDGET_H
