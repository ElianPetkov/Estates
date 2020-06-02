#include <string.h>
#include<iostream>
#include"House.h"
House::House():Estate(),rooms(1),floors(1),yard(1){}
House::House(const char *town,const char *TypeOfEstate,const char*addr,const char*owner,double price,double space,int rooms,int floor):Estate(town,TypeOfEstate,addr,owner,price,space)
{
    this->rooms=rooms;
    this->floors=floors;
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
    std::cout<<"square meters of the yard:"<<" "<<yard<<std::endl;
}

void House::addCharacteristicsToEstate()
{
    Estate::addCharacteristicsToEstate();
    std::cout<<"square meters of the yard:"<<" ";
    std::cin>>yard;
    std::cout<<"Number of rooms of the estate:"<<" ";
    std::cin>>rooms;
    std::cout<<"Number of floors of the estate"<<" ";
    std::cin>>floors;
    std::cin.ignore();
}

House * House::Clone()const
{
    return new House(*this);
}
