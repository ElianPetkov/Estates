#include <iostream>
#include "RegImot.h"
#include <string.h>
#include "HelpfulBroker.h"
HelpfulBroker::HelpfulBroker():name(nullptr),percentage(0),y() {}
HelpfulBroker::HelpfulBroker(Estate **estates,RealEstates y,const char * name,double percentage)
{
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->percentage=percentage;
    this->y=y;
    this->y.NewPrice(percentage);

}
void HelpfulBroker::Copy(const HelpfulBroker & x)
{
    this->name=new char[strlen(x.name)+1];
    strcpy(this->name,x.name);
    this->percentage=x.percentage;
    this->y=x.y;
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
    y.print();
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
    y.PrintByVip();
    std::cout<<std::endl;
}


void HelpfulBroker::LowestPrintHouseByVip()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.LowestPrintHouseByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::LowestPrintFlatByVip()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.LowestPrintFlatByVip();
    std::cout<<std::endl;
}

void HelpfulBroker::LowestPrintByVip()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.LowestPrintByVip();
    std::cout<<std::endl;
}
void HelpfulBroker::PrintHouseByVip()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintHouseByVip();
    std::cout<<std::endl;
}
void HelpfulBroker::PrintFlatByVip()const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintFlatByVip();
    std::cout<<std::endl;
}
void HelpfulBroker::PrintByPriceByVip(double price1,double price2)const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintByPriceByVip(price1,price2);
    std::cout<<std::endl;
}
void HelpfulBroker::PrintTownByVip(char * Town)const
        {
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintTownByVip(Town);
    std::cout<<std::endl;
}
void HelpfulBroker::PrintBySpaceByVip(double size1,double size2)const
{
    std::cout<<"Helpful Broker:"<<std::endl;
    std::cout<<"Broker's name:"<<name<<std::endl<<"Percentage for sales"<<" "<<percentage<<std::endl;
    std::cout<<"Estates:";
    y.PrintBySpaceByVip(size1,size2);
    std::cout<<std::endl;
}

