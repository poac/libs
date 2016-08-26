
#ifndef SCRIPT_CAL_TEST_BRACKET
#define SCRIPT_CAL_TEST_BRACKET

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>


namespace poac{
	namespace test{
		class CScriptCalBracketTest : public CPPUNIT_NS::TestCase
		{

			CPPUNIT_TEST_SUITE(CScriptCalBracketTest);
			CPPUNIT_TEST(TestCal);
			CPPUNIT_TEST(TestParseError);
			CPPUNIT_TEST(TestCalComplex);
			CPPUNIT_TEST(TestParseErrorComplex);
			CPPUNIT_TEST_SUITE_END();

		public:
			CScriptCalBracketTest();
			void setUp(void);
			void tearDown(void); 
		protected:
			void TestCal();
			void TestCalComplex();
			void TestParseError();
			void TestParseErrorComplex();
		};
	}
}
#endif
