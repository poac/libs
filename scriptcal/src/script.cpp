#include "script.h"

namespace poac {
	namespace script{

/************************************************************************/
/*				  COperationFactory运算工厂成员函数	                    */
/************************************************************************/
		// 符号工厂，针对输入产生对应的符号计算对象
		COperation* createOperation(string operate){
			// ...
			COperation * oper = NULL;
			if (operate.size() < 1) {
				// 输入为空
				return oper;
			}

			// 先根据首个字符进行粗分类
			char _SwichCase = operate[0];
			switch(_SwichCase){
			case '+':
				oper = new COperationAdd();
				break;
			case '-':
				oper = new COperationSub();
				break;
			case '*':
				oper = new COperationMul();
				break;
			case '/':
				oper = new COperationDiv();
				break;
			case '=':
				oper = new COperationEqu();
				break;
			default:
				oper = NULL;
				break;
			}
			return oper;
		};
/************************************************************************/
/*			        	     CScript成员函数	                        */
/************************************************************************/
		// Script初始化工作
		bool CScript::InitScript(string input){
			Clear();
			if (input.size() < 1 || !SeparateStr(input)) {
				// 分词失败
				return false;
			}

			return true;
		}
		// 打印分词情况
		void CScript::PrintScript(){
			for (unsigned int i = 0; i < m_ScriptStrPart.size(); i++){
				cout << m_ScriptStrPart[i] << "|";
			}
			cout << endl;
		}

		// 对字符input判定输入类型：
		int CScript::GetTypeChar(char input){
			if (input == ' ' || input == '	') {
				return _Blank;
			}
			if (isOperator(input)) {
				return _Operate;
			}
			if ((input <= 'z' && input >= 'a') || (input <= 'Z' && input >= 'A'))
			{
				return _Letter;
			}
			if (input <= '9' && input >= '0')
			{
				return _Number;
			}
			if (input == '.') {
				return _Dot;
			}
			if (input == ';') {
				return _Semicolon;
			}
			return _Unknow;
		}//GetTypeChar
		int CScript::GetTypeStr(string input){
			// 长度为0
			if (input.size() < 1) {
				return _Unknow;
			}

			// 长度只有1，将字母改为变量名即可
			if (input.size() == 1) {
				char tem = input[0];
				if (GetTypeChar(tem) == _Letter) {
					return _VariableName;
				}
				else{
					return GetTypeChar(tem);
				}
			}

			if (isOperator(input)) {
				return _Operate;
			}

			ETypeChar type_First = (ETypeChar)GetTypeChar(input[0]);
			bool isFloat = false;
			switch(type_First){
			case _Number:
				// 检测字符串是不是数字
				for (unsigned int i = 1; i < input.size(); i++){
					if (GetTypeChar(input[i]) != _Number) {
						// 若不是数字，判断是否第一次出现字母e，表示该数为float型
						if (input[i] == 'e') {
							if (isFloat == false) {
								isFloat = true;
							}
							else{
								return _Unknow;
							}
						}
						else{
							return _Unknow;
						}
					}
				}
				return _Number;
			case _Letter:
				for (unsigned int i = 1; i < input.size(); i++){
					if (GetTypeChar(input[i]) != _Number || GetTypeChar(input[i]) != _Letter) {
						// 若不是数字\字母
						return _Unknow;
					}
				}
				return _VariableName;
			default:
				return _Unknow;
			}

		}
		// 判断input是否是操作符
		bool CScript::isOperator(string input){
			int len_OperatorList = sizeof(gk_Operators)/sizeof(string);
			int i = 0;
			while(i < len_OperatorList){
				if (input == gk_Operators[i]) {
					return true;
				}
				i++;
			}
			return false;
		}
		bool CScript::isOperator(char input){
			string tem(1,input);
			return isOperator(tem);
		}
		// 对输入的字符串进行分词
		bool CScript::SeparateStr(string input){
			int len_input = input.size();
			int i_start = 0, len_varia = 1;	
			while(i_start + len_varia <= len_input){
				char cNowPos = input[i_start+len_varia-1];
				int iTypeNowPos = GetTypeChar(cNowPos);
				string temp_var;
				temp_var.assign(input, i_start, len_varia);
				if (iTypeNowPos == _Blank || iTypeNowPos == _Operate || iTypeNowPos == _Semicolon)
				{// 出现空格\tab\运算符\分号
					if (iTypeNowPos == _Blank) {
						// 若temp_var为空格或tab
						if (len_varia > 1) {
							temp_var.assign(input, i_start, len_varia-1);
							m_ScriptStrPart.push_back(temp_var);

							i_start += len_varia;
							len_varia = 1;
						}
						else{
							i_start++;
							len_varia = 1;
						}
					}
					else{
						// 为操作符——暂且将分号作为运算符的一种进行
						if (len_varia > 1) {
							temp_var.assign(input, i_start, len_varia-1);
							m_ScriptStrPart.push_back(temp_var);
							i_start += len_varia - 1;
							len_varia = 1;
						}
							temp_var.assign(input, i_start, len_varia);
							m_ScriptStrPart.push_back(temp_var);
							i_start++;
							len_varia = 1;
					}
				}
				else if (i_start + len_varia == len_input) {
					// 最后一个字符且不为空格\操作符
					if (len_varia > 1 && GetTypeChar(input[i_start]) == _Number && iTypeNowPos == _Letter) {
						// 变量名首字母为数字
						return false;
					}
					else{
						m_ScriptStrPart.push_back(temp_var);
						break;
					}
				}
				else {
					// 字符\数字\.
					len_varia++;
				}
			}
			return true;
		}
		// 对分好的字符串建树
		bool CScript::CreatScriptTree(){
			int len_PartStr = m_ScriptStrPart.size();
			int i = 0;
			while(i < len_PartStr && m_ScriptStrPart[i] != ";"){
				;
			}

			return true;
		}
		// 清理成员变量，重新生成
		void CScript::Clear(){
			if (m_ScriptStrPart.size() > 0) {
				m_ScriptStrPart.clear();
			}
		}

	};
};