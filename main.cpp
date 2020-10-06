#include <iostream>
#include <string.h>
#include "Estate.h"
#include "flat.h"
#include "House.h"
#include "Plot.h"
#include "RealEstate.h"
#include "agent.h"
#include "HelpfulBroker.h"
#include "DishonestBroker.h"
#include "SimpleBroker.h"
#include "agent.h"
#include "Constants.h"

using namespace std;
int RegisterEstates(RealEstates &listOfEstates)
{
    int NumberOfEstates;
    cout<<"Number of estates:"<<" ";
    do
    {
        cin>>NumberOfEstates;
    }
    while(NumberOfEstates<0 );
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
        while(strcmp(typeOfEstate,flat)&& strcmp(typeOfEstate,house)&& strcmp(typeOfEstate,plot));

        if(!strcmp(typeOfEstate,flat))
        {
            estates[i]=new Flat();
        }

        if(!strcmp(typeOfEstate,house))
        {
            estates[i]=new House();
        }

        if(!strcmp(typeOfEstate,plot))
        {
            estates[i]=new Plot();
        }

        estates[i]->addCharacteristicsToEstate();
        listOfEstates.addEstate(estates[i]);
        cout<<endl;

    }
}
void searchEstates(Agent *listOfAgents[3])
{
    cout<<"Choose a broker:"<<endl;
    cout<<"1 for Dishonest broker"<<endl;
    cout<<"2 for Helpful broker"<<endl;
    cout<<"3 for Simple broker"<<endl;
    int chosenAgent;
    do
    {
        cin>>chosenAgent;
    }
    while(chosenAgent<-1&&chosenAgent>2);
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
        while(option<0 && option>6);
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
            while(strcmp(typeOfEstates,flat)&&strcmp(typeOfEstates,house));

            if(!strcmp(typeOfEstates,house))
            {
                listOfAgents[chosenAgent-1]->printHousesFromLowestPrice();
            }

            if(!strcmp(typeOfEstates,flat))
            {
                listOfAgents[chosenAgent-1]->printFlatsFromLowestPrice();
            }
            break;

        case 2:
            cout<<"Type the price range:"<<" "<<endl;
            double fromPrice,toPrice;
            cin>>fromPrice>>toPrice;
            cin.ignore();
            listOfAgents[chosenAgent-1]->printByPriceRange(fromPrice,toPrice);
            break;

        case 3:
            listOfAgents[chosenAgent-1]->printEstatesFromLowestPrice();
            break;

        case 4:
            cout<<"Type Town you want to search by:"<<" ";
            char townName[30];
            cin.getline(townName,30);
            listOfAgents[chosenAgent-1]->printEstatesByTown(townName);
            break;

        case 5:
            cout<<"Type space range:"<<" ";
            int fromSpace;
            int toSpace;
            cin>>fromSpace>>toSpace;
            cin.ignore();
            listOfAgents[chosenAgent-1]->printBySpaceRange(fromSpace,toSpace);
            break;
        }
    }
    while(option!=0);
}
#include "tests_problem1.cpp"
#include "House_Test.cpp"
#include "Simple_Broker_Test.cpp"
#include "Helpful_Broker_Test.cpp"
#include "Dishonest_Broker_Test.cpp"
#include "Simple_Broker_Test.cpp"
#include "Real_Estate_Test.cpp"
#include "Estate_Test.cpp"
using namespace std;
int main ()
{
    doctest::Context().run();

    RealEstates georgiListWithEstates;
    RealEstates denislavListWithEstates;
    RealEstates ivanListWithEstates;

    RegisterEstates(georgiListWithEstates);
    RegisterEstates(denislavListWithEstates);
    RegisterEstates(ivanListWithEstates);

    DishonestBroker Georgi(georgiListWithEstates,"Georgi Dimitrov",5.0);
    Georgi.print();

    HelpfulBroker Denislav(denislavListWithEstates,"Denislav Dimitrov",3.0);
    Denislav.print();

    SimpleBroker Ivan(ivanListWithEstates,"Ivan Dimitrov",4.5);
    Ivan.print();

    Agent *listOfAgents[3];
    listOfAgents[0]=&Georgi;
    listOfAgents[1]=&Denislav;
    listOfAgents[2]=&Ivan;

    searchEstates(listOfAgents);
}


