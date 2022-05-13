#include "Pointing_testing_class.h"


#include "jmsf/testing/testing_Allocators.h"

#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"
#include "jmsf/pointing/Scoped.hin"
#include "jmsf/pointing/cScoped.hin"
#include "jmsf/memorying/Destructor.hin"
#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Allocator.h"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Allocator.h"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/typeing/Naturals.hin"

#include "jmsf/validating/macroses_Should.h"

#include <utility> // ::std::move


namespace jmsf {
namespace pointing {
namespace testing {


typeing::Memory_natural Pointing_testing_class::get_object_number_value() const noexcept {
	return _object_number;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
typeing::Memory_natural Pointing_testing_class::get_object_counter_value() noexcept {
	return _STATIC_object_counter;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Pointing_testing_class::~Pointing_testing_class() noexcept {
	--_STATIC_object_counter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Pointing_testing_class::Pointing_testing_class() noexcept {
	++_STATIC_object_counter;
	_object_number = _STATIC_object_counter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Shared< Pointing_testing_class > Pointing_testing_class::create_shared(
	const memorying::Womp< memorying::Allocator > &reference_counted_omp_allocator,
	const memorying::Womp< memorying::Allocator > &object_class_allocator )
{
	jmsf_Should_never_be_empty( reference_counted_omp_allocator );
	jmsf_Should_never_be_empty( object_class_allocator );

	return
		Shared< Pointing_testing_class >::create(
			reference_counted_omp_allocator,
			memorying::Constructor< Pointing_testing_class, Pointing_testing_class >::construct(
				object_class_allocator ) );
}

// static
cShared< Pointing_testing_class > Pointing_testing_class::create_cshared(
	const memorying::Womp< memorying::Allocator > &reference_counted_omp_allocator,
	const memorying::Womp< memorying::Allocator > &object_class_allocator )
{
	jmsf_Should_never_be_empty( reference_counted_omp_allocator );
	jmsf_Should_never_be_empty( object_class_allocator );

	return
		cShared< Pointing_testing_class >::create(
			reference_counted_omp_allocator,
			memorying::Constructor< Pointing_testing_class, Pointing_testing_class >::construct(
				object_class_allocator ) );
}

// static
Scoped< Pointing_testing_class > Pointing_testing_class::create_scoped(
	const memorying::Womp< memorying::Allocator > &object_class_allocator )
{
	jmsf_Should_never_be_empty( object_class_allocator );

	return
		Scoped< Pointing_testing_class >::create(
			memorying::Constructor< Pointing_testing_class, Pointing_testing_class >::construct(
				object_class_allocator ) );
}

// static
cScoped< Pointing_testing_class > Pointing_testing_class::create_cscoped(
	const memorying::Womp< memorying::Allocator > &object_class_allocator )
{
	jmsf_Should_never_be_empty( object_class_allocator );

	return
		cScoped< Pointing_testing_class >::create(
			memorying::Constructor< Pointing_testing_class, Pointing_testing_class >::construct(
				object_class_allocator ) );
}

// static
memorying::Omp< Pointing_testing_class > Pointing_testing_class::create_omp(
	const memorying::Womp< memorying::Allocator > &object_class_allocator )
{
	jmsf_Should_never_be_empty( object_class_allocator );

	return memorying::Constructor< Pointing_testing_class, Pointing_testing_class >::construct(
		object_class_allocator );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Shared< Pointing_testing_class > Pointing_testing_class::create_shared_testing_object() {
	return
		Pointing_testing_class::create_shared(
			::jmsf::testing::testing_Allocators::instance()->get_reference_counters_allocator(),
			::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator() );
}

// static
const cShared< Pointing_testing_class > Pointing_testing_class::create_cshared_testing_object() {
	return
		Pointing_testing_class::create_cshared(
			::jmsf::testing::testing_Allocators::instance()->get_reference_counters_allocator(),
			::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator() );
}

// static
Scoped< Pointing_testing_class > Pointing_testing_class::create_scoped_testing_object() {
	return
		Pointing_testing_class::create_scoped(
			::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator() );
}

//static
const cScoped< Pointing_testing_class > Pointing_testing_class::create_cscoped_testing_object() {
	return
		Pointing_testing_class::create_cscoped(
			::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator() );
}

// static
const memorying::Omp< Pointing_testing_class > Pointing_testing_class::create_testing_object_omp() {
	return
		Pointing_testing_class::create_omp(
			::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator() );
}

// static
void Pointing_testing_class::destroy_testing_object_omp( memorying::Omp< Pointing_testing_class > const &a_testing_object_omp ) noexcept {
	memorying::Destructor< Pointing_testing_class >::destruct( a_testing_object_omp );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Pointing_testing_class::Pointing_testing_class( const Pointing_testing_class &/*another*/ ) noexcept
{}

const Pointing_testing_class &Pointing_testing_class::operator =( const Pointing_testing_class &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Pointing_testing_class::Pointing_testing_class( Pointing_testing_class &&/*another*/ ) noexcept {
}

Pointing_testing_class &Pointing_testing_class::operator =( Pointing_testing_class &&another ) noexcept {
	if ( &another == this ) return *this;

	// move
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
typeing::Memory_natural Pointing_testing_class::_STATIC_object_counter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace testing
} // namespace pointing
} // namespace jmsf
