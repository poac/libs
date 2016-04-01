#include "scriptcal.h"
#include <gtest/gtest.h>

using namespace poac;

CScriptCal arith;

//通过性测试
TEST(ArithTest, PositiveInput)
{
	//测试表达式解析结果
	//单种运算符
	EXPECT_TRUE(arith.InitScript("y=x+1+6.5"));
	EXPECT_TRUE(arith.InitScript("y=x-1-6.5"));
	EXPECT_TRUE(arith.InitScript("y=x*1*6.5"));
	EXPECT_TRUE(arith.InitScript("y=x/1/6.5"));

	//混合运算符
	EXPECT_TRUE(arith.InitScript("y=x+3-1.5"));
	EXPECT_TRUE(arith.InitScript("y=x-3+1.5"));
	EXPECT_TRUE(arith.InitScript("y=x+3*1.5"));
	EXPECT_TRUE(arith.InitScript("y=x+3/1.5"));
	EXPECT_TRUE(arith.InitScript("y=x-3*1.5"));
	EXPECT_TRUE(arith.InitScript("y=x-3/1.5"));
	EXPECT_TRUE(arith.InitScript("y=x*3/1.5"));
	EXPECT_TRUE(arith.InitScript("y=x/3*1.5"));
	EXPECT_TRUE(arith.InitScript("y=x*6+3/1.5"));
	EXPECT_TRUE(arith.InitScript("y=x*6+3/1.5-2*x"));

	//测试计算结果
	//单种运算符
	if(arith.InitScript("y=x+1+6.5") == true)
	{
		if(arith.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(10.0, arith.GetY());
	}
	
	if(arith.InitScript("y=x-1-6.5") == true)
	{
		if(arith.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(-6.0, arith.GetY());
	}

	if(arith.InitScript("y=x*1*6.5") == true)
	{
		if(arith.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(9.75, arith.GetY());
	}

	if(arith.InitScript("y=x/1/6.5") == true)
	{
		if(arith.Cal(1.3) == true)
			EXPECT_DOUBLE_EQ(0.2, arith.GetY());
	}

	//混合运算符
	if(arith.InitScript("y=x+3-1.5") == true)
	{
		if(arith.Cal(4.5) == true)
			EXPECT_DOUBLE_EQ(6.0, arith.GetY());
	}

	if(arith.InitScript("y=x-3+1.5") == true)
	{
		if(arith.Cal(4.5) == true)
			EXPECT_DOUBLE_EQ(3.0, arith.GetY());
	}

	if(arith.InitScript("y=x+3*1.5") == true)
	{
		if(arith.Cal(4.5) == true)
			EXPECT_DOUBLE_EQ(9.0, arith.GetY());
	}

	if(arith.InitScript("y=x+3/1.5") == true)
	{
		if(arith.Cal(4.5) == true)
			EXPECT_DOUBLE_EQ(6.5, arith.GetY());
	}

	if(arith.InitScript("y=x*3/1.5") == true)
	{
		if(arith.Cal(4.5) == true)
			EXPECT_DOUBLE_EQ(9.0, arith.GetY());
	}

	if(arith.InitScript("y=x/3*1.5") == true)
	{
		if(arith.Cal(4.5) == true)
			EXPECT_DOUBLE_EQ(2.25, arith.GetY());
	}

	if(arith.InitScript("y=x*3+3/1.5") == true)
	{
		if(arith.Cal(2.0) == true)
			EXPECT_DOUBLE_EQ(8.0, arith.GetY());
	}

	if(arith.InitScript("y=x*6+3/1.5-2*x") == true)
	{
		if(arith.Cal(0.5) == true)
			EXPECT_DOUBLE_EQ(4.0, arith.GetY());
	}
}

//失效性测试
TEST(ArithTest, NegetiveInput)
{
	//表达式无法解析
	EXPECT_FALSE(arith.InitScript("y=x+*6"));
	EXPECT_FALSE(arith.InitScript("y=x+/6"));
	EXPECT_FALSE(arith.InitScript("y=x-*6"));
	EXPECT_FALSE(arith.InitScript("y=x-/6"));
	EXPECT_FALSE(arith.InitScript("y=x+*6"));
	EXPECT_FALSE(arith.InitScript("y=x*/6"));
	EXPECT_FALSE(arith.InitScript("y=x/*6"));
	EXPECT_FALSE(arith.InitScript("y=x*++6"));
	EXPECT_FALSE(arith.InitScript("y=x*+*6"));
	EXPECT_FALSE(arith.InitScript("y=x/+*6"));

	//除数为0时
	if(arith.InitScript("y=x+3/0") == true)
	{
		EXPECT_FALSE(arith.Cal(3.6));
		EXPECT_FALSE(arith.Cal(-3.6));
		EXPECT_FALSE(arith.Cal(0));
	}

	if(arith.InitScript("y=x+3/x") == true)
	{
		EXPECT_FALSE(arith.Cal(0));
	}
}