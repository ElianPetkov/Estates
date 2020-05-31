#ifndef SimpleBroker_H_SimpleBroker
#define SimpleBroker_H_SimpleBroker
#include <iostream>
#include "RegImot.h"
class SimpleBroker
{
    private:
    char * name;
    double percentage;
    RealEstates listOfEstates;

    void Copy(const SimpleBroker &x);
    void Erase();

    public:
    SimpleBroker();
    SimpleBroker(Estate **estates,RealEstates listOfEstates,const char* name,double percentage);
    SimpleBroker(const SimpleBroker &x);
    virtual ~SimpleBroker();
    SimpleBroker& operator=(const SimpleBroker & x);

    virtual void print()const;
    virtual SimpleBroker * Clone()const;
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

