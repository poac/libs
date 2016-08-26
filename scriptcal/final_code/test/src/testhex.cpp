
#include "testhex.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalHexTest::CScriptCalHexTest()
		{
		}

		void CScriptCalHexTest::setUp()
		{
		}

		void CScriptCalHexTest::tearDown()
		{
		}

		void CScriptCalHexTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=hex2dec(x)"));
			CPPUNIT_ASSERT(sc.SetInt(-5));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -5, 0.01);

			CPPUNIT_ASSERT(sc.SetULL(33));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 33, 0.01);

			CPPUNIT_ASSERT(sc.SetInt(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=hex2dec(x)+3"));
			CPPUNIT_ASSERT(sc.SetInt(6));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 9, 0.01);

			CPPUNIT_ASSERT(sc.SetInt(-1));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 2, 0.01);

			CPPUNIT_ASSERT(sc.SetInt(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 3, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=x@0xF0"));
			CPPUNIT_ASSERT(sc.SetInt(0x33));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)0x30);

			CPPUNIT_ASSERT(sc.SetInt(0x0F));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetULL(0xFF));
			CPPUNIT_ASSERT_EQUAL(sc.CalULL(), (unsigned long long)0xF0);
		}

		void CScriptCalHexTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=hex2dec(x"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x(hex2dec)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=hex2dec"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=x/"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
		}
	}
}
