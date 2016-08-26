
#include "testsci.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalSciTest::CScriptCalSciTest()
		{
		}

		void CScriptCalSciTest::setUp()
		{
		}

		void CScriptCalSciTest::tearDown()
		{
		}

		void CScriptCalSciTest::TestCal()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(sc.Open("y=((5)e(1))+x;"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 50, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=((5)e+1)+x;"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 50, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=(-(5)e(1))+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -50, 0.01);

			CPPUNIT_ASSERT(sc.Open("e=2;y=(e-1)+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=(+5e1)+x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 50, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=-(5e-1)+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -0.5, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=(5e002)+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 500, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=(1.6e2)+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 160, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x+(1.5e2)"));
			CPPUNIT_ASSERT(sc.SetDouble(-6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 144, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(2000));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2150, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 150, 0.01);


			CPPUNIT_ASSERT(sc.Open("y=x-(-1.6e2)"));
			CPPUNIT_ASSERT(sc.SetDouble(2000));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(),2160, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(),154, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 160, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x*(5e-1)"));
			CPPUNIT_ASSERT(sc.SetDouble(2000));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1000, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -3, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x^(1e+1)"));
			CPPUNIT_ASSERT(sc.SetDouble(2000));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), pow(2000.0,10), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), pow(-6.0,10), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=(3e-1)*(10)log((2e1))+x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0.3*log10(20.0), 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Sin((9e1))+Cos((0e8))+Tg((4.5e1))*Ctg((-4.5e1))+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Sinh((6e-1)*(1e1))+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sinh(6.0), 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Sqrt((1.6e1))+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 4, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=exp((2.0e2))+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), exp(200.0), 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Abs((-2.016e3))+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2016, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=(6)@((2.1e1))+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=~((-1e2))+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
		}

		void CScriptCalSciTest::TestParseError()
		{
/*	y=1e6;
	y=-2e2;
	y=(3e1.2);	//e前面可以是小数，e后面只能是整数
	y=ln(2e2);
	y=Sin(9e1);
	y=Cos(6e1);
	y=Tg(4.5e1);
	y=Sin(1e1);
	y=Sqrt(1e1);
	y=exp(1e1);
	y=Abs(1e1);
	y=(1)@(1e1);
	y=(1)xor(1e1);
	y=~(1e1);

	*/
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=Abs((-2.016E3))"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

		}
	}
}
