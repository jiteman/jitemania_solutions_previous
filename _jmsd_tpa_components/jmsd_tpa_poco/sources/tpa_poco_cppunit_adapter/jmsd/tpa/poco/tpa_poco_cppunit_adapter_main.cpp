#include "tpa_poco_cppunit_adapter_main.h"

#include "cppunit/TestSuite.h"
#include "cppunit/Test.h"
#include "cppunit/Exception.h"
#include "cppunit/CompilerOutputter.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TextTestRunner.h"
#include "cppunit/TextTestProgressListener.h"
#include "cppunit/BriefTestProgressListener.h"
#include "cppunit/XmlOutputter.h"
#include "cppunit/extensions/TestFactoryRegistry.h"

#include "cppunit/ClockerPlugIn/ClockerModel.h"
#include "cppunit/ClockerPlugIn/ClockerListener.h"
//#include "ClockerXmlHook.h"

#include <stdexcept>
#include <fstream>

#include <string>


namespace jmsd {
namespace tpa {
namespace poco {


int tpa_poco_cppunit_adapter_main(
	int const /*argc*/,
	char const *const /*argv*/ [],
	::std::vector< ::CppUnit::Test * > const &test_suite_list )
{
	CPPUNIT_NS::TestResult controller;

	CPPUNIT_NS::TestResultCollector result;
	controller.addListener( &result );

	CPPUNIT_NS::TextTestProgressListener progress;
	controller.addListener( &progress );

	CPPUNIT_NS::TestRunner test_runner;

//	// Add the top suite to the test runner
//	test_runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );

	::CppUnit::TestSuite *poco_test_suite = new ::CppUnit::TestSuite( "Poco C++ test suite" );

	for ( auto the_suite : test_suite_list ) {
		poco_test_suite->addTest( the_suite );
	}

	test_runner.addTest( poco_test_suite );

	try {
		test_runner.run( controller );
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


//int tpa_poco_cppunit_adapter_main(
//	int const argc,
//	char const *const argv[],
//	::std::vector< ::CppUnit::Test * > const &test_suite_list )
//{
//	::std::vector< ::std::string > program_arguments;
//	{
//		size_t const argument_quantity = argc < 0 ? 0 : argc;

//		for ( size_t argument_index = 0; argument_index < argument_quantity; ++argument_index ) {
//			program_arguments.push_back( ::std::string( argv[ argument_index ] ) );
//		}
//	}

//	::CppUnit::TestSuite *poco_test_suite = new ::CppUnit::TestSuite( "Poco C++ test suite" );

//	for ( auto the_suite : test_suite_list ) {
//		poco_test_suite->addTest( the_suite );
//	}

//	::CppUnit::TestRunner test_runner;
//	test_runner.addTest( poco_test_suite );
//	return test_runner.run( program_arguments ) ? 0 : 1;
//}


} // namespace poco
} // namespace tpa
} // namespace jmsd
