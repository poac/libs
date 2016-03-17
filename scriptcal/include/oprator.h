// ----------------------------------------------------
// ----------------------运算类------------------------
// ----------------------------------------------------

#ifndef _OPRATOR_H_
#define _OPRATOR_H_

namespace oprator{


template <typename T>
class COperation
{
public:
    virtual T GetResult();
    virtual void SetPara();
    virtual vector<T> GetPara();
private:
    vector<T> m_para;
};

template <typename T>
class COperationAdd:public COperation
{
// ...
public:
	T GetResult(){
		if (m_para.size < 2)
		{
			// !!
		}
		return m_para[0] + m_para[1];
	};
};

template <typename T>
class COperationSub:public COperation
{
public:
	T GetResult(){
		if (m_para.size < 2)
		{
			// !!
		}
		return m_para[0] - m_para[1];
	};
};

template <typename T>
class COperationMul:public COperation
{
public:
	T GetResult(){
		if (m_para.size < 2)
		{
			// !!
		}
		return m_para[0] * m_para[1];
	};
};

template <typename T>
class COperationDiv:public COperation
{
public:
	T GetResult(){
		if (m_para.size < 2){
			// !!
		}

		if (abs(m_para[1]) <= 0.000001){
			// !! 除数为0
		}

		return m_para[0] / m_para[1];
	};
};

// 运算工厂
template <typename T>
class COperationFactory
{
public:

	COperationFactory(){
		m_OperationSet.insert("+");
		m_OperationSet.insert("-");
		m_OperationSet.insert("*");
		m_OperationSet.insert("/");
	}

    static COperation<T> createOperation(string operate){
        // ...
		COperation oper = NULL;
		swith(operate){
			case "+":
				oper = new COperationAdd();
				break;
			case "-":
				oper = new COperationSub();
				break;
			case "*":
				oper = new COperationMul();
				break;
			case "/":
				oper = new COperationDiv();
				break;

			default:
				oper = NULL;
				break;
		}
        return oper;
    }

	static bool isOperation(string operate){
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


