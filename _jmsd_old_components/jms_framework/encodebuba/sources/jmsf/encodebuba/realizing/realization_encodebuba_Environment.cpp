#include "realization_encodebuba_Environment.h"


#include "jmsf/encodebuba/realizing/realization_System_information.h"

#include "jmsf/encodebuba/System_information.h"
#include "jmsf/encodebuba/nativing/native_Singleton.hin"
#include "jmsf/encodebuba/nativing/native_Scoped.hin"
#include "jmsf/encodebuba/nativing/native_Nonlinked.hin"


namespace jmsf {
namespace encodebuba {
namespace realizing {


nativing::native_Nonlinked< System_information > realization_encodebuba_Environment::get_system_information() const noexcept {
	if ( _system_information.is_empty() ) return nativing::native_Nonlinked< System_information >();

	return
		nativing::native_Nonlinked< System_information >::create_from_static(
			_system_information.operator ->() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void realization_encodebuba_Environment::initialize_status_text_messages() {
}

int realization_encodebuba_Environment::initialize_environment() {
	return 0;
}

void realization_encodebuba_Environment::terminate_environment() noexcept {
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_encodebuba_Environment::~realization_encodebuba_Environment() noexcept {
	terminate_mixin_environment();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//realization_encodebuba_Environment::realization_encodebuba_Environment() noexcept
//{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_encodebuba_Environment::realization_encodebuba_Environment( const System_information *a_system_information ) noexcept
	:
		_system_information( nativing::native_Scoped< System_information >::create( a_system_information ) )
{
	initialize_mixin_environment();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
realization_encodebuba_Environment *realization_encodebuba_Environment::create() {
	return new realization_encodebuba_Environment( new realizing::realization_System_information );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_encodebuba_Environment::realization_encodebuba_Environment( const realization_encodebuba_Environment &another ) noexcept
	:
		mixin_Environment( another )
{}

const realization_encodebuba_Environment &realization_encodebuba_Environment::operator =( const realization_encodebuba_Environment &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_encodebuba_Environment::realization_encodebuba_Environment( realization_encodebuba_Environment &&another ) noexcept
	:
		_system_information( ::std::move( another._system_information ) )
{}

realization_encodebuba_Environment &realization_encodebuba_Environment::operator =( realization_encodebuba_Environment &&another ) noexcept {
	if ( &another == this ) return *this;

	_system_information = ::std::move( another._system_information );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace encodebuba
} // namespace jmsf

