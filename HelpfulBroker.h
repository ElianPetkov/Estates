#ifndef HelpfulBroker_H_HelpfulBroker
#define HelpfulBroker_H_HelpfulBroker
#include <iostream>
#include "RegImot.h"
class HelpfulBroker
{


    private:
    char * name;
    double percentage;
    void Copy(const HelpfulBroker &x);
    void Erase();
    RealEstates y;

    public:
    HelpfulBroker();
    HelpfulBroker(Estate **estates,RealEstates y,const char* name,double percentage);
    HelpfulBroker(const HelpfulBroker &x);
    ~HelpfulBroker();
    HelpfulBroker & operator=(const HelpfulBroker & x);
    virtual void print()const;
    virtual void PrintByVip()const;
    virtual HelpfulBroker*Clone()const;

    virtual void LowestPrintHouseByVip()const;
    virtual void LowestPrintFlatByVip()const;
    virtual void LowestPrintByVip()const;
    virtual void PrintHouseByVip()const;
    virtual void PrintFlatByVip()const;
    virtual void PrintByPriceByVip(double price1,double price2)const;
    virtual void PrintTownByVip(char * Town)const;
    virtual void PrintBySpaceByVip(double size1,double size2)const;

};
#endif
