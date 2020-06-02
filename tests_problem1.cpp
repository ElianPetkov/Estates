#ifndef __TESTS_PROBLEM1_CPP
#define __TESTS_PROBLEM1_CPP

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
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

TEST_CASE("Test validation and constructor in House class")
{
    House house("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,120,8,2);
    CHECK(house.getRooms()==8);
    CHECK(house.getFloor()==2);
    CHECK(house.getPrice()==130000);
    CHECK(strcpy(house.getOwner(),"Olga Petkova"));
    CHECK(strcpy(house.getAddr(),"bul. Dunav 1"));
    CHECK(strcpy(house.getTown(),"Plovdiv"));
    CHECK(strcpy(house.getTypeOfEstate(),"Classic"));
}
TEST_CASE("Test Simple Broker Constructor")
{
    SimpleBroker ivan(nullptr,"Ivan Dimitrov",4.5);
	CHECK(strcpy(ivan.getName(),"Ivan Dimitrov"));
	CHECK(ivan.getPercentages()==4.5);
}

TEST_CASE("Test Helpful Broker Constructor")
{
    HelpfulBroker ivan(nullptr,"Ivan Dimitrov",4.5);
	CHECK(strcpy(ivan.getName(),"Ivan Dimitrov"));
	CHECK(ivan.getPercentages()==4.5);
}

TEST_CASE("Test Dishonest Broker Constructor")
{
    DishonestBroker ivan(nullptr,"Ivan Dimitrov",4.5);
	CHECK(strcpy(ivan.getName(),"Ivan Dimitrov"));
	CHECK(ivan.getPercentages()==4.5);
}

#endif
