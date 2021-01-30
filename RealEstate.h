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
    RealEstates* Clone()const;


public:
    RealEstates();
    RealEstates(Estate** estates);
    RealEstates(const RealEstates &estate);
    ~RealEstates();
    RealEstates & operator=(const RealEstates &estate);

    Estate* getEstateByPosition(int);
    void addEstate(Estate*);
    void newPrice(double);
    void printEstatesByType(const char * typeOfEstate) const;
    int getCurrent();
    bool sortEstatesByLowerPrice()const;
    bool removeEstate(Estate*);

    void printEstatesByTypeAndLowestPrice(const char*)const;
    void printEstatesFromLowestPrice()const;
    void printByPriceRange(double,double)const;
    void printEstatesByTown(char* town)const;
    void printBySpaceRange(double,double)const;
    void print()const;

    void printEstatesLowestPriceByVipAndType(const char*)const;
    void printEstatesFromLowestPriceByVip()const;
    void printByPriceRangeByVip(double,double)const;
    void printEstatesByTownByVip(char* town)const;
    void printBySpaceRangeByVip(double,double)const;
    void printEstatesByVip()const;
};
#endif
