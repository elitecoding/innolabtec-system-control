#ifndef QT_ARROW_H
#define QT_ARROW_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QSize>
#include <QPoint>
#include <QMouseEvent>

class qt_arrow : public QWidget
{
    Q_OBJECT

protected:
    QPolygon mask;
    QPoint upperLeft;
    bool marked;
    QWidget* widgetFrom;
    QWidget* widgetTo;

public:
    explicit qt_arrow(QWidget* from,QWidget* to,QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    QSize sizeHint() const;

signals:

public slots:

};

#endif // QT_ARROW_H
