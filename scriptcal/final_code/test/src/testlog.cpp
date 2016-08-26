
#include "testlog.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalLogTest::CScriptCalLogTest()
		{
		}

		void CScriptCalLogTest::setUp()
		{
		}

		void CScriptCalLogTest::tearDown()
		{
		}

		void CScriptCalLogTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=ln(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(6.0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), log(6.0), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0.1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), log(0.1), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(-2));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=(10)log(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), log10(6.0), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), log10(0.6), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(-2));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=(x)log(1)"));
			CPPUNIT_ASSERT(sc.SetDouble(0.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(-1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=(x)log(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(0.1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(2016));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(-1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());


			CPPUNIT_ASSERT(sc.Open("y=(10)log(x)*3"));
			CPPUNIT_ASSERT(sc.SetDouble(0.6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), log(0.6)/log(10.0)*3, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(2016));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), log(2016.0)/log(10.0)*3, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=(2)log(x)+1/ln(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(0.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), log(0.5)/log(2.0)+1/log(0.5), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(16));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), log(16.0)/log(2.0)+1/log(16.0), 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
		}

		void CScriptCalLogTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=lnx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=ln+x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=ln-x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=3ln(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=logx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=log(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=log(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=(x)log(-x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			CPPUNIT_ASSERT(sc.SetDouble(0.5));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			CPPUNIT_ASSERT(sc.SetDouble(-6));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			CPPUNIT_ASSERT(sc.SetDouble(6));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			cout << endl;
			cout << str << endl;
		}
	}
}
