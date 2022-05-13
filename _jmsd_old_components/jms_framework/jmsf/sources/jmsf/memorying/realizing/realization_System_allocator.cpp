#include "realization_System_allocator.h"


#include "jmsf/memorying/Womp.hin"
#include "jmsf/typeing/Aso.hin"
#include "jmsf/typeing/Naturals.hin"

#include "jmsf/al_std/stl_hin/cstdlib_al_std.hin"

#include <iostream>


namespace jmsf {
namespace memorying {
namespace realizing {


Memory_address realization_System_allocator::allocate_memory( typeing::Memory_natural a_size, const typeing::Memory_natural /*an_alignment*/ ) {
	return
		a_size.is_nil() ?
				Memory_address()
			:
				Memory_address::create_from_address( typeing::create_address_from_pointer( ::std::malloc( a_size.get_native_value() ) ) );
}

void realization_System_allocator::deallocate_memory( const Memory_address &a_memory, const typeing::Memory_natural /*an_alignment*/ ) {
	if ( a_memory.is_empty() ) return;

	Memory_address &non_const_memory_pointer = const_cast< Memory_address & >( a_memory );
	::std::free( reinterpret_cast< void * >( non_const_memory_pointer.get().get_native_value() ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
 realization_System_allocator::~realization_System_allocator() noexcept {
//	::std::cout << ::std::endl;
//	::std::cout << "realizing_System_allocator::~realizing_System_allocator()" << ::std::endl;
//	::std::cout << ::std::endl;
 }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 realization_System_allocator::realization_System_allocator() noexcept {
//	::std::cout << ::std::endl;
//	::std::cout << "realizing_System_allocator::realizing_System_allocator()" << ::std::endl;
//	::std::cout << ::std::endl;
}

// static
Womp< Allocator > realization_System_allocator::create() noexcept {
	return
		Womp< Allocator >::create(
			Object_pointer< Allocator >::create_from_pointer(
				::new realization_System_allocator ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 realization_System_allocator::realization_System_allocator( const  realization_System_allocator &/*another*/ ) noexcept {
}

const  realization_System_allocator & realization_System_allocator::operator =( const  realization_System_allocator &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace memorying
} // namespace jmsf
