#include <string.h>
#include <iostream>
#include "flat.h"
#include <cassert>
#include "Constants.h"
Flat::Flat():Estate(),rooms(1),floor(1) {}
/*
* Flat constructor
* rooms : initialize the number of the rooms in the flat , can't be 0 or negative number
* floor : initialize the floor of the flat , can't be 0 or negative number
*/
Flat::Flat(const char* typeOfEstate ,const char *town,const char *offerType,const char*addr,const char*owner,double price,double space,int rooms,int floor):Estate(typeOfEstate,town,offerType,addr,owner,price,space)
{
    assert(rooms > 0 && errorMessageForRooms);
    this->rooms=rooms;
    assert(floor > 0 && errorMessageForFloors);
    this->floor=floor;
}
void Flat::Copy(const Flat &flat)
{
    this->rooms=flat.rooms;
    this->floor=flat.floor;
}
/*
* print all of the information for the estate
*/
void Flat::print()const
{
    Estate::print();
    std::cout<<numberOfRooms<<emptyString<<rooms<<std::endl;
    std::cout<<numberOfFloors<<emptyString<<floor<<std::endl;
}
/*
* this function initialize the Flat properties using the console
*/
void Flat::addCharacteristicsToEstate(const char *)
{
    Estate::addCharacteristicsToEstate(flat);

    std::cout<<numberOfRooms<<emptyString;
    int rooms;
    std::cin>>rooms;
    if(rooms <= 0)
    {
        throw std::invalid_argument (errorMessageForRooms);
    }
    this->rooms = rooms;

    std::cout<<"Floor of the estate:"<<emptyString;
    int floor;
    std::cin>>floor;
    if(floor <= 0)
    {
        throw std::invalid_argument (errorMessageForFloors);
    }
    this->floor=floor;
    std::cin.ignore();
}

Flat* Flat::Clone()const
{
    return new Flat(*this);
}


