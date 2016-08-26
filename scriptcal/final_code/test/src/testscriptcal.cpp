
#include "testscriptcal.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalTest::CScriptCalTest()
		{
		}

		void CScriptCalTest::setUp()
		{
		}

		void CScriptCalTest::tearDown()
		{
		}

		void CScriptCalTest::TestCal4power()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=x^(-3)*-2.5^3-3"));
			string str;
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), pow(3.33,-3)*pow(-2.5,3)-3, 0.01);

			CPPUNIT_ASSERT(sc.Open("a=7;b=3;y=x*(3+a)/-2.5-3"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.33*(3+7)/-2.5-3, 0.01);
		}		

		void CScriptCalTest::TestCal4()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=x*-2.5-3"));
			string str;
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.33*-2.5-3, 0.01);

			CPPUNIT_ASSERT(sc.Open("a=7;b=3;y=x*(3+a)/-2.5-3"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.33*(3+7)/-2.5-3, 0.01);
		}		

		void CScriptCalTest::TestCalAdd()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=x+1"));
			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 4.33, 0.01);
			string str;
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=+x++1"));
			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 4.33, 0.01);
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=(x+(1+3.5))"));
			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 7.83, 0.01);
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << str << endl;
		}

		void CScriptCalTest::TestCalAddMinus()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=x-1"));
			string str;
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2.33, 0.01);


			CPPUNIT_ASSERT(sc.Open("y=(x+(1-3.5))"));
			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.33-2.5, 0.01);
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=(x-(a-3.5));a=5.3;"));
			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.33-(5.3-3.5), 0.01);
			CPPUNIT_ASSERT(sc.GetParseState(str));
			CPPUNIT_ASSERT(sc.GetScript(str));
			cout << str << endl;
		}

		void CScriptCalTest::TestParseError()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(!sc.Open("y=x-1-"));
			string str;
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=)x-1"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("x-1"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x-a"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y="));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
		}

		void CScriptCalTest::TestCalSin()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=Sin(x)+1"));
			string str;
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sin(3.33*M_PI/180.0)+1, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Cos(Sin(x))"));
			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), cos(sin(3.33*M_PI/180.0)*M_PI/180.0), 0.01);
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=Sin((x+1)*2.5)-Cos((x-1)*2.5)"));
			CPPUNIT_ASSERT(sc.SetDouble(3.33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sin((3.33+1)*2.5*M_PI/180.0)-cos((3.33-1)*2.5*M_PI/180.0), 0.01);
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << str << endl;
		}
	}
}
