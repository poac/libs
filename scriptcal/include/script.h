/************************************************************************/
/*               Script：主要负责表达式转换为可计算的对象               */
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
		// 字符\字符串类型
		enum ETypeChar{ 
			_Unknow = -1,	// 未知类型

			_Blank = 0,		// 空格，tab
			_Operate = 1,	// 运算符
			_Letter = 2,	// 字母
			_Number = 3,	// 数字
			_Semicolon = 4,	// 分号
			_Dot = 5,		// '.'
			_VariableName = 6	// 变量名
		};

		// 运算工厂
		class COperationFactory {
		public:
			static COperation * createOperation(string operate);
		};

		// 树状节点
		struct SCalNode{
			COperation m_NodeValue;
			SCalNode * m_Parent;
			vector<SCalNode*> m_Children;

			SCalNode():m_NodeValue(),m_Parent(NULL){}
			SCalNode(string name):m_NodeValue(name),m_Parent(NULL){}
			SCalNode(string name, double value):m_NodeValue(name,value),m_Parent(NULL){}

		};

		class CScript{
		public:
			CScript():head(NULL){}
			~CScript(){}
			bool InitScript(string input);
			void PrintScript();
		private:
			// 对字符input判断输入类型  
			ETypeChar GetTypeChar(char input);
			// 对字符串input判断输入类型
			ETypeChar GetTypeStr(string input);
			// 判断是否是操作符
			bool isOperator(char input);
			bool isOperator(string input);
			// 对输入的字符串分词
			bool SeparateStr(string input);
			// 对分好的字符串建树
			bool CreatScriptTree();
			// 将数值类型的string转化为double
			SVarValue CScript::String2VarValue(string input);
			// 清理成员变量
			void Clear();
		private:
			vector<string> m_ScriptStrPart;
			SCalNode * head;
		};
	};
};

#endif
