#include <string.h>
#include <iostream>
#include "RealEstate.h"
#include <cassert>
#include "Constants.h"
Estate::Estate():town(nullptr),offerType(nullptr),addr(nullptr),owner(nullptr),space(0),price(0) {}
Estate::Estate(const char* typeOfEstate,const char *town,const char *offerType,const char*addr,const char*owner,double price,double space):price(price),space(space)
{
    assert(typeOfEstate != nullptr && "typeOfEstate is nullptr");
    assert(typeOfEstate[0] != '\0' && "typeOfEstate is empty string");
    this->typeOfEstate=new char[strlen(typeOfEstate)+1];
    strcpy(this->typeOfEstate,typeOfEstate);

    assert(town != nullptr && "town is nullptr");
    assert(town[0] != '\0' && "town is empty string");
    this->town=new char[strlen(town)+1];
    strcpy(this->town,town);

    assert(offerType != nullptr && "offerType is nullptr");
    assert(offerType[0] != '\0' && "offerType is an empty string");
    this->offerType=new char[strlen(offerType)+1];
    strcpy(this->offerType,offerType);

    assert(addr != nullptr && "addr is nullptr");
    assert(addr[0] != '\0' && "addr is empty string");
    this->addr=new char[strlen(addr)+1];
    strcpy(this->addr,addr);

    assert(owner != nullptr && "owner is nullptr");
    assert(owner[0] != '\0' && "owner is an empty string");
    this->owner=new char[strlen(owner)+1];
    strcpy(this->owner,owner);

}
void Estate::Copy(const Estate &estate)
{
    this->typeOfEstate=new char[strlen(estate.typeOfEstate)+1];
    assert(this->typeOfEstate != nullptr);
    strcpy(this->typeOfEstate,estate.typeOfEstate);

    this->town=new char[strlen(estate.town)+1];
    assert(this->town != nullptr);
    strcpy(this->town,estate.town);


    this->offerType=new char[strlen(estate.offerType)+1];
    assert(this->offerType != nullptr);
    strcpy(this->offerType,estate.offerType);

    this->addr=new char[strlen(estate.addr)+1];
    assert(this->addr != nullptr);
    strcpy(this->addr,estate.addr);

    this->owner=new char[strlen(estate.owner)+1];
    assert(this->owner != nullptr);
    strcpy(this->owner,estate.owner);

    price=estate.price;
    space=estate.space;
}
Estate::Estate(const Estate &estate)
{
    Copy(estate);
}
void Estate::Erase()
{
    delete [] offerType;
    offerType=nullptr;
    delete [] addr;
    addr=nullptr;
    delete [] owner;
    owner=nullptr;
}
Estate::~Estate()
{
    Erase();
}
Estate & Estate::operator =(const Estate &estate)
{
    if(this != &estate)
    {
        Erase();
        Copy(estate);
    }
    return *this;
}
void Estate::print()const
{
    std::cout<<"Town:"<<" "<<town<<std::endl;
    std::cout<<"Type of the Offert:"<<" "<<offerType<<std::endl;
    std::cout<<"Addres:"<<" "<<addr<<std::endl;
    std::cout<<"Name of the owner:"<<" "<<owner<<std::endl;
    std::cout<<"Price:"<<" "<<price<<std::endl;
    std::cout<<"Square meters of the estate:"<<" "<<space<<std::endl;
}
void Estate::addCharacteristicsToEstate(const char * typeOfEstate)
{

    this->typeOfEstate=new char[strlen(typeOfEstate)+1];
    strcpy(this->typeOfEstate,typeOfEstate);

    char buffer[1024];
    std::cout<<"Town:"<<" ";
    std::cin.getline(buffer,1024);
    if(buffer == nullptr)
    {
        throw std::invalid_argument ("town is nullptr");
    }
    if(buffer[0] == '\0')
    {
        throw std::invalid_argument ("town does not have a value");
    }
    this->town=new char[strlen(buffer)+1];
    strcpy(this->town,buffer);

    std::cout<<"Vip or Classic estate:"<<" ";
    do
    {
        std::cin.getline(buffer,1024);
    }
    while(strcmp(buffer,vip)&&strcmp(buffer,"Classic"));
    this->offerType=new char[strlen(buffer)+1];
    if(buffer == nullptr)
    {
        throw std::invalid_argument ("offerType is nullptr");
    }
    if(buffer[0] == '\0')
    {
        throw std::invalid_argument ("offerType does not have a value");
    }
    strcpy(this->offerType,buffer);

    std::cout<<"Addres of the estate:"<<" ";
    std::cin.getline(buffer,1024);
    this->addr=new char[strlen(buffer)+1];
    if(buffer == nullptr)
    {
        throw std::invalid_argument ("addr is nullptr");
    }
    if(buffer[0] == '\0')
    {
        throw std::invalid_argument ("addr does not have a value");
    }
    strcpy(this->addr,buffer);

    std::cout<<"Name of the owner:"<<" ";
    std::cin.getline(buffer,1024);
    if(buffer == nullptr)
    {
        throw std::invalid_argument ("owner is nullptr");
    }
    if(buffer[0] == '\0')
    {
        throw std::invalid_argument ("owner does not have a name");
    }
    this->owner=new char[strlen(buffer)+1];
    strcpy(this->owner,buffer);

    std::cout<<"Price of the estate:"<<" ";
    std::cin>>price;

    std::cout<<"Square meters of the estate:"<<" ";
    std::cin>>space;

    std::cin.ignore();
}

char* Estate::getAddr() const
{
    return addr;
}

char* Estate::getOwner() const
{
    return owner;
}

void Estate::setPrice(double percentagesFromAgent= 0)
{
    this->price=(this->price*percentagesFromAgent/100)+this->price;
}
double Estate::getPrice()const
{
    return price;
}

Estate* Estate::Clone ()const
{
    return new Estate(*this);
}

char* Estate::getTown()const
{
    return town;
}

double Estate::getSpace()const
{
    return space;
}

char* Estate::getOfferType()const
{
    return offerType;
}

char* Estate::getTypeOfEstate()const
{
    return typeOfEstate;
}
