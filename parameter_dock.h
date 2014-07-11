#ifndef PARAMETER_DOCK_H
#define PARAMETER_DOCK_H

#include <string>
#include "point_3d_list.h"

class parameter_dock
{
protected:
    std::string name;
    point_3d_list* param;
public:
    parameter_dock(std::string);
    inline std::string getName(){return this->name;}
    inline point_3d_list* getParam(){return this->param;}
    inline void setParameter(point_3d_list* p){this->param = p;}
};

#endif // PARAMETER_DOCK_H
