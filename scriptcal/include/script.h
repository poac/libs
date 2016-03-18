#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include <string>
#include <iostream>
using namespace std;

namespace script{

template<typename T>
struct SVariableValue{
	string m_Variable;
	T m_Value;
	SVariableValue(string name):m_Variable(name),m_Value(0){}
};

class CSript{
public:
	CSript();
	bool InitScript(string input);

private:

};

};

#endif
