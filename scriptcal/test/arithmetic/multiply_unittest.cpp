#include "scriptcal.h"
#include <gtest/gtest.h>

using namespace poac;

CScriptCal mul;

//ͨ���Բ���
TEST(MulTest, PositiveInput)
{
	//���Ա��ʽ�������
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

	//���Լ�����
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


	//��0���
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

//ʧЧ�Բ���
TEST(MulTest, NegativeInput)
{
	//���ʽ�޷�����
	EXPECT_FALSE(mul.InitScript("y=6x"));
	EXPECT_FALSE(mul.InitScript("y=x6"));
	EXPECT_FALSE(mul.InitScript("y=x**3"));
	EXPECT_FALSE(mul.InitScript("y=x**+3"));
	EXPECT_FALSE(mul.InitScript("y=x**-3"));
	EXPECT_FALSE(mul.InitScript("y=**x"));
	EXPECT_FALSE(mul.InitScript("y=*x"));
	EXPECT_FALSE(mul.InitScript("y=x*"));
}