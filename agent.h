#ifndef AGENT_H_AGENT
#define AGENT_H_AGENT
#include <iostream>
#include "RegImot.h"
class Agent
{

    public:
    virtual void print()const = 0;
    //virtual Agent * Clone()const = 0;
    virtual void PrintHousesFromLowestPrice()=0;
    virtual void PrintFlatsFromLowestPrice()=0;
    virtual void PrintEstatesFromLowestPrice()=0;
    virtual void PrintHouses()=0;
    virtual void PrintFlats()=0;
    virtual void PrintByPriceRange(double price1,double price2)=0;
    virtual void PrintEstatesByTown(char * Town)=0;
    virtual void PrintBySpaceRange(double size1,double size2)=0;

};
#endif
