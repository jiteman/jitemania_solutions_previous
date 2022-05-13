#include "testing_Environment.h"


#include "realizing/realization_testing_Environment.h"

#include "jmsf/cule/cule_Environment.h"
#include "jmsf/jmsf_Environment.h"

#include "jmsf/patterning/Singleton.hin"

#include <iostream>


namespace jmsf {
namespace testing {


// static
typeing::Boolean testing_Environment::initialize() {
	if ( testing_Environment::is_not_empty() ) {
		testing_Environment::instance()->increase_instance_counter();
		return typeing::True;
	}

	if ( !cule::cule_Environment::initialize() ) {
		::std::cout << ::std::endl << "Error: tests_Environment::initialize() - can't initialize cule_Environment" << ::std::endl;
		return typeing::False;
	}

	if ( !jmsf_Environment::initialize() ) {
		::std::cout << ::std::endl << "Error: tests_Environment::initialize() - can't initialize jmsf_Environment" << ::std::endl;
		cule::cule_Environment::deinitialize();
		return typeing::False;
	}

	set_instance( realizing::realization_testing_Environment::create( jmsf_Allocators::instance()->get_subsystem_allocator() ) );

	if ( testing_Environment::is_not_empty() ) {
		testing_Environment::instance()->increase_instance_counter();
	} else {
		cule::cule_Environment::deinitialize();
		jmsf_Environment::deinitialize();
		return typeing::False;
	}

	return typeing::Boolean::create( testing_Environment::instance()->is_ok() );
}

// static
typeing::Boolean testing_Environment::deinitialize() {
	if ( testing_Environment::is_empty() ) {
		return typeing::True;
	}

	testing_Environment::instance()->decrease_instance_counter();

	if ( testing_Environment::instance()->no_valid_instances() ) {
		testing_Environment::destroy_instance();
		cule::cule_Environment::deinitialize();
		jmsf_Environment::deinitialize();
	}

	return testing_Environment::is_empty();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace testing
} // namespace jmsf
