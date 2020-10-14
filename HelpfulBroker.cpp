#include <iostream>
#include "RealEstate.h"
#include <string.h>
#include "HelpfulBroker.h"
#include <cassert>
#include "Constants.h"


HelpfulBroker::HelpfulBroker():name(nullptr),percentage(0),listOfEstates() {}
/*
* constructor for Helpful broker with 3 arguments
* listOfEstate : RealEstate type parameter with list of Estates
* name : the name of the broker can't be empty
* percentage : the percentages of the broker which are added to the estate value , can't be 0
*/
HelpfulBroker::HelpfulBroker(RealEstates listOfEstates, const char* name, double percentage)
{
    assert(name != nullptr && "name: requires non-null argument");
    assert(percentage > 0 && "percentages: requires value > 0");

    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->percentage=percentage;
    this->listOfEstates=listOfEstates;
    this->listOfEstates.newPrice(percentage);
}

void HelpfulBroker::Copy(const HelpfulBroker& broker)
{
    this->name=new char[strlen(broker.name)+1];
    strcpy(this->name,broker.name);
    this->percentage=broker.percentage;
    this->listOfEstates=broker.listOfEstates;
}

HelpfulBroker::HelpfulBroker(const HelpfulBroker& broker)
{
    Copy(broker);
}

void HelpfulBroker::Erase()
{
    delete [] name;
}

HelpfulBroker::~HelpfulBroker()
{
    Erase();
}

HelpfulBroker& HelpfulBroker:: operator=(const HelpfulBroker& broker)
{
    if(this!=&broker)
    {
        Erase();
        Copy(broker);
    }
    return *this;
}
/*
* This function print all the information about Simple broker information with the estate list and the changed price of the estates starting with the Vip estates first
*/
void HelpfulBroker::print()const
{
    std::cout<<helpfulBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<brokerName;
    listOfEstates.printEstatesByVip();
    std::cout<<std::endl;
}
/*
* Print all estates of the type given as argument in ascending order by price starting with the Vip estates first
* const char* typeOfEstate : can be 3 different values (Plot,House,Flat)
*/
void HelpfulBroker:: printEstateFromLowestPriceByType(const char* typeOfEstate)
{
    if(abs(strcmp(typeOfEstate,house) && abs(strcmp(typeOfEstate,flat) && abs(strcmp(typeOfEstate,house))))){
        throw std::invalid_argument ("does not match the 3 possible types of estate(Plot,House,Flat)");
    }
    std::cout<<simpleBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printEstatesLowestPriceByVipAndType(typeOfEstate);
    std::cout<<std::endl;
}
/*
* Print all estates in ascending order by price starting with the vip estates first
*/
void HelpfulBroker::printEstatesFromLowestPrice()
{
    std::cout<<helpfulBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printEstatesFromLowestPriceByVip();
    std::cout<<std::endl;
}
/*
* Print all estates in ascending order in the given range starting with the Vip estates first
* double fromPrice : is the lower price
* double toPrice: is the max price
*/
void HelpfulBroker::printByPriceRange(double fromPrice, double toPrice)
{
    if(toPrice-fromPrice<0)
    {
        throw std::invalid_argument ("difference between fromPrice and toPrice must be > 0");
    }

    std::cout<<helpfulBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printByPriceRangeByVip(fromPrice,toPrice);
    std::cout<<std::endl;
}
/*
* Print all estates from the given town starting with the Vip estate
*/
void HelpfulBroker::printEstatesByTown(char *townName)
{
    if(townName[0] == '\0')
    {
        throw std::invalid_argument (simpleBroker);
    }

    std::cout<<helpfulBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printEstatesByTownByVip(townName);
    std::cout<<std::endl;
}
/*
* Print all estates in the between yard range starting with the Vip estates
* double fromSize : is the lower size of the yard
* double toSize: is the bigger size of the yard
*/
void HelpfulBroker::printBySpaceRange(double fromSize, double toSize)
{
    if(toSize-fromSize<0)
    {
        throw std::invalid_argument ("difference between fromSize and toSize must be > 0");
    }

    std::cout<<helpfulBroker<<std::endl;
    std::cout<<brokerName<<name<<std::endl<<percentageForSales<<" "<<percentage<<std::endl;
    std::cout<<estates;
    listOfEstates.printBySpaceRangeByVip(fromSize,toSize);
    std::cout<<std::endl;
}

