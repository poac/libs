#include "script.h"
//#include "script.cpp"
#include "cal.h"
//#include "cal.cpp"

#ifndef _SCRIPTCAL_H_
#define _SCRIPTCAL_H_

namespace poac {
	 namespace script {

		class CScriptCal{
		public:
			bool Cal(int x){return true;}
			bool Cal(double x){return true;}
			bool InitScript(string input){return true;}
			double GetY(){return y;}
		private:
			double y;
			CCal m_cal;
			CScript m_script;
		};

	};// namespace script
};//namespace poac

#endif