#include "oprator.h"
using namespace std;

namespace poac{
	namespace script{
/************************************************************************/
/*                      COperation类成员函数                            */
/************************************************************************/
		// COperation初始化
		COperation::COperation():m_Val(){
			// 初始化变量
		}
		// 获取结果，若存在返回double型值，否则返回0
		double COperation::GetResult(){
			if (IsExit()) {
				// 若存在，返回double型值
				return m_Val.GetDoubleValue();
			}
			else{
				// 否则，返回0
				return 0;
			}
		}
		// 获取结果，返回SVarValue
		SVarValue COperation::GetValue(){
			return m_Val;
		}
		//设置Value的值
		void COperation::SetValue(SVarValue s){
			m_Val = s;
		}
		// 判断Value值是否存在
		bool COperation::IsExit(){
			if (m_Val.m_Type == _Unkown) {
				// 值不存在
				return false;
			}
			else{
				return true;
			}
		}

/************************************************************************/
/*                      COperation子类函数重写                          */
/************************************************************************/
		/////////////////////////////////////////////////////////////////
		// COperationAdd类——加/正号
		/////////////////////////////////////////////////////////////////
		bool COperationAdd::Cal(){
			if (m_para.size() < 1){
				// 参数列表为空
				return false;
			}
			else if (m_para.size() < 2){
				this->SetValue(m_para[0].GetValue());
			}
			else{
				this->SetValue(m_para[0].GetValue() + m_para[0].GetValue());
			}
			return IsExit();
		}

		/////////////////////////////////////////////////////////////////
		// COperationSub类——减/负号
		/////////////////////////////////////////////////////////////////
		bool COperationSub::Cal(){
			if (m_para.size() < 1){
				// 参数列表为空
				return false;
			}
			else if (m_para.size() < 2){
				// 作为正负符号
				SVarValue Zero("Zero",0);
				this->SetValue(Zero - m_para[0].GetValue());
			}
			else{
				this->SetValue(m_para[0].GetValue() - m_para[0].GetValue());
			}
			return IsExit();
		}

		/////////////////////////////////////////////////////////////////
		// COperationMul类——乘法
		/////////////////////////////////////////////////////////////////
		bool COperationMul::Cal(){
			if (m_para.size() < 2){
				// 参数列表
				return false;
			}
			else{
				this->SetValue(m_para[0].GetValue() * m_para[0].GetValue());
			}
			return IsExit();
		}

		/////////////////////////////////////////////////////////////////
		// COperationDiv类——除法
		/////////////////////////////////////////////////////////////////
		bool COperationDiv::Cal(){
			if (m_para.size() < 2){
				// 参数列表
				return false;
			}
			//else if () {
			//}
			else {
				this->SetValue(m_para[0].GetValue() / m_para[0].GetValue());
			}
			return IsExit();
		}		

/************************************************************************/
/*				  COperationFactory运算工厂成员函数	                    */
/************************************************************************/
		// 初始化，将必要的运算符加入运算符集合
		COperationFactory::COperationFactory(){
			m_OperationSet.insert("+");
			m_OperationSet.insert("-");
			m_OperationSet.insert("*");
			m_OperationSet.insert("/");
			m_OperationSet.insert("(");
			m_OperationSet.insert(")");
			m_OperationSet.insert("=");
		}
		// 判断输入是否是运算符
		bool COperationFactory::isOperation(string operate){
			//judge the operate is a operation
			if (m_OperationSet.count(operate) > 0){
				return true;
			}
			else{
				return false;
			}
		}
		bool COperationFactory::isOperation(char operate){
			string tem = string(1,operate);
			return isOperation(tem);
		}
		// 符号工厂，针对输入产生对应的符号计算对象
		static COperation* createOperation(string operate){
		      // ...
			COperation * oper = NULL;
			if (operate.size() < 1) {
				// 输入为空
				return oper;
			}

			// 先根据首个字符进行粗分类
			char _SwichCase = operate[0];
			switch(_SwichCase){
				case '+':
					oper = new COperationAdd();
					break;
				case '-':
					oper = new COperationSub();
					break;
				case '*':
					oper = new COperationMul();
					break;
				case '/':
					oper = new COperationDiv();
					break;
				default:
					oper = NULL;
					break;
			}
		      return oper;
		};

	};// namespace script
};// namespace poac