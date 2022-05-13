#include "al_qt_Environment.h"


#include "realizing/realization_al_qt_Environment.h"

#include "jmsf/encodebuba/encodebuba_Environment.h"
#include "jmsf/encodebuba/nativing/native_Singleton.hin"
#include "jmsf/encodebuba/nativing/native_Scoped.hin"
#include "jmsf/encodebuba/nativing/native_Nonlinked.hin"

#include <iostream>


namespace jmsf {
namespace al_qt {


// static
bool al_qt_Environment::initialize() {
	if ( al_qt_Environment::is_not_empty() ) {
		al_qt_Environment::instance()->increase_instance_counter();
		return true;
	}

	if ( !encodebuba::encodebuba_Environment::initialize() ) return false;

	set_instance(
		new realizing::realization_al_qt_Environment );

	if ( al_qt_Environment::is_not_empty() ) {
		al_qt_Environment::instance()->increase_instance_counter();
	} else {
		encodebuba::encodebuba_Environment::deinitialize();
		return false;
	}

	return al_qt_Environment::instance()->is_ok();
}

// static
bool al_qt_Environment::deinitialize() {
	if ( al_qt_Environment::is_empty() ) return true;

	al_qt_Environment::instance()->decrease_instance_counter();

	if ( al_qt_Environment::instance()->no_valid_instances() ) {
		al_qt_Environment::destroy_instance();
		encodebuba::encodebuba_Environment::deinitialize();
	}

	return al_qt_Environment::is_empty();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//al_qt_Environment::~al_qt_Environment() noexcept
//{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace al_qt
} // namespace jmsf
