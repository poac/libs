// ----------------------------------------------------
// ----------------------������------------------------
// ----------------------------------------------------
#ifndef _OPRATOR_H_
#define _OPRATOR_H_

#include <string>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

namespace poac{
	namespace script{
		const double gk_MinErro = 0.0001;	// ��С���
		enum ETypeValue{
			_Unkown = -1,		// û�и�ֵ
			_DoubleVale = 0,	// double��
			_IntVale = 1,		// ���ͱ���
			_UnIntVale = 2		// �޷�������
		};
		const string gk_Operators[] = {
			"=",
			"+", "-",
			"*", "/",
			"(", ")",
			"In", "Sin", "Cos", "Tg", "Ctg", "Sinh", "Cosh", "Th", "exp", "Abs", "hex2dec",
			"@", "~", "xor"
		};

		int GetPriority(string input){
			// ������Ϊ�գ�ȡ��͵ȼ�����û�еȼ�
			if (input.size() == 0) {
				// ���ܺ�����Ҫ�޸Ļ����
				return 10;
			}

			// =Ĭ��ȡ��͵ĵȼ�������NULL��һ�㣬�ο�NULL�޸�
			if (input == "=") {
				return 9;
			}

			// ����
			string _No1_Priority[] = { "(", ")" };
			// һԪ�����
			string _No2_Priority[] = { "~",
				"In", "Sin", "Cos", "Tg", "Ctg", "Sinh", "Cosh", "Th", "exp", "Abs", "hex2dec"
			};
			// ��Ԫ�����
			string _No3_Priority[] = {
				"*", "/"
			};
			string _No4_Priority[] = {
				"+", "-"
			};

			for (int i = 0; i < sizeof(_No1_Priority)/sizeof(string); i++){
				if (input == _No1_Priority[i]) {
					return 1;
				}
			}
			
			for (int i = 0; i < sizeof(_No2_Priority)/sizeof(string); i++){
				if (input == _No2_Priority[i]) {
					return 2;
				}
			}

			for (int i = 0; i < sizeof(_No3_Priority)/sizeof(string); i++){
				if (input == _No3_Priority[i]) {
					return 3;
				}
			}

			for (int i = 0; i < sizeof(_No3_Priority)/sizeof(string); i++){
				if (input == _No3_Priority[i]) {
					return 4;
				}
			}
			return -1;
		}


		// ������,int,un int ,double
		union UValue{
			int m_IntValue;
			unsigned int m_UIntValue;
			double m_DoubleValue;

			UValue():m_DoubleValue(0){}
			UValue(int value):m_IntValue(value){}
			UValue(unsigned int value):m_UIntValue(value){}
			UValue(double value):m_DoubleValue(value){}
		};
		// �����ṹ��
		struct SVarValue{
			string m_Name;
			UValue m_Value;
			int m_Type;		// type��0-double,1-int,2-unsigned int��Ĭ��ȡdouble
					// (-1)-û��ֵ
			SVarValue():m_Name("NULL"),m_Value(),m_Type(_Unkown){}
			SVarValue(string name):m_Name(m_Name),m_Value(),m_Type(_Unkown){}
			SVarValue(string name, double value):m_Name(name),m_Value(value),m_Type(_DoubleVale){}
			SVarValue(string name, int value):m_Name(name),m_Value(value),m_Type(_IntVale){}
			SVarValue(string name, unsigned int value):m_Name(name),m_Value(value),m_Type(_UnIntVale){}
			SVarValue(const SVarValue& s):m_Name(s.m_Name),m_Value(s.m_Value),m_Type(s.m_Type){}

			double GetDoubleValue() const {
				if (m_Type == _DoubleVale) {
					return m_Value.m_DoubleValue;
				}
				else if (m_Type == _IntVale) {
					return (double)m_Value.m_IntValue;
				}
				else if (m_Type == _UnIntVale) {
					return (double)m_Value.m_UIntValue;
				}
				// û��ֵʱ
				return 0;
			}
			int GetIntValue() const {
				if (m_Type == _DoubleVale) {
					if (abs(m_Value.m_DoubleValue) < gk_MinErro)	// ����ڿ���ת��
						return (int)m_Value.m_DoubleValue;
					else
						return 0;
				}
				else if (m_Type == _IntVale) {
					return m_Value.m_IntValue;
				}
				else if (m_Type == _UnIntVale) {
					return (int)m_Value.m_UIntValue;
				}
				// û��ֵ
				return 0;
			}
			unsigned int GetUIntValue() const {
				if (m_Type == _DoubleVale) {
					if (abs(m_Value.m_DoubleValue) < gk_MinErro)	// ����ڿ���ת��
						return (unsigned int)m_Value.m_DoubleValue;
					else
						return 0;
				}
				else if (m_Type == _IntVale) {
					return (unsigned int)m_Value.m_IntValue;
				}
				else if (m_Type == _UnIntVale) {
					return m_Value.m_UIntValue;
				}
				// û��ֵ
				return 0;
			}

