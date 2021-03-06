#ifndef POINT_3D_LIST_H
#define POINT_3D_LIST_H

#include "action_param_iface.h"
#include "point_3d.h"

#include <queue>
#include <string>

class point_3d_list : public action_param_iface<point_3d>
{


public:

    enum parameterTypes
    {
       Single, List
    };

    point_3d_list(std::string);
    point_3d& getParam();
    bool hasParameter();
    inline std::string getName(){return name;}
    inline void setType(parameterTypes t){type=t;}
    inline void addPoint(point_3d* p){pointList.push(p);}

private:
    parameterTypes type;
    std::queue<point_3d*> pointList;
    std::string name;

};

#endif // POINT_3D_LIST_H
