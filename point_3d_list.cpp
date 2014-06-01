#include "point_3d_list.h"
#include <iostream>

point_3d_list::point_3d_list(std::string n, parameterTypes type):name(n),type(type)
{
    std::cout<<"point_3d_list ctor"<<std::endl;
}
point_3d point_3d_list::getParam()
{
    point_3d front = this->pointList.front();
    this->pointList.pop();
    return front;
}
