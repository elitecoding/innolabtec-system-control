#ifndef POINT_3D_LIST_H
#define POINT_3D_LIST_H
#include"action_param_iface.h"
#include"point_3d.h"
#include<queue>
class point_3d_list : public action_param_iface<point_3d>
{
    std::queue<point_3d> pointList;
public:
    point_3d_list();
    point_3d getParam();
};

#endif // POINT_3D_LIST_H
