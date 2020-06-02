#include <iostream>
#include "RegImot.h"
#include <string.h>
#include "SimpleBroker.h"
#include <cassert>
SimpleBroker::SimpleBroker():listOfEstates(),name('\0'),percentage(0) {}
SimpleBroker::SimpleBroker(RealEstates listOfEstates,const char* name,double percentage)
{
    assert(name != nullptr && "name: requires non-null argument");
    assert(percentage > 0 && "percentages: requires value > 0");

    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->percentage=percentage;
    this->listOfEstates=listOfEstates;
    this->listOfEstates.NewPrice(percentage);
}

void SimpleBroker::Copy(const SimpleBroker &x)
{
    this->name=new char[strlen(x.name)+1];
    strcpy(this->name,x.name);
    this->percentage=x.percentage;
    this->listOfEstates=x.listOfEstates;

}

SimpleBroker::SimpleBroker(const SimpleBroker &x)
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

SimpleBroker& SimpleBroker::operator=(const SimpleBroker &x)
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

void SimpleBroker::printHousesFromLowestPrice()
{
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printHousesFromLowestPrice();
    std::cout<<std::endl;
}

void SimpleBroker::printFlatsFromLowestPrice()
{
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printFlatsFromLowestPrice();
    std::cout<<std::endl;
}

void SimpleBroker::printEstatesFromLowestPrice()
{
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printEstatesFromLowestPrice();
    std::cout<<std::endl;
}

void SimpleBroker::printHouses()
{
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printHouses();
    std::cout<<std::endl;
}

void SimpleBroker::printFlats()
{
    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printFlats();
    std::cout<<std::endl;
}

void SimpleBroker::printByPriceRange(double fromPrice, double toPrice)
{
    if(toPrice - fromPrice < 0){
        throw std::invalid_argument ("difference between fromPrice and toPrice must be > 0");
    }

    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printByPriceRange(fromPrice,toPrice);
    std::cout<<std::endl;
}

void SimpleBroker::printEstatesByTown(char *townName)
{
    if(townName[0] == '\0'){
        throw std::invalid_argument ("townName shouldn't be empty name");
    }

    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printEstatesByTown(townName);
    std::cout<<std::endl;
}

void SimpleBroker::printBySpaceRange(double fromSize,double toSize)
{
    if(toSize - fromSize < 0){
        throw std::invalid_argument ("difference between fromSize and toSize must be > 0");
    }

    std::cout<<"Simple Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printBySpaceRange(fromSize, toSize);
    std::cout<<std::endl;
}
