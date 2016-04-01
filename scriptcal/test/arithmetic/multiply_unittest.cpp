#include "scriptcal.h"
#include <gtest/gtest.h>

using namespace poac;

CScriptCal mul;

//通过性测试
TEST(MulTest, PositiveInput)
{
	//测试表达式解析结果
	EXPECT_TRUE(mul.InitScript("y=x*6.6"));
	EXPECT_TRUE(mul.InitScript("y=6.6*x"));
	EXPECT_TRUE(mul.InitScript("y=x*+6.6"));
	EXPECT_TRUE(mul.InitScript("y=+6.6*x"));
	EXPECT_TRUE(mul.InitScript("y=x*-6.6"));
	EXPECT_TRUE(mul.InitScript("y=-6.6*x"));
	EXPECT_TRUE(mul.InitScript("y=x*0"));
	EXPECT_TRUE(mul.InitScript("y=0*x"));
	EXPECT_TRUE(mul.InitScript("y=+x*6.6"));
	EXPECT_TRUE(mul.InitScript("y=6.6*+x"));
	EXPECT_TRUE(mul.InitScript("y=-x*6.6"));
	EXPECT_TRUE(mul.InitScript("y=6.6*-x"));

	//测试计算结果
	if(mul.InitScript("y=6*x") == true)
	{
		if(mul.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(9.0, mul.GetY());
		if(mul.Cal(-1.5) == true)
			EXPECT_DOUBLE_EQ(-9.0, mul.GetY());
		if(mul.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, mul.GetY());
	}

	if(mul.InitScript("y=6*+x") == true)
	{
		if(mul.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(9.0, mul.GetY());
		if(mul.Cal(-1.5) == true)
			EXPECT_DOUBLE_EQ(-9.0, mul.GetY());
		if(mul.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, mul.GetY());
	}

	if(mul.InitScript("y=6*-x") == true)
	{
		if(mul.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(-9.0, mul.GetY());
		if(mul.Cal(-1.5) == true)
			EXPECT_DOUBLE_EQ(9.0, mul.GetY());
		if(mul.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, mul.GetY());
	}

	if(mul.InitScript("y=-2*x") == true)
	{
		if(mul.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(-3.0, mul.GetY());
		if(mul.Cal(-1.5) == true)
			EXPECT_DOUBLE_EQ(3.0, mul.GetY());
		if(mul.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, mul.GetY());
	}

	if(mul.InitScript("y=-x*-2") == true)
	{
		if(mul.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(3.0, mul.GetY());
		if(mul.Cal(-1.5) == true)
			EXPECT_DOUBLE_EQ(-3.0, mul.GetY());
		if(mul.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, mul.GetY());
	}

	if(mul.InitScript("y=+x*-2") == true)
	{
		if(mul.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(-3.0, mul.GetY());
		if(mul.Cal(-1.5) == true)
			EXPECT_DOUBLE_EQ(3.0, mul.GetY());
		if(mul.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, mul.GetY());
	}


	//与0相乘
	if(mul.InitScript("y=0*x") == true)
	{
		if(mul.Cal(6.6) == true)
			EXPECT_DOUBLE_EQ(0, mul.GetY());
		if(mul.Cal(-2.5) == true)
			EXPECT_DOUBLE_EQ(0, mul.GetY());
		if(mul.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, mul.GetY());
	}
}

//失效性测试
TEST(MulTest, NegativeInput)
{
	//表达式无法解析
	EXPECT_FALSE(mul.InitScript("y=6x"));
	EXPECT_FALSE(mul.InitScript("y=x6"));
	EXPECT_FALSE(mul.InitScript("y=x**3"));
	EXPECT_FALSE(mul.InitScript("y=x**+3"));
	EXPECT_FALSE(mul.InitScript("y=x**-3"));
	EXPECT_FALSE(mul.InitScript("y=**x"));
	EXPECT_FALSE(mul.InitScript("y=*x"));
	EXPECT_FALSE(mul.InitScript("y=x*"));
}