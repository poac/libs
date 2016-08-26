
#ifndef SCRIPT_PARSER_TEST
#define SCRIPT_PARSER_TEST

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>


namespace poac{
	namespace test{
		class CScriptParserTest : public CPPUNIT_NS::TestCase
		{

			CPPUNIT_TEST_SUITE(CScriptParserTest);
			//CPPUNIT_TEST(TestOpenClose);
			CPPUNIT_TEST(TestParseAdd);
			//CPPUNIT_TEST(TestWriteSpeed);
			CPPUNIT_TEST_SUITE_END();

		public:
			CScriptParserTest();
			void setUp(void);
			void tearDown(void); 
		protected:
			void TestOpenClose();	
			void TestParseAdd();
			void TestWriteSpeed();
		};
	}
}
#endif
