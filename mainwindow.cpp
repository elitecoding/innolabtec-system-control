#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "basic_action_widget.h"
#include "action_container_widget.h"
#include <QPainter>
#include <iostream>
#include <QInputDialog>
#include <QList>
#include <QString>
#include "parameter_dock_widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),factory(0)
{

    ui->setupUi(this);
    setMouseTracking(true);

    this->factory = new action_factory();

    this->container = new action_container_widget(0);

    this->ui->verticalLayout->addWidget(container);

    this->newAction = new QAction("Add",this);
    this->runProgram = new QAction("Run",this);
    this->fileMenu = new QMenu("File",this);
    this->programMenu = new QMenu("Program",this);
    this->programMenu->addAction(this->newAction);
    this->programMenu->addAction(this->runProgram);
    menuBar()->addMenu(this->fileMenu);
    menuBar()->addMenu(this->programMenu);
    connect(this->newAction, SIGNAL(triggered()), this, SLOT(addAction()));
    connect(this->runProgram,SIGNAL(triggered()),this, SLOT(onRunProgram()));
    this->resize(800,600);
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
    std::cout<<"new Action menu"<<std::endl;

    QStringList list;
    std::list<std::string> actions = this->factory->getActionList();

    for(std::list<std::string>::iterator it = actions.begin();it != actions.end();it++)
    {
        std::string s((*it));
        list.append(QString( ((std::string)(*it)).c_str()   ));
    }

    QString action = QInputDialog::getItem(this,"Select Action","Action:",list);

    basic_action_widget* w = this->factory->create(action.toStdString(),this->container,this->container);


    parameter_dock_widget* dock = new parameter_dock_widget(w);

    w->addParameterDock(dock);
    w->move(10,10);
    w->show();
}
void MainWindow::onRunProgram()
{
    this->container->execute();
}
