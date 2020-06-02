#include <iostream>
#include "RegImot.h"
#include <string.h>
#include "DishonestBroker.h"
#include <cassert>
using namespace std;
DishonestBroker::DishonestBroker():listOfEstates(),name(nullptr),percentage(0) {}
DishonestBroker::DishonestBroker(RealEstates listOfEstates,const char* name,double percentage)
{
    assert(name != nullptr && "name: requires non-null argument");
    assert(percentage > 0 && "percentages: requires value > 0");

    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->percentage=percentage;
    this->listOfEstates=listOfEstates;
    this->listOfEstates.newPrice(percentage);
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

void DishonestBroker::print() const
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.print();
    std::cout<<std::endl;
}

void DishonestBroker::printHousesFromLowestPrice()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printHousesFromLowestPrice();
    std::cout<<std::endl;
}

void DishonestBroker::printFlatsFromLowestPrice()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printFlatsFromLowestPrice();
    std::cout<<std::endl;
}

void DishonestBroker::printEstatesFromLowestPrice()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printEstatesFromLowestPrice();
    std::cout<<std::endl;
}

void DishonestBroker::printHouses()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printHouses();
    std::cout<<std::endl;
}

void DishonestBroker::printFlats()
{
    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printFlats();
    std::cout<<std::endl;
}

void DishonestBroker::printByPriceRange(double fromPrice,double toPrice)
{
    if(toPrice - fromPrice < 0){
        throw std::invalid_argument ("difference between fromPrice and toPrice must be > 0");
    }

    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printByPriceRange(fromPrice,toPrice);
    std::cout<<std::endl;
}

void DishonestBroker::printEstatesByTown(char *townName)
{
    if(townName[0] == '\0'){
        throw std::invalid_argument ("townName shouldn't be empty name");
    }

    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printEstatesByTown(townName);
    std::cout<<std::endl;
}

void DishonestBroker::printBySpaceRange(double fromSize,double toSize)
{
    if(toSize - fromSize < 0){
        throw std::invalid_argument ("difference between fromSize and toSize must be > 0");
    }

    std::cout<<"Dishonest Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printBySpaceRange(fromSize,toSize);
    std::cout<<std::endl;
}
