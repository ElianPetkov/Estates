#include <iostream>
#include "RealEstate.h"
#include <string.h>
#include "SimpleBroker.h"
#include <cassert>
#include "Constants.h"

SimpleBroker::SimpleBroker():listOfEstates(),name(nullptr),percentage(0) {}
SimpleBroker::SimpleBroker(RealEstates listOfEstates,const char* name,double percentage)
{
    assert(name != nullptr && "name: requires non-null argument");
    assert(percentage > 0 && "percentages: requires value > 0");

    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->percentage=percentage;
    this->listOfEstates=listOfEstates;
    this->listOfEstates.newPrice(percentage);
}

void SimpleBroker::Copy(const SimpleBroker &broker)
{
    this->name=new char[strlen(broker.name)+1];
    strcpy(this->name,broker.name);
    this->percentage=broker.percentage;
    this->listOfEstates=broker.listOfEstates;

}

SimpleBroker::SimpleBroker(const SimpleBroker &broker)
{
    Copy(broker);
}

void SimpleBroker::Erase()
{
    delete [] name;
}

SimpleBroker::~SimpleBroker()
{
    Erase();
}

SimpleBroker& SimpleBroker::operator=(const SimpleBroker &broker)
{
    if(this != &broker)
    {
        Erase();
        Copy(broker);
    }
    return *this;
}

void SimpleBroker::print()const
{
    std::cout<<simpleBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<emptyString<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.print();
    std::cout<<std::endl;
}
void SimpleBroker::printEstateFromLowestPriceByType(const char* typeOfEstate)
{
    std::cout<<simpleBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<emptyString<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printEstatesByTypeAndLowestPrice(typeOfEstate);
    std::cout<<std::endl;
}

void SimpleBroker::printEstatesFromLowestPrice()
{
    std::cout<<simpleBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<emptyString<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printEstatesFromLowestPrice();
    std::cout<<std::endl;
}



void SimpleBroker::printByPriceRange(double fromPrice, double toPrice)
{
    if(toPrice-fromPrice<0){
        throw std::invalid_argument ("difference between fromPrice and toPrice must be > 0");
    }

    std::cout<<simpleBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<emptyString<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printByPriceRange(fromPrice,toPrice);
    std::cout<<std::endl;
}

void SimpleBroker::printEstatesByTown(char *townName)
{
    if(townName[0] == '\0'){
        throw std::invalid_argument ("townName should not be empty name");
    }

    std::cout<<simpleBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<emptyString<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printEstatesByTown(townName);
    std::cout<<std::endl;
}

void SimpleBroker::printBySpaceRange(double fromSize,double toSize)
{
    if(toSize-fromSize<0){
        throw std::invalid_argument ("difference between fromSize and toSize must be > 0");
    }

    std::cout<<simpleBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<emptyString<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printBySpaceRange(fromSize, toSize);
    std::cout<<std::endl;
}
