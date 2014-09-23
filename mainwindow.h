#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>

#include "action_connector_widget.h"
#include "action_factory.h"
#include "parameter_factory.h"
#include "action_container_widget.h"
#include <list>
#include <map>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMenu *fileMenu;
    QMenu* programMenu;
    QAction *newAction;
    QAction* runProgram;
    QAction* newParameter;
    action_factory* factory;
    parameter_factory* parameterFactroy;
    action_container_widget* container;

private slots:
    void exit();
    void addAction();
    void addParameter();
    void onRunProgram();
};

#endif // MAINWINDOW_H
