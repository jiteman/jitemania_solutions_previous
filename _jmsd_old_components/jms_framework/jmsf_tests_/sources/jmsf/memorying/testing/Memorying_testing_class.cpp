#include "Memorying_testing_class.h"


#include "jmsf/testing/testing_Allocators.h"

//#include "jmsf/pointing/Shared.hin"
//#include "jmsf/pointing/cShared.hin"
//#include "jmsf/pointing/Scoped.hin"
//#include "jmsf/pointing/cScoped.hin"
#include "jmsf/memorying/Destructor.hin"
#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Allocator.h"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/typeing/Naturals.hin"

#include "jmsf/validating/macroses_Should.h"

#include <utility>


namespace jmsf {
namespace memorying {
namespace testing {


typeing::Memory_natural Memorying_testing_class::get_object_number_value() const noexcept {
	return _object_number;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
typeing::Memory_natural Memorying_testing_class::get_object_counter_value() noexcept {
	return _STATIC_object_counter;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Memorying_testing_class::~Memorying_testing_class() noexcept {
	--_STATIC_object_counter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memorying_testing_class::Memorying_testing_class() noexcept {
	++_STATIC_object_counter;
	_object_number = _STATIC_object_counter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
const memorying::Omp< Memorying_testing_class > Memorying_testing_class::create_omp(
	const memorying::Womp< memorying::Allocator > &shared_class_allocator )
{
	jmsf_Should_never_be_empty( shared_class_allocator );

	return memorying::Constructor< Memorying_testing_class, Memorying_testing_class >::construct(
		shared_class_allocator );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
const memorying::Omp< Memorying_testing_class > Memorying_testing_class::create_testing_object_omp() {
	return
		Memorying_testing_class::create_omp(
			::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memorying_testing_class::Memorying_testing_class( const Memorying_testing_class &/*another*/ ) noexcept
{}

const Memorying_testing_class &Memorying_testing_class::operator =( const Memorying_testing_class &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memorying_testing_class::Memorying_testing_class( Memorying_testing_class &&/*another*/ ) noexcept {
}

Memorying_testing_class &Memorying_testing_class::operator =( Memorying_testing_class &&another ) noexcept {
	if ( &another == this ) return *this;

	// move
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
typeing::Memory_natural Memorying_testing_class::_STATIC_object_counter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace testing_dev
} // namespace memorying
} // namespace jmsf
