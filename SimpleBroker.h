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

    char* getName()const{return name;}
    SimpleBroker& operator=(const SimpleBroker &x);
    virtual void print()const;
    virtual void printHousesFromLowestPrice();
    virtual void printFlatsFromLowestPrice();
    virtual void printEstatesFromLowestPrice();
    virtual void printHouses();
    virtual void printFlats();
    virtual void printByPriceRange(double fromPrice, double toPrice);
    virtual void printEstatesByTown(char *Town);
    virtual void printBySpaceRange(double fromSize, double toSize);
};
#endif

