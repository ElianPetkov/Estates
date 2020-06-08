#include <iostream>
#include <string.h>
#include "Plot.h"
#include "Estate.h"
using namespace std;
Plot::Plot():Estate()
{
    for(int i=0; i<5; i++)
    {
        comunnications[i]=0;
    }
}
Plot::Plot(const char *town,const char *TypeOfEstate,const char*addr,const char*owner,double price,double space):Estate(town,TypeOfEstate,addr,owner,price,space)
{
    for(int i=0; i<5; i++)
    {
        comunnications[i]=0;
    }
}
void Plot::addCharacteristicsToEstate()
{
    Estate::addCharacteristicsToEstate();
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
        this->comunnications[0]=1;
    }
    else
    {
        this->comunnications[0]=0;
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
        this->comunnications[1]=1;
    }
    else
    {
        this->comunnications[1]=0;
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
        this->comunnications[2]=1;
    }
    else
    {
        this->comunnications[2]=0;
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
        this->comunnications[3]=1;
    }
    else
    {
        this->comunnications[3]=0;
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
        this->comunnications[4]=1;
    }
    else
    {
        this->comunnications[4]=0;
    }
}

void Plot::print()const
{
    Estate::print();
    if(comunnications[0]==0)
    {
        cout<<"No water"<<endl;
    }
    else
    {
        cout<<"Have water"<<endl;
    }

    if(comunnications[1]==0)
    {
        cout<<"No electricity"<<endl;
    }
    else
    {
        cout<<"Have electricity:"<<endl;
    }
    if(comunnications[2]==0)
    {
        cout<<"Isn't near road"<<endl;
    }
    else
    {
        cout<<"Is near road"<<endl;
    }
    if(comunnications[3]==0)
    {
        cout<<"No water"<<endl;
    }
    else
    {
        cout<<"Have water"<<endl;
    }
    if(comunnications[4]==0)
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
    for(int i=0; i<5; i++)
    {
        comunnications[i]=plot.comunnications[i];
    }
}

Plot::Plot(const Plot &plot):Estate(plot)
{
    Copy(plot);
}

Plot* Plot::Clone()const
{
    return new Plot(*this);
}

