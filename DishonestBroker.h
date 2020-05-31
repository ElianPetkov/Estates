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
    RealEstates y;


    public:
    DishonestBroker();
    DishonestBroker(Estate **estates,RealEstates y,const char* name,double percentage);
    DishonestBroker(const DishonestBroker &x);
    ~DishonestBroker();
    DishonestBroker& operator=(const DishonestBroker & x);
    virtual void print();
    virtual DishonestBroker * Clone()const;
    virtual void LowestPrintHouse();
    virtual void LowestPrintFlat();
    virtual void LowestPrint();
    virtual void PrintHouse();
    virtual void PrintFlat();
    virtual void PrintByPrice(double name1,double name2);
    virtual void PrintTown(char * Town);
    virtual void PrintBySpace(double size1,double size2);


};
#endif
