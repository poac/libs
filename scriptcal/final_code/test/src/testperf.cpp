
#include "testperf.h"
//#include "poacTimer.h"
#include "boostTime.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "poacRandom.h"

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalPerfTest::CScriptCalPerfTest()
		{
		}

		void CScriptCalPerfTest::setUp()
		{
		}

		void CScriptCalPerfTest::tearDown()
		{
		}

		void CScriptCalPerfTest::TestCal()
		{
			__InitCal();
			m_nRepeatCount = 10000;
			long msScript = __ScriptCal();
			long msFunc = __FuncCal(); 
			cout << msScript << "vs" << msFunc << endl;
			CPPUNIT_ASSERT(msScript*1.0 <= msFunc*1.3);
		}

		bool CScriptCalPerfTest::__InitCal()
		{
			CScriptCal *sc = new CScriptCal();
			(sc->Open("y=2^(2)log(x)"));
			m_vCal.push_back(sc);

			sc = new CScriptCal();
			(sc->Open("y=(10)log(100)^x"));
			m_vCal.push_back(sc);

			sc = new CScriptCal();
			(sc->Open("y=x^2+ln(x)+(1.5e1)+Sin(90)-Tg(45)+Ctg(45)+Sinh(x)-Cosh(x)+Sqrt(x)-exp(0)+Abs(x)"));
			m_vCal.push_back(sc);

			sc = new CScriptCal();
			(sc->Open("y=x^2*ln(x)*(1.5e1)/Sin(90)*Tg(45)*Ctg(45)*Sinh(x)/Cosh(x)*Sqrt(x)/exp(0)*Abs(x)"));
			m_vCal.push_back(sc);

			sc = new CScriptCal();
			(sc->Open("y=x^2+ln(x)*(1.5e1)-(Sin(90)+Tg(45)+Ctg(45))+Sinh(x)*Cosh(x)/(Sqrt(4)+exp(0))+Abs(-6)"));
			m_vCal.push_back(sc);

			sc = new CScriptCal();
			(sc->Open("x=1;y=(1)|(3)@(2)"));
			m_vCal.push_back(sc);

			sc = new CScriptCal();
			(sc->Open("x=1;y=(1)xor(3)@(2)"));
			m_vCal.push_back(sc);

			sc = new CScriptCal();
			(sc->Open("x=1;y=(1)|(3)xor(2)"));
			m_vCal.push_back(sc);

			sc = new CScriptCal();
			(sc->Open("x=1;y=~(1)@(3)"));
			m_vCal.push_back(sc);

			sc = new CScriptCal();
			(sc->Open("x=1;y=2*~(1)"));
			m_vCal.push_back(sc);

			sc = new CScriptCal();
			(sc->Open("y=x^2+ln(x)*(1.5e1)-(Sin(90)+Tg(45)+Ctg(45))+Sinh(x)*Cosh(x)/(Sqrt(4)+exp(0))+Abs(-6)+((1)@(2)|(3))*~(1)"));
			m_vCal.push_back(sc);

			return true;
		}

		long CScriptCalPerfTest::__ScriptCal()
		{
			CPoacRandom pr;
			int x[100];
			for (int i=0; i<100; i++)
			{
				x[i] = pr.GetULong();
			}
			//cout << "press any key" << endl;
			//getchar();

			CPoacBoostTime pbt;
			pbt.Start();
			double y=0;

			for (int i=0; i<m_nRepeatCount; i++)
			{
				//CScriptCal sc;
				//(sc->Open("y=2^(2)log(x)"));
				(m_vCal[0]->SetDouble(x[i%100]));
				y +=(m_vCal[0]->Cal());

				(m_vCal[0]->SetDouble(x[i%100]));
				y +=(m_vCal[0]->Cal());

				//(sc->Open("y=(10)log(100)^x"));
				(m_vCal[1]->SetDouble(x[i%100]));
				y +=(m_vCal[1]->Cal());

				(m_vCal[1]->SetDouble(x[i%100]));
				y +=(m_vCal[1]->Cal());

				(m_vCal[1]->SetDouble(x[i%100]));
				y +=(m_vCal[1]->Cal());

				//(sc->Open("y=x^2+ln(x)+(1.5e1)+Sin(90)-Tg(45)+Ctg(45)+Sinh(x)-Cosh(x)+Sqrt(x)-exp(0)+Abs(x)"));
				(m_vCal[2]->SetDouble(x[i%100]));
				y +=(m_vCal[2]->Cal());

				(m_vCal[2]->SetDouble(x[i%100]));
				y +=(m_vCal[2]->Cal());

				//(sc->Open("y=x^2*ln(x)*(1.5e1)/Sin(90)*Tg(45)*Ctg(45)*Sinh(x)/Cosh(x)*Sqrt(x)/exp(0)*Abs(x)"));
				(m_vCal[3]->SetDouble(x[i%100]));
				y +=(m_vCal[3]->Cal());

				(m_vCal[3]->SetDouble(x[i%100]));
				y +=(m_vCal[3]->Cal());

				/*(sc->Open("y=x^2+ln(x)*(1.5e1)-(Sin(90)+Tg(45)+Ctg(45))+Sinh(x)*Cosh(x)/(Sqrt(4)+exp(0))+Abs(-6)"));*/

				(m_vCal[4]->SetDouble(x[i%100]));
				y +=(m_vCal[4]->Cal());

				(m_vCal[4]->SetDouble(x[i%100]));
				y +=(m_vCal[4]->Cal());

				//(sc->Open("x=1;y=(1)|(3)@(2)"));
				(m_vCal[5]->SetDouble(x[i%100]));
				y +=(m_vCal[5]->CalInt() );

				//(sc->Open("x=1;y=(1)xor(3)@(2)"));
				(m_vCal[6]->SetDouble(x[i%100]));
				(!m_vCal[6]->CalInt());

				//(sc->Open("x=1;y=(1)|(3)xor(2)"));
				(m_vCal[7]->SetDouble(x[i%100]));
				y +=(m_vCal[7]->CalInt());

				//(sc->Open("x=1;y=~(1)@(3)"));
				(m_vCal[8]->SetDouble(x[i%100]));
				y +=(m_vCal[8]->CalInt());

				//(sc->Open("x=1;y=2*~(1)"));
				(m_vCal[9]->SetDouble(x[i%100]));
				y +=(m_vCal[9]->CalInt());

				//(sc->Open("y=x^2+ln(x)*(1.5e1)-(Sin(90)+Tg(45)+Ctg(45))+Sinh(x)*Cosh(x)/(Sqrt(4)+exp(0))+Abs(-6)+((1)@(2)|(3))*~(1)"));
				(m_vCal[10]->SetDouble(x[i%100]));
				y +=(m_vCal[10]->Cal());

				(m_vCal[10]->SetDouble(x[i%100]));
				y +=(m_vCal[10]->Cal());
			}

			pbt.Stop();
			long ms = pbt.GetMillSecond();

			cout << y << endl;
			return ms;
		}

		double CScriptCalPerfTest::__Func0(double x)
		{
			return pow(2., log(x)/log(2.));
		}

		double CScriptCalPerfTest::__Func1(double x)
		{
			return pow(log(100.)/log(10.), x);
		}

		double CScriptCalPerfTest::__Func2(double x)
		{
			return pow(x,2.) + log(x) + 1.5*10.0 + sin(M_PI/2.) - tan(M_PI/2./2.) + 1/tan(M_PI/2./2.) + sinh(x/90.0*M_PI/2.) -cosh(x/90.0*M_PI/2.) + sqrt(x)-exp(0.)+abs(x);
		}

		double CScriptCalPerfTest::__Func3(double x)
		{
			return pow(x, 2.)*log(x)*1.5*10./sin(M_PI/2.)*tan(M_PI/2./2.)/tan(M_PI/2./2.)*sinh(x/90.*M_PI/2.)/cosh(x/90.*M_PI/2.)*sqrt(x)/exp(0.)*abs(x);
		}

		double CScriptCalPerfTest::__Func4(double x)
		{
			return pow(x,2.)+log(x)*1.5*10. - sin(M_PI/2.)+tan(M_PI/2./2.)+1./tan(M_PI/2./2.)+sinh(x/90.*M_PI/2.)*cosh(x/90.*M_PI/2.)/(sqrt(4.)+exp(0.)) + abs(-6);
		}

		double CScriptCalPerfTest::__Func5(double x)
		{
			return 1|3&2;
		}

		double CScriptCalPerfTest::__Func6(double x)
		{
			return 1|3^2;
		}
		double CScriptCalPerfTest::__Func7(double x)
		{
			return (~1&3);
		}
		double CScriptCalPerfTest::__Func8(double x)
		{
			return (2*~1);
		}
		double CScriptCalPerfTest::__Func9(double x)
		{
			return pow(x,2.) + log(x)*1.5*10. - (sin(M_PI/2.)+tan(M_PI/2./2.)+1/tan(M_PI/2./2.)) + sinh(x)*cosh(x)/(sqrt(4.)+exp(0.)) + abs(-6) + (1&2|3)*~1;
		}
		double CScriptCalPerfTest::__Func10(double x)
		{
			return 0;
		}

		long CScriptCalPerfTest::__FuncCal()
		{
			CPoacRandom pr;
			int x[100];
			for (int i=0; i<100; i++)
			{
				x[i] = pr.GetULong();
			}
			

			CPoacBoostTime pbt;
			pbt.Start();

			double y = 0.;
			
			for (int i=0; i<m_nRepeatCount; i++)
			{
				y+= __Func0(x[i%100]);

				y += __Func0(x[i%100]);

				y += __Func1(x[i%100]);

				y += __Func1(x[i%100]);

				y += __Func1(x[i%100]);

				y += __Func2(x[i%100]);

				y += __Func2(x[i%100]);

				y += __Func3(x[i%100]);

				y += __Func3(x[i%100]);

				y += __Func4(x[i%100]);

				y += __Func4(x[i%100]);

				y += __Func5(x[i%100]);

				//y+= 1^3&2;

				y+= __Func6(x[i%100]);

				y+= __Func7(x[i%100]);

				y+= __Func8(x[i%100]);

				y+= __Func9(x[i%100]);

				y+= __Func9(x[i%100]);
			}
			pbt.Stop();
			long ms = pbt.GetMillSecond();
			cout << y << endl;
			return ms;
		}

		void CScriptCalPerfTest::TestParseError()
		{
		}
	}
}
