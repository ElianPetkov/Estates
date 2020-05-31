#ifndef REGIMOT_H_REGIMOT
#define REGIMOT_H_REGIMOT
#include<iostream>
#include "Imot.h"
using namespace std;
class RealEstates
{
private:
    void Erase();
    void Copy(const RealEstates & x);
    void resize();
protected:
    int Capacity;
    int Current;
    Estate **estates;

public:
    RealEstates();
    RealEstates(Estate ** estates);
    RealEstates(const RealEstates & x);
    virtual ~RealEstates();
    RealEstates & operator=(const RealEstates &x);

    virtual void print()const;
    void add(Estate * x);
    void remove(Estate x);
    int GetCurrent();
    void NewPrice(int x);
    virtual void PrintByVip()const;
    virtual RealEstates * Clone()const;
    virtual void LowestPrintHouse()const;
    virtual void LowestPrintFlat()const;
    virtual void LowestPrint()const;
    virtual void PrintHouse()const;
    virtual void PrintByPrice(double price1,double price2)const;
    virtual void PrintFlat()const;
    virtual void PrintTown(char * Town)const;
    virtual void PrintBySpace(double size1,double size2)const;
    void NewPrice(double x);

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
