/*#include <iostream>
#include "RegImot.h"
#include <string.h>
#include "agent.h"
Agent::Agent():RealEstates(),name(nullptr),percentage(0){}
Agent::Agent(const Estate *estates,char * name,double percentage):RealEstates(estates)
{
this->name=new char[strlen(name)+1];
strcpy(this->name,name);
this->percentage=percentage;
}
void Agent::Copy(const Agent & x)
{
    this->name=new char[strlen(x.name)+1];
    strcpy(this->name,x.name);
    this->percentage=x.percentage;
}
Agent::Agent(const Agent & x):RealEstates(x)
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
*/
