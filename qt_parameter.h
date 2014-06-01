#ifndef QT_PARAMETER_H
#define QT_PARAMETER_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QSize>
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>

#include <string>
#include <iostream>

class qt_parameter: public QWidget
{
    Q_OBJECT
public:
    explicit qt_parameter(std::string,QWidget*);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

    QSize sizeHint() const;

signals:

public slots:

private:
    QLabel qlName;
    QVBoxLayout qvContainer;

};

#endif // QT_PARAMETER_H
