#include "scriptcal.h"
#include <gtest/gtest.h>

using namespace poac;

CScriptCal add1,add2;

//ͨ���Բ���
TEST(AddTest,PositiveInput)
{
	//���Ա��ʽ�������
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

	//���Լ�����
	if(add2.InitScript("y=x+6") == true)
	{
		//�������������
		if(add2.Cal(3) == true)
		{
			EXPECT_DOUBLE_EQ(9.0, add2.GetY());
		}
		//�������������
		if(add2.Cal(-7.2) == true)
		{
			EXPECT_DOUBLE_EQ(-1.2, add2.GetY());
		}
		//��0���
		if(add2.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(6, add2.GetY());
		}
	}

	if(add2.InitScript("y=x++6") == true)
	{
		//�������������
		if(add2.Cal(3) == true)
		{
			EXPECT_DOUBLE_EQ(9.0, add2.GetY());
		}
		//�������������
		if(add2.Cal(-7.2) == true)
		{
			EXPECT_DOUBLE_EQ(-1.2, add2.GetY());
		}
		//��0���
		if(add2.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(6, add2.GetY());
		}
	}

	if(add2.InitScript("y=+x+6") == true)
	{
		//�������������
		if(add2.Cal(3) == true)
		{
			EXPECT_DOUBLE_EQ(9.0, add2.GetY());
		}
		//�������������
		if(add2.Cal(-7.2) == true)
		{
			EXPECT_DOUBLE_EQ(-1.2, add2.GetY());
		}
		//��0���
		if(add2.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(6, add2.GetY());
		}
	}

	if(add2.InitScript("y=x+0") == true)
	{
		//�������������
		if(add2.Cal(3) == true)
		{
			EXPECT_DOUBLE_EQ(3, add2.GetY());
		}
		//�������������
		if(add2.Cal(-7.2) == true)
		{
			EXPECT_DOUBLE_EQ(-7.2, add2.GetY());
		}
		//��0���
		if(add2.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(0, add2.GetY());
		}
	}

	if(add2.InitScript("y=x+-6.6") == true)
	{
		//�������������
		if(add2.Cal(3) == true)
		{
			EXPECT_DOUBLE_EQ(-3.6, add2.GetY());
		}
		//�������������
		if(add2.Cal(-7.2) == true)
		{
			EXPECT_DOUBLE_EQ(-13.8, add2.GetY());
		}
		//��0���
		if(add2.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(-6.6, add2.GetY());
		}
	}

	if(add2.InitScript("y=-x+6.6") == true)
	{
		//�������������
		if(add2.Cal(3) == true)
		{
			EXPECT_DOUBLE_EQ(3.6, add2.GetY());
		}
		//�������������
		if(add2.Cal(-7.2) == true)
		{
			EXPECT_DOUBLE_EQ(13.8, add2.GetY());
		}
		//��0���
		if(add2.Cal(0) == true)
		{
			EXPECT_DOUBLE_EQ(6.6, add2.GetY());
		}
	}
}

//ʧЧ�Բ���
TEST(AddTest, NegetiveInput)
{
	//���ʽ�޷�����
	EXPECT_FALSE(add1.InitScript("y=x+++6"));
	EXPECT_FALSE(add1.InitScript("y=x++-6"));
	EXPECT_FALSE(add1.InitScript("y=++x"));
	EXPECT_FALSE(add1.InitScript("y=x++"));
	EXPECT_FALSE(add1.InitScript("y=x+"));
}