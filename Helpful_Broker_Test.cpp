#ifndef __HELPFUL_BROKER_TEST__CPP
#define __HELPFUL_BROKER_TEST__CPP
#define DOCTEST_CONFIG_IMPLEMENT

TEST_CASE("Test the name field that is initialize in HelpfulBroker constructor")
{
    HelpfulBroker ivan(nullptr,"Ivan Dimitrov",4.5);
	CHECK(strcpy(ivan.getName(),"Ivan Dimitrov"));
}

TEST_CASE("Test the percentages field that is initialize in HelpfulBroker constructor")
{
    HelpfulBroker ivan(nullptr,"Ivan Dimitrov",4.5);
	CHECK(ivan.getPercentages()==4.5);
}


#endif
