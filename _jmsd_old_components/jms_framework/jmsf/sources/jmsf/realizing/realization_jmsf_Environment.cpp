#include "realization_jmsf_Environment.h"


#include "jmsf/memorying/realizing/realization_System_allocator.h"
#include "jmsf/memorying/realizing/realization_Application_allocator.h"
#include "jmsf/realizing/realization_jmsf_Allocators.h"
#include "jmsf/memorying/Owomp.hin"
#include "jmsf/encodebuba/nativing/native_Singleton.hin"


namespace jmsf {
namespace realizing {


memorying::Womp< memorying::Allocator > realization_jmsf_Environment::get_application_allocator() const noexcept {
	return _application_allocator.get_womp();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void realization_jmsf_Environment::initialize_status_text_messages()
{}

int realization_jmsf_Environment::initialize_environment() {
	_system_allocator = memorying::realizing::realization_System_allocator::create();

	_application_allocator =
		memorying::Owomp< memorying::Allocator >::create(
			memorying::realizing::realization_Application_allocator::create( _system_allocator ) );

	realizing::realization_jmsf_Allocators::create_instance( _application_allocator.get_womp() );
	return 0;
}

void realization_jmsf_Environment::terminate_environment() noexcept {
	jmsf_Allocators::destroy_instance();
	memorying::Destructor< memorying::Allocator >::destruct( _application_allocator.get_omp()  );
	_application_allocator = memorying::Owomp< memorying::Allocator >();

	// Seinsei: info - special case - first (root, base, etc.) allocator created with "new" should be deleted with "delete"
	delete dynamic_cast< const memorying::realizing::realization_System_allocator * >( _system_allocator.operator ->() );
	_system_allocator = memorying::Womp< memorying::Allocator >();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_jmsf_Environment::~realization_jmsf_Environment() noexcept {
	terminate_mixin_environment();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_jmsf_Environment::realization_jmsf_Environment() noexcept {
	initialize_mixin_environment();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//realizing_jmsf_Environment::realizing_jmsf_Environment() noexcept
//{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
jmsf_Environment *realization_jmsf_Environment::create() {
	return new realization_jmsf_Environment;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_jmsf_Environment::realization_jmsf_Environment( const realization_jmsf_Environment &another ) noexcept
	:
		mixin_Environment( another )
{}

const realization_jmsf_Environment &realization_jmsf_Environment::operator =( const realization_jmsf_Environment &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_jmsf_Environment::realization_jmsf_Environment( realization_jmsf_Environment &&/*another*/ ) noexcept {
}

realization_jmsf_Environment &realization_jmsf_Environment::operator =( realization_jmsf_Environment &&another ) noexcept {
	if ( &another == this ) return *this;

	// move
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace jmsf
