#-------------------------------------------------
#
# Project created by QtCreator 2014-03-28T00:50:01
#
#-------------------------------------------------

QT += core gui network

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
    action_connector_widget.cpp \
    action_container_widget.cpp \
    qt_action.cpp \
    innox.cpp \
    action_open_gripper.cpp \
    action_factory.cpp \
    qt_parameter.cpp \
    parameter_dock_widget.cpp \
    parameter_widget.cpp \
    qt_arrow.cpp \
    parameter_dock.cpp \
    action_load_sample.cpp \
    parameter_factory.cpp \
    parameter_connector_widget.cpp

HEADERS  += mainwindow.h \
    point_3d.h \
    point_3d_list.h \
    action_param_iface.h \
    action_iface.h \
    basic_action.h \
    basic_action_widget.h \
    action_connector_widget.h \
    action_container_widget.h \
    qt_action.h \
    action_connection_manager_iface.h \
    innox.h \
    action_open_gripper.h \
    action_factory.h \
    qt_parameter.h \
    parameter_dock_widget.h \
    parameter_widget.h \
    qt_arrow.h \
    parameter_dock.h \
    action_load_sample.h \
    parameter_factory.h \
    parameter_connector_widget.h \
    markable_iface.h

FORMS    += mainwindow.ui
