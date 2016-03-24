#include "script.h"

using namespace script;

// Script初始化工作
bool CSript::InitScript(string input){
	int len_input = input.size();
	vector<string> part_Script;

	int i_start = 0, len_varia = 1;	
	while(i_start + len_varia -1 < len_input){
		
		char cNowPos = input[i_start+len_varia-1];
		int iTypeNowPos = GetTypeChar(cNowPos);
		if (iTypeNowPos == 0 || iTypeNowPos == 1)
		{// 出现空格\tab\运算符
			string temp_var = input.assign(input, i_start, len_varia);
			// 若temp_var为空格或tab
			if (len_varia == 1 && iTypeNowPos == _Blank) {
				i_start++;
				len_varia = 1;
			}
			else if (len_varia == 1 && iTypeNowPos == _Operate) {

			}
		}
		else{// 字符
			len_varia++;
		}


	}

	return true;
}


// 对字符input判定输入类型：
int CSript::GetTypeChar(char input){
	if (input == ' ' || input == '	') {
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