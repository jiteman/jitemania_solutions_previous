#include "Nativing_testing_class.h"


#include "jmsf/encodebuba/nativing/native_Shared.hin"

#include <utility> // ::std::move


namespace jmsf {
namespace encodebuba {
namespace nativing {
namespace testing {


native_memory_natural Nativing_testing_class::get_object_number_value() const noexcept {
	return _object_number;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
native_memory_natural Nativing_testing_class::get_object_counter_value() noexcept {
	return _STATIC_object_counter;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Nativing_testing_class::~Nativing_testing_class() noexcept {
	--_STATIC_object_counter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Nativing_testing_class::Nativing_testing_class() noexcept {
	++_STATIC_object_counter;
	_object_number = _STATIC_object_counter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Nativing_testing_class *Nativing_testing_class::create_new() {
	return new Nativing_testing_class;
}

//// static
//Scoped< Nativing_testing_class > Nativing_testing_class::create_scoped(
//	const memorying::Womp< memorying::Allocator > &shared_class_allocator )
//{
//	jmsf_Should_never_be_empty( shared_class_allocator );

//	return
//		Scoped< Nativing_testing_class >::create(
//			memorying::Constructor< Nativing_testing_class, Nativing_testing_class >::construct(
//				shared_class_allocator ) );
//}

void Nativing_testing_class::destroy() noexcept {
	delete this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Nativing_testing_class::Nativing_testing_class( const Nativing_testing_class &/*another*/ ) noexcept
//{}

//const Nativing_testing_class &Nativing_testing_class::operator =( const Nativing_testing_class &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy
//	return *this;
//}

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Nativing_testing_class::Nativing_testing_class( Nativing_testing_class &&/*another*/ ) noexcept {
//}

//Nativing_testing_class &Nativing_testing_class::operator =( Nativing_testing_class &&another ) noexcept {
//	if ( &another == this ) return *this;

//	// move
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
native_memory_natural Nativing_testing_class::_STATIC_object_counter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace testing
} // namespace nativing
} // namespace encodebuba
} // namespace jmsf
