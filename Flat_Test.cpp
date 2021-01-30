#ifndef __FLAT_TEST__CPP
#define __FLAT_TEST__CPP
#define DOCTEST_CONFIG_IMPLEMENT

#include "flat.h"

TEST_CASE("Test the number of rooms that are initialize in Flat constructor")
{
    Flat flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    CHECK(flat.getRooms()==4);
}
TEST_CASE("Test the floor field that is initialize in Flat constructor")
{
    Flat flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    CHECK(flat.getFloor()==4);
}
TEST_CASE("Test the space field that is initialize in Flat constructor")
{
    Flat flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    CHECK(flat.getSpace()==65);
}
TEST_CASE("Test the price field that is initialize in Flat constructor")
{
    Flat flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    CHECK(flat.getPrice()==120000);
}
TEST_CASE("Test the owner field that is initialize in Flat constructor")
{
    Flat flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    CHECK(strcpy(flat.getOwner(),"Veselin Petkova"));
}
TEST_CASE("Test the address field that is initialize in Flat constructor")
{
    Flat flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    CHECK(strcpy(flat.getAddr(),"bul. Dunav 1"));
}
TEST_CASE("Test the town field that is initialize in Flat constructor")
{
    Flat flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    CHECK(strcpy(flat.getTown(),"Plovdiv"));
}
TEST_CASE("Test the estate type field that is initialize in Flat constructor")
{
    Flat flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    CHECK(strcpy(flat.getTypeOfEstate(),"Vip"));
}


#endif
