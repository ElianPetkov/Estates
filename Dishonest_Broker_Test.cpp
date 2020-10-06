#ifndef __DISHONEST_BROKER_TEST__CPP
#define __DISHONEST_BROKER_TEST__CPP
#define DOCTEST_CONFIG_IMPLEMENT

TEST_CASE("Test the name field that is initialize in DishonestBroker constructor")
{
    DishonestBroker ivan(nullptr,"Ivan Dimitrov",4.5);
	CHECK(!strcmp(ivan.getName(),"Ivan Dimitrov"));
}

TEST_CASE("Test the percentages field that is initialize in DishonestBroker constructor")
{
    DishonestBroker ivan(nullptr,"Ivan Dimitrov",4.5);
	CHECK(ivan.getPercentages()==4.5);
}

#endif
