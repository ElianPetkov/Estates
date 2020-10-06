#include <string.h>
#include <iostream>
#include "flat.h"
#include <cassert>
#include "Constants.h"
Flat::Flat():Estate(),rooms(1),floor(1) {}
Flat::Flat(const char* typeOfEstate ,const char *town,const char *offerType,const char*addr,const char*owner,double price,double space,int rooms,int floor):Estate(typeOfEstate,town,offerType,addr,owner,price,space)
{
    assert(rooms > 0 && "rooms should be more than 0");
    this->rooms=rooms;
    assert(floor > 0 && "floor should be bigger than 0");
    this->floor=floor;
}
void Flat::Copy(const Flat &flat)
{
    this->rooms=flat.rooms;
    this->floor=flat.floor;
}

void Flat::print()const
{
    Estate::print();
    std::cout<<numberOfRooms<<" "<<rooms<<std::endl;
    std::cout<<numberOfFloors<<" "<<floor<<std::endl;
}

void Flat::addCharacteristicsToEstate()
{
    Estate::addCharacteristicsToEstate("Flat");

    std::cout<<numberOfRooms<<" ";
    int rooms;
    std::cin>>rooms;
    if(rooms <= 0)
    {
        throw std::invalid_argument ("rooms should be more than 0");
    }
    this->rooms = rooms;

    std::cout<<"Floor of the estate:"<<" ";
    int floor;
    std::cin>>floor;
    if(floor <= 0)
    {
        throw std::invalid_argument ("rooms should be bigger than 0");
    }
    this->floor=floor;
    std::cin.ignore();
}


void Flat::setRooms(int room)
{
    this->rooms=room;
}

void Flat::setFloors(int floor)
{
    this->floor=floor;
}

int Flat::getFloor()const
{
    return floor;
}

int Flat::getRooms()const
{
    return rooms;
}

Flat* Flat::Clone()const
{
    return new Flat(*this);
}


