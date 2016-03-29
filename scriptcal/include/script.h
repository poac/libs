/************************************************************************/
/*               Script����Ҫ������ʽת��Ϊ�ɼ���Ķ���               */
/************************************************************************/
#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include <string>
#include <vector>
#include <iostream>
#include "oprator.h"
using namespace std;

namespace poac{ 
	namespace script{
		// �ַ�����
		enum ETypeChar{ 
			_Unknow = -1,	// δ֪����
			_Blank = 0,		// �ո�tab,';'
			_Operate = 1,	// �����
			_Letter = 2,	// ��ĸ
			_Number = 3		// ����+��.��
		};

		// ��״�ڵ�
		struct SCalNode{
			COperation m_NodeValue;
			SCalNode * m_Parent;
			vector<SCalNode*> m_Children;


		};

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
			void Clear();
		private:
			COperationFactory m_OperFac;	// ����������
			vector<string> m_ScriptStrPart;
		};
	};
};

#endif
