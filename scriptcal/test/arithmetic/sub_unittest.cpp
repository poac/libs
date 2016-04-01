#include "scriptcal.h"
#include <gtest/gtest.h>

using namespace poac;

CScriptCal sub;

//ͨ���Բ���
TEST(AddTest,PositiveInput)
{
	//���Ա��ʽ�������
	EXPECT_TRUE(sub.InitScript("y=x-1.6"));
	EXPECT_TRUE(sub.InitScript("y=+x-1.6"));
	EXPECT_TRUE(sub.InitScript("y=-x-1.6"));
	EXPECT_TRUE(sub.InitScript("y=x-+1.6"));
	EXPECT_TRUE(sub.InitScript("y=x--1.6"));
	EXPECT_TRUE(sub.InitScript("y=x-0"));
	EXPECT_TRUE(sub.InitScript("y=0-x"));
	EXPECT_TRUE(sub.InitScript("y=-1.6-x"));
	EXPECT_TRUE(sub.InitScript("y=+1.6-x"));
	EXPECT_TRUE(sub.InitScript("y=1.6-+x"));
	EXPECT_TRUE(sub.InitScript("y=1.6--x"));
	EXPECT_TRUE(sub.InitScript("y=1.6-x"));

	
	//���Լ�����
	//xΪ������ʱ
	if(sub.InitScript("y=x-6.6") == true)
	{
		//����������
		if(sub.Cal(7) == true)
		{
			EXPECT_DOUBLE_EQ(0.4, sub.GetY());
		}
		if(sub.Cal(3.6) == true)
		{
			EXPECT_DOUBLE_EQ(-3, sub.GetY());
		}
		//����������
		if(sub.Cal(-1.4) == true)
		{
			EXPECT_DOUBLE_EQ(-8, sub.GetY());
		}
		//0������
		if(sub.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(-6.6, sub.GetY());
		}
	}

	if(sub.InitScript("y=x-+6.6") == true)
	{
		//����������
		if(sub.Cal(7) == true)
		{
			EXPECT_DOUBLE_EQ(0.4, sub.GetY());
		}
		if(sub.Cal(3.6) == true)
		{
			EXPECT_DOUBLE_EQ(-3, sub.GetY());
		}
		//����������
		if(sub.Cal(-1.4) == true)
		{
			EXPECT_DOUBLE_EQ(-8, sub.GetY());
		}
		//0������
		if(sub.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(-6.6, sub.GetY());
		}
	}

	if(sub.InitScript("y=+x-6.6") == true)
	{
		//����������
		if(sub.Cal(7) == true)
		{
			EXPECT_DOUBLE_EQ(0.4, sub.GetY());
		}
		if(sub.Cal(3.6) == true)
		{
			EXPECT_DOUBLE_EQ(-3, sub.GetY());
		}
		//����������
		if(sub.Cal(-1.4) == true)
		{
			EXPECT_DOUBLE_EQ(-8, sub.GetY());
		}
		//0������
		if(sub.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(-6.6, sub.GetY());
		}
	}

	if(sub.InitScript("y=x--2.016") == true)
	{
		//xΪ����
		if(sub.Cal(0.6) == true)
			EXPECT_DOUBLE_EQ(2.616, sub.GetY());
		//xΪ����
		if(sub.Cal(-2.016) == true)
			EXPECT_DOUBLE_EQ(0, sub.GetY());
		//xΪ0
		if(sub.Cal(0) == true)
			EXPECT_DOUBLE_EQ(2.016, sub.GetY());
	}

	if(sub.InitScript("y=-x-2.016") == true)
	{
		//xΪ����
		if(sub.Cal(0.6) == true)
			EXPECT_DOUBLE_EQ(-2.616, sub.GetY());
		//xΪ����
		if(sub.Cal(-2.016) == true)
			EXPECT_DOUBLE_EQ(0, sub.GetY());
		//xΪ0
		if(sub.Cal(0) == true)
			EXPECT_DOUBLE_EQ(-2.016, sub.GetY());
	}

	if(sub.InitScript("y=x-0") == true)
	{
		if(sub.Cal(6.6) == true)
		{
			EXPECT_DOUBLE_EQ(6.6, sub.GetY());
		}
		if(sub.Cal(-6.6) == true)
		{
			EXPECT_DOUBLE_EQ(-6.6, sub.GetY());
		}
		if(sub.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(0, sub.GetY());
		}
	}

	//xΪ����ʱ
	if(sub.InitScript("y=0-x") == true)
	{
		if(sub.Cal(-666) == true)
		{
			EXPECT_DOUBLE_EQ(666, sub.GetY());
		}
		if(sub.Cal(66.6) == true)
		{
			EXPECT_DOUBLE_EQ(-66.6, sub.GetY());
		}
		if(sub.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(0, sub.GetY());
		}
	}

	if(sub.InitScript("y=1.6-x") == true)
	{
		//xΪ����
		if(sub.Cal(0.6) == true)
			EXPECT_DOUBLE_EQ(1.0, sub.GetY());
		//xΪ����
		if(sub.Cal(-3.5) == true)
			EXPECT_DOUBLE_EQ(5.1, sub.GetY());
		//xΪ0
		if(sub.Cal(0) == true)
			EXPECT_DOUBLE_EQ(1.6, sub.GetY());
	}

	if(sub.InitScript("y=1.6-+x") == true)
	{
		//xΪ����
		if(sub.Cal(0.6) == true)
			EXPECT_DOUBLE_EQ(1.0, sub.GetY());
		//xΪ����
		if(sub.Cal(-3.5) == true)
			EXPECT_DOUBLE_EQ(5.1, sub.GetY());
		//xΪ0
		if(sub.Cal(0) == true)
			EXPECT_DOUBLE_EQ(1.6, sub.GetY());
	}

	if(sub.InitScript("y=1.6--x") == true)
	{
		//xΪ����
		if(sub.Cal(0.6) == true)
			EXPECT_DOUBLE_EQ(2.2, sub.GetY());
		//xΪ����
		if(sub.Cal(-3.5) == true)
			EXPECT_DOUBLE_EQ(-1.9, sub.GetY());
		//xΪ0
		if(sub.Cal(0) == true)
			EXPECT_DOUBLE_EQ(1.6, sub.GetY());
	}

	if(sub.InitScript("y=-10-x") == true)
	{
		//xΪ����
		if(sub.Cal(0.6) == true)
			EXPECT_DOUBLE_EQ(-10.6, sub.GetY());
		//xΪ����
		if(sub.Cal(-3.5) == true)
			EXPECT_DOUBLE_EQ(-6.5, sub.GetY());
		//xΪ0
		if(sub.Cal(0) == true)
			EXPECT_DOUBLE_EQ(-10, sub.GetY());
	}

}

//ʧЧ�Բ���
TEST(SubTest, NegetiveInput)
{
	//���ʽ�޷�����
	EXPECT_FALSE(sub.InitScript("y=x--+6"));
	EXPECT_FALSE(sub.InitScript("y=x---6"));
	EXPECT_FALSE(sub.InitScript("y=--x"));
	EXPECT_FALSE(sub.InitScript("y=x--"));
	EXPECT_FALSE(sub.InitScript("y=x-"));
}
