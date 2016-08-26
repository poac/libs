
#include "testcomp.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalCompTest::CScriptCalCompTest()
		{
		}

		void CScriptCalCompTest::setUp()
		{
		}

		void CScriptCalCompTest::tearDown()
		{
		}

		void CScriptCalCompTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=2^(2)log(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(0.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0.5, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 6, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=(10)log(100)^x"));
			CPPUNIT_ASSERT(sc.SetDouble(0.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), pow(2.0,0.5), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-10));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), pow(2.0,-10), 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x^2+ln(x)+(1.5e1)+Sin(90)-Tg(45)+Ctg(45)+Sinh(x)-Cosh(x)+Sqrt(x)-exp(0)+Abs(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 16+1+sinh(1.0)-cosh(1.0)+1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 16+log(4.0)+15+1+sinh(4.0)-cosh(4.0)+5, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x^2*ln(x)*(1.5e1)/Sin(90)*Tg(45)*Ctg(45)*Sinh(x)/Cosh(x)*Sqrt(x)/exp(0)*Abs(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 16*log(4.0)*15*sinh(4.0)/cosh(4.0)*8, 0.01);

			string str;
			CPPUNIT_ASSERT(sc.Open("y=x^2+ln(x)*(1.5e1)-(Sin(90)+Tg(45)+Ctg(45))+Sinh(x)*Cosh(x)/(Sqrt(4)+exp(0))+Abs(-6)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.SetDouble(1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -2+sinh(1.0)*cosh(1.0)/3+6, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 16+log(4.0)*15-3+sinh(4.0)*cosh(4.0)/3+6, 0.01);

			CPPUNIT_ASSERT(sc.Open("x=1;y=(1)|(3)@(2)"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			CPPUNIT_ASSERT(sc.CalInt() == 1|3&2);

			CPPUNIT_ASSERT(sc.Open("x=1;y=(1)xor(3)@(2)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(1));
			CPPUNIT_ASSERT(!sc.CalInt() == 1^3&2);

			CPPUNIT_ASSERT(sc.Open("x=1;y=(1)|(3)xor(2)"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			CPPUNIT_ASSERT(sc.CalInt() == 1|3^2);

			CPPUNIT_ASSERT(sc.Open("x=1;y=~(1)@(3)"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			cout << sc.CalInt() << "vs " << (~1&3) << endl;
			CPPUNIT_ASSERT(sc.CalInt() == (~1&3));

			CPPUNIT_ASSERT(sc.Open("x=1;y=2*~(1)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(1));
			cout << sc.CalInt() << "vs " << (2*~1) << endl;
			CPPUNIT_ASSERT(sc.CalInt() == (2*~1));

			CPPUNIT_ASSERT(sc.Open("y=x^2+ln(x)*(1.5e1)-(Sin(90)+Tg(45)+Ctg(45))+Sinh(x)*Cosh(x)/(Sqrt(4)+exp(0))+Abs(-6)+((1)@(2)|(3))*~(1)"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -2+sinh(1.0)*cosh(1.0)/3+6+(1&2|3)*~1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 16+log(4.0)*15-3+sinh(4.0)*cosh(4.0)/3+6+(1&2|3)*~1, 0.01);
		}

		void CScriptCalCompTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(sc.Open("y=1+(x)@(2)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=1+(x)|(2)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=1+(x)xor(2)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=1*(x)@(2)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=1*(x)|(2)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=1*(x)xor(2)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=(-3)^ln(0.5);x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=(-2)^(2.1e-1);x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=(-2)^Sin(-45);x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=ln((-2)^1);x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=ln(0e1);x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=ln(Sin(-60));x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=ln(Sinh(-1));x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=ln(~1);x=1"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Sqrt((-2)^1);x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Sqrt(ln(0.6));x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Sqrt((-1.5e1));x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Sqrt(Sin(-90));x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Sqrt(Th(-1));x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Sqrt((-1)@(-1));x=1"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=(2^2)@(ln(2));x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=(1e1)|(2);x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=~(Sin(45));x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=(Sinh(1))xor(Cosh(1));x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=(Sqrt(1.5))@(exp(1));x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=~(Abs(1.5));x=1"));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
		}
	}
}
