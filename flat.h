#ifndef FLAT_H_FLAT
#define FLAT_H_FLAT
#include <iostream>
#include "Imot.h"
class Flat:public Estate
{
    private:
    int rooms;
    int floor;
    void Copy(const Flat &x);

    public:
    virtual void  print() const;
    virtual void addCharacteristicsToEstate();
    Flat();
    Flat(const char* town, const char* TypeOfEstate, const char* addr, const char* owner, double price, double space, int rooms, int floor);
    void setRooms(int room);
    void setFloors(int floor);
    int getRooms()const;
    int getFloor()const;
    Flat* Clone()const;
};
#endif
