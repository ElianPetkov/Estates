#ifndef DISHONESTBROKER_H_DISHONESTBROKER
#define DISHONESTBROKER_H_DISHONESTBROKER
#include <iostream>
#include "RegImot.h"
class DishonestBroker
{
    private:
    char * name;
    double percentage;
    void Copy(const DishonestBroker &x);
    void Erase();
    RealEstates listOfEstates;


    public:
    DishonestBroker();
    DishonestBroker(Estate **estates,RealEstates listOfEstates,const char* name,double percentage);
    DishonestBroker(const DishonestBroker &x);
    ~DishonestBroker();
    DishonestBroker& operator=(const DishonestBroker & x);
    virtual void print();
    virtual DishonestBroker * Clone()const;
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
