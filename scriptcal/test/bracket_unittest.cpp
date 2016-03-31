#include "scriptcal.h"
#include <gtest/gtest.h>

using namespace poac;

CScriptCal brk;

/*括号无嵌套时*/
//通过性测试
TEST(BrkTest, EasyPositiveInput)
{
	//测试表达式解析结果
	//单个括号
	EXPECT_TRUE(brk.InitScript("y=x+(-8)"));
	EXPECT_TRUE(brk.InitScript("y=x*(-8)"));
	EXPECT_TRUE(brk.InitScript("y=6+(x+1)"));
	EXPECT_TRUE(brk.InitScript("y=6-(x+1)"));
	EXPECT_TRUE(brk.InitScript("y=6*(x+1)"));
	EXPECT_TRUE(brk.InitScript("y=6/(x+1)"));
	EXPECT_TRUE(brk.InitScript("y=(x+1)*6"));
	EXPECT_TRUE(brk.InitScript("y=(x+1)/6"));
	
	//多个括号
	EXPECT_TRUE(brk.InitScript("y=(x+1)-(6.6+3)"));
	EXPECT_TRUE(brk.InitScript("y=(x+1)*(x-1)"));
	EXPECT_TRUE(brk.InitScript("y=x+(1+2)*(x+1)/(x+3)"));

	//测试计算结果
	//单个括号
	if(brk.InitScript("y=x*(-6)") == true)
	{
		if(brk.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(-9.0, brk.GetY());
	}

	if(brk.InitScript("y=6-(x+1)") == true)
	{
		if(brk.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(3.5, brk.GetY());
	}

	if(brk.InitScript("y=6*(x+1)") == true)
	{
		if(brk.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(15, brk.GetY());
		if(brk.Cal(-1) == true)
			EXPECT_DOUBLE_EQ(0, brk.GetY());
	}

	if(brk.InitScript("y=(x+1)/6") == true)
	{
		if(brk.Cal(11) == true)
			EXPECT_DOUBLE_EQ(2.0, brk.GetY());
		if(brk.Cal(-1) == true)
			EXPECT_DOUBLE_EQ(0, brk.GetY());
	}

	if(brk.InitScript("y=6/(x+1)") == true)
	{
		if(brk.Cal(11) == true)
			EXPECT_DOUBLE_EQ(0.5, brk.GetY());
		if(brk.Cal(-1.5) == true)
			EXPECT_DOUBLE_EQ(-12, brk.GetY());
		EXPECT_FALSE(brk.Cal(-1));	//除数不能为0
	}

	//多个括号
	if(brk.InitScript("y=(x+1)*(x-1)") == true)
	{
		if(brk.Cal(3) == true)
			EXPECT_DOUBLE_EQ(8, brk.GetY());
		if(brk.Cal(-1) == true)
			EXPECT_DOUBLE_EQ(0, brk.GetY());
	}

	if(brk.InitScript("y=x+(1+2)*(x+1)") == true)
	{
		if(brk.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(9.0, brk.GetY());
		if(brk.Cal(0) == true)
			EXPECT_DOUBLE_EQ(3, brk.GetY());
		if(brk.Cal(-0.75) == true)
			EXPECT_DOUBLE_EQ(0, brk.GetY());
	}

	if(brk.InitScript("y=x+(1+2)*(x+1)/(x+3)") == true)
	{
		if(brk.Cal(3.0) == true)
			EXPECT_DOUBLE_EQ(5.0, brk.GetY());
		if(brk.Cal(-9.0) == true)
			EXPECT_DOUBLE_EQ(-5.0, brk.GetY());
		EXPECT_FALSE(brk.Cal(-3));	//除数不能为0
	}
}

//失效性测试
TEST(BrkTest, EasyNegativeInput)
{
	//表达式无法解析
	EXPECT_FALSE(brk.InitScript("y=x+(x+1"));
	EXPECT_FALSE(brk.InitScript("y=x+x+1)"));
	EXPECT_FALSE(brk.InitScript("y=x+(x+1("));
	EXPECT_FALSE(brk.InitScript("y=x+()+1"));
	EXPECT_FALSE(brk.InitScript("y=x+)x+1)"));
}


/*括号有嵌套时*/
//通过性测试
TEST(BrkTest, ComplexPositiveInput)
{
	//测试表达式解析结果
	EXPECT_TRUE(brk.InitScript("y=((x+1)+3)*2"));
	EXPECT_TRUE(brk.InitScript("y=((x+1)+(x+3))*2"));
	EXPECT_TRUE(brk.InitScript("y=((x+1)*3+2)/6"));
	EXPECT_TRUE(brk.InitScript("y=16/(((x+1)+(x-3))*2)"));

	//测试计算结果
	if(brk.InitScript("y=((x+1)+3)*2") == true)
	{
		if(brk.Cal(3.0) == true)
			EXPECT_DOUBLE_EQ(14.0, brk.GetY());
		if(brk.Cal(-4) == true)
			EXPECT_DOUBLE_EQ(0, brk.GetY());
	}

	if(brk.InitScript("y=((x+1)+(x+3))*2") == true)
	{
		if(brk.Cal(1.0) == true)
			EXPECT_DOUBLE_EQ(12.0, brk.GetY());
		if(brk.Cal(-4) == true)
			EXPECT_DOUBLE_EQ(-8.0, brk.GetY());
	}

	if(brk.InitScript("y=((x+1)*3+2)/6") == true)
	{
		if(brk.Cal(1.0) == true)
			EXPECT_DOUBLE_EQ(1.333333, brk.GetY());
		if(brk.Cal(-6) == true)
			EXPECT_DOUBLE_EQ(-2.166667, brk.GetY());
	}

	if(brk.InitScript("y=16/(((x+1)+(x-3))*2)") == true)
	{
		if(brk.Cal(5.0) == true)
			EXPECT_DOUBLE_EQ(1.0, brk.GetY());
		if(brk.Cal(-7) == true)
			EXPECT_DOUBLE_EQ(-0.5, brk.GetY());
		EXPECT_FALSE(brk.Cal(1));	//除数不能为0
	}
}

//失效性测试
TEST(BrkTest, ComplexNegativeInput)
{
	//表达式无法解析
	EXPECT_FALSE(brk.InitScript("y=3*((x+1)+2"));
	EXPECT_FALSE(brk.InitScript("y=3*(x+1)+2)"));
	EXPECT_FALSE(brk.InitScript("y=3*((x+1)+2("));
	EXPECT_FALSE(brk.InitScript("y=3*((x+1)+2))"));
	EXPECT_FALSE(brk.InitScript("y=3*(((x+1)+2)*x"));
	EXPECT_FALSE(brk.InitScript("y=3*((x+1)+2)*x)"));
}