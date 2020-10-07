#ifndef REGIMOT_H_REGIMOT
#define REGIMOT_H_REGIMOT
#include<iostream>
#include "Estate.h"
using namespace std;
class RealEstates
{
private:

    Estate **estates;
    int capacity;
    int current;

protected:
    void Erase();
    void Copy(const RealEstates& x);
    void resize();
    void sortEstatesByPrice()const;
    void printEstatesByTypeAndVip(const char * typeOfEstate) const;
    void printEstatesByType(const char * typeOfEstate) const;


public:
    RealEstates();
    RealEstates(Estate** estates);
    RealEstates(const RealEstates &estate);
    virtual ~RealEstates();
    RealEstates & operator=(const RealEstates &estate);
    Estate* getEstateByPosition(int);

    virtual void print()const;
    void addEstate(Estate*);
    bool removeEstate(Estate*);
    int getCurrent();
    virtual RealEstates* Clone()const;
    void newPrice(double);

    virtual void printHousesFromLowestPrice()const;
    virtual void printFlatsFromLowestPrice()const;
    virtual void printEstatesFromLowestPrice()const;
    virtual void printHouses()const;
    virtual void printByPriceRange(double,double)const;
    virtual void printFlats()const;
    virtual void printEstatesByTown(char* town)const;
    virtual void printBySpaceRange(double,double)const;

    virtual void printHousesFromLowestPriceByVip()const;
    virtual void printFlatsFromLowestPriceByVip()const;
    virtual void printEstatesFromLowestPriceByVip()const;
    virtual void printHousesByVip()const;
    virtual void printFlatsByVip()const;
    virtual void printByPriceRangeByVip(double,double)const;
    virtual void printEstatesByTownByVip(char* town)const;
    virtual void printBySpaceRangeByVip(double,double)const;
    virtual void printEstatesByVip()const;
};
#endif
