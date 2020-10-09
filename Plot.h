#ifndef PLOT_H_PLOT
#define PLOT_H_PLOT
#include <iostream>
#include "Estate.h"
class Plot:public Estate
{
private:
    bool hasWater;
    bool hasElectricity;
    bool hasTelepfone;
    bool hasRoad;
    bool hasSewerage;

    void Copy(const Plot &plot);
public:
    Plot();
    Plot(bool hasWater,bool hasElectricity,bool hasTelepfone,bool hasRoad,bool hasSewerage,const char* typeOfEstate,const char* town, const char* offerType, const char* addr, const char* owner, double price, double space);
    Plot(const Plot &plot);

    Plot* Clone()const;
    virtual void addCharacteristicsToEstate(const char *);
    virtual void print()const;
};
#endif
