#include "realization_al_std_Environment.h"


#include "jmsf/encodebuba/realizing/realization_System_information.h"

#include "jmsf/encodebuba/nativing/native_Singleton.hin"
//#include "jmsf/encodebuba/nativing/native_Scoped.hin"
//#include "jmsf/encodebuba/nativing/native_Nonlinked.hin"


namespace jmsf {
namespace al_std {
namespace realizing {



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void realization_al_std_Environment::initialize_status_text_messages() {
}

int realization_al_std_Environment::initialize_environment() {
	return 0;
}

void realization_al_std_Environment::terminate_environment() noexcept {
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_al_std_Environment::~realization_al_std_Environment() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_al_std_Environment::realization_al_std_Environment() noexcept {
	initialize_mixin_environment();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//realization_al_std_Environment::realization_al_std_Environment() noexcept
//{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
realization_al_std_Environment *realization_al_std_Environment::create() {
	return new realization_al_std_Environment;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_al_std_Environment::realization_al_std_Environment( const realization_al_std_Environment &another ) noexcept
	:
		mixin_Environment( another )
{}

const realization_al_std_Environment &realization_al_std_Environment::operator =( const realization_al_std_Environment &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_al_std_Environment::realization_al_std_Environment( realization_al_std_Environment &&/*another*/ ) noexcept
{}

realization_al_std_Environment &realization_al_std_Environment::operator =( realization_al_std_Environment &&another ) noexcept {
	if ( &another == this ) return *this;

	// move
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace al_std
} // namespace jmsf

