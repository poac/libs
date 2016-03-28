#include "script.h"

namespace poac {
	namespace script{

		// Script��ʼ������
		bool CScript::InitScript(string input){
			if (input.size() < 1 || !SeparateStr(input)) {
				// �ִ�ʧ��
				return false;
			}

			return true;
		}

		void CScript::PrintScript(){
			for (int i = 0; i < m_ScriptStrPart.size(); i++){
				cout << m_ScriptStrPart[i] << "|";
			}
			cout << endl;
		}

		// ���ַ�input�ж��������ͣ�
		int CScript::GetTypeChar(char input){
			if (input == ' ' || input == '	' || input == ';') {
				return _Blank;
			}

			if (m_OperFac.isOperation(input)) {
				return _Operate;
			}

			if ((input <= 'z' && input >= 'a') || (input <= 'Z' && input >= 'A'))
			{
				return _Letter;
			}

			if ((input <= '9' && input >= '0') || input == '.')
			{
				return _Number;
			}

			return _Unknow;
		}//GetTypeChar

		// ��������ַ������зִ�
		bool CScript::SeparateStr(string input){
			int len_input = input.size();
			int i_start = 0, len_varia = 1;	
			while(i_start + len_varia <= len_input){
				char cNowPos = input[i_start+len_varia-1];
				int iTypeNowPos = GetTypeChar(cNowPos);
				string temp_var;
				temp_var.assign(input, i_start, len_varia);
				if (iTypeNowPos == _Blank || iTypeNowPos == _Operate)
				{// ���ֿո�\tab\�����
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
						// Ϊ������
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
					// �ַ���������
					len_varia++;
				}
			}
			return true;
		}

	};
};