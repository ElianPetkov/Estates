#include <string.h>
#include<iostream>
#include"RegImot.h"
#include "Imot.h"
#include <cassert>
using namespace std;
RealEstates::RealEstates():capacity(10),current(0),estates(nullptr)
{
    this->estates=new Estate*[capacity];
}
RealEstates::RealEstates(Estate **estates)
{

    capacity=10;
    current=0;
    this->estates=new Estate*[capacity];
    assert(this->estates!=nullptr);
}
void RealEstates::Copy(const RealEstates & x)
{

    this->current=x.current;
    this->capacity=x.capacity;
    this->estates=new Estate*[capacity];
    assert(this->estates!=nullptr);
    for(int i=0; i<current; i++)
    {
        estates[i]=x.estates[i]->Clone();
    }
}
RealEstates::RealEstates(const RealEstates & x)
{
    Copy(x);
}
void RealEstates::Erase()
{
    delete [] estates;
}
RealEstates&  RealEstates::operator=(const RealEstates & x)
{
    if(this!=&x)
    {
        Erase();
        Copy(x);
    }
    return *this;
}
void RealEstates::print()const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<current; i++)
    {
        cout<<"Information about the estate:"<<endl;
        estates[i]->print();
    }

}
void RealEstates::resize()
{

    Estate **tmp=estates;
    capacity*=2;
    estates=new Estate*[capacity];
    assert(this->estates!=nullptr);
    for(int i=0; i<current; i++)
    {
        estates[i]=tmp[i];
    }
    delete [] tmp;


}
void RealEstates::add(Estate* estate)
{
    if(current==capacity)
    {
        resize();
    }
    estates[current]=estate;
    current++;

}
void RealEstates::remove(Estate *estate)
{

    int index=-1;
    for(int i = 0; i < current; ++i)
    {
        if(!strcmp(estates[i]->getOwner(),estate->getOwner()) && !strcmp(estates[i]->getAddr(),estate->getAddr()) )
        {
            index=i;
            break;
        }
    }
    if(index!=-1)
    {
        for(int i=index; i<current-1; i++)
        {
            estates[i]=estates[i+1];
        }
        delete estates[current-1] ;
        estates [current-1]=nullptr;
        current--;
    }
}

RealEstates::~RealEstates()
{
    Erase();
}
int RealEstates::getCurrent()
{
    return current;
}
RealEstates * RealEstates::Clone()const
{
    return new RealEstates(*this);
}
void RealEstates::newPrice(int estate)
{
    for(int i=0; i<current; i++)
    {
        estates[i]->Estate::setPrice(estates[i]->getPrice()+(estates[i]->getPrice()*estate)/100);
    }
}
void RealEstates::printHousesFromLowestPrice()const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for (int i = 0; i < current ; i++)
    {
        if(estates[i]->getYard()>0)
        {
            for (int j = i + 1; j < current; j++)
            {
                {

                    if(estates[i]->getPrice()>estates[j]->getPrice())
                    {
                        Estate *b;
                        b=estates[i]->Clone();
                        estates[i]=estates[j]->Clone();
                        estates[j]=b->Clone();
                    }
                }
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(estates[i]->getYard()>0)
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }

}
void RealEstates::newPrice(double x)
{
    for(int i=0; i<current; i++)
    {
        estates[i]->Estate::setPrice(x);
    }
}

void RealEstates::printFlatsFromLowestPrice()const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for (int i = 0; i < current ; i++)
    {
        if(estates[i]->getFloor()>0)
        {
            for (int j = i + 1; j < current; j++)
            {
                if(estates[j]->getFloor()>0)
                {

                    if(estates[i]->getPrice()>estates[j]->getPrice())
                    {
                        Estate *b;
                        b=estates[i]->Clone();
                        estates[i]=estates[j]->Clone();
                        estates[j]=b->Clone();
                    }
                }
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(estates[i]->getFloor()>0)
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::printEstatesFromLowestPrice()const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for (int i = 0; i < current ; i++)
    {


        for (int j = i + 1; j < current; j++)
        {


            if(estates[i]->getPrice()>estates[j]->getPrice())
            {
                Estate *b;
                b=estates[i]->Clone();
                estates[i]=estates[j]->Clone();
                estates[j]=b->Clone();
            }

        }

    }
    for(int i=0; i<current; i++)
    {

        cout<<"Information about the estate:"<<endl;
        estates[i]->print();
    }
}

void RealEstates::printHouses()const
{

    for(int i=0; i<current; i++)
    {
        if(estates[i]->getYard()>0)
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }

}

void RealEstates::printFlats()const
{

    for(int i=0; i<current; i++)
    {
        if(estates[i]->getYard()>0)
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }

}

void RealEstates::printByPriceRange(double price1,double price2)const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<current; i++)
    {
        if(estates[i]->getPrice()>=price1 && estates[i]->getPrice()<=price2)
        {

            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::printEstatesByTown(char * Town)const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTown(),Town))
        {

            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::printBySpaceRange(double size1,double size2)const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<current; i++)
    {
        if(estates[i]->getSpace()>size1&&estates[i]->getSpace()<size2)
        {

            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
}
void RealEstates::PrintByVip()const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),"vip")||!strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }

}

void RealEstates::printHousesFromLowestPriceByVip()const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),"vip")||!strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            cout<<"Information about the estate:"<<endl;
            if(estates[i]->getYard()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }

    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            if(estates[i]->getYard()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
}

void RealEstates::printFlatsFromLowestPriceByVip()const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),"vip")||!strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            cout<<"Information about the estate:"<<endl;
            if(estates[i]->getFloor()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }

    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            if(estates[i]->getFloor()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
}
void RealEstates::printEstatesFromLowestPriceByVip()const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for (int i = 0; i < current ; i++)
    {


        for (int j = i + 1; j < current; j++)
        {


            if(estates[i]->getPrice()>estates[j]->getPrice())
            {
                Estate *b;
                b=estates[i]->Clone();
                estates[i]=estates[j]->Clone();
                estates[j]=b->Clone();
            }

        }

    }
    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),"vip")||!strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
}
void RealEstates::printHousesByVip()const
{

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),"vip")||!strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            if(estates[i]->getYard()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            if(estates[i]->getYard()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }


}
void RealEstates::printFlatsByVip()const
{

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),"vip")||!strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            if(estates[i]->getFloor()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            if(estates[i]->getFloor()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
}

void RealEstates::printByPriceRangeByVip(double price1,double price2)const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),"vip")||!strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            if(estates[i]->getPrice()>=price1 && estates[i]->getPrice()<=price2)
            {

                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            if(estates[i]->getPrice()>=price1 && estates[i]->getPrice()<=price2)
            {

                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
}
void RealEstates::printEstatesByTownByVip(char * Town)const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),"vip")||!strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            if(!strcmp(estates[i]->getTown(),Town))
            {

                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            if(!strcmp(estates[i]->getTown(),Town))
            {

                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }

}

void RealEstates::printBySpaceRangeByVip(double size1,double size2)const
{
    if(current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),"vip")||!strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            if(estates[i]->getSpace()>size1&&estates[i]->getSpace()<size2)
            {

                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),"Vip"))
        {
            if(estates[i]->getSpace()>size1&&estates[i]->getSpace()<size2)
            {

                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
}
