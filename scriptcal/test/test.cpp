#include <gtest/gtest.h>
#include "script.h"

using namespace std;
using namespace poac;
//using namespace poac::script;




int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	testScript.InitScript("y = 5.439*(x+3)-(x*x+a+-3);a=3");

}