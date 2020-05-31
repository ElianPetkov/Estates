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
    RealEstates listOfEstates;

    public:
    HelpfulBroker();
    HelpfulBroker(Estate **estates,RealEstates listOfEstates,const char* name,double percentage);
    HelpfulBroker(const HelpfulBroker &x);
    ~HelpfulBroker();
    HelpfulBroker & operator=(const HelpfulBroker & x);
    virtual void print()const;
    virtual void PrintByVip()const;
    virtual HelpfulBroker*Clone()const;

    virtual void ByVip()const;
    virtual void PrintFlatsFromLowestPriceByVip()const;
    virtual void PrintEstatesFromLowestPriceByVip()const;
    virtual void PrintHousesByVip()const;
    virtual void PrintFlatsByVip()const;
    virtual void PrintByPriceRangeByVip(double price1,double price2)const;
    virtual void PrintEstatesByTownByVip(char * Town)const;
    virtual void PrintBySpaceRangeByVip(double size1,double size2)const;

};
#endif
