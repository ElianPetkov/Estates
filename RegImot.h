#ifndef REGIMOT_H_REGIMOT
#define REGIMOT_H_REGIMOT
#include<iostream>
#include "Imot.h"
using namespace std;
class RealEstates
{
private:
    void Erase();
    void Copy(const RealEstates& x);
    void resize();
protected:
    int capacity;
    int current;
    Estate **estates;

public:
    RealEstates();
    RealEstates(Estate** estates);
    RealEstates(const RealEstates &estate);
    virtual ~RealEstates();
    RealEstates & operator=(const RealEstates &estate);

    virtual void print()const;
    void add(Estate*);
    void remove(Estate*);
    int getCurrent();
    void newPrice(int);
    virtual void PrintByVip()const;
    virtual RealEstates* Clone()const;
    virtual void printHousesFromLowestPrice()const;
    virtual void printFlatsFromLowestPrice()const;
    virtual void printEstatesFromLowestPrice()const;
    virtual void printHouses()const;
    virtual void printByPriceRange(double,double)const;
    virtual void printFlats()const;
    virtual void printEstatesByTown(char* Town)const;
    virtual void printBySpaceRange(double,double)const;
    void newPrice(double);

    virtual void printHousesFromLowestPriceByVip()const;
    virtual void printFlatsFromLowestPriceByVip()const;
    virtual void printEstatesFromLowestPriceByVip()const;
    virtual void printHousesByVip()const;
    virtual void printFlatsByVip()const;
    virtual void printByPriceRangeByVip(double,double)const;
    virtual void printEstatesByTownByVip(char* Town)const;
    virtual void printBySpaceRangeByVip(double,double)const;
};
#endif
