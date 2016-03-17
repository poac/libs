#include "script.h"
#include "cal.h"

#ifndef _SCRIPTCAL_H_
#define _SCRIPTCAL_H_

namespace poac
{

class CScriptCal{
public:
	bool Cal(int x);
	bool Cal(double x);
	bool InitScript(string input);
	double GetY(){return y;}
private:
	double y;
	cal::CCal m_cal;
	script::CSript m_script;
};

};

#endif