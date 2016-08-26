
#ifndef SCRIPT_CAL_TEST_DIV
#define SCRIPT_CAL_TEST_DIV

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>


namespace poac{
	namespace test{
		class CScriptCalDivTest : public CPPUNIT_NS::TestCase
		{

			CPPUNIT_TEST_SUITE(CScriptCalDivTest);
			CPPUNIT_TEST(TestCal);
			CPPUNIT_TEST(TestParseError);
			CPPUNIT_TEST_SUITE_END();

		public:
			CScriptCalDivTest();
			void setUp(void);
			void tearDown(void); 
		protected:
			void TestCal();
			void TestParseError();
		};
	}
}
#endif
