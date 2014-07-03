#include "point_3d_list.h"
#include <iostream>

point_3d_list::point_3d_list(std::string n):name(n)
{
    std::cout<<"point_3d_list ctor"<<std::endl;
}

bool point_3d_list::hasParameter()
{
    return (!this->pointList.empty());
}

point_3d point_3d_list::getParam()
{
    if(!this->pointList.empty())
    {
        point_3d front = this->pointList.front();
        this->pointList.pop();
        return front;
    }else
    {
        throw "list empty";
    }
}
