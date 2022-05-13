#include "Test_environment_maintainer.h"


#include "Test.h"

#include "jmsf/cule/cule_Allocators.h"

#include "jmsf/cule/excepting/Fixture_set_up_exception.h"
#include "jmsf/cule/excepting/Fixture_tear_down_exception.h"
#include "jmsf/cule/validating/cule_Exception.h"

#include "jmsf/pointing/cNonlinked.hin"
#include "jmsf/pointing/cShared.hin"
#include "jmsf/validating/Exception_information.h"
#include "jmsf/validating/Exception_information_summarizer.h"
#include "jmsf/validating/Foreign_exception.h"

#include <iostream>


namespace jmsf {
namespace cule {
namespace testing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Test_environment_maintainer::~Test_environment_maintainer() noexcept {
	if ( _the_current_test.is_empty() ) return;

	try {
		try {
			_the_current_test->tear_down_fixture();

		} catch ( const ::jmsf::validating::Exception &an_exception ) {
			const ::jmsf::validating::Exception_information_summarizer
				eis(
					cule_Allocators::instance()->get_reference_counters_allocator(),
					cule_Allocators::instance()->get_subsystem_allocator(),
					an_exception );

			const excepting::Fixture_tear_down_exception fixture_tear_down_exception(
				eis.get_all_summary( cule_Allocators::instance()->get_ansii_allocating_assistor() ),
				JMSF_FILE_AND_LINE );

			*_the_exception_information =
				::jmsf::validating::Exception_information::create_from_exception(
					cule_Allocators::instance()->get_reference_counters_allocator(),
					cule_Allocators::instance()->get_subsystem_allocator(),
					fixture_tear_down_exception );

		} JMSF_CATCH_FOREIGN_EXCEPTIONS( "CULE" );

	} catch ( const ::jmsf::validating::Foreign_exception &a_foreign_exception ) {
		const ::jmsf::validating::Exception_information_summarizer
			eis(
				cule_Allocators::instance()->get_reference_counters_allocator(),
				cule_Allocators::instance()->get_subsystem_allocator(),
				a_foreign_exception );

		const excepting::Fixture_tear_down_exception fixture_tear_down_exception(
			eis.get_all_summary( cule_Allocators::instance()->get_ansii_allocating_assistor() ),
			JMSF_FILE_AND_LINE );

		*_the_exception_information =
			::jmsf::validating::Exception_information::create_from_exception(
				cule_Allocators::instance()->get_reference_counters_allocator(),
				cule_Allocators::instance()->get_subsystem_allocator(),
				fixture_tear_down_exception );
	}

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Test_environment_maintainer::Test_environment_maintainer(
	pointing::cShared< ::jmsf::validating::Exception_information > *an_exception_information,
	const pointing::cNonlinked< Test > &a_test )
	:
		_the_exception_information( an_exception_information ),
		_the_current_test( a_test )
{
	jmsf_Should_never_be_empty_native_pointer( _the_exception_information );

	if ( _the_current_test.is_empty() ) return;

	try {
		try {
			_the_current_test->set_up_fixture();

		} catch ( const ::jmsf::validating::Exception &an_exception ) {
			const ::jmsf::validating::Exception_information_summarizer
				eis(
					cule_Allocators::instance()->get_reference_counters_allocator(),
					cule_Allocators::instance()->get_subsystem_allocator(),
					an_exception );

			throw excepting::Fixture_set_up_exception(
				eis.get_all_summary( cule_Allocators::instance()->get_ansii_allocating_assistor() ),
				JMSF_FILE_AND_LINE );

		} JMSF_CATCH_FOREIGN_EXCEPTIONS( "CULE" );

	} catch ( const ::jmsf::validating::Foreign_exception &a_foreign_exception ) {
			const ::jmsf::validating::Exception_information_summarizer
				eis(
					cule_Allocators::instance()->get_reference_counters_allocator(),
					cule_Allocators::instance()->get_subsystem_allocator(),
					a_foreign_exception );

			throw excepting::Fixture_set_up_exception(
				eis.get_all_summary( cule_Allocators::instance()->get_ansii_allocating_assistor() ),
				JMSF_FILE_AND_LINE );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Test_environment_maintainer::Test_environment_maintainer( const Test_environment_maintainer &/*another*/ ) noexcept {
//}

//const Test_environment_maintainer &Test_environment_maintainer::operator =( const Test_environment_maintainer &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy
//	return *this;
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Test_environment_maintainer::Test_environment_maintainer( Test_environment_maintainer &&/*another*/ ) noexcept {
//}

//Test_environment_maintainer &Test_environment_maintainer::operator =( Test_environment_maintainer &&another ) noexcept {
//	if ( &another == this ) return *this;

//	// move
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace testing
} // namespace cule
} // namespace jmsf

