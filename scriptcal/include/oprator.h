// ----------------------------------------------------
// ----------------------运算类------------------------
// ----------------------------------------------------

#ifndef cwj
#define cwj
#endif

#ifndef _OPRATOR_H_
#define _OPRATOR_H_

#include <string>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

namespace oprator{

	const double kMinErro = 0.0001;	// 最小误差


// 共用体,int,un int ,double
union UValue{
	int m_IntValue;
	unsigned int m_UIntValue;
	double m_DoubleValue;

	UValue():m_DoubleValue(0){}
	UValue(int value):m_IntValue(value){}
	UValue(unsigned int value):m_UIntValue(value){}
	UValue(double value):m_DoubleValue(value){}
};

// 变量结构体
struct SVarValue{
	string m_Name;
	UValue m_Value;
	int m_Type;		// type：0-double,1-int,2-unsigned int，默认取double
					// (-1)-没有值
	SVarValue():m_Name("NULL"),m_Value(),m_Type(-1){}
	SVarValue(string name):m_Name(m_Name),m_Value(),m_Type(-1){}
	SVarValue(string name, double value):m_Name(name),m_Value(value),m_Type(0){}
	SVarValue(string name, int value):m_Name(name),m_Value(value),m_Type(1){}
	SVarValue(string name, unsigned int value):m_Name(name),m_Value(value),m_Type(2){}

	double GetDoubleValue() const {
		if (m_Type == 0) {
			return m_Value.m_DoubleValue;
		}
		else if (m_Type == 1) {
			return (double)m_Value.m_IntValue;
		}
		else if (m_Type == 2) {
			return (double)m_Value.m_UIntValue;
		}
		// 没有值时
		return 0;
	}
	int GetIntValue() const {
		if (m_Type == 0) {
			if (abs(m_Value.m_DoubleValue) < kMinErro)	// 误差内可以转换
				return (int)m_Value.m_DoubleValue;
			else
				return 0;
		}
		else if (m_Type == 1) {
			return m_Value.m_IntValue;
		}
		else if (m_Type == 2) {
			return (int)m_Value.m_UIntValue;
		}
		// 没有值
		return 0;
	}
	unsigned int GetUIntValue() const {
		if (m_Type == 0) {
			if (abs(m_Value.m_DoubleValue) < kMinErro)	// 误差内可以转换
				return (unsigned int)m_Value.m_DoubleValue;
			else
				return 0;
		}
		else if (m_Type == 1) {
			return (unsigned int)m_Value.m_IntValue;
		}
		else if (m_Type == 2) {
			return m_Value.m_UIntValue;
		}
		// 没有值
		return 0;
	}

