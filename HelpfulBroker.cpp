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

void HelpfulBroker::Print()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.print();
    std::cout<<std::endl;
}

void HelpfulBroker::print()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintByVip();
    std::cout<<std::endl;
}


void HelpfulBroker::PrintHousesFromLowestPrice()
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintHousesFromLowestPriceByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::PrintFlatsFromLowestPrice()
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintFlatsFromLowestPriceByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::PrintEstatesFromLowestPrice()
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintEstatesFromLowestPriceByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::PrintHouses()
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintHousesByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::PrintFlats()
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintFlatsByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::PrintByPriceRange(double fromPrice, double toPrice)
{
     if(toPrice - fromPrice < 0){
        throw std::invalid_argument ("difference between fromPrice and toPrice must be > 0");
        }

    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintByPriceRangeByVip(fromPrice,toPrice);
    std::cout<<std::endl;
}

void HelpfulBroker::PrintEstatesByTown(char *townName){
    if(townName[0] == '\0'){
        throw std::invalid_argument ("townName shouldn't be empty name");
    }

    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintEstatesByTownByVip(townName);
    std::cout<<std::endl;
}

void HelpfulBroker::PrintBySpaceRange(double fromSize, double toSize)
{
    if(toSize - fromSize < 0){
        throw std::invalid_argument ("difference between fromSize and toSize must be > 0");
    }

    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintBySpaceRangeByVip(fromSize,toSize);
    std::cout<<std::endl;
}
