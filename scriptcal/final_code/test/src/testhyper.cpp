
#include "testhyper.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalHyperTest::CScriptCalHyperTest()
		{
		}

		void CScriptCalHyperTest::setUp()
		{
		}

		void CScriptCalHyperTest::tearDown()
		{
		}

		void CScriptCalHyperTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=Sinh(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(-6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sinh(-6.0), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(2016));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sinh(2016.0), 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Cosh(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(-2));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), cosh(-2.), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(2016));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), cosh(2016.0), 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Th(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(-3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), tanh(-3.0), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(2016));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), tanh(2016.0), 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Sinh(x)+3*Th(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(-3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sinh(-3.0)+3*tanh(-3.0), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sinh(3.0)+3*tanh(3.0), 0.01);

			string str;
			CPPUNIT_ASSERT(sc.Open("y=Sinh(Cosh(x))"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
			CPPUNIT_ASSERT(sc.SetDouble(-3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sinh(cosh(-3.0)), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sinh(cosh(0.)), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(2016));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sinh(cosh(2016.0)), 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Th(Sinh(x))"));
			CPPUNIT_ASSERT(sc.SetDouble(-3));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), tanh(sinh(-3.0)), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), tanh(sinh(6.0)), 0.01);
		}

		void CScriptCalHyperTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=sinh(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=cosh(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=th(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=tanh(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Sinhx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Coshx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Thx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=SinhSinh(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=SinhTh(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Th(Sinhx)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
		}
	}
}
