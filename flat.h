#ifndef FLAT_H_FLAT
#define FLAT_H_FLAT
#include <iostream>
#include "Estate.h"
class Flat:public Estate
{
    private:
    int rooms;
    int floor;
    void Copy(const Flat &flat);

    public:
    Flat();
    Flat(const char* typeOfEstate,const char* town, const char* offerType, const char* addr, const char* owner, double price, double space, int rooms, int floor);

    virtual void  print() const;
    virtual void addCharacteristicsToEstate(const char *);
    void setRooms(int room);
    void setFloors(int floor);
    int getRooms()const;
    int getFloor()const;
    Flat* Clone()const;
};
#endif
