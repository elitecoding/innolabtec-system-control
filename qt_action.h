#ifndef QT_ACTION_H
#define QT_ACTION_H

#include <QWidget>
#include <QSize>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <string>

#include "parameter_dock_widget.h"

class qt_action : public QWidget
{
    Q_OBJECT
public:
    explicit qt_action(std::string name,QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent * event);

    QSize sizeHint() const;

    void addParameterDock(parameter_dock_widget*);


signals:

public slots:

protected:
    QLabel qlName;
    QVBoxLayout qvContainer;
    QHBoxLayout qhContainer;
    bool isDragging;
    QPoint dragStart;

};

#endif // QT_ACTION_H
