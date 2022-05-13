#include "encodebuba_Environment.h"


#include "realizing/realization_encodebuba_Environment.h"
#include "realizing/realization_System_information.h"

#include "nativing/native_Singleton.hin"
#include "nativing/native_Nonlinked.hin"


namespace jmsf {
namespace encodebuba {


// static
bool encodebuba_Environment::initialize() {
	if ( encodebuba_Environment::is_not_empty() ) {
		encodebuba_Environment::instance()->increase_instance_counter();
		return true;
	}

	encodebuba_Environment::set_instance(
		new realizing::realization_encodebuba_Environment(
			new realizing::realization_System_information ) );

	if ( encodebuba_Environment::is_not_empty() ) {
		encodebuba_Environment::instance()->increase_instance_counter();
	}

	return encodebuba_Environment::instance()->is_ok();
}

// static
bool encodebuba_Environment::deinitialize() {
	if ( encodebuba_Environment::is_empty() ) return true;

	encodebuba_Environment::instance()->decrease_instance_counter();

	if ( encodebuba_Environment::instance()->no_valid_instances() ) {
		encodebuba_Environment::destroy_instance();
	}

	return encodebuba_Environment::is_empty();
}


} // namespace encodebuba
} // namespace jmsf
