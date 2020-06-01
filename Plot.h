#ifndef PLOT_H_PLOT
#define PLOT_H_PLOT
#include <iostream>
#include "Imot.h"
class Plot:public Estate
{
    private:
    int a[5];
    void Copy(const Plot &x);
    public:
    Plot();
    Plot(const char *town,const char *TypeOfEstate,const char*addr,const char*owner,double price,double space);
    Plot(const Plot & x);
    enum Comunnication{water,electicity,telephone,nearRoad,sewerage};


    Plot * Clone()const;
    virtual void AddCharacteristicsToEstate();
    virtual void print()const;




};
#endif
