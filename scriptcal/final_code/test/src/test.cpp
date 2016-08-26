


#include <iostream>


#include <cppunit/TestRunner.h>

#include <cppunit/TestResult.h>

#include <cppunit/TestResultCollector.h>

#include <cppunit/extensions/HelperMacros.h>

#include <cppunit/BriefTestProgressListener.h>

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/CompilerOutputter.h>

#include "../include/testscriptparser.h"
#include "../include/testscriptcal.h"
#include "../include/testadd.h"
#include "../include/testsub.h"
#include "../include/testmulti.h"
#include "../include/testdiv.h"
#include "../include/testarith.h"
#include "../include/testbracket.h"
#include "../include/testexp.h"
#include "../include/testabs.h"
#include "../include/testbit.h"
#include "../include/testhyper.h"
#include "../include/testtri.h"
#include "../include/testexp1.h"
#include "../include/testsqrt.h"
#include "../include/testlog.h"
#include "../include/testbranch.h"
#include "../include/testhex.h"
#include "../include/testsci.h"
#include "../include/testcomp.h"
#include "../include/testperf.h"

#include <time.h>
#include <stdio.h>


using namespace std;
using namespace poac::test;
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptParserTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalAddTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalSubTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalMultiTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalDivTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalArithTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalBracketTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalExpTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalAbsTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalBitTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalHyperTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalTriTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalExp1Test);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalSqrtTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalLogTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalBranchTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalHexTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalSciTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalCompTest);
CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalPerfTest);

CPPUNIT_TEST_SUITE_REGISTRATION(CScriptCalTest);


int main( int argc, char **argv )

{

	// Create the event manager and test controller

	CPPUNIT_NS::TestResult controller;

	// Add a listener that colllects test result

/*	CPPUNIT_NS::TestResultCollector result;

	controller.addListener( &result );    */    
	CPPUNIT_NS::TestResultCollector result;

	controller.addListener( &result );        


	// Add a listener that print dots as test run.

	CPPUNIT_NS::BriefTestProgressListener progress;

	controller.addListener( &progress );      


	// Add the top suite to the test runner

	CPPUNIT_NS::TestRunner runner;

	runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );

	time_t tmbegin;
	time(&tmbegin);
	runner.run( controller );

	time_t tmend;
	time(&tmend);
	
	cout << "used time: " << tmend-tmbegin << endl;
	//CPPUNIT_NS::OStream *xmlStream = new CPPUNIT_NS::OFileStream( "report.xml" );

	//// Print test in a compiler compatible format.
	//CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
	//outputter.write(); 
	CPPUNIT_NS::CompilerOutputter outputter( &result,std::cout );
	outputter.write(); 
	//CPPUNIT_NS::XmlOutputter xmlOutputter( &result, *xmlStream );
	//xmlOutputter.setStyleSheet( "report.xsl" );
	//xmlOutputter.write(); 

	getchar();

	return 0/*result.wasSuccessful() ? 0 : 1*/;

}


