#ifndef ACTION_CONNECTION_MANAGER_IFACE_H
#define ACTION_CONNECTION_MANAGER_IFACE_H

#include "action_iface.h"
class action_connection_manager_iface
{
public:
    virtual void startConnection(action_iface*) = 0;
    virtual void stopConnection(action_iface*) = 0;
    virtual void connect(action_iface*) = 0;
};

#endif // ACTION_CONNECTION_MANAGER_IFACE_H
