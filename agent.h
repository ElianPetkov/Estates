#ifndef AGENT_H_AGENT
#define AGENT_H_AGENT
#include <iostream>
#include "RegImot.h"
class Agent:public RealEstates
{
    private:
    char * name;
    double percentage;
    void Copy(const Agent &x);
    void Erase();

    public:
    Agent();
    Agent(const Estate *estates,char* name,double percentage);
    Agent(const Agent &x);
    ~Agent();

};
#endif
