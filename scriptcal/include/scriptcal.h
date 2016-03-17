#ifndef _SCRIPTCAL_H_
#define _SCRIPTCAL_H_

namespace poac
{

class CScriptCal{
public:
	double Cal(int x);
	double Cal(double x);
	bool InitScript(string input);

private:
	cal::CCal m_cal;
	script::CSript m_script;
};

};

#endif