#include "jmsf_Environment.h"


#include "jmsf/typeing/Boolean.h"

#include "realizing/realization_jmsf_Environment.h"

#include "jmsf/al_std/al_std_Environment.h"
#include "jmsf/encodebuba/encodebuba_Environment.h"
#include "jmsf/encodebuba/nativing/native_Singleton.hin"


#include "jmsf/jmsf_Allocators.h"
#include "jmsf/pointing/Nonlinked.hin"
//#include <utility>
#include <iostream>


namespace jmsf {


// static
typeing::Boolean jmsf_Environment::initialize() {
	if ( jmsf_Environment::is_not_empty() ) {
		jmsf_Environment::instance()->increase_instance_counter();
		return typeing::True;
	}

	if ( !encodebuba::encodebuba_Environment::initialize() ) {
		::std::cout << ::std::endl << "Error: jmsf_Environment::initialize() - can't initialize encodebuba_Environment" << ::std::endl;
		return typeing::False;
	}

	if ( !al_std::al_std_Environment::initialize() ) {
		::std::cout << ::std::endl << "Error: jmsf_Environment::initialize() - can't initialize al_std_Environment" << ::std::endl;
		encodebuba::encodebuba_Environment::deinitialize();
		return typeing::False;
	}

	set_instance( new realizing::realization_jmsf_Environment );

	if ( jmsf_Environment::is_not_empty() ) {
		jmsf_Environment::instance()->increase_instance_counter();
	} else {
		encodebuba::encodebuba_Environment::deinitialize();
		al_std::al_std_Environment::deinitialize();
		return typeing::False;
	}

	return typeing::Boolean::create( jmsf_Environment::instance()->is_ok() );
}

// static
typeing::Boolean jmsf_Environment::deinitialize() {
	if ( jmsf_Environment::is_empty() ) return typeing::True;

	jmsf_Environment::instance()->decrease_instance_counter();

	if ( jmsf_Environment::instance()->no_valid_instances() ) {
		jmsf_Environment::destroy_instance();
		encodebuba::encodebuba_Environment::deinitialize();
		al_std::al_std_Environment::deinitialize();
	}

	return typeing::Boolean::create( jmsf_Environment::is_empty() );
}


} // namespace jmsf
