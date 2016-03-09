#include <gtest/gtest.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include "scriptcal.h"

using namespace std;
using namespace poac;


TEST(FooTest, HandleNoneZeroInput)
{
 //   EXPECT_EQ("it is null", Cal(NULL));
//    EXPECT_EQ("it is ok", Cal("fdd"));

	//EXPECT_EQ(3, Foo(2,1));
	//EXPECT_EQ(4, Foo(2,2));
	//EXPECT_EQ(8, Foo(5,3));

	ifstream in("123.txt");
	if (! in.is_open())
		cout << "Error open" << endl;
	while (!in.eof() )  
    {  
		int a, b, c;
		in >> a >> b >> c;
		EXPECT_EQ(a, Foo(b,c));
    } 
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

    return 0;
}