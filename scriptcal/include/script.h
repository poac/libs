#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include <string>
#include <vector>
#include <iostream>
#include "oprator.h"
using namespace std;
using namespace oprator;

namespace script{


class CScript{
public:
	CScript(){}
	~CScript(){}
	bool InitScript(string input);
	void PrintScript();
private:
	// ���ַ�input�ж���������
	int GetTypeChar(char input);
	// ��������ַ����ִ�
	bool SeparateStr(string input);
private:
	enum ETypeChar{ 
		_Unknow = -1,	// δ֪����
		_Blank = 0,		// �ո�tab,';'
		_Operate = 1,	// �����
		_Letter = 2,	// ��ĸ
		_Number = 3		// ����+��.��
	};
	COperationFactory m_OperFac;	// ����������
	vector<string> m_ScriptStrPart;
};

};

#endif
