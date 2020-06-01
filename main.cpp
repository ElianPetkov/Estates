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
using namespace std;
int Register(RealEstates &listOfEstates)
{
    int NumberOfEstates;
    char a[20];
    cout<<"Number of estates:"<<" ";
    do
    {
        cin>>NumberOfEstates;
    }
    while(NumberOfEstates<0);
    cin.ignore();
    Estate **estates=new Estate*[NumberOfEstates];
    for(int i=0; i<NumberOfEstates; i++)
    {
        cout<<"Type of the estate:Flat,House or Plot:"<<" ";
        do
        {
            cin.getline(a,20);
        }
        while(strcmp(a,"Flat")&& strcmp(a,"House")&& strcmp(a,"Plot"));

        if(!strcmp(a,"Flat"))
        {
            estates[i]=new Flat();
        }

        if(!strcmp(a,"House"))
        {
            estates[i]=new House();
        }

        if(!strcmp(a,"Plot"))
        {
            estates[i]=new Plot();
        }

        estates[i]->read();

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
    int agentNumber;
    do
    {
        cin>>agentNumber;
    }
    while(agentNumber<-1&&agentNumber>2);
    cout<<endl;
    cin.ignore();
    int c;
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
            cin>>c;
        }
        while(c<0&&c>6);
        cin.ignore();
        switch(c)
        {
        case 1:
            char b[20];
            cout<<"Type of the estates you want to sort ,by lowest price:flat or house:"<<" ";
            do
            {
                cin.getline(b,20);
            }
            while(strcmp(b,"flat")&&strcmp(b,"house"));
            if(!strcmp(b,"house"))
            {
                listOfAgents[agentNumber-1]->PrintHousesFromLowestPrice();
            }

            if(!strcmp(b,"flat"))
            {
                listOfAgents[agentNumber-1]->PrintFlatsFromLowestPrice();
            }
            break;
        case 2:
            cout<<"Type the price range:"<<" "<<endl;
            double price1,price2;
            cin>>price1>>price2;
            cin.ignore();
            listOfAgents[agentNumber-1]->PrintByPriceRange(price1,price2);
            break;
        case 3:
            listOfAgents[agentNumber-1]->PrintEstatesFromLowestPrice();
            break;
        case 4:
            cout<<"Type Town you want to search by:"<<" ";
            char a[30];
            cin.getline(a,30);
            listOfAgents[agentNumber-1]->PrintEstatesByTown(a);
            break;
        case 5:
            cout<<"Type space range:"<<" ";
            int x;
            int y;
            cin>>x>>y;
            cin.ignore();
            listOfAgents[agentNumber-1]->PrintBySpaceRange(x,y);
            break;
        }
    }
    while(c!=0);
}
int main()
{
    RealEstates georgiListWithEstates;
    RealEstates denislavListWithEstates;
    RealEstates ivanListWithEstates;

    Register(georgiListWithEstates);
    Register(denislavListWithEstates);
    Register(ivanListWithEstates);

    DishonestBroker Georgi(georgiListWithEstates,"Georgi Dimitrov",5.0);
    Georgi.print();

    HelpfulBroker Denislav(denislavListWithEstates,"Denislav Dimitrov",3.0);
    Denislav.Print();

    SimpleBroker Ivan(ivanListWithEstates,"Ivan Dimitrov",3.0);
    Ivan.print();

    Agent *listOfAgents[3];
    listOfAgents[0]=&Georgi;
    listOfAgents[1]=&Denislav;
    listOfAgents[2]=&Ivan;

    SearchEstates(listOfAgents);
}





