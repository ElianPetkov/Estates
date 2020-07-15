#include <iostream>
#include "RealEstate.h"
#include <string.h>
#include "DishonestBroker.h"
#include <cassert>
#include "Constants.h"

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

void DishonestBroker::Copy(const DishonestBroker& broker)
{
    this->name=new char[strlen(broker.name)+1];
    strcpy(this->name,broker.name);
    this->percentage=broker.percentage;
    this->listOfEstates=broker.listOfEstates;
}

DishonestBroker::DishonestBroker(const DishonestBroker& broker)
{
    Copy(broker);
}

void DishonestBroker::Erase()
{
    delete [] name;
}

DishonestBroker::~DishonestBroker()
{
    Erase();
}

DishonestBroker &DishonestBroker:: operator=(const DishonestBroker & broker)
{
    if(this != &broker)
    {
        Erase();
        Copy(broker);
    }
    return *this;
}

void DishonestBroker::print() const
{
    std::cout<<dishonestBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.print();
    std::cout<<std::endl;
}

void DishonestBroker::printHousesFromLowestPrice()
{
    std::cout<<dishonestBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printHousesFromLowestPrice();
    std::cout<<std::endl;
}

void DishonestBroker::printFlatsFromLowestPrice()
{
    std::cout<<dishonestBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printFlatsFromLowestPrice();
    std::cout<<std::endl;
}

void DishonestBroker::printEstatesFromLowestPrice()
{
    std::cout<<dishonestBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printEstatesFromLowestPrice();
    std::cout<<std::endl;
}

void DishonestBroker::printHouses()
{
    std::cout<<dishonestBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printHouses();
    std::cout<<std::endl;
}

void DishonestBroker::printFlats()
{
    std::cout<<dishonestBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printFlats();
    std::cout<<std::endl;
}

void DishonestBroker::printByPriceRange(double fromPrice,double toPrice)
{
    if(toPrice-fromPrice<0)
    {
        throw std::invalid_argument ("difference between fromPrice and toPrice must be > 0");
    }

    std::cout<<dishonestBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printByPriceRange(fromPrice,toPrice);
    std::cout<<std::endl;
}

void DishonestBroker::printEstatesByTown(char* townName)
{
    if(townName[0] == '\0')
    {
        throw std::invalid_argument ("townName shouldn't be empty name");
    }

    std::cout<<dishonestBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printEstatesByTown(townName);
    std::cout<<std::endl;
}

void DishonestBroker::printBySpaceRange(double fromSize,double toSize)
{
    if(toSize-fromSize<0)
    {
        throw std::invalid_argument ("difference between fromSize and toSize must be > 0");
    }

    std::cout<<dishonestBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printBySpaceRange(fromSize,toSize);
    std::cout<<std::endl;
}
char* DishonestBroker:: getName()const
{
    return name;
}
double DishonestBroker::getPercentages()const
{
    return percentage;
}
