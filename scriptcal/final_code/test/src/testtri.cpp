
#include "testtri.h"
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
		CScriptCalTriTest::CScriptCalTriTest()
		{
		}

		void CScriptCalTriTest::setUp()
		{
		}

		void CScriptCalTriTest::tearDown()
		{
		}

		void CScriptCalTriTest::TestCal()
		{
			CScriptCal sc;
			CPPUNIT_ASSERT(sc.Open("y=Sin(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(90));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(450));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-200));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sin(-200.0*M_PI/180), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Cos(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(90));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);
			CPPUNIT_ASSERT(sc.SetDouble(450));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-180));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Tg(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(60));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sqrt(3.0), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-45));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			//CPPUNIT_ASSERT(sc.SetDouble(-90));
			//cout << sc.Cal() << endl;
			//CPPUNIT_ASSERT(sc.IsCalError());

			//CPPUNIT_ASSERT(sc.SetDouble(270));
			//cout << sc.Cal() << endl;
			//CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Ctg(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(90));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-45));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(270));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			//CPPUNIT_ASSERT(sc.SetDouble(180));
			//sc.Cal();
			//CPPUNIT_ASSERT(sc.IsCalError());

			//CPPUNIT_ASSERT(sc.SetDouble(-180));
			//sc.Cal();
			//CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Sin(x)+Sin(90)*Tg(x)"));
			CPPUNIT_ASSERT(sc.SetDouble(-200));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sin(-200*M_PI/180)+tan(-200*M_PI/180), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(45));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sqrt(2.0)/2+1, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);
			//CPPUNIT_ASSERT(sc.SetDouble(-90));
			//sc.Cal();
			//CPPUNIT_ASSERT(sc.IsCalError());

			//CPPUNIT_ASSERT(sc.SetDouble(90));
			//sc.Cal();
			//CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.Open("y=Sin(Sin(x))"));
			CPPUNIT_ASSERT(sc.SetDouble(90));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sin(1*M_PI/180), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-60));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), sin(sin(-60*M_PI/180)*M_PI/180), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Tg(Tg(x))"));

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(80));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), tan(tan(80*M_PI/180)*M_PI/180), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-210));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), tan(tan(-210*M_PI/180)*M_PI/180), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(90));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0.14917, 0.01);
			//sc.Cal();
			//CPPUNIT_ASSERT(sc.IsCalError());

			//CPPUNIT_ASSERT(sc.SetDouble(atan(90.0)*180/M_PI));
			//CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), -113371591279906.55, 0.01);
			////sc.Cal();
			////CPPUNIT_ASSERT(sc.IsCalError());


			CPPUNIT_ASSERT(sc.Open("y=Tg(Sin(x))"));

			CPPUNIT_ASSERT(sc.SetDouble(0));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 0, 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(90));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), tan(sin(90*M_PI/180)*M_PI/180), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-60));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), tan(sin(-60*M_PI/180)*M_PI/180), 0.01);

			CPPUNIT_ASSERT(sc.Open("y=Ctg(Sin(x))"));
			CPPUNIT_ASSERT(sc.SetDouble(90));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1/tan(1*M_PI/180), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(-45));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1/tan(sin(-45*M_PI/180)*M_PI/180), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(60));
			CPPUNIT_ASSERT_DOUBLES_EQUAL(sc.Cal(), 1/tan(sin(60*M_PI/180)*M_PI/180), 0.01);

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(180));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
		}

		void CScriptCalTriTest::TestParseError()
		{
			CScriptCal sc;
			string str;
			CPPUNIT_ASSERT(!sc.Open("y=sin(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=cos(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=tg(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=ctg(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Sinx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Cosx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Tgx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Ctgx"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=SinSin(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=SinTg(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Tg(Sinx)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(!sc.Open("y=Ctg(Cosx)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(!sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.Open("y=1/Sin(x)"));
			CPPUNIT_ASSERT(sc.GetScript(str));
			CPPUNIT_ASSERT(sc.GetParseState(str));
			cout << endl;
			cout << str << endl;

			CPPUNIT_ASSERT(sc.SetDouble(0));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(180));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(360));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());

			CPPUNIT_ASSERT(sc.SetDouble(-540));
			sc.Cal();
			CPPUNIT_ASSERT(sc.IsCalError());
		}
	}
}
