#include "scriptcal.h"
#include <gtest/gtest.h>

using namespace poac::script;

CScriptCal epo;

//通过性测试
TEST(EpoTest, PositiveInput)
{
	//测试表达式解析结果
	//单独的指数运算
	EXPECT_TRUE(epo.InitScript("y=x^2"));
	EXPECT_TRUE(epo.InitScript("y=x^(-2)"));
	EXPECT_TRUE(epo.InitScript("y=(-x)^2"));
	EXPECT_TRUE(epo.InitScript("y=-x^2"));
	EXPECT_TRUE(epo.InitScript("y=x^0"));
	EXPECT_TRUE(epo.InitScript("y=0^x"));
	EXPECT_TRUE(epo.InitScript("y=x^(1/2)"));
	EXPECT_TRUE(epo.InitScript("y=x^(1-0.5)"));
	EXPECT_TRUE(epo.InitScript("y=2^x"));
	EXPECT_TRUE(epo.InitScript("y=(-2)^x"));
	EXPECT_TRUE(epo.InitScript("y=-2^x"));
	EXPECT_TRUE(epo.InitScript("y=+2^x"));
	EXPECT_TRUE(epo.InitScript("y=x^2^3"));
	EXPECT_TRUE(epo.InitScript("y=2^x^3"));

	//指数运算和四则运算的混合运算
	EXPECT_TRUE(epo.InitScript("y=3+2^x"));
	EXPECT_TRUE(epo.InitScript("y=3*2^x"));
	EXPECT_TRUE(epo.InitScript("y=x^2+3^x"));
	EXPECT_TRUE(epo.InitScript("y=x^2-3^x"));
	EXPECT_TRUE(epo.InitScript("y=x^2*3^x"));
	EXPECT_TRUE(epo.InitScript("y=x^2/3^x"));
	EXPECT_TRUE(epo.InitScript("y=x^2+15*x^3"));

	//测试计算结果
	if(epo.InitScript("y=x^2") == true)
	{
		if(epo.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(2.25, epo.GetY());
		if(epo.Cal(-3) == true)
			EXPECT_DOUBLE_EQ(9, epo.GetY());
		if(epo.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, epo.GetY());
	}

	if(epo.InitScript("y=x^(-2)") == true)
	{
		if(epo.Cal(2) == true)
			EXPECT_DOUBLE_EQ(0.25, epo.GetY());
		if(epo.Cal(-2) == true)
			EXPECT_DOUBLE_EQ(0.25, epo.GetY());
		EXPECT_FALSE(epo.Cal(0));		   //0不能为除数
	}

	if(epo.InitScript("y=-x^2") == true)
	{
		if(epo.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(-2.25, epo.GetY());
		if(epo.Cal(-3) == true)
			EXPECT_DOUBLE_EQ(-9, epo.GetY());
		if(epo.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, epo.GetY());
	}

	if(epo.InitScript("y=(-x)^3") == true)
	{
		if(epo.Cal(2) == true)
			EXPECT_DOUBLE_EQ(-8, epo.GetY());
		if(epo.Cal(-3) == true)
			EXPECT_DOUBLE_EQ(27, epo.GetY());
		if(epo.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, epo.GetY());
	}

	if(epo.InitScript("y=x^0") == true)
	{
		if(epo.Cal(1.5) == true)
			EXPECT_DOUBLE_EQ(1, epo.GetY());
		if(epo.Cal(-3) == true)
			EXPECT_DOUBLE_EQ(1, epo.GetY());
		if(epo.Cal(0) == true)
			EXPECT_DOUBLE_EQ(1, epo.GetY());
	}

	if(epo.InitScript("y=x^(1-0.5)") == true)
	{
		if(epo.Cal(4) == true)
			EXPECT_DOUBLE_EQ(2, epo.GetY());
		EXPECT_FALSE(epo.Cal(-9));			//负数不能开根号
			
		if(epo.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, epo.GetY());
	}

	if(epo.InitScript("y=2^x") == true)
	{
		if(epo.Cal(3) == true)
			EXPECT_DOUBLE_EQ(8, epo.GetY());
		if(epo.Cal(-2) == true)
			EXPECT_DOUBLE_EQ(0.25, epo.GetY());
		if(epo.Cal(0) == true)
			EXPECT_DOUBLE_EQ(1, epo.GetY());
	}

	if(epo.InitScript("y=-2^x") == true)
	{
		if(epo.Cal(3) == true)
			EXPECT_DOUBLE_EQ(-8, epo.GetY());
		if(epo.Cal(-2) == true)
			EXPECT_DOUBLE_EQ(-0.25, epo.GetY());
		if(epo.Cal(0) == true)
			EXPECT_DOUBLE_EQ(-1, epo.GetY());
	}

	if(epo.InitScript("y=x^2^3") == true)
	{
		if(epo.Cal(2) == true)
			EXPECT_DOUBLE_EQ(64, epo.GetY());
		if(epo.Cal(-2) == true)
			EXPECT_DOUBLE_EQ(64, epo.GetY());
		if(epo.Cal(0) == true)
			EXPECT_DOUBLE_EQ(1, epo.GetY());
	}

	if(epo.InitScript("y=2^x^3") == true)
	{
		if(epo.Cal(2) == true)
			EXPECT_DOUBLE_EQ(64, epo.GetY());
		if(epo.Cal(-1) == true)
			EXPECT_DOUBLE_EQ(0.125, epo.GetY());
		if(epo.Cal(0) == true)
			EXPECT_DOUBLE_EQ(1, epo.GetY());
	}

	if(epo.InitScript("y=3*4^x") == true)
	{
		if(epo.Cal(0.5) == true)
			EXPECT_DOUBLE_EQ(6, epo.GetY());
		if(epo.Cal(-1) == true)
			EXPECT_DOUBLE_EQ(0.75, epo.GetY());
		if(epo.Cal(0) == true)
			EXPECT_DOUBLE_EQ(3, epo.GetY());
	}

	if(epo.InitScript("y=x^2*3^x") == true)
	{
		if(epo.Cal(2) == true)
			EXPECT_DOUBLE_EQ(36, epo.GetY());
		if(epo.Cal(-1) == true)
			EXPECT_DOUBLE_EQ(0.333333, epo.GetY());
		if(epo.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, epo.GetY());
	}

	if(epo.InitScript("y=x^2+3*x^(-2)") == true)
	{
		if(epo.Cal(2) == true)
			EXPECT_DOUBLE_EQ(4.75, epo.GetY());
		if(epo.Cal(-1) == true)
			EXPECT_DOUBLE_EQ(4, epo.GetY());
		if(epo.Cal(0) == true)
			EXPECT_DOUBLE_EQ(0, epo.GetY());
	}
}

//失效性测试
TEST(EpoTest, Negative)
{
	//表达式无法解析
	EXPECT_FALSE(epo.InitScript("y=x^-3"));
	EXPECT_FALSE(epo.InitScript("y=3^-x"));
	EXPECT_FALSE(epo.InitScript("y=x^+3"));
	EXPECT_FALSE(epo.InitScript("y=3^+x"));
	EXPECT_FALSE(epo.InitScript("y=x^^3"));
	EXPECT_FALSE(epo.InitScript("y=x^"));
	EXPECT_FALSE(epo.InitScript("y=^x"));

	//除数为0的情况前面已涉及
	//负数的1/2的备注的乘方的状况
	if(epo.InitScript("y=(-4)^x") == true)
	{
		EXPECT_FALSE(epo.Cal(1/2));
		EXPECT_FALSE(epo.Cal(1/4));
		EXPECT_FALSE(epo.Cal(1/6));
		EXPECT_FALSE(epo.Cal(-1/2));
	}
}

