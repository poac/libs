#include "script.h"

namespace poac {
	namespace script{

/************************************************************************/
/*				  COperationFactory运算工厂成员函数	                    */
/************************************************************************/
		// 符号工厂，针对输入产生对应的符号计算对象
		COperation* COperationFactory::createOperation(string operate){
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
		ETypeChar CScript::GetTypeChar(char input){
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
		// 对字符串string input判断输入类型
		ETypeChar CScript::GetTypeStr(string input){
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

			ETypeChar type_First = GetTypeChar(input[0]);
			bool isFloat = false;	// 标记是否有小数点
			bool isEx = false;		// 判断是否是科学计数法
			switch(type_First){
			case _Number:
				// 检测字符串是不是数字
				for (unsigned int i = 1; i < input.size(); i++){
					if (GetTypeChar(input[i]) != _Number) {
						if (i == input.size()-1) {
							// 最后一个字符不是数字
							return _Unknow;
						}
						// 若不是数字，判断是否第一次出现字母e，表示该数为float型
						if (input[i] == 'e' /*|| input[i] == 'E'*/) {
							if (isEx == false) {
								isEx = true;
								if (input[i+1] == '-' || input[i+1] == '+') {
									// 跳过+/-号判断
									i++;
								}
							}
							else{
								return _Unknow;
							}
						}// if
						else if (GetTypeChar(input[i]) == _Dot){
							if (isFloat == false) {
								isFloat = true;
							}
							else{
								return _Unknow;
							}
						}// else if
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
		// 判断input中是否包含(
		bool CScript::isHaveLeftParenthesis(string input){
			if (input.size() < 1) {
				return false;
			}
			
			int len = input.size();
			for (int i = 0; i < len; ++i) {
				if (input[i] == '(') {
					return true;
				}
			}
			return false;
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
			// 临时变量构造树
			SCalNode *temp_ScalNode = head;
			// 字符串分割的数量
			int len_PartStr = m_ScriptStrPart.size();
			// 定义变量栈和符号栈
			stack<COperation> stack_operation;	// 貌似不需要。。只要一个临时变量即可吧………………
			string pre_operation;
			stack<COperation> stack_variable;

			int i = 0;
			while(i < len_PartStr && m_ScriptStrPart[i] != ";"){
				string tem_StrPart = m_ScriptStrPart[i];
				ETypeChar type_Str = GetTypeStr(tem_StrPart);
				if (type_Str == _VariableName) {
					// 若是变量名
					COperation temp_coperation(tem_StrPart);
					stack_variable.push(temp_coperation);
				}
				else if (type_Str == _Number) {
					COperation temp_coperation(String2VarValue(tem_StrPart));
					stack_variable.push(temp_coperation);
				}
				else if (type_Str == _Operate) {
					// 先产生对应的函数工厂，若不存在再继续判断操作符
					COperation *tem_operate = COperationFactory::createOperation(tem_StrPart);
					if (tem_operate == NULL) {
						if (tem_StrPart == ")") {
							// 若是由于）引起，向上查找
							// 先跳过处理过程
						}
						else {
							// 出现无法识别的符号
							return false;
						}
					}

					// 操作符要对当前操作符比较优先级，确定指针上移还是下移
					// 并构造计算节点SCalNode
					// 先将比较过程写在这里，需移出去
					if (GetPriority(tem_StrPart) < GetPriority(pre_operation)) {
						// 若当前加入的操作符高于之前，即等级小，向下构造树
						SCalNode *now_SCalNode = new SCalNode(*tem_operate);
						now_SCalNode->m_Parent = temp_ScalNode;
						if (temp_ScalNode != NULL) {
							// temp_ScalNode 不为空，设置孩子
							temp_ScalNode->m_Children.push_back(now_SCalNode);
						}
					}
					else {
						// 向上构造树

					}

				}

				i++;
			}

			return true;
		}
		// 将数值类型的string转化为double
		SVarValue CScript::String2VarValue(string input){
			// 注，由于正负号与字符串分离，因此第一个符号不会出现+/-
			// 只可能在科学计数法中字母e后出现+/-
			if (GetTypeStr(input) != _Number || input.size() < 1) {
				return SVarValue("NULL");
			}

			double val_input = 0;
			int len_input = input.size();
			int i = 0;
			// 整数部分
			while(i < len_input && input[i] != '.' && input[i] != 'e'/* 大写E暂不考虑*/){
				val_input *= 10;
				val_input += input[i] - '0';
				i++;
			}
			// 小数部分
			if (i < len_input && input[i] == '.') {
				i++;
				double _div = 10.0;
				while(i < len_input && input[i] != 'e'){
					val_input += (input[i] - '0')/_div;
					_div *= 10.0;
					i++;
				}
			}
			// 指数部分
			int input_index = 0;
			bool flag = true;	// 正负号，默认为正
			if (i < len_input && input[i] == 'e') {
				i++;
				if (input[i] == '+') {
					flag = true;
					i++;
				}
				else if (input[i] == '-') {
					flag = false;
					i++;
				}
				// 记录指数值
				while(i < len_input){
					input_index *= 10;
					input_index += input[i] - '0';
					i++;
				}

				if (flag == false) {
					// 为负
					input_index *= (-1);
				}

				val_input *= pow(10.0,input_index);
			}

			//if (abs(val_input-(int)val_input) < gk_MinErro) {
			//	// 为整形
			//	return SVarValue(input,(int)val_input);
			//}
			//else
				return SVarValue(input,val_input);
		}
		// 清理成员变量，重新生成
		void CScript::Clear(){
			if (m_ScriptStrPart.size() > 0) {
				m_ScriptStrPart.clear();
			}
		}
	};
};