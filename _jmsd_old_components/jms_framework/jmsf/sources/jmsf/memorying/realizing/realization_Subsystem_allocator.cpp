#include "realization_Subsystem_allocator.h"


#include "jmsf/memorying/Omp.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Constructor.hin"


namespace jmsf {
namespace memorying {
namespace realizing {


Memory_address realization_Subsystem_allocator::allocate_memory( const typeing::Memory_natural a_size, const typeing::Memory_natural an_alignment ) {
	return _application_allocator->allocate_memory( a_size, an_alignment );
}

void realization_Subsystem_allocator::deallocate_memory( const Memory_address &a_memory, const typeing::Memory_natural an_alignment ) {
	_application_allocator->deallocate_memory( a_memory, an_alignment );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_Subsystem_allocator::~realization_Subsystem_allocator() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Subsystem_allocator::realization_Subsystem_allocator( const memorying::Womp< memorying::Allocator > &application_allocator ) noexcept
	:
		_application_allocator( application_allocator )
{}

// static
Omp< Allocator > realization_Subsystem_allocator::create( const memorying::Womp< memorying::Allocator > &application_allocator ) noexcept {
	return Constructor< Allocator, realization_Subsystem_allocator >::construct( application_allocator, application_allocator );
//	return Omp< Allocator >();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Subsystem_allocator::realization_Subsystem_allocator( const realization_Subsystem_allocator &/*another*/ ) noexcept {
}

const realization_Subsystem_allocator &realization_Subsystem_allocator::operator =( const realization_Subsystem_allocator &another ) noexcept {
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
