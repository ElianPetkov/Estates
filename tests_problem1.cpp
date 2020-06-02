#ifndef __TESTS_PROBLEM1_CPP
#define __TESTS_PROBLEM1_CPP

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "SimpleBroker.h"

TEST_CASE("Test addition")
{
	SimpleBroker Ivan(nullptr,"Ivan Dimitrov",4.5);
	CHECK (strcpy(Ivan.getName(),"Ivan Dimitrov"));
}

#endif
