
#ifndef SCRIPT_CAL_TEST_TRI
#define SCRIPT_CAL_TEST_TRI

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>


namespace poac{
	namespace test{
		class CScriptCalTriTest : public CPPUNIT_NS::TestCase
		{

			CPPUNIT_TEST_SUITE(CScriptCalTriTest);
			CPPUNIT_TEST(TestCal);
			CPPUNIT_TEST(TestParseError);
			CPPUNIT_TEST_SUITE_END();

		public:
			CScriptCalTriTest();
			void setUp(void);
			void tearDown(void); 
		protected:
			void TestCal();
			void TestParseError();
		};
	}
}
#endif
