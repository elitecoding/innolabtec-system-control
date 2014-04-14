#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "basic_action_widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    basic_action_widget* w = new basic_action_widget(ui->frame,"My first action");
    w->execute();
    w->move(80,80);
}

MainWindow::~MainWindow()
{
    delete ui;
}
