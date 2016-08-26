
#include "testexp.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalExpTest::CScriptCalExpTest()
		{
		}

		void CScriptCalExpTest::setUp()
		{
		}

		void CScriptCalExpTest::tearDown()
		{
		}

		void CScriptCalExpTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=x^2"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2.25, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x^(-2)"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0.25, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0.25, 0.01);

			double x = pow(0, -2.);
			cout << endl;
			cout << x << endl;
			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=-x^2"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -2.25, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -9, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=(-x)^3"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -8, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 27, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x^0"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			x = pow(-3., 0);
			cout << endl;
			cout << x << endl;
			CPPUNIT_ASSERT(sc.SetDouble(-3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x^(1-0.5)"));
			CPPUNIT_ASSERT(sc.SetDouble(4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-9));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=2^x"));
			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 8, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(),0.25, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=-2^x"));
			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -8, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(),-0.25, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -1, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x^2^3"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 64, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(),64, 0.01);

			x = pow(pow(0., 2.), 3.);
			cout << endl;
			cout << x << endl;
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=2^x^3"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 64, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(),0.125, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=3*4^x"));
			CPPUNIT_ASSERT(sc.SetDouble(0.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 6, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(),0.75, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x^2*3^x"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 36, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(),0.333333, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x^2+3*x^(-2)"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 4.75, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(),4, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);
		}

		void CScriptCalExpTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=x^-3"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=3^-x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x^+3"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=3^+x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x^^3"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x^"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=^x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));

			CPPUNIT_ASSERT(sc.Open("y=(-4)^x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.SetDouble(1/2.));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			CPPUNIT_ASSERT(sc.SetDouble(-1/2.));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
		}
	}
}
