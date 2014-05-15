#ifndef ACTION_IFACE_H
#define ACTION_IFACE_H

class action_connector;

class action_iface
{
public:
    virtual void execute() = 0;
    virtual void setNext(action_connector* next) = 0;
};

#endif // ACTION_IFACE_H
