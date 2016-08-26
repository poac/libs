
#ifndef SCRIPT_CAL_TEST
#define SCRIPT_CAL_TEST

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>


namespace poac{
	namespace test{
		class CScriptCalTest : public CPPUNIT_NS::TestCase
		{

			CPPUNIT_TEST_SUITE(CScriptCalTest);
			CPPUNIT_TEST(TestCal4);
			CPPUNIT_TEST(TestCal4power);
			CPPUNIT_TEST(TestCalAdd);
			CPPUNIT_TEST(TestCalAddMinus);
			CPPUNIT_TEST(TestParseError);
			CPPUNIT_TEST(TestCalSin);
			CPPUNIT_TEST_SUITE_END();

		public:
			CScriptCalTest();
			void setUp(void);
			void tearDown(void); 
		protected:
			void TestCal4();	
			void TestCalAdd();
			void TestCalAddMinus();
			void TestCal4power();
			void TestParseError();
			void TestCalSin();
		};
	}
}
#endif
