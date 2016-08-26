
#pragma once

#ifndef POAC_SCRIPT_CAL
#define POAC_SCRIPT_CAL

#include <vector>
#include <string>

using namespace std;

namespace poac{
	namespace scriptcal
	{

		class CScriptParser;
		class CCalModel;
		class CScriptCal
		{
		public:
			CScriptCal();
			~CScriptCal(void);

			bool Open(char* strScript);

			bool SetInt(long long x);

			bool SetULL( unsigned long long x);

			bool SetDouble(double x);

			long long CalInt();

			unsigned long long CalULL();

			double Cal();

			// �õ�������Ľű�
			bool GetScript(std::string &str);
			
			// �õ�����״̬
			bool GetParseState(std::string &str);

			// �������
			bool IsCalError();

		public:
			void Name(string &strName)
			{
				sprintf(m_strName, "%s", strName.c_str());
			};

			char* Name()
			{
				return m_strName;
			};
		private:
			CScriptParser *m_pScriptParser;
			CCalModel *m_pCalModel;
			char m_strName[50];
		};
	}
}
#endif
