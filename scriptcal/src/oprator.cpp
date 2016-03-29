#include "oprator.h"
using namespace std;

namespace poac{
	namespace script{
/************************************************************************/
/*                      COperation���Ա����                            */
/************************************************************************/
		// COperation��ʼ��
		COperation::COperation():m_Val(){
			// ��ʼ������
		}
		// ��ȡ����������ڷ���double��ֵ�����򷵻�0
		double COperation::GetResult(){
			if (IsExit()) {
				// �����ڣ�����double��ֵ
				return m_Val.GetDoubleValue();
			}
			else{
				// ���򣬷���0
				return 0;
			}
		}
		// ��ȡ���������SVarValue
		SVarValue COperation::GetValue(){
			return m_Val;
		}
		//����Value��ֵ
		void COperation::SetValue(SVarValue s){
			m_Val = s;
		}
		// �ж�Valueֵ�Ƿ����
		bool COperation::IsExit(){
			if (m_Val.m_Type == _Unkown) {
				// ֵ������
				return false;
			}
			else{
				return true;
			}
		}

/************************************************************************/
/*                      COperation���ຯ����д                          */
/************************************************************************/
		/////////////////////////////////////////////////////////////////
		// COperationAdd�ࡪ����/����
		/////////////////////////////////////////////////////////////////
		bool COperationAdd::Cal(){
			if (m_para.size() < 1){
				// �����б�Ϊ��
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
		// COperationSub�ࡪ����/����
		/////////////////////////////////////////////////////////////////
		bool COperationSub::Cal(){
			if (m_para.size() < 1){
				// �����б�Ϊ��
				return false;
			}
			else if (m_para.size() < 2){
				// ��Ϊ��������
				SVarValue Zero("Zero",0);
				this->SetValue(Zero - m_para[0].GetValue());
			}
			else{
				this->SetValue(m_para[0].GetValue() - m_para[0].GetValue());
			}
			return IsExit();
		}

		/////////////////////////////////////////////////////////////////
		// COperationMul�ࡪ���˷�
		/////////////////////////////////////////////////////////////////
		bool COperationMul::Cal(){
			if (m_para.size() < 2){
				// �����б�
				return false;
			}
			else{
				this->SetValue(m_para[0].GetValue() * m_para[0].GetValue());
			}
			return IsExit();
		}

		/////////////////////////////////////////////////////////////////
		// COperationDiv�ࡪ������
		/////////////////////////////////////////////////////////////////
		bool COperationDiv::Cal(){
			if (m_para.size() < 2){
				// �����б�
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
/*				  COperationFactory���㹤����Ա����	                    */
/************************************************************************/
		// ��ʼ��������Ҫ��������������������
		COperationFactory::COperationFactory(){
			m_OperationSet.insert("+");
			m_OperationSet.insert("-");
			m_OperationSet.insert("*");
			m_OperationSet.insert("/");
			m_OperationSet.insert("(");
			m_OperationSet.insert(")");
			m_OperationSet.insert("=");
		}
		// �ж������Ƿ��������
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
		// ���Ź�����������������Ӧ�ķ��ż������
		static COperation* createOperation(string operate){
		      // ...
			COperation * oper = NULL;
			if (operate.size() < 1) {
				// ����Ϊ��
				return oper;
			}

			// �ȸ����׸��ַ����дַ���
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