#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "basic_action_widget.h"
#include <QPainter>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    basic_action_widget* w = new basic_action_widget(ui->frame,"My first action");
    w->execute();
    w->move(80,80);
    setMouseTracking(true);
    grabMouse();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    if(this->drawConnection)
    {
        paint.drawLine(startPoint,stopPoint);
    }

    std::list<action_connector_widget*>::iterator iter;

    for(iter = this->connections.begin();iter != this->connections.end();iter++)
    {
        action_connector_widget* con = (action_connector_widget*)(*iter);
        paint.drawLine(con->getFrom(),con->getTo());
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    std::cout<<"mose move event"<<std::endl;
    if(this->drawConnection)
    {
        this->stopPoint = event->pos();
        this->update();
        std::cout<<"mose move event ann mouse was pressed"<<std::endl;
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(drawConnection)
    {
        drawConnection = false;
        this->connections.push_back(new action_connector_widget(0,this->startPoint,event->pos()));
    }else
    {
        this->startPoint = event->pos();
        this->drawConnection = true;
    }
}
