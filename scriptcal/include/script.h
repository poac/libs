/************************************************************************/
/*               Script����Ҫ������ʽת��Ϊ�ɼ���Ķ���               */
/************************************************************************/
#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cmath>
#include "oprator.h"
using namespace std;

namespace poac{ 
	namespace script{
		// �ַ�\�ַ�������
		enum ETypeChar{ 
			_Unknow = -1,	// δ֪����

			_Blank = 0,		// �ո�tab
			_Operate = 1,	// �����
			_Letter = 2,	// ��ĸ
			_Number = 3,	// ����
			_Semicolon = 4,	// �ֺ�
			_Dot = 5,		// '.'
			_VariableName = 6	// ������
		};

		// ���㹤��
		class COperationFactory {
		public:
			static COperation * createOperation(string operate);
		};

		// ��״�ڵ�
		struct SCalNode{
			COperation m_NodeValue;
			SCalNode * m_Parent;
			vector<SCalNode*> m_Children;
			
			SCalNode():m_NodeValue(),m_Parent(NULL){}
			SCalNode(const COperation coperation):m_NodeValue(coperation),m_Parent(NULL){
				// ָ��ŵ��ⲿ���п��ǰɡ������繹������
			}
			SCalNode(string name):m_NodeValue(name),m_Parent(NULL){}
			SCalNode(string name, double value):m_NodeValue(name,value),m_Parent(NULL){}

			SCalNode(const SCalNode &CopyScalNode){
				// �������ƺ���
				m_NodeValue = CopyScalNode.m_NodeValue;
				m_Parent = CopyScalNode.m_Parent;
				m_Children.clear();
				for (int i = 0; i < CopyScalNode.m_Children.size(); i++) {
					m_Children.push_back(CopyScalNode.m_Children[i]);
				}
			}
		};

		class CScript{
		public:
			CScript():head(NULL){}
			~CScript(){}
			bool InitScript(string input);
			void PrintScript();
		private:
			// ���ַ�input�ж���������  
			ETypeChar GetTypeChar(char input);
			// ���ַ���input�ж���������
			ETypeChar GetTypeStr(string input);
			// �ж��Ƿ��ǲ�����
			bool isOperator(char input);
			bool isOperator(string input);
			// �ж�input���Ƿ����(
			bool isHaveLeftParenthesis(string input);
			// ��������ַ����ִ�
			bool SeparateStr(string input);
			// �Էֺõ��ַ�������
			bool CreatScriptTree();
			// ����ֵ���͵�stringת��Ϊdouble
			SVarValue CScript::String2VarValue(string input);
			// �����Ա����
			void Clear();
		private:
			vector<string> m_ScriptStrPart;
			SCalNode * head;
		};
	};
};

#endif
