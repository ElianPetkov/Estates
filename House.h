#ifndef HOUSE_H_HOUSE
#define HOUSE_H_HOUSE
#include "Estate.h"
class House:public Estate
{
    private:
    int rooms;
    int floors;
    double yard;

    protected:
    House* Clone()const;
    void Copy(const House &house);

    public:
    House();
    House(const char* typeOfEstate,const char* town, const char* offerType, const char* addr, const char* owner, double price, double space, int rooms, int floor);
    House(const House &house);
    House& operator=(const House &house);

    virtual void print()const;
    virtual void addCharacteristicsToEstate(const char *);
};
#endif