	// 运算符重载
	SVarValue operator+(const SVarValue & AddPara) const {
		if (m_Type == (-1) || AddPara.m_Type == (-1)) {
			return SVarValue("SUM");
		}

		if (m_Type == AddPara.m_Type) {	
			// 类型一致
			if (m_Type == 0) {
				return SVarValue("add", m_Value.m_DoubleValue + AddPara.m_Value.m_DoubleValue);
			}
			else if (m_Type == 1) {
				return SVarValue("add", m_Value.m_IntValue + AddPara.m_Value.m_IntValue);
			}
			else{
				return SVarValue("add", m_Value.m_UIntValue + AddPara.m_Value.m_UIntValue);
			}
		}
		else if (m_Type == 0 || AddPara.m_Type == 0) {
			// 其中有一个为double
			return SVarValue("add", GetDoubleValue() + AddPara.GetDoubleValue());
		}
		else
			return SVarValue("add", GetIntValue() + AddPara.GetIntValue());

	}	
	SVarValue operator-(const SVarValue & SubPara) const {
		if (m_Type == (-1) || SubPara.m_Type == (-1)) {
			return SVarValue("SUB");
		}

		if (m_Type == SubPara.m_Type) {	
			// 类型一致
			if (m_Type == 0) {
				return SVarValue("sub", m_Value.m_DoubleValue + SubPara.m_Value.m_DoubleValue);
			}
			else if (m_Type == 1) {
				return SVarValue("sub", m_Value.m_IntValue + SubPara.m_Value.m_IntValue);
			}
			else{
				return SVarValue("sub", m_Value.m_UIntValue + SubPara.m_Value.m_UIntValue);
			}
		}
		else if (m_Type == 0 || SubPara.m_Type == 0) {
			// 其中有一个为double
			return SVarValue("sub", GetDoubleValue() - SubPara.GetDoubleValue());
		}
		else
			return SVarValue("sub", GetIntValue() - SubPara.GetIntValue());

	}
	SVarValue operator*(const SVarValue & MulPara) const {
		if (m_Type == (-1) || MulPara.m_Type == (-1)) {
			return SVarValue("MUL");
		}

		if (m_Type == MulPara.m_Type) {	
			// 类型一致
			if (m_Type == 0) {
				return SVarValue("mul", m_Value.m_DoubleValue * MulPara.m_Value.m_DoubleValue);
			}
			else if (m_Type == 1) {
				return SVarValue("mul", m_Value.m_IntValue * MulPara.m_Value.m_IntValue);
			}
			else{
				return SVarValue("mul", m_Value.m_UIntValue * MulPara.m_Value.m_UIntValue);
			}
		}
		else if (m_Type == 0 || MulPara.m_Type == 0) {
			// 其中有一个为double
			return SVarValue("mul", GetDoubleValue() * MulPara.GetDoubleValue());
		}
		else
			return SVarValue("mul", GetIntValue() * MulPara.GetIntValue());

	}
	SVarValue operator/(const SVarValue & DivPara) const {
		if (m_Type == (-1) || DivPara.m_Type == (-1)) {
			return SVarValue("DIV");
		}

		if (abs(DivPara.GetDoubleValue()) < kMinErro) {
			// 除数为0
			return SVarValue("DIV");
		}
		// 商全部转为double型相除
		return SVarValue("div",GetDoubleValue()/DivPara.GetDoubleValue());
	}
};


class COperation{

public:
    virtual SVarValue GetResult();
//    virtual void SetPara();
    virtual vector<SVarValue> GetPara(){return m_para;}
protected:	// ??
    vector<SVarValue> m_para;
};
class COperationAdd:public COperation
{
// +运算符，两种可能，正号，加号
public:
	SVarValue GetResult(){
		if (m_para.size() < 1){
			// 参数列表为空
		}
		else if (m_para.size() < 2){
			return m_para[0];
		}
		else{
			return m_para[0] + m_para[1];
		}
	}
};
class COperationSub:public COperation{

public:
	SVarValue GetResult(){
		if (m_para.size() < 1) {
			// 参数列表为空
		}
		else if (m_para.size() < 2){
			SVarValue ZeroV("Sub",0);
			return ZeroV-m_para[0];
		}
		else{
			return m_para[0] - m_para[1];
		}
	}
};
class COperationMul:public COperation
{
public:
	SVarValue GetResult(){
		if (m_para.size() < 2)
		{
			// !!
		}
		return m_para[0] * m_para[1];
	}
};


class COperationDiv:public COperation {
public:
	SVarValue GetResult(){
		if (m_para.size() < 2){
			// !!
		}

		if (abs(m_para[1].GetDoubleValue()) <= 0.000001){
			// !! 除数为0
			return SVarValue("Div is 0");
		}
		return m_para[0] / m_para[1];
	}
};

// 运算工厂
class COperationFactory {
public:
	COperationFactory(){
		m_OperationSet.insert("+");
		m_OperationSet.insert("-");
		m_OperationSet.insert("*");
		m_OperationSet.insert("/");
		m_OperationSet.insert("(");
		m_OperationSet.insert(")");
		m_OperationSet.insert("=");
	}

  //  static COperation* createOperation(string operate){
  //      // ...
		//COperation * oper = NULL;
		//switch(operate){
		//	case "+":
		//		oper = new COperationAdd();
		//		break;
		//	case "-":
		//		oper = new COperationSub();
		//		break;
		//	case "*":
		//		oper = new COperationMul();
		//		break;
		//	case "/":
		//		oper = new COperationDiv();
		//		break;
		//	default:
		//		oper = NULL;
		//		break;
		//}
  //      return oper;
  //  };

	bool isOperation(char operate){
		string tem = string(1,operate);
		return isOperation(tem);
	}

	bool isOperation(string operate){
		//judge the operate is a operation
		if (m_OperationSet.count(operate) > 0){
			return true;
		}
		else{
			return false;
		}
	}

private:
	set<string> m_OperationSet;
};

};

#endif


