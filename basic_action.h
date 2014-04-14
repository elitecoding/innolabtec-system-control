#ifndef BASIC_ACTION_H
#define BASIC_ACTION_H

#include"action_iface.h"
#include<QWidget>
#include<string>

class basic_action: public action_iface
{
    std::string name;
public:
    basic_action();
    basic_action(std::string);
    void execute();
};

#endif // BASIC_ACTION_H
