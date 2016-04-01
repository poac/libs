#include "scriptcal.h"
#include <gtest/gtest.h>

using namespace poac;

CScriptCal divi;

//通过性测试
TEST(DiviTest, PositiveInput)
{
	//测试表达式解析结果
	EXPECT_TRUE(divi.InitScript("y=x/6"));
	EXPECT_TRUE(divi.InitScript("y=6/x"));
	EXPECT_TRUE(divi.InitScript("y=x/+6"));
	EXPECT_TRUE(divi.InitScript("y=+6/x"));
	EXPECT_TRUE(divi.InitScript("y=x/-6"));
	EXPECT_TRUE(divi.InitScript("y=-6/x"));
	EXPECT_TRUE(divi.InitScript("y=+x/6"));
	EXPECT_TRUE(divi.InitScript("y=6/+x"));
	EXPECT_TRUE(divi.InitScript("y=-x/6"));
	EXPECT_TRUE(divi.InitScript("y=6/-x"));
	EXPECT_TRUE(divi.InitScript("y=0/x"));
	EXPECT_TRUE(divi.InitScript("y=x/0"));

	//测试计算结果
	//x为被除数时
	if(divi.InitScript("y=x/3") == true)
	{
		if(divi.Cal(3.3) == true)
			EXPECT_DOUBLE_EQ(1.1, divi.GetY());
		if(divi.Cal(-1) == true)
			EXPECT_DOUBLE_EQ(-0.333333, divi.GetY());
		if(divi.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, divi.GetY());
	}

	if(divi.InitScript("y=x/+3") == true)
	{
		if(divi.Cal(3.3) == true)
			EXPECT_DOUBLE_EQ(1.1, divi.GetY());
		if(divi.Cal(-1) == true)
			EXPECT_DOUBLE_EQ(-0.333333, divi.GetY());
		if(divi.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, divi.GetY());
	}

	if(divi.InitScript("y=x/-3") == true)
	{
		if(divi.Cal(3.3) == true)
			EXPECT_DOUBLE_EQ(-1.1, divi.GetY());
		if(divi.Cal(-1) == true)
			EXPECT_DOUBLE_EQ(0.333333, divi.GetY());
		if(divi.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, divi.GetY());
	}

	if(divi.InitScript("y=-x/3") == true)
	{
		if(divi.Cal(3.3) == true)
			EXPECT_DOUBLE_EQ(-1.1, divi.GetY());
		if(divi.Cal(-1) == true)
			EXPECT_DOUBLE_EQ(0.333333, divi.GetY());
		if(divi.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, divi.GetY());
	}

	if(divi.InitScript("y=+x/3") == true)
	{
		if(divi.Cal(3.3) == true)
			EXPECT_DOUBLE_EQ(1.1, divi.GetY());
		if(divi.Cal(-1) == true)
			EXPECT_DOUBLE_EQ(-0.333333, divi.GetY());
		if(divi.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, divi.GetY());
	}

	//x为除数时
	if(divi.InitScript("y=2016/x") == true)
	{
		if(divi.Cal(2) == true)
			EXPECT_DOUBLE_EQ(1008, divi.GetY());
		if(divi.Cal(-4) == true)
			EXPECT_DOUBLE_EQ(-504, divi.GetY());
		EXPECT_FALSE(divi.Cal(0));   //当x取0时无法计算
	}

	if(divi.InitScript("y=-2016/x") == true)
	{
		if(divi.Cal(2) == true)
			EXPECT_DOUBLE_EQ(-1008, divi.GetY());
		if(divi.Cal(-4) == true)
			EXPECT_DOUBLE_EQ(504, divi.GetY());
		EXPECT_FALSE(divi.Cal(0));	//当x取0时无法计算
	}

	if(divi.InitScript("y=2016/+x") == true)
	{
		if(divi.Cal(2) == true)
			EXPECT_DOUBLE_EQ(1008, divi.GetY());
		if(divi.Cal(-4) == true)
			EXPECT_DOUBLE_EQ(-504, divi.GetY());
		EXPECT_FALSE(divi.Cal(0));   //当x取0时无法计算
	}

	if(divi.InitScript("y=2016/-x") == true)
	{
		if(divi.Cal(2) == true)
			EXPECT_DOUBLE_EQ(-1008, divi.GetY());
		if(divi.Cal(-4) == true)
			EXPECT_DOUBLE_EQ(504, divi.GetY());
		EXPECT_FALSE(divi.Cal(0));   //当x取0时无法计算
	}

	if(divi.InitScript("y=0/x") == true)
	{
		if(divi.Cal(2) == true)
			EXPECT_DOUBLE_EQ(0, divi.GetY());
		if(divi.Cal(-4) == true)
			EXPECT_DOUBLE_EQ(0, divi.GetY());
		EXPECT_FALSE(divi.Cal(0));	//当x取0时无法计算
	}
}

//失效性测试
TEST(DiviTest, NegetiveInput)
{
	//表达式无法解析
	EXPECT_FALSE(divi.InitScript("y=x//3"));
	EXPECT_FALSE(divi.InitScript("y=x//+3"));
	EXPECT_FALSE(divi.InitScript("y=x//-3"));
	EXPECT_FALSE(divi.InitScript("y=x/"));
	EXPECT_FALSE(divi.InitScript("y=//x"));
	EXPECT_FALSE(divi.InitScript("y=/x"));

	//除数为0时
	if(divi.InitScript("y=x/0") == true)
	{
		EXPECT_FALSE(divi.Cal(3.6));
		EXPECT_FALSE(divi.Cal(-3.6));
		EXPECT_FALSE(divi.Cal(0));
	}

	//x为除数且x=0时的情况在上面已测
}