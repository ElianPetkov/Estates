#include <iostream>
#include "RealEstate.h"
#include <string.h>
#include "DishonestBroker.h"
#include <cassert>
#include "Constants.h"

using namespace std;
DishonestBroker::DishonestBroker():listOfEstates(),name(nullptr),percentage(0) {}
/*
* constructor for Dishonest broker with 3 arguments
* listOfEstate : RealEstate type parameter with list of Estates
* name : the name of the broker can't be empty
* percentage : the percentages of the broker which are added to the estate value , can't be 0
*/
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
/*
* This function print all the information about Simple broker information with the estate list and the changed price of the estates
*/
void DishonestBroker::print() const
{
    std::cout<<dishonestBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.print();
    std::cout<<std::endl;
}
/*
* Print all estates of the type given as argument in ascending order by price
* const char* typeOfEstate : can be 3 different values (Plot,House,Flat)
*/
void DishonestBroker:: printEstateFromLowestPriceByType(const char* typeOfEstate)
{
    std::cout<<simpleBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printEstatesLowestPriceByVipAndType(typeOfEstate);
    std::cout<<std::endl;
}
/*
* Print all estates in ascending order by price
*/
void DishonestBroker::printEstatesFromLowestPrice()
{
    std::cout<<dishonestBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printEstatesFromLowestPrice();
    std::cout<<std::endl;
}

/*
* Print all estates in ascending order in the given range
* double fromPrice : is the lower price
* double toPrice: is the max price
*/
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
/*
* Print all estates from the given town
*/
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
/*
* Print all estates in the between yard range
* double fromSize : is the lower size of the yard
* double toSize: is the bigger size of the yard
*/
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
