#include <string.h>
#include <iostream>
#include "House.h"
#include <cassert>
#include "Constants.h"

House::House():Estate(),rooms(1),floors(1),yard(1) {}
/*
*House constructor
* rooms : initialize the number of the rooms in the house , can't be 0 or negative number
* floors : initialize the number of floors of the house , can't be 0 or negative number
* yard : initialize the yard size of the house , can't be 0 or negative number
*/
House::House(const char* typeOfEstate,const char *town,const char *offerType,const char*addr,const char*owner,double price,double space,int rooms,int floors):Estate(typeOfEstate,town,offerType,addr,owner,price,space)
{
    assert(rooms> 0 && "rooms should be more than 0");
    this->rooms=rooms;
    assert(floors> 0 && "floors should be more than 0");
    this->floors=floors;
    assert(space > 0 && "yard should be more than 0 square metters");
    this->yard=space;
}

void House::Copy(const House &house)
{
    this->rooms=house.rooms;
    this->floors=house.floors;
    this->yard=house.yard;
}

House::House(const House &house):Estate(house)
{
    Copy(house);
}

House & House::operator=(const House &house)
{
    if(this != &house)
    {
        Estate::operator=(house);
        Copy(house);
    }
    return *this;
}
/*
* print all of the information for the estate
*/
void House::print()const
{
    Estate::print();
    std::cout<<numberOfRooms<<emptyString<<rooms<<std::endl;
    std::cout<<numberOfFloors<<emptyString<<floors<<std::endl;
    std::cout<<squereMetersOfYard<<emptyString<<yard<<std::endl;
}
/*
* this function initialize the House properties
*/
void House::addCharacteristicsToEstate()
{
    Estate::addCharacteristicsToEstate(house);
    std::cout<<squereMetersOfYard<<emptyString;
    int yard;
    std::cin>>yard;
    if(yard <= 0)
    {
        throw std::invalid_argument ("yard should be bigger than 0 square meters");
    }
    this->yard=yard;

    std::cout<<numberOfRooms<<emptyString;
    int rooms;
    std::cin>>rooms;
    if(rooms <= 0)
    {
        throw std::invalid_argument ("house should have more than 0 rooms");
    }
    this->rooms=rooms;

    std::cout<<numberOfFloors<<emptyString;
    int floors;
    std::cin>>floors;
    if(floors <= 0)
    {
        throw std::invalid_argument ("house should have more than 0 floors");
    }
    std::cin.ignore();
    this->floors=floors;
}

House* House::Clone()const
{
    return new House(*this);
}
