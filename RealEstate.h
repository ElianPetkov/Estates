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
    void printEstatesByTypeAndVip(const char * typeOfEstate) const;
    virtual RealEstates* Clone()const;


public:
    RealEstates();
    RealEstates(Estate** estates);
    RealEstates(const RealEstates &estate);
    virtual ~RealEstates();
    RealEstates & operator=(const RealEstates &estate);

    //tested helping functions for the class
    Estate* getEstateByPosition(int);
    void addEstate(Estate*);
    void newPrice(double);
    void printEstatesByType(const char * typeOfEstate) const;
    int getCurrent();
    bool sortEstatesByLowerPrice()const;
    bool removeEstate(Estate*);

    virtual void printEstatesByTypeAndLowestPrice(const char*)const;
    virtual void printEstatesFromLowestPrice()const;
    virtual void printByPriceRange(double,double)const;
    virtual void printEstatesByTown(char* town)const;
    virtual void printBySpaceRange(double,double)const;
    virtual void print()const;

    virtual void printEstatesLowestPriceByVipAndType(const char*)const;
    virtual void printEstatesFromLowestPriceByVip()const;
    virtual void printByPriceRangeByVip(double,double)const;
    virtual void printEstatesByTownByVip(char* town)const;
    virtual void printBySpaceRangeByVip(double,double)const;
    virtual void printEstatesByVip()const;
};
#endif
