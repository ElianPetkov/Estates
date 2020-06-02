#include "House.h."

House.h::House.h()
{
    //ctor
}

House.h::~House.h()
{
    //dtor
}

House.h::House.h(const House.h& other)
{
    //copy ctor
}

House.h& House.h::operator=(const House.h& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
