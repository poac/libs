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
	// ���ַ�input�ж���������
	int GetTypeChar(char input);
private:
	enum ETypeChar{ 
		_Unknow = -1,	// δ֪����
		_Blank = 0,		// �ո�tab
		_Operate = 1,	// �����
		_Letter = 2,	// ��ĸ
		_Number = 3		// ����+��.��
	};
	COperationFactory m_OperFac;
};

};

#endif
