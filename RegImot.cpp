#include <string.h>
#include<iostream>
#include"RegImot.h"
#include "Imot.h"
#include <cassert>
using namespace std;
RealEstates::RealEstates():Capacity(10),Current(0),estates(nullptr)
{
    this->estates=new Estate*[Capacity];
}
RealEstates::RealEstates(Estate **estates)
{

    Capacity=10;
    Current=0;
    this->estates=new Estate*[Capacity];
    assert(this->estates!=nullptr);
}
void RealEstates::Copy(const RealEstates & x)
{

    this->Current=x.Current;
    this->Capacity=x.Capacity;
    this->estates=new Estate*[Capacity];
    assert(this->estates!=nullptr);
    for(int i=0; i<Current; i++)
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
    if(Current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<Current; i++)
    {
        cout<<"Information about the estate:"<<endl;
        estates[i]->print();
    }

}
void RealEstates::resize()
{

    Estate **tmp=estates;
    Capacity*=2;
    estates=new Estate*[Capacity];
    assert(this->estates!=nullptr);
    for(int i=0; i<Current; i++)
    {
        estates[i]=tmp[i];
    }
    delete [] tmp;


}
void RealEstates::add(Estate * x)
{
    if(Current==Capacity)
    {
        resize();
    }
    estates[Current]=x;
    Current++;

}
void RealEstates::remove(Estate x)
{

    int index=-1;
    for(int i = 0; i < Current; ++i)
    {
        if(!strcmp(estates[i]->getOwner(),x.getOwner()) && !strcmp(estates[i]->getAddr(),x.getAddr()) )
        {
            index=i;
            break;
        }
    }
    if(index!=-1)
    {
        for(int i=index; i<Current-1; i++)
        {
            estates[i]=estates[i+1];
        }
        delete estates[Current-1] ;
        estates [Current-1]=nullptr;
        Current--;
    }
}

