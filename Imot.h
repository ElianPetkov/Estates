#ifndef IMOT_H_IMOT
#define IMOT_H_IMOT
#include<iostream>
class Estate
{
private:
    char* town;
    char* TypeOfEstate;
    char* addr;
    char* owner;
    double price;
    double space;

    void Copy(const Estate & x);
    void Erase();

public:
    Estate();
    Estate(const char *town,const char *TypeOfEstate,const char*addr,const char*owner,double price,double space);
    Estate(const Estate & x);
    virtual ~Estate();
    Estate & operator=(const Estate & x);

    char *GetTypeOfEstate()const;
    const char * getAddr()const;
    const char * getOwner()const;
    void setPrice(double x);
    double getPrice()const;
    double getSpace()const;

    virtual Estate* Clone() const;
    virtual double getYard()const
    {
        return 0;
    }
    virtual int getFloor()const
    {
        return 0;
    };
    virtual char* getTown()const;
    virtual void print()const;
    virtual void addCharacteristicsToEstate();
};
#endif
