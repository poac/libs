#include "scriptcal.h"
#include <gtest/gtest.h>

using namespace poac;

CScriptCal divi;

//ͨ���Բ���
TEST(DiviTest, PositiveInput)
{
	//���Ա��ʽ�������
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

	//���Լ�����
	//xΪ������ʱ
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

	//xΪ����ʱ
	if(divi.InitScript("y=2016/x") == true)
	{
		if(divi.Cal(2) == true)
			EXPECT_DOUBLE_EQ(1008, divi.GetY());
		if(divi.Cal(-4) == true)
			EXPECT_DOUBLE_EQ(-504, divi.GetY());
		EXPECT_FALSE(divi.Cal(0));   //��xȡ0ʱ�޷�����
	}

	if(divi.InitScript("y=-2016/x") == true)
	{
		if(divi.Cal(2) == true)
			EXPECT_DOUBLE_EQ(-1008, divi.GetY());
		if(divi.Cal(-4) == true)
			EXPECT_DOUBLE_EQ(504, divi.GetY());
		EXPECT_FALSE(divi.Cal(0));	//��xȡ0ʱ�޷�����
	}

	if(divi.InitScript("y=2016/+x") == true)
	{
		if(divi.Cal(2) == true)
			EXPECT_DOUBLE_EQ(1008, divi.GetY());
		if(divi.Cal(-4) == true)
			EXPECT_DOUBLE_EQ(-504, divi.GetY());
		EXPECT_FALSE(divi.Cal(0));   //��xȡ0ʱ�޷�����
	}

	if(divi.InitScript("y=2016/-x") == true)
	{
		if(divi.Cal(2) == true)
			EXPECT_DOUBLE_EQ(-1008, divi.GetY());
		if(divi.Cal(-4) == true)
			EXPECT_DOUBLE_EQ(504, divi.GetY());
		EXPECT_FALSE(divi.Cal(0));   //��xȡ0ʱ�޷�����
	}

	if(divi.InitScript("y=0/x") == true)
	{
		if(divi.Cal(2) == true)
			EXPECT_DOUBLE_EQ(0, divi.GetY());
		if(divi.Cal(-4) == true)
			EXPECT_DOUBLE_EQ(0, divi.GetY());
		EXPECT_FALSE(divi.Cal(0));	//��xȡ0ʱ�޷�����
	}
}

//ʧЧ�Բ���
TEST(DiviTest, NegetiveInput)
{
	//���ʽ�޷�����
	EXPECT_FALSE(divi.InitScript("y=x//3"));
	EXPECT_FALSE(divi.InitScript("y=x//+3"));
	EXPECT_FALSE(divi.InitScript("y=x//-3"));
	EXPECT_FALSE(divi.InitScript("y=x/"));
	EXPECT_FALSE(divi.InitScript("y=//x"));
	EXPECT_FALSE(divi.InitScript("y=/x"));

	//����Ϊ0ʱ
	if(divi.InitScript("y=x/0") == true)
	{
		EXPECT_FALSE(divi.Cal(3.6));
		EXPECT_FALSE(divi.Cal(-3.6));
		EXPECT_FALSE(divi.Cal(0));
	}

	//xΪ������x=0ʱ������������Ѳ�
}