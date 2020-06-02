#ifndef HelpfulBroker_H_HelpfulBroker
#define HelpfulBroker_H_HelpfulBroker
#include <iostream>
#include "agent.h"
class HelpfulBroker: public Agent
{
    private:
    char * name;
    double percentage;
    void Copy(const HelpfulBroker &x);
    void Erase();
    RealEstates listOfEstates;

    public:
    HelpfulBroker();
    HelpfulBroker(RealEstates listOfEstates, const char* name, double percentage);
    HelpfulBroker(const HelpfulBroker &x);
    ~HelpfulBroker();
    HelpfulBroker & operator=(const HelpfulBroker &x);
    virtual void Print()const;

    virtual void print()const;
    virtual void PrintHousesFromLowestPrice();
    virtual void PrintFlatsFromLowestPrice();
    virtual void PrintEstatesFromLowestPrice();
    virtual void PrintHouses();
    virtual void PrintFlats();
    virtual void PrintByPriceRange(double, double );
    virtual void PrintEstatesByTown(char *Town);
    virtual void PrintBySpaceRange(double, double );
};
#endif
