#include <iostream>
#include <string.h>
#include "agent.h"
#include "RegImot.h"
Agent::Agent():name(nullptr),percentage(0){}
Agent::Agent(RealEstates listOfEstates,char * name,double percentage)
{
this->name=new char[strlen(name)+1];
strcpy(this->name,name);
this->percentage=percentage;
this->listOfEstates = listOfEstates;
}
void Agent::Copy(const Agent & x)
{
    this->name=new char[strlen(x.name)+1];
    strcpy(this->name,x.name);
    this->percentage=x.percentage;
    this->listOfEstates = x.listOfEstates;
}
Agent::Agent(const Agent & x)
{
    Copy(x);
}
void Agent::Erase()
{
    delete [] name;
}
Agent::~Agent()
{
    Erase();
}

