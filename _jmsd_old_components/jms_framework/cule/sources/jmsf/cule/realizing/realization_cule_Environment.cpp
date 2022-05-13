#include "realization_cule_Environment.h"


#include "realization_cule_Allocators.h"
#include "jmsf/cule/to_libs/system/System_time.h"
#include "jmsf/cule/executing/realizing/realization_Test_stop_watch.h"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/validating/macroses_Should.h"

#include "jmsf/cule/cule_main.h"

#include "jmsd/platform_support/platform_detection/compiler_detection.h"


namespace jmsf {
namespace cule {
namespace realizing {


int realization_cule_Environment::run_all_tests() const {
	int result = 0;

#if !defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
		result = cule_main_console();

#else
//		result = cule_main_visual_studio();
	result = cule_main_console();

#endif

	return result;
}

//void realization_cule_Environment::initialize_mixin() noexcept {
//	initialize_mixin_environment();
//}

//void realization_cule_Environment::terminate_mixin() noexcept {
//	terminate_mixin_environment();
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void realization_cule_Environment::initialize_status_text_messages()
{}

int realization_cule_Environment::initialize_environment() {
	realizing::realization_cule_Allocators::create_instance( _application_allocator );

	{
		pointing::Shared< to_libs::system::System_time > system_time =
			pointing::Shared< to_libs::system::System_time >::create(
				cule_Allocators::instance()->get_reference_counters_allocator(),
				memorying::Constructor< to_libs::system::System_time, to_libs::system::System_time >::construct(
					cule_Allocators::instance()->get_subsystem_allocator() ) );

		executing::Test_stop_watch::set_instance(
			executing::realizing::realization_Test_stop_watch::create(
				cule_Allocators::instance()->get_subsystem_allocator(),
				system_time ) );
	}

	return 0;
}

void realization_cule_Environment::terminate_environment() noexcept {
	executing::Test_stop_watch::destroy_instance();
	cule_Allocators::destroy_instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_cule_Environment::~realization_cule_Environment() noexcept {
	terminate_mixin_environment();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_cule_Environment::realization_cule_Environment() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_cule_Environment::realization_cule_Environment( const memorying::Womp< memorying::Allocator > &application_allocator ) noexcept
	:
		_application_allocator( application_allocator )
{
	initialize_mixin_environment();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
memorying::Omp< cule_Environment > realization_cule_Environment::create( const memorying::Womp< memorying::Allocator > &application_allocator ) {
	jmsf_Should_never_be_empty( application_allocator );

	return
		memorying::Constructor< cule_Environment, realization_cule_Environment >::construct(
			application_allocator,
			application_allocator );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_cule_Environment::realization_cule_Environment( const realization_cule_Environment &another ) noexcept
	:
		mixin_Environment( ::std::move( const_cast< realization_cule_Environment & >( another ) ) )
{}

const realization_cule_Environment &realization_cule_Environment::operator =( const realization_cule_Environment &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_cule_Environment::realization_cule_Environment( realization_cule_Environment &&/*another*/ ) noexcept {
}

realization_cule_Environment &realization_cule_Environment::operator =( realization_cule_Environment &&another ) noexcept {
	if ( &another == this ) return *this;

	// move
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace cule
} // namespace jmsf

