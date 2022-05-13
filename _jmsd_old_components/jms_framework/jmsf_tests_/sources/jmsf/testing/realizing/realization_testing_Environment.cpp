#include "realization_testing_Environment.h"


#include "realizing_testing_Allocators.h"
#include "jmsf/testing/testing_Factory_maintainer.h"

#include "jmsf/memorying/Constructor.hin"

#include "jmsf/validating/macroses_Should.h"


namespace jmsf {
namespace testing {
namespace realizing {


//void realization_tests_Environment::initialize_mixin() noexcept {
//	initialize_mixin_environment();
//}

//void realization_tests_Environment::terminate_mixin() noexcept {
//	terminate_mixin_environment();
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void realization_testing_Environment::initialize_status_text_messages()
{}

int realization_testing_Environment::initialize_environment() {
	realizing_testing_Allocators::create_instance( _application_allocator );
	testing_Factory_maintainer::create_instance( _application_allocator );
	return 0;
}

void realization_testing_Environment::terminate_environment() noexcept {
	testing_Factory_maintainer::destroy_instance();
	testing_Allocators::destroy_instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_testing_Environment::~realization_testing_Environment() noexcept {
	terminate_mixin_environment();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_testing_Environment::realization_testing_Environment() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_testing_Environment::realization_testing_Environment( const memorying::Womp< memorying::Allocator > &application_allocator ) noexcept
	:
		_application_allocator( application_allocator )
{
	initialize_mixin_environment();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
memorying::Omp< testing_Environment > realization_testing_Environment::create( const memorying::Womp< memorying::Allocator > &application_allocator ) {
	jmsf_Should_never_be_empty( application_allocator );

	return
		memorying::Constructor< testing_Environment, realization_testing_Environment >::construct(
			application_allocator,
			application_allocator );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_testing_Environment::realization_testing_Environment( const realization_testing_Environment &another ) noexcept
	:
		mixin_Environment( another )
{}

const realization_testing_Environment &realization_testing_Environment::operator =( const realization_testing_Environment &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_testing_Environment::realization_testing_Environment( realization_testing_Environment &&/*another*/ ) noexcept {
}

realization_testing_Environment &realization_testing_Environment::operator =( realization_testing_Environment &&another ) noexcept {
	if ( &another == this ) return *this;

	// move
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace testing
} // namespace jmsf
