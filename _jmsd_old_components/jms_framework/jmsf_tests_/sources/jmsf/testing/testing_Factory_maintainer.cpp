#include "testing_Factory_maintainer.h"


#include "testing_Allocators.h"
#include "jmsf/pointing_old/sensing/realizing/realizing_factory_Sensing.h"
#include "jmsf/pointing_old/sensing/factory_Sensing.h"

#include "jmsf/patterning/Singleton.hin"
#include "jmsf/memorying/Constructor.hin"


namespace jmsf {
namespace testing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
testing_Factory_maintainer::~testing_Factory_maintainer() noexcept {
	pointing::sensing::factory_Sensing::destroy_instance();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
testing_Factory_maintainer::testing_Factory_maintainer() noexcept {
	pointing::sensing::realizing::realizing_factory_Sensing::create_instance(
		testing_Allocators::instance()->get_subsystem_allocator(),
		testing_Allocators::instance()->get_reference_counters_allocator(),
		testing_Allocators::instance()->get_subsystem_allocator() );
}

// static
void testing_Factory_maintainer::create_instance( const memorying::Womp< memorying::Allocator > &an_allocator ) noexcept {
	set_instance( memorying::Constructor< testing_Factory_maintainer, testing_Factory_maintainer >::construct( an_allocator ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//testing_Factory_maintainer::testing_Factory_maintainer( const testing_Factory_maintainer &another ) noexcept
//	:
//		Singleton( another )
//{}

//const testing_Factory_maintainer &testing_Factory_maintainer::operator =( const testing_Factory_maintainer &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace testing
} // namespace jmsf
