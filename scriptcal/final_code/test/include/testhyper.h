
#ifndef SCRIPT_CAL_TEST_HYPER
#define SCRIPT_CAL_TEST_HYPER

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>


namespace poac{
	namespace test{
		class CScriptCalHyperTest : public CPPUNIT_NS::TestCase
		{

			CPPUNIT_TEST_SUITE(CScriptCalHyperTest);
			CPPUNIT_TEST(TestCal);
			CPPUNIT_TEST(TestParseError);
			CPPUNIT_TEST_SUITE_END();

		public:
			CScriptCalHyperTest();
			void setUp(void);
			void tearDown(void); 
		protected:
			void TestCal();
			void TestParseError();
		};
	}
}
#endif
