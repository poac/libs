
#ifndef SCRIPT_CAL_TEST_PERF
#define SCRIPT_CAL_TEST_PERF

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include "../../include/scriptcal.h"


namespace poac{
	namespace test{
		class CScriptCalPerfTest : public CPPUNIT_NS::TestCase
		{

			CPPUNIT_TEST_SUITE(CScriptCalPerfTest);
			CPPUNIT_TEST(TestCal);
			//CPPUNIT_TEST(TestParseError);
			CPPUNIT_TEST_SUITE_END();

		public:
			CScriptCalPerfTest();
			void setUp(void);
			void tearDown(void); 
		protected:
			void TestCal();
			void TestParseError();

		private:
			long __ScriptCal();
			long __FuncCal();
			bool __InitCal();

			double __Func0(double x);
			double __Func1(double x);
			double __Func2(double x);
			double __Func3(double x);
			double __Func4(double x);
			double __Func5(double x);
			double __Func6(double x);
			double __Func7(double x);
			double __Func8(double x);
			double __Func9(double x);
			double __Func10(double x);

		private:
			vector<poac::scriptcal::CScriptCal*> m_vCal;
			int m_nRepeatCount;
		};
	}
}
#endif
