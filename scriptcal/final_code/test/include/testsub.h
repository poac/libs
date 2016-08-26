
#ifndef SCRIPT_CAL_TEST_SUB
#define SCRIPT_CAL_TEST_SUB

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>


namespace poac{
	namespace test{
		class CScriptCalSubTest : public CPPUNIT_NS::TestCase
		{

			CPPUNIT_TEST_SUITE(CScriptCalSubTest);
			CPPUNIT_TEST(TestCalSub);
			CPPUNIT_TEST(TestParseError);
			CPPUNIT_TEST_SUITE_END();

		public:
			CScriptCalSubTest();
			void setUp(void);
			void tearDown(void); 
		protected:
			void TestCalSub();
			void TestParseError();
		};
	}
}
#endif
