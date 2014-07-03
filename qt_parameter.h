#ifndef QT_PARAMETER_H
#define QT_PARAMETER_H

#include "qt_action.h"


class qt_parameter: public qt_action
{
    Q_OBJECT
public:
    explicit qt_parameter(std::string,QWidget*);

    void paintEvent(QPaintEvent *);

    QSize sizeHint() const;

signals:

public slots:

private:

};

#endif // QT_PARAMETER_H
