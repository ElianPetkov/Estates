#include <string.h>
#include<iostream>
#include"RegImot.h"
#include<cassert>
Estate::Estate():town(nullptr),TypeOfEstate(nullptr),addr(nullptr),owner(nullptr),space(0),price(0) {}
Estate::Estate(const char *town,const char *TypeOfEstate,const char*addr,const char*owner,double price,double space):price(price),space(space)
{
    this->town=new char[strlen(town)+1];
    assert(this->town!=nullptr);
    strcpy(this->town,town);

    this->TypeOfEstate=new char[strlen(TypeOfEstate)+1];
    assert(this->TypeOfEstate!=nullptr);
    strcpy(this->TypeOfEstate,TypeOfEstate);

    this->addr=new char[strlen(addr)+1];
    assert(this->addr!=nullptr);
    strcpy(this->addr,addr);

    this->owner=new char[strlen(owner)+1];
    assert(this->owner!=nullptr);
    strcpy(this->owner,owner);

}
void Estate::Copy(const Estate&x)
{
    this->town=new char[strlen(x.town)+1];
    assert(this->town!=nullptr);
    strcpy(this->town,x.town);


    this->TypeOfEstate=new char[strlen(x.TypeOfEstate)+1];
    assert(this->TypeOfEstate!=nullptr);
    strcpy(this->TypeOfEstate,x.TypeOfEstate);

    this->addr=new char[strlen(x.addr)+1];
    assert(this->addr!=nullptr);
    strcpy(this->addr,x.addr);

    this->owner=new char[strlen(x.owner)+1];
    assert(this->owner!=nullptr);
    strcpy(this->owner,x.owner);

    price=x.price;
    space=x.space;
}
Estate::Estate(const Estate &x)
{
    Copy(x);
}
void Estate::Erase()
{
    delete [] TypeOfEstate;
    TypeOfEstate=nullptr;
    delete [] addr;
    addr=nullptr;
    delete [] owner;
    owner=nullptr;
}
Estate::~Estate()
{
    Erase();
}
Estate & Estate::operator =(const Estate & x)
{
    if(this!=&x)
    {
        Erase();
        Copy(x);
    }
    return *this;
}
void Estate::print()const
{
    std::cout<<"Town:"<<" "<<town<<std::endl;
    std::cout<<"Type of the Offert:"<<" "<<TypeOfEstate<<std::endl;
    std::cout<<"Addres:"<<" "<<addr<<std::endl;
    std::cout<<"Name of the owner:"<<" "<<owner<<std::endl;
    std::cout<<"Price:"<<" "<<price<<std::endl;
    std::cout<<"Square meters of the estate:"<<" "<<space<<std::endl;
}
void Estate::addCharacteristicsToEstate()
{
    char buffer[1024];

    std::cout<<"Town:"<<" ";
    std::cin.getline(buffer,1024);
    this->town=new char[strlen(buffer)+1];
    assert(this->town!=nullptr);
    strcpy(this->town,buffer);

    std::cout<<"Vip or Classic estate:"<<" ";
    do
    {
        std::cin.getline(buffer,1024);
    }
    while(strcmp(buffer,"Vip")&&strcmp(buffer,"Classic"));
    this->TypeOfEstate=new char[strlen(buffer)+1];
    assert(this->TypeOfEstate!=nullptr);
    strcpy(this->TypeOfEstate,buffer);

    std::cout<<"addres of the estate:"<<" ";
    std::cin.getline(buffer,1024);
    this->addr=new char[strlen(buffer)+1];
    assert(this->addr!=nullptr);
    strcpy(this->addr,buffer);

    std::cout<<"Name of the owner"<<" ";
    std::cin.getline(buffer,1024);
    this->owner=new char[strlen(buffer)+1];
    assert(this->owner!=nullptr);
    strcpy(this->owner,buffer);

    std::cout<<"Price of the estate:"<<" ";
    std::cin>>price;

    std::cout<<"square meters of the estate:"<<" ";
    std::cin>>space;

    std::cin.ignore();
}
const char* Estate::getAddr() const
{
    return addr;
}
const char* Estate::getOwner() const
{
    return owner;
}
void Estate::setPrice(double x)
{

    this->price=this->price+(this->price*x)/100.0;
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
char* Estate::GetTypeOfEstate()const
{
    return TypeOfEstate;
}