RealEstates::~RealEstates()
{
    Erase();
}
int RealEstates::GetCurrent()
{
    return Current;
}
RealEstates * RealEstates::Clone()const
{
    return new RealEstates(*this);
}
void RealEstates::NewPrice(int x)
{
    for(int i=0; i<Current; i++)
    {
        estates[i]->Estate::setPrice(estates[i]->getPrice()+(estates[i]->getPrice()*x)/100);
    }
}
void RealEstates::PrintHousesFromLowestPrice()const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for (int i = 0; i < Current ; i++)
    {
        if(estates[i]->GetYard()>0)
        {
            for (int j = i + 1; j < Current; j++)
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
    for(int i=0; i<Current; i++)
    {
        if(estates[i]->GetYard()>0)
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }

}
void RealEstates::NewPrice(double x)
{
    for(int i=0; i<Current; i++)
    {
        estates[i]->Estate::setPrice(x);
    }
}

void RealEstates::PrintFlatsFromLowestPrice()const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for (int i = 0; i < Current ; i++)
    {
        if(estates[i]->GetFloor()>0)
        {
            for (int j = i + 1; j < Current; j++)
            {
                if(estates[j]->GetFloor()>0)
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
    for(int i=0; i<Current; i++)
    {
        if(estates[i]->GetFloor()>0)
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::PrintEstatesFromLowestPrice()const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for (int i = 0; i < Current ; i++)
    {


        for (int j = i + 1; j < Current; j++)
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
    for(int i=0; i<Current; i++)
    {

        cout<<"Information about the estate:"<<endl;
        estates[i]->print();
    }
}

void RealEstates::PrintHouses()const
{

    for(int i=0; i<Current; i++)
    {
        if(estates[i]->GetYard()>0)
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }

}

void RealEstates::PrintFlats()const
{

    for(int i=0; i<Current; i++)
    {
        if(estates[i]->GetYard()>0)
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }

}

void RealEstates::PrintByPriceRange(double price1,double price2)const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<Current; i++)
    {
        if(estates[i]->getPrice()>=price1 && estates[i]->getPrice()<=price2)
        {

            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::PrintEstatesByTown(char * Town)const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<Current; i++)
    {
        if(!strcmp(estates[i]->GetTown(),Town))
        {

            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
}

void RealEstates::PrintBySpaceRange(double size1,double size2)const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<Current; i++)
    {
        if(estates[i]->GetSpace()>size1&&estates[i]->GetSpace()<size2)
        {

            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
}
void RealEstates::PrintByVip()const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<Current; i++)
    {
        if(!strcmp(estates[i]->GetTypeOfEstate(),"vip")||!strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
    for(int i=0; i<Current; i++)
    {
        if(strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }

}

void RealEstates::ByVip()const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<Current; i++)
    {
        if(!strcmp(estates[i]->GetTypeOfEstate(),"vip")||!strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            cout<<"Information about the estate:"<<endl;
            if(estates[i]->GetYard()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }

    for(int i=0; i<Current; i++)
    {
        if(strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            if(estates[i]->GetYard()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
}

void RealEstates::PrintFlatsFromLowestPriceByVip()const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<Current; i++)
    {
        if(!strcmp(estates[i]->GetTypeOfEstate(),"vip")||!strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            cout<<"Information about the estate:"<<endl;
            if(estates[i]->GetFloor()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }

    for(int i=0; i<Current; i++)
    {
        if(strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            if(estates[i]->GetFloor()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
}
void RealEstates::PrintEstatesFromLowestPriceByVip()const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for (int i = 0; i < Current ; i++)
    {


        for (int j = i + 1; j < Current; j++)
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
    for(int i=0; i<Current; i++)
    {
        if(!strcmp(estates[i]->GetTypeOfEstate(),"vip")||!strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
    for(int i=0; i<Current; i++)
    {
        if(strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            cout<<"Information about the estate:"<<endl;
            estates[i]->print();
        }
    }
}
void RealEstates::PrintHousesByVip()const
{

    for(int i=0; i<Current; i++)
    {
        if(!strcmp(estates[i]->GetTypeOfEstate(),"vip")||!strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            if(estates[i]->GetYard()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<Current; i++)
    {
        if(strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            if(estates[i]->GetYard()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }


}
void RealEstates::PrintFlatsByVip()const
{

    for(int i=0; i<Current; i++)
    {
        if(!strcmp(estates[i]->GetTypeOfEstate(),"vip")||!strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            if(estates[i]->GetFloor()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<Current; i++)
    {
        if(strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            if(estates[i]->GetFloor()>0)
            {
                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
}

void RealEstates::PrintByPriceRangeByVip(double price1,double price2)const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<Current; i++)
    {
        if(!strcmp(estates[i]->GetTypeOfEstate(),"vip")||!strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            if(estates[i]->getPrice()>=price1 && estates[i]->getPrice()<=price2)
            {

                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<Current; i++)
    {
        if(strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            if(estates[i]->getPrice()>=price1 && estates[i]->getPrice()<=price2)
            {

                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
}
void RealEstates::PrintEstatesByTownByVip(char * Town)const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<Current; i++)
    {
        if(!strcmp(estates[i]->GetTypeOfEstate(),"vip")||!strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            if(!strcmp(estates[i]->GetTown(),Town))
            {

                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<Current; i++)
    {
        if(strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            if(!strcmp(estates[i]->GetTown(),Town))
            {

                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }

}

void RealEstates::PrintBySpaceRangeByVip(double size1,double size2)const
{
    if(Current==0)
    {
        cout<<"empty";
    }

    for(int i=0; i<Current; i++)
    {
        if(!strcmp(estates[i]->GetTypeOfEstate(),"vip")||!strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            if(estates[i]->GetSpace()>size1&&estates[i]->GetSpace()<size2)
            {

                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
    for(int i=0; i<Current; i++)
    {
        if(strcmp(estates[i]->GetTypeOfEstate(),"Vip"))
        {
            if(estates[i]->GetSpace()>size1&&estates[i]->GetSpace()<size2)
            {

                cout<<"Information about the estate:"<<endl;
                estates[i]->print();
            }
        }
    }
}
