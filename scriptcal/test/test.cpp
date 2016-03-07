#include <gtest/gtest.h>
#include "scriptcal.h"

using namespace poac;

TEST(FooTest, HandleNoneZeroInput)
{
 //   EXPECT_EQ("it is null", Cal(NULL));
//    EXPECT_EQ("it is ok", Cal("fdd"));
	EXPECT_EQ(1, Foo(1,0));
	EXPECT_EQ(3, Foo(2,1));
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

    return 0;
}