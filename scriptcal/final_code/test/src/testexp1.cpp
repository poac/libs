
#include "testexp1.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalExp1Test::CScriptCalExp1Test()
		{
		}

		void CScriptCalExp1Test::setUp()
		{
		}

		void CScriptCalExp1Test::tearDown()
		{
		}

		void CScriptCalExp1Test::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=exp(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(-3.0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), exp(-3.0), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(6.0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), exp(6.0), 0.01);

			CPPUNIT_ASSERT(sc.Open("y=exp(3+x*2)"));
			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), exp(3.0), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1.0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(6.0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), exp(15.0), 0.01);

			CPPUNIT_ASSERT(sc.Open("y=exp(x)+3/exp(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(-6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), exp(-6.0)+3./exp(-6.0), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 4, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=exp(exp(x))"));
			CPPUNIT_ASSERT(sc.SetDouble(2016));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), exp(exp(2016.0)), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), exp(1.0), 0.01);
		}

		void CScriptCalExp1Test::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=expx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=exp(expx)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=expexp(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			//CPPUNIT_ASSERT(sc.Open("y=x/0"));
			//CPPUNIT_ASSERT(sc.GetScript(str));
			//CPPUNIT_ASSERT(sc.GetParseState(str));
			//CPPUNIT_ASSERT(sc.SetDouble(1));
			//sc.Cal();
			//CPPUNIT_ASSERT(sc.IsCalError());
			//cout << endl;
			//cout << str << endl;
		}
	}
}
