
#include "testarith.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalArithTest::CScriptCalArithTest()
		{
		}

		void CScriptCalArithTest::setUp()
		{
		}

		void CScriptCalArithTest::tearDown()
		{
		}

		void CScriptCalArithTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=x+1+6.5"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9.0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x-1-6.5"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -6.0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x*1*6.5"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9.75, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x/1/6.5"));
			CPPUNIT_ASSERT(sc.SetDouble(1.3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0.2, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x+3-1.5"));
			CPPUNIT_ASSERT(sc.SetDouble(4.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 6.0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x-3+1.5"));
			CPPUNIT_ASSERT(sc.SetDouble(4.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x+3*1.5"));
			CPPUNIT_ASSERT(sc.SetDouble(4.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9.0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x+3/1.5"));
			CPPUNIT_ASSERT(sc.SetDouble(4.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 6.5, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x*3/1.5"));
			CPPUNIT_ASSERT(sc.SetDouble(4.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9.0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x/3*1.5"));
			CPPUNIT_ASSERT(sc.SetDouble(4.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2.25, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x*3+3/1.5"));
			CPPUNIT_ASSERT(sc.SetDouble(2.0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 8.0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x*6+3/1.5-2*x"));
			CPPUNIT_ASSERT(sc.SetDouble(0.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 4.0, 0.01);
		}

		void CScriptCalArithTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=x+*6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x+/6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x-*6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x-/6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x+*6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x*/6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x/*6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=x*++6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x*+*6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x/+*6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=x+3/0"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=x+3/x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			cout << endl;
			cout << str << endl;
		}
	}
}
