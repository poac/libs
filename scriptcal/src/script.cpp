#include "script.h"

namespace poac {
	namespace script{

/************************************************************************/
/*				  COperationFactory���㹤����Ա����	                    */
/************************************************************************/
		// ���Ź�����������������Ӧ�ķ��ż������
		COperation* COperationFactory::createOperation(string operate){
			// ...
			COperation * oper = NULL;
			if (operate.size() < 1) {
				// ����Ϊ��
				return oper;
			}

			// �ȸ����׸��ַ����дַ���
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
/*			        	     CScript��Ա����	                        */
/************************************************************************/
		// Script��ʼ������
		bool CScript::InitScript(string input){
			Clear();
			if (input.size() < 1 || !SeparateStr(input)) {
				// �ִ�ʧ��
				return false;
			}

			return true;
		}
		// ��ӡ�ִ����
		void CScript::PrintScript(){
			for (unsigned int i = 0; i < m_ScriptStrPart.size(); i++){
				cout << m_ScriptStrPart[i] << "|";
			}
			cout << endl;
		}

		// ���ַ�input�ж��������ͣ�
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
		// ���ַ���string input�ж���������
		ETypeChar CScript::GetTypeStr(string input){
			// ����Ϊ0
			if (input.size() < 1) {
				return _Unknow;
			}

			// ����ֻ��1������ĸ��Ϊ����������
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
			bool isFloat = false;	// ����Ƿ���С����
			bool isEx = false;		// �ж��Ƿ��ǿ�ѧ������
			switch(type_First){
			case _Number:
				// ����ַ����ǲ�������
				for (unsigned int i = 1; i < input.size(); i++){
					if (GetTypeChar(input[i]) != _Number) {
						if (i == input.size()-1) {
							// ���һ���ַ���������
							return _Unknow;
						}
						// ���������֣��ж��Ƿ��һ�γ�����ĸe����ʾ����Ϊfloat��
						if (input[i] == 'e' /*|| input[i] == 'E'*/) {
							if (isEx == false) {
								isEx = true;
								if (input[i+1] == '-' || input[i+1] == '+') {
									// ����+/-���ж�
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
						// ����������\��ĸ
						return _Unknow;
					}
				}
				return _VariableName;
			default:
				return _Unknow;
			}

		}
		// �ж�input�Ƿ��ǲ�����
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
		// �ж�input���Ƿ����(
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
		// ��������ַ������зִ�
		bool CScript::SeparateStr(string input){
			int len_input = input.size();
			int i_start = 0, len_varia = 1;	
			while(i_start + len_varia <= len_input){
				char cNowPos = input[i_start+len_varia-1];
				int iTypeNowPos = GetTypeChar(cNowPos);
				string temp_var;
				temp_var.assign(input, i_start, len_varia);
				if (iTypeNowPos == _Blank || iTypeNowPos == _Operate || iTypeNowPos == _Semicolon)
				{// ���ֿո�\tab\�����\�ֺ�
					if (iTypeNowPos == _Blank) {
						// ��temp_varΪ�ո��tab
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
						// Ϊ�������������ҽ��ֺ���Ϊ�������һ�ֽ���
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
					// ���һ���ַ��Ҳ�Ϊ�ո�\������
					if (len_varia > 1 && GetTypeChar(input[i_start]) == _Number && iTypeNowPos == _Letter) {
						// ����������ĸΪ����
						return false;
					}
					else{
						m_ScriptStrPart.push_back(temp_var);
						break;
					}
				}
				else {
					// �ַ�\����\.
					len_varia++;
				}
			}
			return true;
		}
		// �Էֺõ��ַ�������
		bool CScript::CreatScriptTree(){
			// ��ʱ����������
			SCalNode *temp_ScalNode = head;
			// �ַ����ָ������
			int len_PartStr = m_ScriptStrPart.size();
			// �������ջ�ͷ���ջ
			stack<COperation> stack_operation;	// ò�Ʋ���Ҫ����ֻҪһ����ʱ�������ɰɡ�����������
			string pre_operation;
			stack<COperation> stack_variable;

			int i = 0;
			while(i < len_PartStr && m_ScriptStrPart[i] != ";"){
				string tem_StrPart = m_ScriptStrPart[i];
				ETypeChar type_Str = GetTypeStr(tem_StrPart);
				if (type_Str == _VariableName) {
					// ���Ǳ�����
					COperation temp_coperation(tem_StrPart);
					stack_variable.push(temp_coperation);
				}
				else if (type_Str == _Number) {
					COperation temp_coperation(String2VarValue(tem_StrPart));
					stack_variable.push(temp_coperation);
				}
				else if (type_Str == _Operate) {
					// �Ȳ�����Ӧ�ĺ������������������ټ����жϲ�����
					COperation *tem_operate = COperationFactory::createOperation(tem_StrPart);
					if (tem_operate == NULL) {
						if (tem_StrPart == ")") {
							// �������ڣ��������ϲ���
							// �������������
						}
						else {
							// �����޷�ʶ��ķ���
							return false;
						}
					}

					// ������Ҫ�Ե�ǰ�������Ƚ����ȼ���ȷ��ָ�����ƻ�������
					// ���������ڵ�SCalNode
					// �Ƚ��ȽϹ���д��������Ƴ�ȥ
					if (GetPriority(tem_StrPart) < GetPriority(pre_operation)) {
						// ����ǰ����Ĳ���������֮ǰ�����ȼ�С�����¹�����
						SCalNode *now_SCalNode = new SCalNode(*tem_operate);
						now_SCalNode->m_Parent = temp_ScalNode;
						if (temp_ScalNode != NULL) {
							// temp_ScalNode ��Ϊ�գ����ú���
							temp_ScalNode->m_Children.push_back(now_SCalNode);
						}
					}
					else {
						// ���Ϲ�����

					}

				}

				i++;
			}

			return true;
		}
		// ����ֵ���͵�stringת��Ϊdouble
		SVarValue CScript::String2VarValue(string input){
			// ע���������������ַ������룬��˵�һ�����Ų������+/-
			// ֻ�����ڿ�ѧ����������ĸe�����+/-
			if (GetTypeStr(input) != _Number || input.size() < 1) {
				return SVarValue("NULL");
			}

			double val_input = 0;
			int len_input = input.size();
			int i = 0;
			// ��������
			while(i < len_input && input[i] != '.' && input[i] != 'e'/* ��дE�ݲ�����*/){
				val_input *= 10;
				val_input += input[i] - '0';
				i++;
			}
			// С������
			if (i < len_input && input[i] == '.') {
				i++;
				double _div = 10.0;
				while(i < len_input && input[i] != 'e'){
					val_input += (input[i] - '0')/_div;
					_div *= 10.0;
					i++;
				}
			}
			// ָ������
			int input_index = 0;
			bool flag = true;	// �����ţ�Ĭ��Ϊ��
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
				// ��¼ָ��ֵ
				while(i < len_input){
					input_index *= 10;
					input_index += input[i] - '0';
					i++;
				}

				if (flag == false) {
					// Ϊ��
					input_index *= (-1);
				}

				val_input *= pow(10.0,input_index);
			}

			//if (abs(val_input-(int)val_input) < gk_MinErro) {
			//	// Ϊ����
			//	return SVarValue(input,(int)val_input);
			//}
			//else
				return SVarValue(input,val_input);
		}
		// �����Ա��������������
		void CScript::Clear(){
			if (m_ScriptStrPart.size() > 0) {
				m_ScriptStrPart.clear();
			}
		}
	};
};