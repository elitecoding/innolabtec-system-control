#ifndef PARAMETER_DOCK_WIDGET_H
#define PARAMETER_DOCK_WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QSize>
#include <QPainter>

#include <string>

class basic_action_widget;


class parameter_dock_widget : public QWidget
{
    Q_OBJECT

public:

    explicit parameter_dock_widget(basic_action_widget *parent);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    QSize sizeHint() const;
    void addParameter(std::string);

signals:

public slots:

private:

};

#endif // PARAMETER_DOCK_WIDGET_H
