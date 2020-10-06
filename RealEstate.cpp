#include <string.h>
#include<iostream>
#include"RealEstate.h"
#include "Estate.h"
#include <cassert>
#include "Constants.h"
using namespace std;
RealEstates::RealEstates():capacity(10),current(0),estates(nullptr)
{
    this->estates=new Estate*[capacity];
}
RealEstates::RealEstates(Estate** estates)
{
    capacity=10;
    current=0;
    this->estates=new Estate*[capacity];
    assert(this->estates != nullptr);
}
void RealEstates::Copy(const RealEstates &estate)
{

    this->current=estate.current;
    this->capacity=estate.capacity;
    this->estates=new Estate*[capacity];
    assert(this->estates!=nullptr);
    for(int i=0; i<current; i++)
    {
        estates[i]=estate.estates[i]->Clone();
    }
}
RealEstates::RealEstates(const RealEstates &estate)
{
    Copy(estate);
}
void RealEstates::Erase()
{
    delete [] estates;
}
RealEstates &RealEstates::operator=(const RealEstates &estate)
{
    if(this != &estate)
    {
        Erase();
        Copy(estate);
    }
    return *this;
}
void RealEstates::print()const
{
    if(current==0)
    {
        cout<<empty;
    }

    for(int i=0; i<current; i++)
    {
        cout<<informationForEstate<<endl;
        estates[i]->print();
    }

}
void RealEstates::resize()
{
    Estate** temporaryEstate=estates;
    capacity*=2;
    estates=new Estate*[capacity];
    assert(this->estates!=nullptr);
    for(int i=0; i<current; i++)
    {
        estates[i]=temporaryEstate[i];
    }
    delete [] temporaryEstate;
}

void RealEstates::addEstate(Estate* estate)
{
    if(current==capacity)
    {
        resize();
    }
    estates[current]=estate;
    current++;

}
void RealEstates::removeEstate(Estate* estate)
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

RealEstates* RealEstates::Clone()const
{
    return new RealEstates(*this);
}
void RealEstates::printHousesFromLowestPrice()const
{
    if(current==0)
    {
        cout<<empty;
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
                        Estate* temporaryEstate=estates[i]->Clone();
                        estates[i]=estates[j]->Clone();
                        estates[j]=temporaryEstate->Clone();
                    }
                }
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(estates[i]->getYard()>0)
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }

}

Estate *RealEstates :: getEstateByPosition(int position)
{
    return this->estates[position]->Clone();
}

void RealEstates::newPrice(double newPrice)
{
    for(int i=0; i<current; i++)
    {
        estates[i]->Estate::setPrice(newPrice);
    }
}

void RealEstates::printFlatsFromLowestPrice()const
{
    if(current==0)
    {
        cout<<empty;
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
                        Estate* temporaryEstate=estates[i]->Clone();
                        estates[i]=estates[j]->Clone();
                        estates[j]=temporaryEstate->Clone();
                    }
                }
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(estates[i]->getFloor()>0)
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::printEstatesFromLowestPrice()const
{
    if(current==0)
    {
        cout<<empty;
    }
    for (int i = 0; i < current ; i++)
    {
        for (int j = i + 1; j < current; j++)
        {
            if(estates[i]->getPrice()>estates[j]->getPrice())
            {
                Estate *temporaryEstate=estates[i]->Clone();
                estates[i]=estates[j]->Clone();
                estates[j]=temporaryEstate->Clone();
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        cout<<informationForEstate<<endl;
        estates[i]->print();
    }
}

void RealEstates::printHouses()const
{
    for(int i=0; i<current; i++)
    {
        if(estates[i]->getYard()>0)
        {
            cout<<informationForEstate<<endl;
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
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::printByPriceRange(double price1,double price2)const
{
    if(current==0)
    {
        cout<<empty;
    }

    for(int i=0; i<current; i++)
    {
        if(estates[i]->getPrice()>=price1 && estates[i]->getPrice()<=price2)
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::printEstatesByTown(char * town)const
{
    if(current==0)
    {
        cout<<empty;
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTown(),town))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::printBySpaceRange(double fromSize,double toSize)const
{
    if(current==0)
    {
        cout<<empty;
    }

    for(int i=0; i<current; i++)
    {
        if(estates[i]->getSpace()>fromSize&&estates[i]->getSpace()<toSize)
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
}
void RealEstates::printEstatesByVip()const
{
    if(current==0)
    {
        cout<<empty;
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),vip)||!strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::printHousesFromLowestPriceByVip()const
{
    if(current==0)
    {
        cout<<empty;
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),vip)||!strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            cout<<informationForEstate<<endl;
            if(estates[i]->getYard()>0)
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }

    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            if(estates[i]->getYard()>0)
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }
}

void RealEstates::printFlatsFromLowestPriceByVip()const
{
    if(current==0)
    {
        cout<<empty;
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),vip)||!strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            cout<<informationForEstate<<endl;
            if(estates[i]->getFloor()>0)
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }

    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            if(estates[i]->getFloor()>0)
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }
}
void RealEstates::printEstatesFromLowestPriceByVip()const
{
    if(current==0)
    {
        cout<<empty;
    }

    for (int i = 0; i < current ; i++)
    {
        for (int j = i + 1; j < current; j++)
        {
            if(estates[i]->getPrice()>estates[j]->getPrice())
            {
                Estate *temporaryEstate=estates[i]->Clone();
                estates[i]=estates[j]->Clone();
                estates[j]=temporaryEstate->Clone();
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),vip)||!strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
}
void RealEstates::printHousesByVip()const
{

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),vip)||!strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            if(estates[i]->getYard()>0)
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            if(estates[i]->getYard()>0)
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }
}
void RealEstates::printFlatsByVip()const
{

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),vip)||!strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            if(estates[i]->getFloor()>0)
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            if(estates[i]->getFloor()>0)
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }
}

void RealEstates::printByPriceRangeByVip(double fromPrice,double toPrice)const
{
    if(current==0)
    {
        cout<<empty;
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),vip)||!strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            if(estates[i]->getPrice()>=fromPrice && estates[i]->getPrice()<=toPrice)
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            if(estates[i]->getPrice()>=fromPrice && estates[i]->getPrice()<=toPrice)
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }
}
void RealEstates::printEstatesByTownByVip(char* town)const
{
    if(current==0)
    {
        cout<<empty;
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),vip)||!strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            if(!strcmp(estates[i]->getTown(),town))
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            if(!strcmp(estates[i]->getTown(),town))
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }
}

void RealEstates::printBySpaceRangeByVip(double fromSize,double toSize)const
{
    if(current==0)
    {
        cout<<empty;
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),vip)||!strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            if(estates[i]->getSpace()>fromSize && estates[i]->getSpace()<toSize)
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getTypeOfEstate(),vip))
        {
            if(estates[i]->getSpace()>fromSize && estates[i]->getSpace()<toSize)
            {
                cout<<informationForEstate<<endl;
                estates[i]->print();
            }
        }
    }
}
