
#include "testmulti.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalMultiTest::CScriptCalMultiTest()
		{
		}

		void CScriptCalMultiTest::setUp()
		{
		}

		void CScriptCalMultiTest::tearDown()
		{
		}

		void CScriptCalMultiTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=6*x"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -9.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=6*+x"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -9.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=6*-x"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -9.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=-2*x"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -3.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=-x*-2"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -3.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=+x*-2"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -3.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=0*x"));
			CPPUNIT_ASSERT(sc.SetDouble(1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

		}

		void CScriptCalMultiTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=6x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x**3"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x**+3"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x**-3"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=**x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=*x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x*"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
		}
	}
}
