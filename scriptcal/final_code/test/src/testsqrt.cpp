
#include "testsqrt.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalSqrtTest::CScriptCalSqrtTest()
		{
		}

		void CScriptCalSqrtTest::setUp()
		{
		}

		void CScriptCalSqrtTest::tearDown()
		{
		}

		void CScriptCalSqrtTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=Sqrt(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sqrt(6.0), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-2));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			CPPUNIT_ASSERT(sc.SetDouble(-16));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Sqrt(3+x*2)"));
			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sqrt(3.0), 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-1.6));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			CPPUNIT_ASSERT(sc.SetDouble(-2016));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Sqrt(x)+Sqrt(4)/Sqrt(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sqrt(6.0)+2/sqrt(6.0), 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			CPPUNIT_ASSERT(sc.SetDouble(-2016));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Sqrt(Sqrt(x))"));
			CPPUNIT_ASSERT(sc.SetDouble(6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sqrt(sqrt(6.0)), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);
		}

		void CScriptCalSqrtTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=sqrt(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Sqrtx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Sqrt(Sqrtx)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=SqrtSqrt(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
		}
	}
}
