
#ifndef SCRIPT_CAL_TEST_LOG
#define SCRIPT_CAL_TEST_LOG

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>


namespace poac{
	namespace test{
		class CScriptCalLogTest : public CPPUNIT_NS::TestCase
		{

			CPPUNIT_TEST_SUITE(CScriptCalLogTest);
			CPPUNIT_TEST(TestCal);
			CPPUNIT_TEST(TestParseError);
			CPPUNIT_TEST_SUITE_END();

		public:
			CScriptCalLogTest();
			void setUp(void);
			void tearDown(void); 
		protected:
			void TestCal();
			void TestParseError();
		};
	}
}
#endif