			// ���������
			SVarValue operator=(const SVarValue & s) {
				this->m_Name = s.m_Name;
				this->m_Value = s.m_Value;
				this->m_Type = s.m_Type;
				return *this;
			}
			SVarValue operator+(const SVarValue & AddPara) const {
				if (m_Type == (_Unkown) || AddPara.m_Type == (_Unkown)) {
					return SVarValue("SUM");
				}

				if (m_Type == AddPara.m_Type) {	
					// ����һ��
					if (m_Type == _DoubleVale) {
						return SVarValue("add", m_Value.m_DoubleValue + AddPara.m_Value.m_DoubleValue);
					}
					else if (m_Type == _IntVale) {
						return SVarValue("add", m_Value.m_IntValue + AddPara.m_Value.m_IntValue);
					}
					else{
						return SVarValue("add", m_Value.m_UIntValue + AddPara.m_Value.m_UIntValue);
					}
				}
				else if (m_Type == _DoubleVale || AddPara.m_Type == _DoubleVale) {
					// ������һ��Ϊdouble
					return SVarValue("add", GetDoubleValue() + AddPara.GetDoubleValue());
				}
				else
					return SVarValue("add", GetIntValue() + AddPara.GetIntValue());

			}	
			SVarValue operator-(const SVarValue & SubPara) const {
				if (m_Type == (_Unkown) || SubPara.m_Type == (_Unkown)) {
					return SVarValue("SUB");
				}

				if (m_Type == SubPara.m_Type) {	
					// ����һ��
					if (m_Type == _DoubleVale) {
						return SVarValue("sub", m_Value.m_DoubleValue + SubPara.m_Value.m_DoubleValue);
					}
					else if (m_Type == _IntVale) {
						return SVarValue("sub", m_Value.m_IntValue + SubPara.m_Value.m_IntValue);
					}
					else{
						return SVarValue("sub", m_Value.m_UIntValue + SubPara.m_Value.m_UIntValue);
					}
				}
				else if (m_Type == _DoubleVale || SubPara.m_Type == _DoubleVale) {
					// ������һ��Ϊdouble
					return SVarValue("sub", GetDoubleValue() - SubPara.GetDoubleValue());
				}
				else
					return SVarValue("sub", GetIntValue() - SubPara.GetIntValue());

			}
			SVarValue operator*(const SVarValue & MulPara) const {
				if (m_Type == (_Unkown) || MulPara.m_Type == (_Unkown)) {
					return SVarValue("MUL");
				}

				if (m_Type == MulPara.m_Type) {	
					// ����һ��
					if (m_Type == _DoubleVale) {
						return SVarValue("mul", m_Value.m_DoubleValue * MulPara.m_Value.m_DoubleValue);
					}
					else if (m_Type == _IntVale) {
						return SVarValue("mul", m_Value.m_IntValue * MulPara.m_Value.m_IntValue);
					}
					else{
						return SVarValue("mul", m_Value.m_UIntValue * MulPara.m_Value.m_UIntValue);
					}
				}
				else if (m_Type == _IntVale || MulPara.m_Type == _IntVale) {
					// ������һ��Ϊdouble
					return SVarValue("mul", GetDoubleValue() * MulPara.GetDoubleValue());
				}
				else
					return SVarValue("mul", GetIntValue() * MulPara.GetIntValue());

			}
			SVarValue operator/(const SVarValue & DivPara) const {
				if (m_Type == (-1) || DivPara.m_Type == (-1)) {
					return SVarValue("DIV");
				}

				if (abs(DivPara.GetDoubleValue()) < gk_MinErro) {
					// ����Ϊ0
					return SVarValue("DIV");
				}
				// ��ȫ��תΪdouble�����
				return SVarValue("div",GetDoubleValue()/DivPara.GetDoubleValue());
			}
		};

		class COperation{
		public:
			// ���캯��
			COperation(){}
			COperation(SVarValue svarvalue):m_Val(svarvalue){}
			COperation(string name):m_Val(name){}
			COperation(string name, double value):m_Val(name,value){}
			COperation(string name, int value):m_Val(name,value){}
			COperation(string name, unsigned int value):m_Val(name,value){}
			// ��������
			virtual ~COperation(){}
			// ��ȡ���������double
			double GetResult();
			// ��ȡ���������SVarValue
			SVarValue GetValue();
			//����Value��ֵ
			void SetValue(SVarValue s);
			// ����ֵ����¼��m_Val
			virtual bool Cal();
			// �ж�Valueֵ�Ƿ����
			bool IsExit();
		public:
			vector<COperation> m_para;
		private:
			SVarValue m_Val;
		};
		class COperationAdd:public COperation {
			// ��дcal���㺯��
			bool Cal();
		};
		class COperationSub:public COperation {
			// ��дcal���㺯��
			bool Cal();
		};
		class COperationMul:public COperation {
			// ��дcal���㺯��
			bool Cal();
		};
		class COperationDiv:public COperation {
			// ��дcal���㺯��
			bool Cal();
		};
		class COperationEqu:public COperation{
		public:
			bool Cal();
		};
	};
};

#endif


