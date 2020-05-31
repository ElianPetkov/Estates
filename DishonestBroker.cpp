#include <iostream>
#include "RegImot.h"
#include <string.h>
#include "DishonestBroker.h"
using namespace std;
DishonestBroker::DishonestBroker():y(),name(nullptr),percentage(0) {}
DishonestBroker::DishonestBroker(Estate **estates,RealEstates y,const char* name,double percentage)
{
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->percentage=percentage;
    this->y=y;
    this->y.NewPrice(percentage);

}
void DishonestBroker::Copy(const DishonestBroker & x)
{
    this->name=new char[strlen(x.name)+1];
    strcpy(this->name,x.name);
    this->percentage=x.percentage;
    this->y=x.y;

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
    y.print();
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
    y.LowestPrintHouse();
    std::cout<<std::endl;
}
void DishonestBroker::LowestPrintFlat()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.LowestPrintFlat();
    std::cout<<std::endl;
}
void DishonestBroker::LowestPrint()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.LowestPrint();
    std::cout<<std::endl;
}

void DishonestBroker::PrintHouse()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintHouse();
    std::cout<<std::endl;
}
void DishonestBroker::PrintFlat()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintFlat();
    std::cout<<std::endl;
}
void DishonestBroker::PrintByPrice(double price1,double price2)
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintByPrice(price1,price2);
    std::cout<<std::endl;
}

void DishonestBroker::PrintTown(char * Town)
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintTown(Town);
    std::cout<<std::endl;
}

void DishonestBroker::PrintBySpace(double size1,double size2)
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintBySpace(size1,size2);
    std::cout<<std::endl;
}
