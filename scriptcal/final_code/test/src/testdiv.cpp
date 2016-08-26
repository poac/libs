
#include "testdiv.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalDivTest::CScriptCalDivTest()
		{
		}

		void CScriptCalDivTest::setUp()
		{
		}

		void CScriptCalDivTest::tearDown()
		{
		}

		void CScriptCalDivTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=x/3"));
			CPPUNIT_ASSERT(sc.SetDouble(3.3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1.1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -0.33333, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x/+3"));
			CPPUNIT_ASSERT(sc.SetDouble(3.3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1.1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -0.3333, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x/-3"));
			CPPUNIT_ASSERT(sc.SetDouble(3.3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -1.1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0.3333, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=-x/3"));
			CPPUNIT_ASSERT(sc.SetDouble(3.3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -1.1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0.3333, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=+x/3"));
			CPPUNIT_ASSERT(sc.SetDouble(3.3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1.1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -0.3333, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=2016/x"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1008, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -504, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=-2016/x"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -1008, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 504, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());


			CPPUNIT_ASSERT(sc.Open("y=2016/+x"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1008, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -504, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=2016/-x"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -1008, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 504, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=0/x"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-4));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
		}

		void CScriptCalDivTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=x//3"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x//+3"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x//-3"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x/"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=//x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=/x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=x/0"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			cout << endl;
			cout << str << endl;
		}
	}
}
