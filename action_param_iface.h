#ifndef ACTION_PARAM_IFACE_H
#define ACTION_PARAM_IFACE_H

template<class T>class action_param_iface
{
public:
    virtual T getParam() = 0;
};

#endif // ACTION_PARAM_IFACE_H
