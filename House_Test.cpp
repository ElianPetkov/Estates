#ifndef __HOUSE_TEST__CPP
#define __HOUSE_TEST__CPP
#define DOCTEST_CONFIG_IMPLEMENT

#include "House.h"


TEST_CASE("Test the number of rooms that are initialize in House constructor")
{
    House house("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    CHECK(house.getRooms()==8);
}
TEST_CASE("Test the yard field that is initialize in House constructor")
{
    House house("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    CHECK(house.getYard()==60);
}
TEST_CASE("Test the floor field that is initialize in House constructor")
{
    House house("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    CHECK(house.getFloor()==2);
}
TEST_CASE("Test the price field that is initialize in House constructor")
{
    House house("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    CHECK(house.getPrice()==130000);
}
TEST_CASE("Test the owner field that is initialize in House constructor")
{
    House house("Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60,8,2);
    CHECK(!strcmp(house.getOwner(),"Olga Petkova"));
}
TEST_CASE("Test the address field that is initialize in House constructor")
{
    House house("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    CHECK(!strcmp(house.getAddr(),"bul. Dunav 1"));
}
TEST_CASE("Test the town field that is initialize in House constructor")
{
    House house("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    CHECK(!strcmp(house.getTown(),"Plovdiv"));
}
TEST_CASE("Test the estate type field that is initialize in House constructor")
{
    House house("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    CHECK(!strcmp(house.getTypeOfEstate(),"Classic"));
}


#endif
