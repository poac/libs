#include "script.h"

namespace poac {
	namespace script{

/************************************************************************/
/*				  COperationFactory���㹤����Ա����	                    */
/************************************************************************/
		// ���Ź�����������������Ӧ�ķ��ż������
		COperation* createOperation(string operate){
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

			ETypeChar type_First = (ETypeChar)GetTypeChar(input[0]);
			bool isFloat = false;
			switch(type_First){
			case _Number:
				// ����ַ����ǲ�������
				for (unsigned int i = 1; i < input.size(); i++){
					if (GetTypeChar(input[i]) != _Number) {
						// ���������֣��ж��Ƿ��һ�γ�����ĸe����ʾ����Ϊfloat��
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
			int len_PartStr = m_ScriptStrPart.size();
			int i = 0;
			while(i < len_PartStr && m_ScriptStrPart[i] != ";"){
				;
			}

			return true;
		}
		// �����Ա��������������
		void CScript::Clear(){
			if (m_ScriptStrPart.size() > 0) {
				m_ScriptStrPart.clear();
			}
		}

	};
};