//#include"scriptcal.h"
//#include<iostream>
//#include <gtest/gtest.h>
//#include <string>
//#include <stdio.h>
//
//using namespace poac;
//using namespace std;
//
//double _x[] = {-1.0,0,1.0};
//double _y[3] = {0};
//for (int i = 0; i < sizeof(_x); i++)
//{
//	_y[i] = _x[i] + 19;
//}
//string s = "y=x+19;x=";
//string _s[3], s2[3];
//for (int i = 0; i < 3; i++)
//{
//	char buffer[20];
//	sprintf(buffer , "%f" , _x[i]);
//	s2[i] = buffer;
//	_s[i] = s + s2[i];
//}
//
////此处将_s[i]传入到接口中，利用其解析的结果计算出相应表达式的值
//TEST(AdditionTest,HandleInput)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		EXPECT_EQ(_y[i],val2);
//	}
//}