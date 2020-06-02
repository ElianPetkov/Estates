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
    virtual void PrintHousesFromLowestPrice()const;
    virtual void PrintFlatsFromLowestPrice()const;
    virtual void PrintEstatesFromLowestPrice()const;
    virtual void PrintHouses()const;
    virtual void PrintByPriceRange(double price1,double price2)const;
    virtual void PrintFlats()const;
    virtual void PrintEstatesByTown(char * Town)const;
    virtual void PrintBySpaceRange(double size1,double size2)const;
    void NewPrice(double x);

    virtual void PrintHousesFromLowestPriceByVip()const;
    virtual void PrintFlatsFromLowestPriceByVip()const;
    virtual void PrintEstatesFromLowestPriceByVip()const;
    virtual void PrintHousesByVip()const;
    virtual void PrintFlatsByVip()const;
    virtual void PrintByPriceRangeByVip(double price1,double price2)const;
    virtual void PrintEstatesByTownByVip(char * Town)const;
    virtual void PrintBySpaceRangeByVip(double size1,double size2)const;
};
#endif
