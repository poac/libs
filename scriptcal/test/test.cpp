#include <gtest/gtest.h>
#include "script.h"

using namespace std;
using namespace poac::script;
//using namespace poac::script;


	//ifstream in("123.txt");
	//if (! in.is_open())
	//	cout << "Error open" << endl;
	//while (!in.eof() )  
	//   {  
	//	int a, b, c;
	//	in >> a >> b >> c;
	//	EXPECT_EQ(a, Foo(b,c));
	//   } 


int main(int argc, char* argv[])
{
	//script::CScript testScript;
	//testScript.InitScript("y=a+3;a=3");
	//testScript.PrintScript();

	//testScript.InitScript("y = 5.439*(x+3)-(x*x+a+-3);a=3");
	//testScript.PrintScript();

	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	getchar();
	return 0;
}