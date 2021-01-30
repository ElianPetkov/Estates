#ifndef IMOT_H_IMOT
#define IMOT_H_IMOT
#include<iostream>
class Estate
{
private:
    char* typeOfEstate;
    char* town;
    char* offerType;
    char* addr;
    char* owner;
    double price;
    double space;

    void Copy(const Estate &estate);
    void Erase();

public:
    Estate();
    Estate(const char* typeOfEstate,const char *town,const char *offerType,const char* addr,const char* owner,double price,double space);
    Estate(const Estate &estate);
    virtual ~Estate();
    Estate& operator=(const Estate &estate);

    char* getOfferType()const;
    char* getTypeOfEstate()const;
    char* getAddr()const;
    char* getOwner()const;
    void setPrice(double);
    double getPrice()const;
    double getSpace()const;

    virtual Estate* Clone() const;
    virtual double getYard()const{}
    virtual int getFloor()const{}
    virtual char* getTown()const;
    virtual void print()const;
    virtual void addCharacteristicsToEstate(const char *);
};
#endif
