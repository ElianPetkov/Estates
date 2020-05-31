#include <iostream>
#include "RegImot.h"
#include <string.h>
#include "SimpleBroker.h"
#include <cassert>
SimpleBroker::SimpleBroker():RealEstates(),y(),name(nullptr),percentage(0){}
SimpleBroker::SimpleBroker(Estate **estates,RealEstates y,const char* name,double percentage):RealEstates(estates)
{
this->name=new char[strlen(name)+1];
assert(this->name!=nullptr);
strcpy(this->name,name);
this->percentage=percentage;
this->y=y;
this->y.NewPrice(percentage);
}
void SimpleBroker::Copy(const SimpleBroker & x)
{
    this->name=new char[strlen(x.name)+1];
    assert(this->name!=nullptr);
    strcpy(this->name,x.name);
    this->percentage=x.percentage;
     this->y=x;

}
SimpleBroker::SimpleBroker(const SimpleBroker & x):RealEstates(x)
{
    Copy(x);
}
void SimpleBroker::Erase()
{
    delete [] name;
}
SimpleBroker::~SimpleBroker()
{
    Erase();
}
SimpleBroker& SimpleBroker::operator=(const SimpleBroker & x)
{
    if(this!=&x)
    {
        RealEstates::operator=(x);
        Erase();
        Copy(x);
    }
    return *this;
}
void SimpleBroker::print()const
{
std::cout<<"Simple Broker:"<<std::endl;
std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
std::cout<<"Estates:";
y.print();
std::cout<<std::endl;
}


SimpleBroker * SimpleBroker:: Clone()const
{
    return new SimpleBroker(*this);
}
void SimpleBroker::LowestPrintHouse()
{
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.LowestPrintHouse();
    std::cout<<std::endl;
}
void SimpleBroker::LowestPrintFlat()
{
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.LowestPrintFlat();
    std::cout<<std::endl;
}
void SimpleBroker::LowestPrint()
{
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.LowestPrint();
    std::cout<<std::endl;
}

    void SimpleBroker::PrintHouse()
    {
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintHouse();
    std::cout<<std::endl;
}
void SimpleBroker::PrintFlat()
        {
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintFlat();
    std::cout<<std::endl;
}
void SimpleBroker::PrintByPrice(double price1,double price2)
        {
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintByPrice(price1,price2);
    std::cout<<std::endl;
}

void SimpleBroker::PrintTown(char * Town)
        {
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintTown(Town);
    std::cout<<std::endl;
}

void SimpleBroker::PrintBySpace(double size1,double size2)
{
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintBySpace(size1,size2);
    std::cout<<std::endl;
}
