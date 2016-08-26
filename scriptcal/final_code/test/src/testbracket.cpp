
#include "testbracket.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalBracketTest::CScriptCalBracketTest()
		{
		}

		void CScriptCalBracketTest::setUp()
		{
		}

		void CScriptCalBracketTest::tearDown()
		{
		}

		void CScriptCalBracketTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=x*(-6)"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -9.0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=6-(x+1)"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.5, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=6*(x+1)"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 15, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=(x+1)/6"));
			CPPUNIT_ASSERT(sc.SetDouble(11));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2.0, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=6/(x+1)"));
			CPPUNIT_ASSERT(sc.SetDouble(11));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0.5, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -12, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=(x+1)*(x-1)"));
			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 8, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x+(1+2)*(x+1)"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-0.75));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x+(1+2)*(x+1)/(x+3)"));
			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 5, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-9));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -5, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-3));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
		}

		void CScriptCalBracketTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=x+(x+1"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x+x+1)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x+(x+1("));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x+()+1"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x+)x+1)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
		}

		void CScriptCalBracketTest::TestParseErrorComplex()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=3*((x+1)+2"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=3*(x+1)+2)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=3*((x+1)+2("));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=3*((x+1)+2))"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=3*(((x+1)+2)*x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=3*((x+1)+2)*x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
		}

		void CScriptCalBracketTest::TestCalComplex()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=((x+1)+3)*2"));
			CPPUNIT_ASSERT(sc.SetDouble(3.0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 14.0, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=((x+1)+(x+3))*2"));
			CPPUNIT_ASSERT(sc.SetDouble(1.0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 12.0, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -8.0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=((x+1)*3+2)/6"));
			CPPUNIT_ASSERT(sc.SetDouble(1.0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1.333333, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -2.166667, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=16/(((x+1)+(x-3))*2)"));
			CPPUNIT_ASSERT(sc.SetDouble(5.0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1.0, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-7));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -0.5, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
		}
	}
}
