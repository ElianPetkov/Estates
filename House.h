#ifndef HOUSE_H_HOUSE
#define HOUSE_H_HOUSE
#include "Imot.h"
class House:public Estate
{
    private:
    int rooms;
    int floors;
    double yard;
    void Copy(const House &x);

    public:
    House();
    House(const char* town, const char* TypeOfEstate, const char* addr, const char* owner, double price, double space, int rooms, int floor);
    House(const House &x);
    House & operator=(const House &x);

    House* Clone()const;
    virtual void print()const;
    virtual void addCharacteristicsToEstate();
};
#endif
