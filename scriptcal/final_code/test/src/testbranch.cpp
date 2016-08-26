
#include "testbranch.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalBranchTest::CScriptCalBranchTest()
		{
		}

		void CScriptCalBranchTest::setUp()
		{
		}

		void CScriptCalBranchTest::tearDown()
		{
		}

		void CScriptCalBranchTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=0<x<=10:ln(x)#10<x<=20:x+6#20<x:6*x+2016"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), log(2.0), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(20));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 26, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(100));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2616, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=0<x<=10:ln(x)+b#10<x<=20:x+6#20<x:6*x+2016;a=0;b=10;"));
			CPPUNIT_ASSERT(sc.SetDouble(2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), log(2.0)+10, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=-10<x<=0:-x#20>=x>10:x+6#20<x<=100:6*x+2016"));
			CPPUNIT_ASSERT(sc.SetDouble(-9));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(20));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 26., 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(100));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2616, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-10));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			CPPUNIT_ASSERT(sc.SetDouble(1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			CPPUNIT_ASSERT(sc.SetDouble(10));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			CPPUNIT_ASSERT(sc.SetDouble(100.1));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=-99999<x<=0:   -x  #  0<x<=99999   :x"));
			CPPUNIT_ASSERT(sc.SetDouble(-9));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(99999));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 99999, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(-99999));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
			CPPUNIT_ASSERT(sc.SetDouble(100000));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
		}

		void CScriptCalBranchTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=0<x<=10:ln(x)#x>10,x<=20:x+6#20<x:6*x+2016"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=ln(x):0<x<=10#x>10:x+6"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=0<x<=10£ºln(x)#10<x<=20£ºx+6#20<x£º6*x+2016"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=-1<x<=0:1/x#0<x:x"));
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
