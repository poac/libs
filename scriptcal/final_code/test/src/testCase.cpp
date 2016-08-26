

#include <cppunit/config/SourcePrefix.h>
#include "../include/testCase.h"


void Test::testHelloWorld(void) { std::cout << "Hello, world!" << std::endl; 
	CPPUNIT_ASSERT(3.0==3.5);
}
void Test::testDoubleEqual(void) { std::cout << "test double equal!" << std::endl; 
	CPPUNIT_ASSERT_DOUBLES_EQUAL(3.0,3.5, 0.1);
}


