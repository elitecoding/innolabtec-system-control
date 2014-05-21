#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "basic_action_widget.h"
#include "action_container_widget.h"
#include <QPainter>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setMouseTracking(true);

    action_container_widget* container = new action_container_widget(0);
    this->ui->verticalLayout->addWidget(container);

    connect(menuBar()->addMenu("File")->addAction("Exit",this,""), SIGNAL(triggered()), this, SLOT(exit()));
}



MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::exit()
{
    this->close();
}
void MainWindow::addAction()
{

}
