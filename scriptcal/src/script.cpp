#include "script.h"

using namespace script;

// Script初始化工作
bool CScript::InitScript(string input){
	if (input.size() < 1 || !SeparateStr(input)) {
		// 分词失败
		return false;
	}

	return true;
}

void CScript::PrintScript(){
	for (int i = 0; i < m_ScriptStrPart.size(); i++){
		cout << m_ScriptStrPart[i] << "|";
	}
	cout << "PringScript ok " << endl;
}

// 对字符input判定输入类型：
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

// 对输入的字符串进行分词
bool CScript::SeparateStr(string input){
	int len_input = input.size();
	vector<string> part_Script;

	int i_start = 0, len_varia = 1;	
	while(i_start + len_varia -1 < len_input){
		char cNowPos = input[i_start+len_varia-1];
		int iTypeNowPos = GetTypeChar(cNowPos);
		string temp_var = input.assign(input, i_start, len_varia);
		if (iTypeNowPos == _Blank || iTypeNowPos == _Operate)
		{// 出现空格\tab\运算符
			if (len_varia == 1 && iTypeNowPos == _Blank) {
				// 若temp_var为空格或tab
				i_start++;
				len_varia = 1;
			}
			else if (len_varia == 1 && iTypeNowPos == _Operate) {
				// 为操作符
				m_ScriptStrPart.push_back(temp_var);
				i_start++;
				len_varia = 1;
			}
			else if (len_varia > 1 && GetTypeChar(input[i_start]) == _Letter) {
				// 首字母为字母
				m_ScriptStrPart.push_back(temp_var);
				i_start = i_start + len_varia;
				len_varia = 1;
			}
			else{
				// 初始化失败
				return false;
			}
		}
		else if (i_start + len_varia - 1 == len_input) {
			// 最后一个字符
			if (len_varia == 1 && iTypeNowPos == _Blank) {
				// 若temp_var为空格或tab
				break;
			}
			else if (len_varia == 1 && iTypeNowPos == _Operate) {
				// 为操作符
				m_ScriptStrPart.push_back(temp_var);
				break;
			}
			else if (len_varia > 1 && GetTypeChar(input[i_start]) == _Letter) {
				// 首字母为字母
				m_ScriptStrPart.push_back(temp_var);
				break;
			}
			else{
				// 初始化失败
				return false;
			}
		}
		else {
			// 字符或者数字
			len_varia++;
		}
	}
	return true;
}