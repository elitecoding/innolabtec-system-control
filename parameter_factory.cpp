#include "parameter_factory.h"

parameter_factory::parameter_factory()
{
}
void parameter_factory::loadParameter(std::string path)
{
    point_3d_list* p = new point_3d_list("test");
    parameter.push_back(p);
}
