
#ifndef SCRIPT_CAL_TEST_EXP1
#define SCRIPT_CAL_TEST_EXP1

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>


namespace poac{
	namespace test{
		class CScriptCalExp1Test : public CPPUNIT_NS::TestCase
		{

			CPPUNIT_TEST_SUITE(CScriptCalExp1Test);
			CPPUNIT_TEST(TestCal);
			CPPUNIT_TEST(TestParseError);
			CPPUNIT_TEST_SUITE_END();

		public:
			CScriptCalExp1Test();
			void setUp(void);
			void tearDown(void); 
		protected:
			void TestCal();
			void TestParseError();
		};
	}
}
#endif
