#ifndef DISHONESTBROKER_H_DISHONESTBROKER
#define DISHONESTBROKER_H_DISHONESTBROKER
#include <iostream>
#include "agent.h"
class DishonestBroker:public Agent
{
private:
    char* name;
    double percentage;
    void Copy(const DishonestBroker &broker);
    void Erase();
    RealEstates listOfEstates;

protected:
    virtual void printEstateFromLowestPriceByType(const char*);
    virtual void printEstatesFromLowestPrice();
    virtual void printByPriceRange(double,double);
    virtual void printEstatesByTown(char* townName);
    virtual void printBySpaceRange(double,double );

public:
    DishonestBroker();
    DishonestBroker(RealEstates listOfEstates, const char* name, double percentage);
    DishonestBroker(const DishonestBroker &broker);
    virtual ~DishonestBroker();
    DishonestBroker& operator=(const DishonestBroker &broker);

    char* getName()const;
    double getPercentages()const;
    virtual void print()const;

};
#endif
