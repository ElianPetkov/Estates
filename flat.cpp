#include <string.h>
#include<iostream>
#include"flat.h"
#include<cassert>
Flat::Flat():Estate(),rooms(1),floor(1) {}
Flat::Flat(const char *town,const char *TypeOfEstate,const char*addr,const char*owner,double price,double space,int rooms,int floor):Estate(town,TypeOfEstate,addr,owner,price,space)
{
    this->rooms=rooms;
    this->floor=floor;
}
void Flat::Copy(const Flat & x)
{

    this->rooms=x.rooms;
    this->floor=x.floor;
}

void Flat::print()const
{

    Estate::print();

    std::cout<<"Number of rooms:"<<" "<<rooms<<std::endl;
    std::cout<<"Floor of the estate:"<<" "<<floor<<std::endl;
}

void Flat::addCharacteristicsToEstate()
{
    Estate::addCharacteristicsToEstate();
    std::cout<<"Number of Rooms "<<" ";
    std::cin>>rooms;
    std::cout<<"Floor of the estate"<<" ";
    std::cin>>floor;
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

Flat * Flat::Clone()const
{
    return new Flat(*this);
}


