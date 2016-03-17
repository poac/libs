#include <gtest/gtest.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include "scriptcal.h"

using namespace std;
using namespace poac;


TEST(FooTest, HandleNoneZeroInput)
{
	//EXPECT_EQ(3, Foo(2,1));
	//EXPECT_EQ(4, Foo(2,2));
	//EXPECT_EQ(8, Foo(5,3));
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

    return 0;
}