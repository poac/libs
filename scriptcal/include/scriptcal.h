#include "script.h"
//#include "script.cpp"
#include "cal.h"
//#include "cal.cpp"

#ifndef _SCRIPTCAL_H_
#define _SCRIPTCAL_H_

namespace poac
{
	 namespace script{

class CScriptCal{
public:
	bool Cal(int x);
	bool Cal(double x);
	bool InitScript(string input);
	double GetY(){return y;}
private:
	double y;
	CCal m_cal;
	script::CScript m_script;
};

};
};

#endif