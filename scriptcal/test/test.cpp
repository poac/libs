#include <gtest/gtest.h>
//#include <time.h>
//#include <fstream>
//#include <iostream>
#include "scriptcal.h"

using namespace std;
using namespace poac;


TEST(FooTest, HandleNoneZeroInput)   //一个右边参数对应一个测试用例，左边参数对应一个测试集
{

	EXPECT_EQ(3, Foo(2,1));
	EXPECT_EQ(4, Foo(2,2));
	EXPECT_EQ(8, Foo(5,3));

	//ifstream in("123.txt");
	//if (! in.is_open())
	//	cout << "Error open" << endl;
	//while (!in.eof() )  
 //   {  
	//	int a, b, c;
	//	in >> a >> b >> c;
	//	EXPECT_EQ(a, Foo(b,c));
 //   } 
}

TEST(FooTest, HandleInvalidInput)
{

	EXPECT_EQ(3, Foo(2,1));
	EXPECT_EQ(4, Foo(2,2));
	EXPECT_EQ(8, Foo(5,3));
}

TEST(BarTest, HandleNoneZeroInput)
{

	EXPECT_EQ(3, Bar(2,1));
	EXPECT_EQ(4, Bar(6,2));
	EXPECT_EQ(8, Bar(2,3));
}



int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

    return 0;
}