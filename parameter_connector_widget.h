#ifndef PARAMETER_CONNECTION_WIDGET_H
#define PARAMETER_CONNECTION_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QSize>
#include <QMouseEvent>

#include "qt_arrow.h"

class parameter_dock_widget;
class parameter_widget;

class parameter_connector_widget : public qt_arrow
{
public:

    parameter_connector_widget(QWidget* parent =0);
    explicit parameter_connector_widget(QWidget* parent,parameter_widget* from,parameter_dock_widget* to);

    inline void setTo(parameter_dock_widget* p){this->widgetTo=(QWidget*)p;}

    inline parameter_dock_widget* getTo() const {return (parameter_dock_widget*)this->widgetTo;}

    void deleteConnection();




    void onActionMoved();

};

#endif // PARAMETER_CONNECTION_WIDGET_H
