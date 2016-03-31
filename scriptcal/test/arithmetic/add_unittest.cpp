#include "scriptcal.h"
#include <gtest/gtest.h>

using namespace poac;

CScriptCal add1,add2;

//通过性测试
TEST(AddTest,PositiveInput)
{
	//测试表达式解析结果
	EXPECT_TRUE(add1.InitScript("y=x+1.6"));
	EXPECT_TRUE(add1.InitScript("y=1.6+x"));
	EXPECT_TRUE(add1.InitScript("y=x+0"));
	EXPECT_TRUE(add1.InitScript("y=0+x"));
	EXPECT_TRUE(add1.InitScript("y=x+-6"));
	EXPECT_TRUE(add1.InitScript("y=-6+x"));
	EXPECT_TRUE(add1.InitScript("y=x++6"));
	EXPECT_TRUE(add1.InitScript("y=+6+x"));
	EXPECT_TRUE(add1.InitScript("y=+x+6"));
	EXPECT_TRUE(add1.InitScript("y=6++x"));
	EXPECT_TRUE(add1.InitScript("y=-x+6"));
	EXPECT_TRUE(add1.InitScript("y=6+-x"));

	//测试计算结果
	if(add2.InitScript("y=x+6") == true)
	{
		//正数与正数相加
		if(add2.Cal(3) == true)
		{
			EXPECT_DOUBLE_EQ(9.0, add2.GetY());
		}
		//负数与正数相加
		if(add2.Cal(-7.2) == true)
		{
			EXPECT_DOUBLE_EQ(-1.2, add2.GetY());
		}
		//与0相加
		if(add2.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(6, add2.GetY());
		}
	}

	if(add2.InitScript("y=x++6") == true)
	{
		//正数与正数相加
		if(add2.Cal(3) == true)
		{
			EXPECT_DOUBLE_EQ(9.0, add2.GetY());
		}
		//负数与正数相加
		if(add2.Cal(-7.2) == true)
		{
			EXPECT_DOUBLE_EQ(-1.2, add2.GetY());
		}
		//与0相加
		if(add2.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(6, add2.GetY());
		}
	}

	if(add2.InitScript("y=+x+6") == true)
	{
		//正数与正数相加
		if(add2.Cal(3) == true)
		{
			EXPECT_DOUBLE_EQ(9.0, add2.GetY());
		}
		//负数与正数相加
		if(add2.Cal(-7.2) == true)
		{
			EXPECT_DOUBLE_EQ(-1.2, add2.GetY());
		}
		//与0相加
		if(add2.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(6, add2.GetY());
		}
	}

	if(add2.InitScript("y=x+0") == true)
	{
		//正数与正数相加
		if(add2.Cal(3) == true)
		{
			EXPECT_DOUBLE_EQ(3, add2.GetY());
		}
		//负数与正数相加
		if(add2.Cal(-7.2) == true)
		{
			EXPECT_DOUBLE_EQ(-7.2, add2.GetY());
		}
		//与0相加
		if(add2.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(0, add2.GetY());
		}
	}

	if(add2.InitScript("y=x+-6.6") == true)
	{
		//正数与正数相加
		if(add2.Cal(3) == true)
		{
			EXPECT_DOUBLE_EQ(-3.6, add2.GetY());
		}
		//负数与正数相加
		if(add2.Cal(-7.2) == true)
		{
			EXPECT_DOUBLE_EQ(-13.8, add2.GetY());
		}
		//与0相加
		if(add2.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(-6.6, add2.GetY());
		}
	}

	if(add2.InitScript("y=-x+6.6") == true)
	{
		//正数与正数相加
		if(add2.Cal(3) == true)
		{
			EXPECT_DOUBLE_EQ(3.6, add2.GetY());
		}
		//负数与正数相加
		if(add2.Cal(-7.2) == true)
		{
			EXPECT_DOUBLE_EQ(13.8, add2.GetY());
		}
		//与0相加
		if(add2.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(6.6, add2.GetY());
		}
	}
}

//失效性测试
TEST(AddTest, NegetiveInput)
{
	//表达式无法解析
	EXPECT_FALSE(add1.InitScript("y=x+++6"));
	EXPECT_FALSE(add1.InitScript("y=x++-6"));
	EXPECT_FALSE(add1.InitScript("y=++x"));
	EXPECT_FALSE(add1.InitScript("y=x++"));
	EXPECT_FALSE(add1.InitScript("y=x+"));
}