#ifndef AGENT_H_AGENT
#define AGENT_H_AGENT
#include <iostream>
#include "RegImot.h"
class Agent
{
    private:
    char * name;
    double percentage;
    RealEstates listOfEstates;
    void Copy(const Agent &x);
    void Erase();

    public:
    Agent();
    Agent(RealEstates listOfEstates,char* name,double percentage);
    Agent(const Agent &x);
    ~Agent();

    virtual void print(){};
    virtual Agent * Clone()const{};
    virtual void PrintHousesFromLowestPrice(){};
    virtual void PrintFlatsFromLowestPrice(){};
    virtual void PrintEstatesFromLowestPrice(){};
    virtual void PrintHouses(){};
    virtual void PrintFlats(){};
    virtual void PrintByPriceRange(double price1,double price2){};
    virtual void PrintEstatesByTown(char * Town){};
    virtual void PrintBySpaceRange(double size1,double size2){};

};
#endif
