#ifndef __TESTS_PROBLEM1_CPP
#define __TESTS_PROBLEM1_CPP

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
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
TEST_CASE("Tests remove function in RealEstate class")
{
    RealEstates listOfEstates;
    Estate **estates = new Estate*[2];
    estates[0]=new House("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    estates[1]=new Flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    listOfEstates.addEstate(estates[0]);
    listOfEstates.addEstate(estates[1]);
    CHECK(listOfEstates.getCurrent() == 2);
    listOfEstates.removeEstate(*&estates[1]);
    CHECK(listOfEstates.getCurrent()== 1);
}
TEST_CASE("Tests add function in RealEstate class")
{
    RealEstates listOfEstates;
    Estate **estates = new Estate*[2];
    estates[0]=new House("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    estates[1]=new Flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    listOfEstates.addEstate(estates[0]);
    listOfEstates.addEstate(estates[1]);
    CHECK(listOfEstates.getCurrent() == 2);
}


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
TEST_CASE("Test Simple Broker Constructor and validations")
{
    SimpleBroker ivan(nullptr,"Ivan Dimitrov",4.5);
	CHECK(strcpy(ivan.getName(),"Ivan Dimitrov"));
	CHECK(ivan.getPercentages()==4.5);
}

TEST_CASE("Test Helpful Broker Constructor and validations")
{
    HelpfulBroker ivan(nullptr,"Ivan Dimitrov",4.5);
	CHECK(strcpy(ivan.getName(),"Ivan Dimitrov"));
	CHECK(ivan.getPercentages()==4.5);
}

TEST_CASE("Test Dishonest Broker Constructor and validations")
{
    DishonestBroker ivan(nullptr,"Ivan Dimitrov",4.5);
	CHECK(strcpy(ivan.getName(),"Ivan Dimitrov"));
	CHECK(ivan.getPercentages()==4.5);
}

#endif
