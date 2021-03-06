#ifndef ACTION_CONTAINER_WIDGET_H
#define ACTION_CONTAINER_WIDGET_H

#include <QWidget>
#include "action_connector_widget.h"
#include "parameter_connector_widget.h"
#include "basic_action_widget.h"
#include "parameter_widget.h"
#include "action_connection_manager_iface.h"
#include <list>
#include <QPoint>
#include "innox.h"
#include "markable_iface.h"
#include <QKeyEvent>

class action_container_widget : public QWidget, public action_connection_manager_iface
{
    Q_OBJECT

    bool drawConnection;

    QPoint startPoint;
    QPoint stopPoint;

    std::list<action_connector_widget*> connections;

    basic_action_widget* pendingConnection;
    parameter_widget* pendingParameter;

    bool connectionStarted;

    innox* innoxControl;

    markable_iface* currentMarkedItem;

public:
    explicit action_container_widget(QWidget *parent = 0);
    void attacheConnection(basic_action_widget* action);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);

    //Connection Manager
    void startConnection(basic_action_widget*);
    void stopConnection(basic_action_widget*);
    void connect(basic_action_widget*);
    void connect(parameter_widget*);
    void connect(parameter_dock_widget*);
    void execute();
    void mark(markable_iface*);

signals:

public slots:

};

#endif // ACTION_CONTAINER_WIDGET_H
