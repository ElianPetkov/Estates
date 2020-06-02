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

    char* getName()const{return name;}
    double getPercentages()const{return percentage;}
    virtual void print()const;
    virtual void printHousesFromLowestPrice();
    virtual void printFlatsFromLowestPrice();
    virtual void printEstatesFromLowestPrice();
    virtual void printHouses();
    virtual void printFlats();
    virtual void printByPriceRange(double, double );
    virtual void printEstatesByTown(char *Town);
    virtual void printBySpaceRange(double, double );
};
#endif
