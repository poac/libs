#include "scriptcal.h"
#include <gtest/gtest.h>

using namespace poac;

CScriptCal brk;

/*������Ƕ��ʱ*/
//ͨ���Բ���
TEST(BrkTest, EasyPositiveInput)
{
	//���Ա��ʽ�������
	//��������
	EXPECT_TRUE(brk.InitScript("y=x+(-8)"));
	EXPECT_TRUE(brk.InitScript("y=x*(-8)"));
	EXPECT_TRUE(brk.InitScript("y=6+(x+1)"));
	EXPECT_TRUE(brk.InitScript("y=6-(x+1)"));
	EXPECT_TRUE(brk.InitScript("y=6*(x+1)"));
	EXPECT_TRUE(brk.InitScript("y=6/(x+1)"));
	EXPECT_TRUE(brk.InitScript("y=(x+1)*6"));
	EXPECT_TRUE(brk.InitScript("y=(x+1)/6"));
	
	//�������
	EXPECT_TRUE(brk.InitScript("y=(x+1)-(6.6+3)"));
	EXPECT_TRUE(brk.InitScript("y=(x+1)*(x-1)"));
	EXPECT_TRUE(brk.InitScript("y=x+(1+2)*(x+1)/(x+3)"));

	//���Լ�����
	//��������
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
		EXPECT_FALSE(brk.Cal(-1));	//��������Ϊ0
	}

	//�������
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
		EXPECT_FALSE(brk.Cal(-3));	//��������Ϊ0
	}
}

//ʧЧ�Բ���
TEST(BrkTest, EasyNegativeInput)
{
	//���ʽ�޷�����
	EXPECT_FALSE(brk.InitScript("y=x+(x+1"));
	EXPECT_FALSE(brk.InitScript("y=x+x+1)"));
	EXPECT_FALSE(brk.InitScript("y=x+(x+1("));
	EXPECT_FALSE(brk.InitScript("y=x+()+1"));
	EXPECT_FALSE(brk.InitScript("y=x+)x+1)"));
}


/*������Ƕ��ʱ*/
//ͨ���Բ���
TEST(BrkTest, ComplexPositiveInput)
{
	//���Ա��ʽ�������
	EXPECT_TRUE(brk.InitScript("y=((x+1)+3)*2"));
	EXPECT_TRUE(brk.InitScript("y=((x+1)+(x+3))*2"));
	EXPECT_TRUE(brk.InitScript("y=((x+1)*3+2)/6"));
	EXPECT_TRUE(brk.InitScript("y=16/(((x+1)+(x-3))*2)"));

	//���Լ�����
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
		EXPECT_FALSE(brk.Cal(1));	//��������Ϊ0
	}
}

//ʧЧ�Բ���
TEST(BrkTest, ComplexNegativeInput)
{
	//���ʽ�޷�����
	EXPECT_FALSE(brk.InitScript("y=3*((x+1)+2"));
	EXPECT_FALSE(brk.InitScript("y=3*(x+1)+2)"));
	EXPECT_FALSE(brk.InitScript("y=3*((x+1)+2("));
	EXPECT_FALSE(brk.InitScript("y=3*((x+1)+2))"));
	EXPECT_FALSE(brk.InitScript("y=3*(((x+1)+2)*x"));
	EXPECT_FALSE(brk.InitScript("y=3*((x+1)+2)*x)"));
}