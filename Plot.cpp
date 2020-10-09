#include <iostream>
#include <string.h>
#include "Plot.h"
#include "Estate.h"
using namespace std;
Plot::Plot():Estate()
{
    this->hasWater = 0;
    this->hasElectricity=0;
    this->hasRoad=0;
    this->hasSewerage=0;
    this->hasTelepfone=0;

}
Plot::Plot(bool hasWater,bool hasElectricity,bool hasTelepfone,bool hasRoad,bool hasSewerage,const char* typeOfEstate,const char *town,const char *offerType,const char*addr,const char*owner,double price,double space):Estate(typeOfEstate,town,offerType,addr,owner,price,space)
{
    this->hasWater = hasWater;
    this->hasElectricity=hasElectricity;
    this->hasRoad=hasRoad;
    this->hasSewerage=hasSewerage;
    this->hasTelepfone=hasTelepfone;
}
void Plot::addCharacteristicsToEstate(const char *)
{
    Estate::addCharacteristicsToEstate("Plot");
    cout<<"Are the following comunnications included in the plot:"<<endl;
    char answer[20];
    do
    {
        cout<<"Does the plot has water"<<". Answer with Yes or No "<<endl;
        cout<<"Type your answer: ";
        cin.getline(answer,20);
    }
    while(strcmp(answer,"Yes") && strcmp(answer,"No"));
    if(!strcmp(answer,"Yes"))
    {
        this->hasWater=1;
    }
    else
    {
        this->hasWater=0;
    }

    do
    {
        cout<<"Does the plot has an electicity"<<". Answer with Yes or No "<<endl;
        cout<<"Type your answer: ";
        cin.getline(answer,20);
    }
    while(strcmp(answer,"Yes") && strcmp(answer,"No"));
    if(!strcmp(answer,"Yes"))
    {
        this->hasElectricity=1;
    }
    else
    {
        this->hasElectricity=0;
    }

    do
    {
        cout<<"Does the plot has a telephone"<<". Answer with Yes or No "<<endl;
        cout<<"Type your answer: ";
        cin.getline(answer,20);
    }
    while(strcmp(answer,"Yes") && strcmp(answer,"No"));
    if(!strcmp(answer,"Yes"))
    {
        this->hasTelepfone=1;
    }
    else
    {
        this->hasTelepfone=0;
    }

    do
    {
        cout<<"Does the plot is near a road"<<". Answer with Yes or No "<<endl;
        cout<<"Type your answer: ";
        cin.getline(answer,20);
    }
    while(strcmp(answer,"Yes") && strcmp(answer,"No"));
    if(!strcmp(answer,"Yes"))
    {
        this->hasRoad=1;
    }
    else
    {
        this->hasRoad=0;
    }

    do
    {
        cout<<"Does the plot has a sewerage"<<". Answer with Yes or No "<<endl;
        cout<<"Type your answer: ";
        cin.getline(answer,20);
    }
    while(strcmp(answer,"Yes") && strcmp(answer,"No"));
    if(!strcmp(answer,"Yes"))
    {
        this->hasSewerage=1;
    }
    else
    {
        this->hasSewerage=0;
    }
}

void Plot::print()const
{
    Estate::print();
    if(hasWater==0)
    {
        cout<<"No water"<<endl;
    }
    else
    {
        cout<<"Have water"<<endl;
    }

    if(hasElectricity==0)
    {
        cout<<"No electricity"<<endl;
    }
    else
    {
        cout<<"Have electricity:"<<endl;
    }
    if(hasRoad==0)
    {
        cout<<"Isn't near road"<<endl;
    }
    else
    {
        cout<<"Is near road"<<endl;
    }
    if(hasTelepfone==0)
    {
        cout<<"No telephone"<<endl;
    }
    else
    {
        cout<<"Have telephone"<<endl;
    }
    if(hasSewerage==0)
    {
        cout<<"No sewerage"<<endl;
    }
    else
    {
        cout<<"Have sewerage"<<endl;
    }
}

void Plot::Copy(const Plot &plot)
{
    this->hasWater = plot.hasWater;
    this->hasElectricity=plot.hasElectricity;
    this->hasRoad=plot.hasRoad;
    this->hasSewerage=plot.hasSewerage;
    this->hasTelepfone=plot.hasTelepfone;
}

Plot::Plot(const Plot &plot):Estate(plot)
{
    Copy(plot);
}

Plot* Plot::Clone()const
{
    return new Plot(*this);
}

