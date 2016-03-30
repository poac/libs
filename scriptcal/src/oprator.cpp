#include "oprator.h"
using namespace std;

namespace poac{
	namespace script{
/************************************************************************/
/*                      COperation类成员函数                            */
/************************************************************************/
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
		// 返回IsExit的值
		bool COperation::Cal(){
			return IsExit();
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

		/////////////////////////////////////////////////////////////////
		// COperationEqu类——等号
		/////////////////////////////////////////////////////////////////
		bool COperationEqu::Cal(){
			if (m_para.size() < 1){
				// 参数列表
				return false;
			}
			else {
				this->SetValue(m_para[0].GetValue());
			}
			return IsExit();
		}	

	};// namespace script
};// namespace poac