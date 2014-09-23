#ifndef POINT_3D_H
#define POINT_3D_H

#include "action_param_iface.h"
#include <ostream>
#include <string>

class point_3d : public action_param_iface<point_3d>
{

    double x;
    double y;
    double z;


public:
    std::string myName;
    point_3d();
    point_3d(std::string,double,double,double);

    point_3d& getParam();
    inline double getX(){return x;}
    inline double getY(){return y;}
    inline double getZ(){return z;}
    inline std::string getName() const {return myName;}
    void print(std::ostream &) const;
};

std::ostream& operator<< (std::ostream& stream, const point_3d& point);

#endif // POINT_3D_H
