#ifndef PLOT_H_PLOT
#define PLOT_H_PLOT
#include <iostream>
#include "Estate.h"
class Plot:public Estate
{
private:
    int comunnications[5];
    void Copy(const Plot &plot);
public:
    Plot();
    Plot(const char* town, const char* TypeOfEstate, const char* addr, const char* owner, double price, double space);
    Plot(const Plot &plot);

    Plot* Clone()const;
    virtual void addCharacteristicsToEstate();
    virtual void print()const;
};
#endif
