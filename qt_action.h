#ifndef QT_ACTION_H
#define QT_ACTION_H

#include <QWidget>
#include <QSize>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>
#include <string>

class qt_action : public QWidget
{
    Q_OBJECT
public:
    explicit qt_action(std::string name,QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

    QSize sizeHint() const;
signals:

public slots:

private:
    QLabel qlName;
    QVBoxLayout qvContainer;
};

#endif // QT_ACTION_H
