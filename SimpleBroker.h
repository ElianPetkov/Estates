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

    void Copy(const SimpleBroker &broker);
    void Erase();

protected:
    virtual void printEstatesFromLowestPrice();
    virtual void printEstateFromLowestPriceByType(const char*);
    virtual void printByPriceRange(double fromPrice, double toPrice);
    virtual void printEstatesByTown(char* Town);
    virtual void printBySpaceRange(double fromSize, double toSize);

public:
    SimpleBroker();
    SimpleBroker(RealEstates listOfEstates, const char* name, double percentage);
    SimpleBroker(const SimpleBroker &broker);
    virtual ~SimpleBroker();
    SimpleBroker& operator=(const SimpleBroker &broker);

    virtual void print()const;

};
#endif

