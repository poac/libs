
#include "testadd.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalAddTest::CScriptCalAddTest()
		{
		}

		void CScriptCalAddTest::setUp()
		{
		}

		void CScriptCalAddTest::tearDown()
		{
		}

		void CScriptCalAddTest::TestCalAdd()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=x+6"));
			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-7.2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -1.2, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 6, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x++6"));
			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-7.2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -1.2, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 6, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=+x+6"));
			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-7.2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -1.2, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 6, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x+0"));
			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-7.2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -7.2, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x+-6.6"));
			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -3.6, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-7.2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -13.8, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -6.6, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=-x+6.6"));
			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.6, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-7.2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 13.8, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 6.6, 0.01);
		}

		void CScriptCalAddTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(sc.Open("y=x+++6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=x++-6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=++x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x++"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x+"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
		}
	}
}
