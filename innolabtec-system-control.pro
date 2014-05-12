#-------------------------------------------------
#
# Project created by QtCreator 2014-03-28T00:50:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = innolabtec-system-control
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    point_3d.cpp \
    point_3d_list.cpp \
    basic_action.cpp \
    basic_action_widget.cpp \
    param_action.cpp \
    action_connector.cpp \
    action_connector_widget.cpp

HEADERS  += mainwindow.h \
    point_3d.h \
    point_3d_list.h \
    action_param_iface.h \
    action_iface.h \
    basic_action.h \
    basic_action_widget.h \
    param_action.h \
    action_connector.h \
    action_connector_widget.h

FORMS    += mainwindow.ui
