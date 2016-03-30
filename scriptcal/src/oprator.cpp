#include "oprator.h"
using namespace std;

namespace poac{
	namespace script{
/************************************************************************/
/*                      COperation���Ա����                            */
/************************************************************************/
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
		// ����IsExit��ֵ
		bool COperation::Cal(){
			return IsExit();
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

		/////////////////////////////////////////////////////////////////
		// COperationEqu�ࡪ���Ⱥ�
		/////////////////////////////////////////////////////////////////
		bool COperationEqu::Cal(){
			if (m_para.size() < 1){
				// �����б�
				return false;
			}
			else {
				this->SetValue(m_para[0].GetValue());
			}
			return IsExit();
		}	

	};// namespace script
};// namespace poac