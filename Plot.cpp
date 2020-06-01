#include <iostream>
#include <string.h>
#include "Plot.h"
#include "Imot.h"
using namespace std;
Plot::Plot():Estate()
{
    for(int i=0; i<5; i++)
    {
        a[i]=0;
    }
}
Plot::Plot(const char *town,const char *TypeOfEstate,const char*addr,const char*owner,double price,double space):Estate(town,TypeOfEstate,addr,owner,price,space)
{
    for(int i=0; i<5; i++)
    {
        a[i]=0;
    }
}
void Plot::AddCharacteristicsToEstate()
{
    Estate::AddCharacteristicsToEstate();
    cout<<"Are the following comunnications included in the plot:"<<" ";
    cout<<"Type Yes or No"<<endl;
    char b[20];

    cout<<"Water"<<" ";
    do
    {
        cin.getline(b,20);
    }
    while(strcmp(b,"Yes") && strcmp(b,"No"));
    if(!strcmp(b,"Yes"))
    {
        this->a[0]=1;
    }
    else
    {
        this->a[0]=0;
    }
    cout<<"electicity"<<" ";

    do
    {
        cin.getline(b,20);
    }
    while(strcmp(b,"Yes") && strcmp(b,"No"));
    if(!strcmp(b,"Yes"))
    {
        this->a[1]=1;
    }
    else
    {
        this->a[1]=0;
    }

    cout<<"telephone"<<" ";
    do
    {
        cin.getline(b,20);
    }
    while(strcmp(b,"Yes") && strcmp(b,"No"));
    if(!strcmp(b,"Yes"))
    {
        this->a[2]=1;
    }
    else
    {
        this->a[2]=0;
    }
    cout<<"nearRoad"<<" ";
    do
    {
        cin.getline(b,20);
    }
    while(strcmp(b,"Yes") && strcmp(b,"No"));
    if(!strcmp(b,"Yes"))
    {
        this->a[3]=1;
    }
    else
    {
        this->a[3]=0;
    }

    cout<<"sewerage"<<" ";
    do
    {
        cin.getline(b,20);
    }
    while(strcmp(b,"Yes") && strcmp(b,"No"));
    if(!strcmp(b,"Yes"))
    {
        this->a[4]=1;
    }
    else
    {
        this->a[4]=0;
    }
}
void Plot::print()const
{
    Estate::print();
    if(a[0]==0)
    {
        cout<<"No water"<<endl;
    }
    else
    {
        cout<<"Have water"<<endl;
    }

    if(a[1]==0)
    {
        cout<<"No electricity"<<endl;
    }
    else
    {
        cout<<"Have electricity:"<<endl;
    }
    if(a[2]==0)
    {
        cout<<"Isn't near road"<<endl;
    }
    else
    {
        cout<<"Is near road"<<endl;
    }
    if(a[3]==0)
    {
        cout<<"No water"<<endl;
    }
    else
    {
        cout<<"Have water"<<endl;
    }
    if(a[4]==0)
    {
        cout<<"No sewerage"<<endl;
    }
    else
    {
        cout<<"Have sewerage"<<endl;
    }
}


void Plot::Copy(const Plot & x)
{
    for(int i=0; i<5; i++)
    {
        a[i]=x.a[i];
    }
}
Plot::Plot(const Plot &x):Estate(x)
{
    Copy (x);
}
Plot * Plot::Clone()const
{
    return new Plot(*this);
}

