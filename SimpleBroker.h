#ifndef SimpleBroker_H_SimpleBroker
#define SimpleBroker_H_SimpleBroker
#include <iostream>
#include "agent.h"
class SimpleBroker:public Agent
{
    private:
    char* name;
    double percentage;
    RealEstates listOfEstates;

    void Copy(const SimpleBroker &x);
    void Erase();

    public:
    SimpleBroker();
    SimpleBroker(RealEstates listOfEstates, const char* name, double percentage);
    SimpleBroker(const SimpleBroker &x);
    virtual ~SimpleBroker();

    SimpleBroker& operator=(const SimpleBroker &x);
    virtual void print()const;
    virtual void PrintHousesFromLowestPrice();
    virtual void PrintFlatsFromLowestPrice();
    virtual void PrintEstatesFromLowestPrice();
    virtual void PrintHouses();
    virtual void PrintFlats();
    virtual void PrintByPriceRange(double fromPrice, double toPrice);
    virtual void PrintEstatesByTown(char *Town);
    virtual void PrintBySpaceRange(double fromSize, double toSize);
};
#endif

