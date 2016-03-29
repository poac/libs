/************************************************************************/
/*               Script：主要负责表达式转换为可计算的对象               */
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
		// 字符类型
		enum ETypeChar{ 
			_Unknow = -1,	// 未知类型
			_Blank = 0,		// 空格，tab,';'
			_Operate = 1,	// 运算符
			_Letter = 2,	// 字母
			_Number = 3		// 数字+‘.’
		};

		// 树状节点
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
			// 对字符input判定输入类型
			int GetTypeChar(char input);
			// 对输入的字符串分词
			bool SeparateStr(string input);
			void Clear();
		private:
			COperationFactory m_OperFac;	// 操作符工厂
			vector<string> m_ScriptStrPart;
		};
	};
};

#endif
