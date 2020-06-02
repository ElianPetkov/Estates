#include <iostream>
#include "RegImot.h"
#include <string.h>
#include "HelpfulBroker.h"
#include <cassert>
HelpfulBroker::HelpfulBroker():name(nullptr),percentage(0),listOfEstates() {}
HelpfulBroker::HelpfulBroker(RealEstates listOfEstates, const char * name, double percentage)
{
    assert(name != nullptr && "name: requires non-null argument");
    assert(percentage > 0 && "percentages: requires value > 0");

    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->percentage=percentage;
    this->listOfEstates=listOfEstates;
    this->listOfEstates.NewPrice(percentage);
}

void HelpfulBroker::Copy(const HelpfulBroker & x)
{
    this->name=new char[strlen(x.name)+1];
    strcpy(this->name,x.name);
    this->percentage=x.percentage;
    this->listOfEstates=x.listOfEstates;
}

HelpfulBroker::HelpfulBroker(const HelpfulBroker & x)
{
    Copy(x);
}

void HelpfulBroker::Erase()
{
    delete [] name;
}

HelpfulBroker::~HelpfulBroker()
{
    Erase();
}

HelpfulBroker & HelpfulBroker:: operator=(const HelpfulBroker & x)
{
    if(this!=&x)
    {
        Erase();
        Copy(x);
    }
    return *this;
}

void HelpfulBroker::print()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintByVip();
    std::cout<<std::endl;
}


void HelpfulBroker::printHousesFromLowestPrice()
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printHousesFromLowestPriceByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::printFlatsFromLowestPrice()
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printFlatsFromLowestPriceByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::printEstatesFromLowestPrice()
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printEstatesFromLowestPriceByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::printHouses()
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printHousesByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::printFlats()
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printFlatsByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::printByPriceRange(double fromPrice, double toPrice)
{
     if(toPrice - fromPrice < 0){
        throw std::invalid_argument ("difference between fromPrice and toPrice must be > 0");
        }

    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printByPriceRangeByVip(fromPrice,toPrice);
    std::cout<<std::endl;
}

void HelpfulBroker::printEstatesByTown(char *townName){
    if(townName[0] == '\0'){
        throw std::invalid_argument ("townName shouldn't be empty name");
    }

    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printEstatesByTownByVip(townName);
    std::cout<<std::endl;
}

void HelpfulBroker::printBySpaceRange(double fromSize, double toSize)
{
    if(toSize - fromSize < 0){
        throw std::invalid_argument ("difference between fromSize and toSize must be > 0");
    }

    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.printBySpaceRangeByVip(fromSize,toSize);
    std::cout<<std::endl;
}
