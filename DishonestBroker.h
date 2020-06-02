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
    virtual void printHousesFromLowestPrice();
    virtual void printFlatsFromLowestPrice();
    virtual void printEstatesFromLowestPrice();
    virtual void printHouses();
    virtual void printFlats();
    virtual void printByPriceRange(double ,double);
    virtual void printEstatesByTown(char* townName);
    virtual void printBySpaceRange(double ,double );
};
#endif
