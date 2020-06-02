#include <string.h>
#include <iostream>
#include "House.h"
#include <cassert>
House::House():Estate(),rooms(1),floors(1),yard(1) {}
House::House(const char *town,const char *TypeOfEstate,const char*addr,const char*owner,double price,double space,int rooms,int floor):Estate(town,TypeOfEstate,addr,owner,price,space)
{
    assert(rooms > 0 && "rooms should be more than 0");
    this->rooms=rooms;
    assert(floors > 0 && "floors should be more than 0");
    this->floors=floors;
    assert(yard > 0 && "yard should be more than 0 square metters");
    this->yard=yard;
}

void House::Copy(const House & x)
{
    this->rooms=x.rooms;
    this->floors=x.floors;
    this->yard=x.yard;
}

House::House(const House & x):Estate(x)
{
    Copy(x);
}

House & House::operator=(const House & x)
{
    if(this!=&x)
    {
        Estate::operator=(x);
        Copy(x);
    }
    return *this;
}

void House::print()const
{
    Estate::print();
    std::cout<<"Rooms of the estate:"<<" "<<rooms<<std::endl;
    std::cout<<"Number of floors:"<<" "<<floors<<std::endl;
    std::cout<<"Square meters of the yard:"<<" "<<yard<<std::endl;
}

void House::addCharacteristicsToEstate()
{
    Estate::addCharacteristicsToEstate();
    std::cout<<"Square meters of the yard:"<<" ";
    int yard;
    std::cin>>yard;
    if(yard <= 0)
    {
        throw std::invalid_argument ("yard should be bigger than 0 square meters");
    }
    this->yard=yard;

    std::cout<<"Number of rooms of the estate:"<<" ";
    int rooms;
    std::cin>>rooms;
    if(rooms <= 0)
    {
        throw std::invalid_argument ("house should have more than 0 rooms");
    }
    this->rooms=rooms;

    std::cout<<"Number of floors of the estate:"<<" ";
    int floors;
    std::cin>>floors;
    if(floors <= 0)
    {
        throw std::invalid_argument ("house should have more than 0 floors");
    }
    std::cin.ignore();
    this->floors=floors;
}

House * House::Clone()const
{
    return new House(*this);
}
