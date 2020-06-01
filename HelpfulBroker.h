#ifndef HelpfulBroker_H_HelpfulBroker
#define HelpfulBroker_H_HelpfulBroker
#include <iostream>
#include "RegImot.h"
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
    HelpfulBroker(RealEstates listOfEstates,const char* name,double percentage);
    HelpfulBroker(const HelpfulBroker &x);
    ~HelpfulBroker();
    HelpfulBroker & operator=(const HelpfulBroker & x);
    virtual void Print()const;
    //virtual HelpfulBroker*Clone()const;

    virtual void print()const;
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
