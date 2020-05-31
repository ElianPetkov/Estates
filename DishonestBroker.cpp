#include <iostream>
#include "RegImot.h"
#include <string.h>
#include "DishonestBroker.h"
using namespace std;
DishonestBroker::DishonestBroker():listOfEstates(),name(nullptr),percentage(0) {}
DishonestBroker::DishonestBroker(Estate **estates,RealEstates listOfEstates,const char* name,double percentage)
{
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->percentage=percentage;
    this->listOfEstates=listOfEstates;
    this->listOfEstates.NewPrice(percentage);

}
void DishonestBroker::Copy(const DishonestBroker & x)
{
    this->name=new char[strlen(x.name)+1];
    strcpy(this->name,x.name);
    this->percentage=x.percentage;
    this->listOfEstates=x.listOfEstates;

}
DishonestBroker::DishonestBroker(const DishonestBroker & x)
{
    Copy(x);
}
void DishonestBroker::Erase()
{
    delete [] name;
}
DishonestBroker::~DishonestBroker()
{
    Erase();
}
DishonestBroker &DishonestBroker:: operator=(const DishonestBroker & x)
{
    if(this!=&x)
    {
        Erase();
        Copy(x);
    }
    return *this;
}
void DishonestBroker::print()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.print();
    std::cout<<std::endl;
}
DishonestBroker * DishonestBroker:: Clone()const
{
    return new DishonestBroker(*this);
}
void DishonestBroker::LowestPrintHouse()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.LowestPrintHouse();
    std::cout<<std::endl;
}
void DishonestBroker::LowestPrintFlat()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.LowestPrintFlat();
    std::cout<<std::endl;
}
void DishonestBroker::LowestPrint()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.LowestPrint();
    std::cout<<std::endl;
}

void DishonestBroker::PrintHouse()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintHouse();
    std::cout<<std::endl;
}
void DishonestBroker::PrintFlat()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintFlat();
    std::cout<<std::endl;
}
void DishonestBroker::PrintByPrice(double price1,double price2)
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintByPrice(price1,price2);
    std::cout<<std::endl;
}

void DishonestBroker::PrintTown(char * Town)
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintTown(Town);
    std::cout<<std::endl;
}

void DishonestBroker::PrintBySpace(double size1,double size2)
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintBySpace(size1,size2);
    std::cout<<std::endl;
}
