#ifndef ACTION_CONNECTOR_H
#define ACTION_CONNECTOR_H

#include "action_iface.h"

class action_connector
{
    action_iface* from;
    action_iface* to;
public:
    action_connector();
    inline void setTo(action_iface* p){this->to=p;}
    inline void setFrom(action_iface* p){this->from=p;}
    inline action_iface* getFrom() const {return this->from;}
    inline action_iface* getTo() const {return this->to;}

};

#endif // ACTION_CONNECTOR_H
