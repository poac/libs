#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include <string>
#include <vector>
#include <iostream>
#include "oprator.h"
using namespace std;
using namespace oprator;

namespace script{


class CSript{
public:
	CSript();
	~CSript();
	bool InitScript(string input);

private:
	// 对字符input判定输入类型
	int GetTypeChar(char input);
private:
	enum ETypeChar{ 
		_Unknow = -1,	// 未知类型
		_Blank = 0,		// 空格，tab
		_Operate = 1,	// 运算符
		_Letter = 2,	// 字母
		_Number = 3		// 数字+‘.’
	};
	COperationFactory m_OperFac;
};

};

#endif
