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
#include "qt_parameter.h"
#include "point_3d.h"
#include "point_3d_list.h"

/**
 * @brief Setup menu structure and factories
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),factory(0)
{

    ui->setupUi(this);
    setMouseTracking(true);

    this->factory = new action_factory();

    this->parameterFactroy = new parameter_factory();
    this->parameterFactroy->loadParameter("path to xml file");

    this->container = new action_container_widget(0);

    this->ui->verticalLayout->addWidget(container);

    this->newAction = new QAction("Add Action",this);
    this->newParameter = new QAction("Add Parameter",this);
    this->runProgram = new QAction("Run",this);

    this->fileMenu = new QMenu("File",this);
    this->programMenu = new QMenu("Program",this);


    this->programMenu->addAction(this->newAction);
    this->programMenu->addAction(this->newParameter);

    this->programMenu->addAction(this->runProgram);

    menuBar()->addMenu(this->fileMenu);
    menuBar()->addMenu(this->programMenu);

    connect(this->newAction, SIGNAL(triggered()), this, SLOT(addAction()));
    connect(this->newParameter, SIGNAL(triggered()), this, SLOT(addParameter()));
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

    w->show();

}
void MainWindow::addParameter()
{
    std::cout<<"new Parameter menu"<<std::endl;

    QStringList list;
    std::list<point_3d_list*> actions = *(this->parameterFactroy->getParameterList());

    std::map<std::string,point_3d_list*> translate;

    for(std::list<point_3d_list*>::iterator it = actions.begin();it != actions.end();it++)
    {
        list.append(QString( ((point_3d_list*)(*it))->getName().c_str()));
        translate.insert( std::pair<std::string,point_3d_list*>( ((point_3d_list*)(*it))->getName(),(point_3d_list*)(*it)) );
    }

    QString action = QInputDialog::getItem(this,"Select Parameter","Parameter:",list);


    parameter_widget* w = new parameter_widget(translate.at(action.toStdString()),this->container,this->container);

    w->show();
}
void MainWindow::onRunProgram()
{
    this->container->execute();
}
