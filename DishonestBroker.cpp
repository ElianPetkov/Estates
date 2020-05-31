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
void DishonestBroker::PrintHousesFromLowestPrice()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintHousesFromLowestPrice();
    std::cout<<std::endl;
}
void DishonestBroker::PrintFlatsFromLowestPrice()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintFlatsFromLowestPrice();
    std::cout<<std::endl;
}
void DishonestBroker::PrintEstatesFromLowestPrice()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintEstatesFromLowestPrice();
    std::cout<<std::endl;
}

void DishonestBroker::PrintHouses()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintHouses();
    std::cout<<std::endl;
}
void DishonestBroker::PrintFlats()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintFlats();
    std::cout<<std::endl;
}
void DishonestBroker::PrintByPriceRange(double price1,double price2)
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintByPriceRange(price1,price2);
    std::cout<<std::endl;
}

void DishonestBroker::PrintEstatesByTown(char * Town)
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintEstatesByTown(Town);
    std::cout<<std::endl;
}

void DishonestBroker::PrintBySpaceRange(double size1,double size2)
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintBySpaceRange(size1,size2);
    std::cout<<std::endl;
}
