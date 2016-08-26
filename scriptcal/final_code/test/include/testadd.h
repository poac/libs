
#ifndef SCRIPT_CAL_TEST_ADD
#define SCRIPT_CAL_TEST_ADD

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>


namespace poac{
	namespace test{
		class CScriptCalAddTest : public CPPUNIT_NS::TestCase
		{

			CPPUNIT_TEST_SUITE(CScriptCalAddTest);
			CPPUNIT_TEST(TestCalAdd);
			CPPUNIT_TEST(TestParseError);
			CPPUNIT_TEST_SUITE_END();

		public:
			CScriptCalAddTest();
			void setUp(void);
			void tearDown(void); 
		protected:
			void TestCalAdd();
			void TestParseError();
		};
	}
}
#endif
