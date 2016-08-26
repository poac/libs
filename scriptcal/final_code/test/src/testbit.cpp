
#include "testbit.h"
#include "poacTimer.h"
#include "../../include/scriptcal.h"
#include <math.h>

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptCalBitTest::CScriptCalBitTest()
		{
		}

		void CScriptCalBitTest::setUp()
		{
		}

		void CScriptCalBitTest::tearDown()
		{
		}

		void CScriptCalBitTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=(x)@(x)"));
			CPPUNIT_ASSERT(sc.SetInt(-6));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)-6);

			CPPUNIT_ASSERT(sc.SetInt(0));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)0);

			CPPUNIT_ASSERT(sc.SetInt(2016));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)2016);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(153.45));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=(x)|(x)"));
			CPPUNIT_ASSERT(sc.SetInt(-6));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)-6);

			CPPUNIT_ASSERT(sc.SetInt(0));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)0);

			CPPUNIT_ASSERT(sc.SetInt(2016));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)2016);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(153.45));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			//CPPUNIT_ASSERT(sc.SetULL(4300000000));
			//sc.Cal();
			//CPPUNIT_ASSERT(sc.IsCalError());

			//CPPUNIT_ASSERT(sc.SetInt(-2150000000));
			//sc.Cal();
			//CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=(x)xor(x)"));
			CPPUNIT_ASSERT(sc.SetInt(-6));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)0);

			CPPUNIT_ASSERT(sc.SetInt(0));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)0);

			CPPUNIT_ASSERT(sc.SetInt(2016));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)0);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(153.45));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=~(x)"));
			CPPUNIT_ASSERT(sc.SetInt(-6));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)~-6);

			CPPUNIT_ASSERT(sc.SetInt(0));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)~0);

			CPPUNIT_ASSERT(sc.SetInt(2016));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)~2016);

			CPPUNIT_ASSERT(sc.SetDouble(-1.5));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(153.45));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=~(x)@(x)"));
			CPPUNIT_ASSERT(sc.SetInt(-6));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)(~-6&-6));

			CPPUNIT_ASSERT(sc.SetInt(0));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)(~0&0));

			CPPUNIT_ASSERT(sc.SetInt(2016));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)(~2016&2016));

			CPPUNIT_ASSERT(sc.Open("y=~((x)@(x))"));
			CPPUNIT_ASSERT(sc.SetInt(-6));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)(~(-6&-6)));

			CPPUNIT_ASSERT(sc.SetInt(0));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)(~(0&0)));

			CPPUNIT_ASSERT(sc.SetInt(2016));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)(~(2016&2016)));

			CPPUNIT_ASSERT(sc.Open("y=(x)xor((x)@(2016))"));
			CPPUNIT_ASSERT(sc.SetInt(-6));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)(-6^(-6&2016)));

			CPPUNIT_ASSERT(sc.SetInt(0));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)(0^(0&2016)));

			CPPUNIT_ASSERT(sc.SetInt(2016));
			CPPUNIT_ASSERT_EQUAL(sc.CalInt(), (long long)(0));
		}

		void CScriptCalBitTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			//CPPUNIT_ASSERT(!sc.Open("y=x@x"));
			//CPPUNIT_ASSERT(sc.GetScript(str));
			//CPPUNIT_ASSERT(!sc.GetParseState(str));
			//cout << endl;
			//cout << str << endl;

			//CPPUNIT_ASSERT(!sc.Open("y=x|x"));
			//CPPUNIT_ASSERT(sc.GetScript(str));
			//CPPUNIT_ASSERT(!sc.GetParseState(str));
			//cout << endl;
			//cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=xxorx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			//CPPUNIT_ASSERT(!sc.Open("y=~x"));
			//CPPUNIT_ASSERT(sc.GetScript(str));
			//CPPUNIT_ASSERT(!sc.GetParseState(str));
			//cout << endl;
			//cout << str << endl;

			//CPPUNIT_ASSERT(!sc.Open("(x)@x"));
			//CPPUNIT_ASSERT(sc.GetScript(str));
			//CPPUNIT_ASSERT(!sc.GetParseState(str));
			//cout << endl;
			//cout << str << endl;

			//CPPUNIT_ASSERT(!sc.Open("y=x@(x)"));
			//CPPUNIT_ASSERT(sc.GetScript(str));
			//CPPUNIT_ASSERT(!sc.GetParseState(str));
			//cout << endl;
			//cout << str << endl;

			//CPPUNIT_ASSERT(!sc.Open("y=(x)|x"));
			//CPPUNIT_ASSERT(sc.GetScript(str));
			//CPPUNIT_ASSERT(!sc.GetParseState(str));
			//cout << endl;
			//cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=(x)xorx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=(x)@@(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=(x)@|(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=(x)@xor(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=~~(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=(x)||(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=@(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=(x)@"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=xor(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=|(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=(x)~"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;
		}
	}
}
