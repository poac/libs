
#include "testsub.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalSubTest::CScriptCalSubTest()
		{
		}

		void CScriptCalSubTest::setUp()
		{
		}

		void CScriptCalSubTest::tearDown()
		{
		}

		void CScriptCalSubTest::TestCalSub()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=x-6.6"));
			CPPUNIT_ASSERT(sc.SetDouble(7));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0.4, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(3.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -3, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1.4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -8, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -6.6, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x-+6.6"));
			CPPUNIT_ASSERT(sc.SetDouble(7));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0.4, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(3.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -3, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1.4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -8, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -6.6, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=+x-6.6"));
			CPPUNIT_ASSERT(sc.SetDouble(7));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0.4, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(3.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -3, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1.4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -8, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -6.6, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x--2.016"));
			CPPUNIT_ASSERT(sc.SetDouble(0.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2.616, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-2.016));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2.016, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=-x-2.016"));
			CPPUNIT_ASSERT(sc.SetDouble(0.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -2.616, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-2.016));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -2.016, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x-0"));
			CPPUNIT_ASSERT(sc.SetDouble(6.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 6.6, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-6.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -6.6, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=0-x"));
			CPPUNIT_ASSERT(sc.SetDouble(-666));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 666, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(66.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -66.6, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=1.6-x"));
			CPPUNIT_ASSERT(sc.SetDouble(0.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-3.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 5.1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1.6, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=1.6-+x"));
			CPPUNIT_ASSERT(sc.SetDouble(0.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-3.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 5.1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1.6, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=1.6--x"));
			CPPUNIT_ASSERT(sc.SetDouble(0.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2.2, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-3.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -1.9, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1.6, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=-10-x"));
			CPPUNIT_ASSERT(sc.SetDouble(0.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -10.6, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-3.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -6.5, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -10, 0.01);
		}

		void CScriptCalSubTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(sc.Open("y=x--+6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=x---6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=--x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x--"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x-"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
		}
	}
}
