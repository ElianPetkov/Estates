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
TEST_CASE("Test validation and constructor in House class")
{
    House house("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    CHECK(house.getRooms()==8);
    CHECK(house.getYard()==60);
    CHECK(house.getFloor()==2);
    CHECK(house.getPrice()==130000);
    CHECK(strcpy(house.getOwner(),"Olga Petkova"));
    CHECK(strcpy(house.getAddr(),"bul. Dunav 1"));
    CHECK(strcpy(house.getTown(),"Plovdiv"));
    CHECK(strcpy(house.getTypeOfEstate(),"Classic"));
}
TEST_CASE("Test validation and constructor in Flat class")
{
    Flat flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    CHECK(flat.getRooms()==4);
    CHECK(flat.getFloor()==4);
    CHECK(flat.getSpace()==65);
    CHECK(flat.getPrice()==120000);
    CHECK(strcpy(flat.getOwner(),"Veselin Petkova"));
    CHECK(strcpy(flat.getAddr(),"bul. Dunav 1"));
    CHECK(strcpy(flat.getTown(),"Plovdiv"));
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
