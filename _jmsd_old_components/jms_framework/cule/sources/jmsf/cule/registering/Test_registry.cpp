#include "Test_registry.h"


//#include "jmsf/cule/Test.h"

#include "jmsf/pointing/cNonlinked.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/typeing/Naturals.hin"

#include "jmsf/validating/Should.h"


namespace jmsf {
namespace cule {
namespace registering {


void Test_registry::register_test( const pointing::cNonlinked< testing::Test > &new_test ) noexcept {
	_registered_tests.push_back( new_test );
}

void Test_registry::register_disabled_test( const pointing::cNonlinked< testing::Test > &new_test ) noexcept {
	_registered_disabled_tests.push_back( new_test );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const ::std::vector< pointing::cNonlinked< testing::Test > > &Test_registry::get_registered_tests() const noexcept {
	return _registered_tests;
}

const ::std::vector< pointing::cNonlinked< testing::Test > > &Test_registry::get_registered_disabled_tests() const noexcept {
	return _registered_disabled_tests;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Test_registry::~Test_registry() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Test_registry::Test_registry() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace registering
} // namespace cule
} // namespace jmsf
