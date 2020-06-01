#ifndef SimpleBroker_H_SimpleBroker
#define SimpleBroker_H_SimpleBroker
#include <iostream>
#include "RegImot.h"
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
    SimpleBroker(RealEstates listOfEstates,const char* name,double percentage);
    SimpleBroker(const SimpleBroker &x);
    virtual ~SimpleBroker();
    SimpleBroker& operator=(const SimpleBroker & x);

    virtual void print()const;
    //virtual Agent * Clone()const;
    virtual void PrintHousesFromLowestPrice();
    virtual void PrintFlatsFromLowestPrice();
    virtual void PrintEstatesFromLowestPrice();
    virtual void PrintHouses();
    virtual void PrintFlats();
    virtual void PrintByPriceRange(double price1,double price2);
    virtual void PrintEstatesByTown(char * Town);
    virtual void PrintBySpaceRange(double size1,double size2);
};
#endif

