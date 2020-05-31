#include <iostream>
#include "RegImot.h"
#include <string.h>
#include "HelpfulBroker.h"
HelpfulBroker::HelpfulBroker():name(nullptr),percentage(0),listOfEstates() {}
HelpfulBroker::HelpfulBroker(Estate **estates,RealEstates listOfEstates,const char * name,double percentage)
{
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->percentage=percentage;
    this->listOfEstates=listOfEstates;
    this->listOfEstates.NewPrice(percentage);

}
void HelpfulBroker::Copy(const HelpfulBroker & x)
{
    this->name=new char[strlen(x.name)+1];
    strcpy(this->name,x.name);
    this->percentage=x.percentage;
    this->listOfEstates=x.listOfEstates;
}
HelpfulBroker::HelpfulBroker(const HelpfulBroker & x)
{
    Copy(x);
}
void HelpfulBroker::Erase()
{
    delete [] name;
}
HelpfulBroker::~HelpfulBroker()
{
    Erase();
}
HelpfulBroker & HelpfulBroker:: operator=(const HelpfulBroker & x)
{
    if(this!=&x)
    {
        Erase();
        Copy(x);
    }
    return *this;
}
void HelpfulBroker::print()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.print();
    std::cout<<std::endl;
}

HelpfulBroker * HelpfulBroker:: Clone()const
{
    return new HelpfulBroker(*this);
}

void HelpfulBroker::PrintByVip()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintByVip();
    std::cout<<std::endl;
}


void HelpfulBroker::ByVip()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.ByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::PrintFlatsFromLowestPriceByVip()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintFlatsFromLowestPriceByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::PrintEstatesFromLowestPriceByVip()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintEstatesFromLowestPriceByVip();
    std::cout<<std::endl;
}
void HelpfulBroker::PrintHousesByVip()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintHousesByVip();
    std::cout<<std::endl;
}
void HelpfulBroker::PrintFlatsByVip()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintFlatsByVip();
    std::cout<<std::endl;
}
void HelpfulBroker::PrintByPriceRangeByVip(double price1,double price2)const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintByPriceRangeByVip(price1,price2);
    std::cout<<std::endl;
}
void HelpfulBroker::PrintEstatesByTownByVip(char * Town)const
        {
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintEstatesByTownByVip(Town);
    std::cout<<std::endl;
}
void HelpfulBroker::PrintBySpaceRangeByVip(double size1,double size2)const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    listOfEstates.PrintBySpaceRangeByVip(size1,size2);
    std::cout<<std::endl;
}

