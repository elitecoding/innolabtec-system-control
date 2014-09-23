#include "point_3d_list.h"
#include <iostream>

point_3d_list::point_3d_list(std::string n):name(n),type(List),pointList()
{
    std::cout<<"point_3d_list ctor"<<std::endl;
    std::cout<<"name: "<<this->getName()<<std::endl;
}

bool point_3d_list::hasParameter()
{
    return (!this->pointList.empty());
}

point_3d& point_3d_list::getParam()
{

    point_3d* front = this->pointList.front();

    if(this->type == point_3d_list::List)
    {
        if(!this->pointList.empty())
        {
            point_3d* front = this->pointList.front();
            this->pointList.pop();
            return *front;
        }else
        {
            //return *(new point_3d());
            throw "list empty";
        }
    }

    return *front;
}
