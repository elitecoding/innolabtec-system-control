/**
\brief Not really a factory at all... This class pre creates all possible position parameter from a given teach file.
\author Julian Arnold
\file parameter_factory.h
This class created all position parameter using loadParameter method and stores them in a list
*/

#ifndef PARAMETER_FACTORY_H
#define PARAMETER_FACTORY_H

#include <string>
#include <list>
#include <QXmlStreamReader>
#include "parameter_widget.h"

class parameter_factory
{
    std::list<point_3d_list*> parameter;
public:
    parameter_factory();
    void loadParameter(std::string);
    inline std::list<point_3d_list*>* getParameterList(){return &parameter;}
};

#endif // PARAMETER_FACTORY_H
