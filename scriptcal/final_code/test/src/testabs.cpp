
#include "testabs.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalAbsTest::CScriptCalAbsTest()
		{
		}

		void CScriptCalAbsTest::setUp()
		{
		}

		void CScriptCalAbsTest::tearDown()
		{
		}

		void CScriptCalAbsTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=Abs(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(-3.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.6, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(3.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.6, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Abs(3+x*2)"));
			CPPUNIT_ASSERT(sc.SetDouble(-6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Abs(x)+3/Abs(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(-3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 4, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 4, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Abs(Abs(x))"));
			CPPUNIT_ASSERT(sc.SetDouble(-6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 6, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(9));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);
		}

		void CScriptCalAbsTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=abs(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Absx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Abs(Absx)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=AbsAbs(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
		}
	}
}
