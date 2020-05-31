#include <iostream>
#include "RegImot.h"
#include <string.h>
#include "SimpleBroker.h"
#include <cassert>
SimpleBroker::SimpleBroker():listOfEstates(),name(nullptr),percentage(0){}
SimpleBroker::SimpleBroker(Estate **estates,RealEstates listOfEstates,const char* name,double percentage)
{
this->name=new char[strlen(name)+1];
assert(this->name!=nullptr);
strcpy(this->name,name);
this->percentage=percentage;
this->listOfEstates=listOfEstates;
this->listOfEstates.NewPrice(percentage);
}
void SimpleBroker::Copy(const SimpleBroker & x)
{
    this->name=new char[strlen(x.name)+1];
    assert(this->name!=nullptr);
    strcpy(this->name,x.name);
    this->percentage=x.percentage;
     this->listOfEstates=x.listOfEstates;

}
SimpleBroker::SimpleBroker(const SimpleBroker & x)
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
listOfEstates.print();
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
    listOfEstates.LowestPrintHouse();
    std::cout<<std::endl;
}
void SimpleBroker::LowestPrintFlat()
{
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.LowestPrintFlat();
    std::cout<<std::endl;
}
void SimpleBroker::LowestPrint()
{
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.LowestPrint();
    std::cout<<std::endl;
}

    void SimpleBroker::PrintHouse()
    {
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintHouse();
    std::cout<<std::endl;
}
void SimpleBroker::PrintFlat()
        {
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintFlat();
    std::cout<<std::endl;
}
void SimpleBroker::PrintByPrice(double price1,double price2)
        {
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintByPrice(price1,price2);
    std::cout<<std::endl;
}

void SimpleBroker::PrintTown(char * Town)
        {
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintTown(Town);
    std::cout<<std::endl;
}

void SimpleBroker::PrintBySpace(double size1,double size2)
{
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintBySpace(size1,size2);
    std::cout<<std::endl;
}
