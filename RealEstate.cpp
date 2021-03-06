#include <string.h>
#include<iostream>
#include"RealEstate.h"
#include "Estate.h"
#include <cassert>
#include "Constants.h"

using namespace std;
RealEstates::RealEstates():capacity(10),current(0),estates(nullptr)
{
    this->estates=new Estate*[10];
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
        cout<<emptyListWithEstates;
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
bool RealEstates::removeEstate(Estate* estate)
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
        return 1;
    }
    return 0;
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

void RealEstates::printEstatesByTypeAndLowestPrice(const char *typeOfEstate)const
{
        if(current==0)
    {
        cout<<emptyListWithEstates;
        return ;
    }

    sortEstatesByLowerPrice();
    printEstatesByType(typeOfEstate);

}

Estate* RealEstates :: getEstateByPosition(int position)
{
    Estate* estate = this->estates[position]->Clone();
    return estate;
}

void RealEstates::newPrice(double percentagesFromAgent)
{
    for(int i=0; i<current; i++)
    {
        estates[i]->Estate::setPrice(percentagesFromAgent);
    }
}

void RealEstates::printEstatesFromLowestPrice()const
{
    if(current==0)
    {
        cout<<emptyListWithEstates;
        return;
    }
    sortEstatesByLowerPrice();
    for(int i=0; i<current; i++)
    {
        cout<<informationForEstate<<endl;
        estates[i]->print();
    }
}

void RealEstates::printByPriceRange(double smallerPrice,double biggerPrice)const
{
    if(current==0)
    {
        cout<<emptyListWithEstates;
        return ;
    }

    for(int i=0; i<current; i++)
    {
        if(estates[i]->getPrice()>=smallerPrice && estates[i]->getPrice()<=biggerPrice)
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
        cout<<emptyListWithEstates;
        return;
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
        cout<<emptyListWithEstates;
        return ;
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

void RealEstates::printEstatesLowestPriceByVipAndType(const char* typeOfEstate)const
{
    sortEstatesByLowerPrice();
    printEstatesByTypeAndVip(typeOfEstate);
}

void RealEstates::printEstatesFromLowestPriceByVip()const
{
    sortEstatesByLowerPrice();
    printEstatesByVip();
}

void RealEstates::printByPriceRangeByVip(double fromPrice,double toPrice)const
{
    if(current==0)
    {
        cout<<emptyListWithEstates;
        return ;
    }

    for(int i=0; i<current; i++)
    {
        if(estates[i]->getPrice()>=fromPrice && estates[i]->getPrice()<=toPrice && (!strcmp(estates[i]->getOfferType(),vip)))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
    for(int i=0; i<current; i++)
    {
        if(estates[i]->getPrice()>=fromPrice && estates[i]->getPrice()<=toPrice && strcmp(estates[i]->getOfferType(),vip))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
}
void RealEstates::printEstatesByTownByVip(char* town)const
{
    if(current==0)
    {
        cout<<emptyListWithEstates;
        return ;
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getOfferType(),vip)&&(!strcmp(estates[i]->getTown(),town)))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTown(),town)&& strcmp(estates[i]->getOfferType(),vip))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::printBySpaceRangeByVip(double fromSize,double toSize)const
{
    if(current==0)
    {
        cout<<emptyListWithEstates;
        return ;
    }

    for(int i=0; i<current; i++)
    {
        if((estates[i]->getSpace()>fromSize && estates[i]->getSpace()<toSize)&&!strcmp(estates[i]->getOfferType(),vip))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
    for(int i=0; i<current; i++)
    {
        if((estates[i]->getSpace()>fromSize && estates[i]->getSpace()<toSize) &&(strcmp(estates[i]->getOfferType(),vip)))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
}
bool RealEstates::sortEstatesByLowerPrice() const
{
    if(current == 0)
        return 0;

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
    return 1;
}
void RealEstates::printEstatesByTypeAndVip(const char * typeOfEstate) const
{
    if(current==0)
    {
        cout<<emptyListWithEstates;
    }
    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getOfferType(),vip) && !strcmp(estates[i]->getTypeOfEstate(),typeOfEstate))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getOfferType(),vip)&& !strcmp(estates[i]->getTypeOfEstate(),typeOfEstate))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::printEstatesByType(const char * typeOfEstate) const
{
    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getTypeOfEstate(),typeOfEstate))
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
        cout<<emptyListWithEstates;
        return;
    }

    for(int i=0; i<current; i++)
    {
        if(!strcmp(estates[i]->getOfferType(),vip))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
    for(int i=0; i<current; i++)
    {
        if(strcmp(estates[i]->getOfferType(),vip))
        {
            cout<<informationForEstate<<endl;
            estates[i]->print();
        }
    }
}
