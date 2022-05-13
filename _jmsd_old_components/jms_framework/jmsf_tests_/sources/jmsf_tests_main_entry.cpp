#include "jmsf/cule/cule_main.h"


//#include "jmsf/encodebuba/encodebuba_Environment.h"
//#include "jmsf/al_std/al_std_Environment.h"
#include "jmsf/jmsf_Environment.h"
#include "jmsf/cule/cule_Environment.h"
#include "jmsf/testing/testing_Environment.h"
#include "jmsf/testing/testing_Allocators.h"

#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/Native_C_string.h"

#include "jmsf/patterning/Singleton.hin"
#include "jmsf/patterning/Instance_destroyer.hin"
//#include "jmsf/pointing/Constant_pointer.hin"
#include "jmsf/memorying/Wamp.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Omp.hin"

// Seinsei: todonext - move uneccessary to tests
#include "jmsf/pointing/Scoped.hin"
#include "jmsf/pointing/Nonlinked.hin"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cWeak.hin"


#include "jmsf/validating/Exception.h"
#include "jmsf/encodebuba/validating/native_Exception.h"

#include "jmsf/pointing/pre_tests_Weak.hxx"
#include "jmsf/pointing/pre_tests_Shared.hxx"
#include "jmsf/pointing/pre_tests_cWeak.hxx"
#include "jmsf/pointing/pre_tests_cShared.hxx"
#include "jmsf/pointing/pre_tests_Nonlinked.hxx"
#include "jmsf/pointing/pre_tests_cNonlinked.hxx"
#include "jmsf/pointing/pre_tests_Scoped.hxx"
#include "jmsf/pointing/pre_tests_cScoped.hxx"

#include "jmsd/tpa/gtm/gtm_library_main.h"

//#include "cppunit/TextOutputter.h"
//#include "cppunit/TextTestRunner.h"
//#include "poco/Foundation/FoundationTestSuite.h"

#include <iostream>


// Seinsei: todonext - complete transfer to JMSF_DEBUG
int main( const int argc, const char *const argv[] ) {
	// initialize testing framework
	// if testing framework is ok, perform tests
	// else report problem

	if ( !::jmsf::testing::testing_Environment::initialize() ) {
		::std::cout << ::std::endl << "Error: test_main_entry::main() - can't initialize tests_Environment" << ::std::endl;
		return -1;
	}

	// Seinsei: todonext - move this try/catch and messages to cule_Environment::run_all_tests()

	{
//		if ( false ) {
//			::CppUnit::TextTestRunner text_test_runner;
//			text_test_runner.addTest( FoundationTestSuite::suite() );
//			text_test_runner.run();
//		}

		{
			::std::cout << "[JMSD] Main internal test started" << ::std::endl;

			// preliminary tests (memory pointers, object pointers, etc.)
			::jmsf::pointing::pre_tests_weak::pre_tests_Weak();
			::jmsf::pointing::pre_tests_shared::pre_tests_Shared();
			::jmsf::pointing::pre_tests_cweak::pre_tests_cWeak();
			::jmsf::pointing::pre_tests_cshared::pre_tests_cShared();
			::jmsf::pointing::pre_tests_nonlinked::pre_tests_Nonlinked();
			::jmsf::pointing::pre_tests_cnonlinked::pre_tests_cNonlinked();
			::jmsf::pointing::pre_tests_scoped::pre_tests_Scoped();
			::jmsf::pointing::pre_tests_cscoped::pre_tests_cScoped();

			::jmsd::tpa::gtm::gmock_main( argc, argv, false );

			::std::cout << "[JMSD] Main internal test finished" << ::std::endl;
		}
	}

	try {
		const int test_run_result = ::jmsf::cule::cule_Environment::instance()->run_all_tests();
		::jmsf::testing::testing_Environment::deinitialize();
//		::std::cout << ::std::endl << "test_main_entry::main() -> exiting" << ::std::endl;
		return test_run_result;
	} catch ( const ::jmsf::encodebuba::validating::native_Exception &a_native_exception ) {
		::jmsf::memorying::Womp< ::jmsf::texting::Ansii_allocating_assistor > allocating_assistor =
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor();

		::std::cout << ::std::endl;
		::std::cout << "Performing tests... - native_Exception is catched";
		::std::cout << ::std::endl;
		::std::cout << "in : ";
		::std::cout << a_native_exception.get_filename();
		::std::cout << ::std::endl;
		::std::cout << "at : ";
		::std::cout << a_native_exception.get_line_number();
		::std::cout << ::std::endl;
		::std::cout << "with reason: ";
		::std::cout << a_native_exception.get_reason_description();
		::std::cout << ::std::endl;
		::std::cout << "with type: ";
		::std::cout << a_native_exception.get_type_information();
		::std::cout << ::std::endl;
		::std::cout << ::std::endl;
		return -101;
	} catch ( const ::jmsf::validating::Exception &an_exception ) {
		::jmsf::memorying::Womp< ::jmsf::texting::Ansii_allocating_assistor > allocating_assistor =
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor();

		::std::cout << ::std::endl;
		::std::cout << "Performing tests... - Exception is catched";
		::std::cout << ::std::endl;
		::std::cout << "in : ";
		::std::cout << allocating_assistor->create_native_from_ansii_text( an_exception.get_filename().get_as_cshared() )->get().operator ->();
		::std::cout << ::std::endl;
		::std::cout << "at : ";
		::std::cout << an_exception.get_line_number().get_native_value();
		::std::cout << ::std::endl;
		::std::cout << "with reason: ";
		::std::cout << allocating_assistor->create_native_from_ansii_text( an_exception.get_reason_description().get_as_cshared() )->get().operator ->();
		::std::cout << ::std::endl;
		::std::cout << "with details: ";
		::std::cout << allocating_assistor->create_native_from_ansii_text( an_exception.get_detailed_description().get_as_cshared() )->get().operator ->();
		::std::cout << ::std::endl;
		::std::cout << "with type: ";
		::std::cout << allocating_assistor->create_native_from_ansii_text( an_exception.get_type_information().get_as_cshared() )->get().operator ->();
		::std::cout << ::std::endl;
		::std::cout << ::std::endl;
		return -102;
	} catch ( const ::std::exception &an_exception ) {
		::std::cout << ::std::endl;
		::std::cout << "Performing tests... - standard exception is catched";
		::std::cout << ::std::endl;
		::std::cout << "what: ";
		::std::cout << an_exception.what();
		::std::cout << ::std::endl;
		return -103;
	} catch ( ... ) {
		::std::cout << ::std::endl;
		::std::cout << "Performing tests... - unknown exception is catched";
		::std::cout << ::std::endl;
		return -104;
	}
}
