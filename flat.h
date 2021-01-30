#ifndef FLAT_H_FLAT
#define FLAT_H_FLAT
#include <iostream>
#include "Estate.h"
class Flat:public Estate
{
    private:
    int rooms;
    int floor;

    protected:
    Flat* Clone()const;
    void Copy(const Flat &flat);

    public:
    Flat();
    Flat(const char* typeOfEstate,const char* town, const char* offerType, const char* addr, const char* owner, double price, double space, int rooms, int floor);

    virtual void  print() const;
    virtual void addCharacteristicsToEstate(const char *);
};
#endif
