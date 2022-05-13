#include "Single_test_runner.h"


#include "jmsf/cule/resulting/Test_result_collector.h"

#include "jmsf/cule/resulting/Test_fault.h"

#include "jmsf/cule/user_interfacing/Ui_output.h"
#include "jmsf/cule/executing/Test_stop_watch.h"
#include "jmsf/cule/testing/Test_environment_maintainer.h"

#include "jmsf/cule/cule_Allocators.h"


#include "jmsf/pointing/cNonlinked.hin"
#include "jmsf/pointing/Weak.hin"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/patterning/Singleton.hin"
#include "jmsf/memorying/Constructor.hin"

#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/String_literal.h"

#include "jmsf/memorying/Womp.hin"

#include "jmsf/cule/testing/Test.h"
#include "jmsf/cule/resulting/Test_fault.h"
#include "jmsf/cule/excepting/Test_fault_exception.h"

// #include "jmsf/validating/macroses_Should.h"

#include "jmsf/validating/Exception_information.h"
#include "jmsf/validating/Foreign_exception.h"

#include "jmsf/encodebuba/validating/native_Exception.h"


namespace jmsf {
namespace cule {
namespace executing {


void Single_rest_runner::run_the_test() {
	jmsf_Should_never_be_empty( _the_test );

	_test_fault_collector->one_more_test_running();

	Test_stop_watch::instance()->start_local();

	if ( _the_test.is_empty() ) return; // Seinsei: todonext - do something meaningful

	pointing::cShared< ::jmsf::validating::Exception_information > tear_down_exception_information;

	try { // catch Foreign_exception
		try { // JMSF_CATCH_FOREIGN_EXCEPTIONS
			{
				testing::Test_environment_maintainer test_environment_maintainer( &tear_down_exception_information, _the_test );
				_the_test->run();
			}

		} catch ( const excepting::Test_fault_exception &test_fault_exception ) {
			_test_fault_collector->add_test_failure( create_new_test_failure_from_exception( test_fault_exception ) );

		} catch ( const ::jmsf::encodebuba::validating::native_Exception &encodebuba_native_exception ) {
			_test_fault_collector->add_test_error( create_new_test_failure_from_native_exception( encodebuba_native_exception ) );

		} catch ( const ::jmsf::validating::Exception &jmsf_exception ) {
			_test_fault_collector->add_test_error( create_new_test_failure_from_exception( jmsf_exception ) );

		} JMSF_CATCH_FOREIGN_EXCEPTIONS( "CULE" );

	} catch ( const ::jmsf::validating::Foreign_exception &foreign_exception ) {
		_test_fault_collector->add_test_foreign_error( create_new_test_failure_from_exception( foreign_exception ) );

	}

	if ( tear_down_exception_information.is_not_empty() ) {
		_test_fault_collector->add_test_error( create_new_test_failure_from_exception_information( tear_down_exception_information ) );
		tear_down_exception_information = pointing::cShared< ::jmsf::validating::Exception_information >();
	}
}

Single_rest_runner::~Single_rest_runner() noexcept
{}

Single_rest_runner::Single_rest_runner(
	const pointing::Shared< resulting::Test_result_collector > &test_result_collector,
	const pointing::cNonlinked< testing::Test > &a_test )
	:
		_the_test( a_test ),
		_test_fault_collector( test_result_collector )
{}

Single_rest_runner::Single_rest_runner( const Single_rest_runner & ) // another
{}

const Single_rest_runner &Single_rest_runner::operator=( const Single_rest_runner &another ) {
	if ( this == &another ) return *this;

	// copy
	return *this;
}

pointing::cShared< resulting::Test_fault > Single_rest_runner::create_new_test_failure_from_native_exception(
	const ::jmsf::encodebuba::validating::native_Exception &a_native_exception )
{
	const pointing::cShared< ::jmsf::validating::Exception_information > exception_information =
		::jmsf::validating::Exception_information::create_from_native_exception(
			cule_Allocators::instance()->get_reference_counters_allocator(),
			cule_Allocators::instance()->get_subsystem_allocator(),
			cule_Allocators::instance()->get_ansii_allocating_assistor(),
			a_native_exception );

	return create_new_test_failure_from_exception_information( exception_information );
}

pointing::cShared< resulting::Test_fault > Single_rest_runner::create_new_test_failure_from_exception( const ::jmsf::validating::Exception &an_exception ) {
	const pointing::cShared< ::jmsf::validating::Exception_information > exception_information =
		::jmsf::validating::Exception_information::create_from_exception(
			cule_Allocators::instance()->get_reference_counters_allocator(),
			cule_Allocators::instance()->get_subsystem_allocator(),
			an_exception );

	return create_new_test_failure_from_exception_information( exception_information );
}

pointing::cShared< resulting::Test_fault > Single_rest_runner::create_new_test_failure_from_exception_information(
	const pointing::cShared< ::jmsf::validating::Exception_information > &an_exception_information )
{
	return
		resulting::Test_fault::create(
			cule_Allocators::instance()->get_reference_counters_allocator(),
			cule_Allocators::instance()->get_subsystem_allocator(),
			_the_test,
			an_exception_information );
}


} // namespace execution
} // namespace cule
} // namespace jmsf
