#include <iostream>
#include <string.h>
#include "Imot.h"
#include "flat.h"
#include "House.h"
#include "Plot.h"
#include "RegImot.h"
#include "agent.h"
#include "HelpfulBroker.h"
#include "DishonestBroker.h"
#include "SimpleBroker.h"
#include "agent.h"
#include <cassert>
using namespace std;
int RegisterEstates(RealEstates &listOfEstates)
{
    int NumberOfEstates;
    cout<<"Number of estates:"<<" ";
    do
    {
        cin>>NumberOfEstates;
    }
    while(NumberOfEstates<0);
    cin.ignore();

    Estate **estates=new Estate*[NumberOfEstates];
    char typeOfEstate[20];
    for(int i=0; i<NumberOfEstates; i++)
    {
        cout<<"Type of the estate:Flat,House or Plot:"<<" ";
        do
        {
            cin.getline(typeOfEstate,20);
        }
        while(strcmp(typeOfEstate,"Flat")&& strcmp(typeOfEstate,"House")&& strcmp(typeOfEstate,"Plot"));

        if(!strcmp(typeOfEstate,"Flat"))
        {
            estates[i]=new Flat();
        }

        if(!strcmp(typeOfEstate,"House"))
        {
            estates[i]=new House();
        }

        if(!strcmp(typeOfEstate,"Plot"))
        {
            estates[i]=new Plot();
        }

        estates[i]->addCharacteristicsToEstate();
        listOfEstates.add(estates[i]);
        cout<<endl;

    }
}
void SearchEstates(Agent *listOfAgents[3])
{
    cout<<"Choose a broker:"<<endl;
    cout<<"1 for Dishonest broker"<<endl;
    cout<<"2 for Helpful broker"<<endl;
    cout<<"3 for Simple broker"<<endl;
    int chosenAngen;
    do
    {
        cin>>chosenAngen;
    }
    while(chosenAngen<-1&&chosenAngen>2);
    cout<<endl;
    cin.ignore();

    int option;
    do
    {
        cout<<"Chose a way to search:"<<endl;
        cout<<"(1)-Type Of the estate:"<<endl;
        cout<<"(2)-Price range:"<<endl;
        cout<<"(3)-All estates by lowest price:"<<endl;
        cout<<"(4)-By town:"<<endl;
        cout<<"(5)-By space:"<<endl;
        cout<<"(0)-For exit:"<<endl;

        do
        {
            cin>>option;
        }
        while(option<0&&option>6);
        cin.ignore();
        switch(option)
        {
        case 1:
            char typeOfEstates[20];
            cout<<"Type of the estates you want to sort ,by lowest price:Flat or House:"<<" ";
            do
            {
                cin.getline(typeOfEstates,20);
            }
            while(strcmp(typeOfEstates,"Flat")&&strcmp(typeOfEstates,"House"));

            if(!strcmp(typeOfEstates,"House"))
            {
                listOfAgents[chosenAngen-1]->PrintHousesFromLowestPrice();
            }

            if(!strcmp(typeOfEstates,"Flat"))
            {
                listOfAgents[chosenAngen-1]->PrintFlatsFromLowestPrice();
            }
            break;

        case 2:
            cout<<"Type the price range:"<<" "<<endl;
            double fromPrice,toPrice;
            cin>>fromPrice>>toPrice;
            cin.ignore();
            listOfAgents[chosenAngen-1]->PrintByPriceRange(fromPrice,toPrice);
            break;

        case 3:
            listOfAgents[chosenAngen-1]->PrintEstatesFromLowestPrice();
            break;

        case 4:
            cout<<"Type Town you want to search by:"<<" ";
            char townName[30];
            cin.getline(townName,30);
            listOfAgents[chosenAngen-1]->PrintEstatesByTown(townName);
            break;

        case 5:
            cout<<"Type space range:"<<" ";
            int fromSpace;
            int toSpace;
            cin>>fromSpace>>toSpace;
            cin.ignore();
            listOfAgents[chosenAngen-1]->PrintBySpaceRange(fromSpace,toSpace);
            break;
        }
    }
    while(option!=0);
}
int main()
{
    RealEstates georgiListWithEstates;
    RealEstates denislavListWithEstates;
    RealEstates ivanListWithEstates;

    RegisterEstates(georgiListWithEstates);
    RegisterEstates(denislavListWithEstates);
    RegisterEstates(ivanListWithEstates);


    DishonestBroker Georgi(georgiListWithEstates,"Georgi Dimitrov",5.0);
    Georgi.print();

    HelpfulBroker Denislav(denislavListWithEstates,"Denislav Dimitrov",3.0);
    Denislav.Print();

    SimpleBroker Ivan(ivanListWithEstates,"Ivan Dimitrov",4.5);
    Ivan.print();

    Agent *listOfAgents[3];
    listOfAgents[0]=&Georgi;
    listOfAgents[1]=&Denislav;
    listOfAgents[2]=&Ivan;

    SearchEstates(listOfAgents);
}





