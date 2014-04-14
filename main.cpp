#include "mainwindow.h"
#include <QApplication>
#include "point_3d_list.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
