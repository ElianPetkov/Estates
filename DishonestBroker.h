#ifndef DISHONESTBROKER_H_DISHONESTBROKER
#define DISHONESTBROKER_H_DISHONESTBROKER
#include <iostream>
#include "agent.h"
class DishonestBroker:public Agent
{
    private:
    char* name;
    double percentage;
    void Copy(const DishonestBroker &x);
    void Erase();
    RealEstates listOfEstates;

    public:
    DishonestBroker();
    DishonestBroker(RealEstates listOfEstates, const char* name, double percentage);
    DishonestBroker(const DishonestBroker &x);
    virtual ~DishonestBroker();
    DishonestBroker& operator=(const DishonestBroker &x);

    virtual void print()const;
    virtual void PrintHousesFromLowestPrice();
    virtual void PrintFlatsFromLowestPrice();
    virtual void PrintEstatesFromLowestPrice();
    virtual void PrintHouses();
    virtual void PrintFlats();
    virtual void PrintByPriceRange(double ,double);
    virtual void PrintEstatesByTown(char* townName);
    virtual void PrintBySpaceRange(double ,double );
};
#endif
