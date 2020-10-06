#ifndef REGIMOT_H_REGIMOT
#define REGIMOT_H_REGIMOT
#include<iostream>
#include "Estate.h"
using namespace std;
class RealEstates
{
private:
    void Erase();
    void Copy(const RealEstates& x);

protected:
    int capacity;
    int current;
    Estate **estates;
    void resize();

public:
    RealEstates();
    RealEstates(Estate** estates);
    RealEstates(const RealEstates &estate);
    virtual ~RealEstates();
    RealEstates & operator=(const RealEstates &estate);
    Estate* getEstateByPosition(int);

    virtual void print()const;
    void addEstate(Estate*);
    void removeEstate(Estate*);
    int getCurrent();
    virtual void printEstatesByVip()const;
    virtual RealEstates* Clone()const;
    virtual void printHousesFromLowestPrice()const;
    virtual void printFlatsFromLowestPrice()const;
    virtual void printEstatesFromLowestPrice()const;
    virtual void printHouses()const;
    virtual void printByPriceRange(double,double)const;
    virtual void printFlats()const;
    virtual void printEstatesByTown(char* town)const;
    virtual void printBySpaceRange(double,double)const;
    void newPrice(double);

    virtual void printHousesFromLowestPriceByVip()const;
    virtual void printFlatsFromLowestPriceByVip()const;
    virtual void printEstatesFromLowestPriceByVip()const;
    virtual void printHousesByVip()const;
    virtual void printFlatsByVip()const;
    virtual void printByPriceRangeByVip(double,double)const;
    virtual void printEstatesByTownByVip(char* town)const;
    virtual void printBySpaceRangeByVip(double,double)const;
};
#endif
