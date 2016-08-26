
#include "testscriptparser.h"
#include "poacTimer.h"
#include "../../include/scriptparser/scriptparser.h"
#include "../../include/calmodel/calmodel.h"

using namespace poac::scriptcal;
using namespace std;

namespace poac
{
	namespace test
	{
		CScriptParserTest::CScriptParserTest()
		{
		}

		void CScriptParserTest::setUp()
		{
		}

		void CScriptParserTest::tearDown()
		{
		}

		void CScriptParserTest::TestOpenClose()
		{
		}		

		void CScriptParserTest::TestParseAdd()
		{
			CCalModel cm;
			CScriptParser sp;
			CPPUNIT_ASSERT(sp.Open("y=x+1", &cm));
			std::string str;
			sp.GetScript(str);
			cout << endl;
			std::cout << str << std::endl;
		}

		void CScriptParserTest::TestWriteSpeed()
		{
			CPoacTimer<CScriptParserTest> timer;

		}
	}
}
