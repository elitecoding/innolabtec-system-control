#include "point_3d.h"
#include<iostream>
point_3d::point_3d():x(0),y(0),z(0)
{
    std::cout<<"point_3d ctor"<<std::endl;
}
point_3d::point_3d(double px, double py, double pz):x(px),y(py),z(pz)
{
    std::cout<<"point_3d ctor"<<std::endl;
}
point_3d point_3d::getParam()
{
    return *this;
}
void point_3d::print(std::ostream& stream) const
{
    stream<<"( "<<this->x<<", "<<this->y<<", "<<this->z<<" )";
}

std::ostream& operator<<(std::ostream& stream, const point_3d& point)
{
    point.print(stream);
    return stream;
}
