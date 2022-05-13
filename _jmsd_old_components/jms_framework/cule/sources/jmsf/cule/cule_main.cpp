#include "cule_main.h"


#include "cule_Allocators.h"
#include "executing/Test_runner.h"
#include "user_interfacing/Ui_output.h"
#include "user_interfacing/Console_ui_output_threaded.h"
#include "user_interfacing/Console_ui_output.h"
#include "user_interfacing/Debug_ui_output.h"

#include "jmsf/cule/executing/realizing/realization_Test_stop_watch.h"
#include "to_libs/system/System_time.h"

#include "jmsf/pointing/Shared.hin"
#include "jmsf/patterning/Singleton.hin"

#include "jmsf/memorying/Constructor.hin"


#include "jmsf/synchronizing/Event.h"


//#include "jmsf/validating/error_debug_output.h"
#include "jmsf/encodebuba/encodebuba_logging_macroses_.h"

//#include "jmsf/typeing/Native_C_string.hin"
#include <iostream>


namespace jmsf {
namespace cule {


// int cule_real_main( const pointing::Pointer< user_interfaces::UiOutput > &uiOutput );
int cule_real_main( pointing::Shared< user_interfaces::Ui_output > &uiOutput );


int cule_main_console() {
//	pointing::Shared< user_interfaces::Ui_output > ui_output =
//		pointing::Shared< user_interfaces::Ui_output >::create(
//			cule_Allocators::instance()->get_reference_counters_allocator(),
//			memorying::Constructor< user_interfaces::Ui_output, user_interfaces::Console_ui_output >::construct(
//				cule_Allocators::instance()->get_subsystem_allocator() ) );

	pointing::Shared< user_interfaces::Ui_output > ui_output =
		pointing::Shared< user_interfaces::Ui_output >::create(
			cule_Allocators::instance()->get_reference_counters_allocator(),
			memorying::Constructor< user_interfaces::Ui_output, user_interfaces::Console_ui_output_threaded >::construct(
				cule_Allocators::instance()->get_subsystem_allocator() ) );

//	pointing::Shared< user_interfaces::Ui_output > ui_output =
//		pointing::Shared< user_interfaces::Ui_output >::create(
//			cule_Allocators::instance()->get_reference_counters_allocator(),
//			memorying::Constructor< user_interfaces::Ui_output, user_interfaces::Debug_ui_output >::construct(
//				cule_Allocators::instance()->get_subsystem_allocator() ) );

//	throw ::std::logic_error( "TestRunner::run() - no tests to run" );

	int result = 0;

//	try {
		result = cule_real_main( ui_output );
//	} catch ( const ::jmsf::validating::Exception &an_exception ) {
//		JMSF_LOG_ERROR_OUTPUT( "cule_main_console() - Exception is catched" );
//		::std::cout << ::std::endl;
//		::std::cout << "cule_main_console() - Exception is catched";
//		::std::cout << ::std::endl;
//		::std::cout << "in : ";
//		::std::cout << an_exception.get_filename().get_as_native_C_string( cule_Allocators::instance()->get_character_array_allocator() ).get_array().get();
//		::std::cout << ::std::endl;
//		::std::cout << "at : ";
//		::std::cout << an_exception.get_line_number().get_native_value();
//		::std::cout << ::std::endl;
//		::std::cout << "with reason: ";
//		::std::cout << an_exception.get_reason_description().get_as_native_C_string( cule_Allocators::instance()->get_character_array_allocator() ).get_array().get();
//		::std::cout << ::std::endl;
//		::std::cout << "with details: ";
//		::std::cout << an_exception.get_detailed_description().get_as_native_C_string( cule_Allocators::instance()->get_character_array_allocator() ).get_array().get();
//		::std::cout << ::std::endl;
//		::std::cout << "with type: ";
//		::std::cout << an_exception.get_type_information().get_as_native_C_string( cule_Allocators::instance()->get_character_array_allocator() ).get_array().get();
//		::std::cout << ::std::endl;
//		::std::cout << ::std::endl;
//		throw;
//	} catch ( ... ) {
//		JMSF_LOG_ERROR_OUTPUT( "cule_main_console() - unknown exception is catched" );
//		throw;
//	}

	return result;
}

int cule_main_visual_studio() {
//	pointing::Pointer< user_interfaces::UiOutput > ui_output =
//		pointing::Pointer< user_interfaces::UiOutput >::create_shared(
//			cule_Allocators::instance()->get_reference_counters_allocator(),
//			memorying::Constructor< user_interfaces::UiOutput, user_interfaces::DebugOutputUi >::construct(
//				cule_Allocators::instance()->_get_subsystem_allocator() ) );

	pointing::Shared< user_interfaces::Ui_output > ui_output =
		pointing::Shared< user_interfaces::Ui_output >::create(
			cule_Allocators::instance()->get_reference_counters_allocator(),
			memorying::Constructor< user_interfaces::Ui_output, user_interfaces::Debug_ui_output >::construct(
				cule_Allocators::instance()->get_subsystem_allocator() ) );

	return cule_real_main( ui_output );
}


// local functions
int cule_real_main( pointing::Shared< user_interfaces::Ui_output > &ui_output ) {
	jmsf_Should_never_be_empty( ui_output );

//	::std::cout << "cule_real_main() - started" << ::std::endl;

	if ( ui_output.is_not_empty() ) {
		executing::Test_runner( ui_output ).run();
	}

//	try {
//		testRunner.run();
//	} catch ( const ::jmsf::validating::Exception &an_exception ) {
//		JMSF_LOG_ERROR_OUTPUT( "cule_real_main() - Exception is catched" );
//		::std::cout << ::std::endl;
//		::std::cout << "cule_real_main() - Exception is catched";
//		::std::cout << ::std::endl;
//		::std::cout << "in : ";
//		::std::cout << an_exception.get_filename().get_as_native_C_string( cule_Allocators::instance()->get_character_array_allocator() ).get_array().get();
//		::std::cout << ::std::endl;
//		::std::cout << "at : ";
//		::std::cout << an_exception.get_line_number().get_native_value();
//		::std::cout << ::std::endl;
//		::std::cout << "with reason: ";
//		::std::cout << an_exception.get_reason_description().get_as_native_C_string( cule_Allocators::instance()->get_character_array_allocator() ).get_array().get();
//		::std::cout << ::std::endl;
//		::std::cout << "with details: ";
//		::std::cout << an_exception.get_detailed_description().get_as_native_C_string( cule_Allocators::instance()->get_character_array_allocator() ).get_array().get();
//		::std::cout << ::std::endl;
//		::std::cout << "with type: ";
//		::std::cout << an_exception.get_type_information().get_as_native_C_string( cule_Allocators::instance()->get_character_array_allocator() ).get_array().get();
//		::std::cout << ::std::endl;
//		::std::cout << ::std::endl;
//		throw;
//	} catch ( ... ) {
//		JMSF_LOG_ERROR_OUTPUT( "cule_real_main() - unknown exception is catched" );
//		throw;
//	}

//	::std::cout << "cule_real_main() - ended" << ::std::endl;
	return 0;
}


} // namespace cule
} // namespace jmsf
