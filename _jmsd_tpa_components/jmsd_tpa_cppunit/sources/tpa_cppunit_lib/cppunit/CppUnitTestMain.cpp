#include "CppUnitTestMain.h"

#include "cppunit/Exception.h"
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include "cppunit/TextTestRunner.h"
#include <cppunit/TextTestProgressListener.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "cppunit/ClockerPlugIn/ClockerModel.h"
#include "cppunit/ClockerPlugIn/ClockerListener.h"
//#include "ClockerXmlHook.h"

#include <stdexcept>
#include <fstream>


int test_cppunit_main( int const /*argc*/, char const *const /*argv*/ [] ) {
	CPPUNIT_NS::TestResult controller;

	CPPUNIT_NS::TestResultCollector result;
	controller.addListener( &result );

	CPPUNIT_NS::TextTestProgressListener progress;
	controller.addListener( &progress );

	// Add the top suite to the test runner
	CPPUNIT_NS::TestRunner runner;
	runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );

	try {
		runner.run( controller );
	} catch ( CPPUNIT_NS::Exception const &an_exception ) {
		::std::cout << ::std::endl;
		::std::cout << "Performing tests... - Exception is catched";
		::std::cout << ::std::endl;
		::std::cout << "in : ";
		::std::cout << an_exception.sourceLine().fileName();
		::std::cout << ::std::endl;
		::std::cout << "at : ";
		::std::cout << an_exception.sourceLine().lineNumber();
		::std::cout << ::std::endl;
		::std::cout << "with reason: ";
		::std::cout << an_exception.what();
		::std::cout << ::std::endl;
		::std::cout << "with details: ";
		::std::cout << an_exception.message().details();
		::std::cout << ::std::endl;
		::std::cout << ::std::endl;
		::std::cout << ::std::endl;
		return -101;
	} catch ( const ::std::exception &an_exception ) {
		::std::cout << ::std::endl;
		::std::cout << "Performing tests... - standard exception is catched";
		::std::cout << ::std::endl;
		::std::cout << "what: ";
		::std::cout << an_exception.what();
		::std::cout << ::std::endl;
		return -102;
	} catch ( ... ) {
		::std::cout << ::std::endl;
		::std::cout << "Performing tests... - unknown exception is catched";
		::std::cout << ::std::endl;
		return -103;
	}

	CPPUNIT_NS::stdCOut() << ::std::endl;

	// Print test in a compiler compatible format.
	CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
	outputter.write();

	return 0;
}


//int test_cppunit_main( int const argc, char const *const argv[] ) {
//  // Retreive test path from command line first argument. Default to "" which resolve
//  // to the top level suite.
//  std::string testPath = (argc > 1) ? std::string(argv[1]) : std::string("");

//  // Create the event manager and test controller
//  CPPUNIT_NS::TestResult controller;

//	ClockerModel the_model;
//	ClockerListener the_dumper( &the_model, true, false );
////	ClockerXmlHook the_xmlHook( the_model );

//    controller.addListener( &the_dumper );

//  // Add a listener that colllects test result
//  CPPUNIT_NS::TestResultCollector result;
//  controller.addListener( &result );


//  // Add a listener that print dots as test run.
//#ifdef WIN32
//  CPPUNIT_NS::TextTestProgressListener progress;
//#else
//  CPPUNIT_NS::BriefTestProgressListener progress;
//#endif
//  controller.addListener( &progress );

//  // Add the top suite to the test runner
//  CPPUNIT_NS::TestRunner runner;
//  runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
//  try
//  {
//    CPPUNIT_NS::stdCOut() << "Running "  <<  testPath;
//    runner.run( controller, testPath );

//    CPPUNIT_NS::stdCOut() << "\n";

//    // Print test in a compiler compatible format.
//    CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
//    outputter.write();

//// Uncomment this for XML output
////    std::ofstream file( "tests.xml" );
////    CPPUNIT_NS::XmlOutputter xml( &result, file );
////    xml.setStyleSheet( "report.xsl" );
////    xml.write();
////    file.close();
//  }
//  catch ( std::invalid_argument &e )  // Test path not resolved
//  {
//    CPPUNIT_NS::stdCOut()  <<  "\n"
//                            <<  "ERROR: "  <<  e.what()
//                            << "\n";
//    return 0;
//  }

//  return result.wasSuccessful() ? 0 : 1;
//}
