#include "script.h"

#ifndef _CAL_H_
#define _CAL_H_

namespace cal{
// cal �����ռ�

class CCal{
public:
	bool CalScript(const script::CSript & CalModel, int x);
	bool CalScript(const script::CSript & CalModel, double x);
	double GetResult(){return result;}
private:
	double result;
};

};


#endif