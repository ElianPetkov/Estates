#ifndef AGENT_H_AGENT
#define AGENT_H_AGENT
#include <iostream>
class Agent
{
    public:
    virtual void print()const=0;
    virtual void printEstateFromLowestPriceByType(const char*)=0;
    virtual void printEstatesFromLowestPrice()=0;
    virtual void printByPriceRange(double,double)=0;
    virtual void printEstatesByTown(char* Town)=0;
    virtual void printBySpaceRange(double,double)=0;
};
#endif
