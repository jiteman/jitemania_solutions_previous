#pragma once

#include "realization_Subsystem_allocator.hxx"


#include "../Allocator.h"

#include "jmsf/memorying/Womp.hin"

//#include "jmsf/jmsf_Environment.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Constructor.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace memorying {
namespace realizing {


class JMSF_SHARED_INTERFACE realization_Subsystem_allocator :
	public Allocator
{

public:
	// virtuals Allocator
	Memory_address allocate_memory( typeing::Memory_natural a_size, typeing::Memory_natural an_alignment );
	void deallocate_memory( const Memory_address &a_memory, typeing::Memory_natural an_alignment );
	//~virtuals Allocator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~realization_Subsystem_allocator() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Allocator, realization_Subsystem_allocator >;
	realization_Subsystem_allocator( const memorying::Womp< memorying::Allocator > &application_allocator ) noexcept;

public:
	// Seinsei: todonext - create allocator subtypes - like with exceptions (application, subsystem, etc.) +
	// realizations to mix them into final allocator (like cule_subsystem_allocator)
	// friend jmsf_Environment;
	static Omp< Allocator > create( const memorying::Womp< memorying::Allocator > &application_allocator ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_Subsystem_allocator( const realization_Subsystem_allocator &another ) noexcept;
	const realization_Subsystem_allocator &operator =( const realization_Subsystem_allocator &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Womp< Allocator > _application_allocator;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace memorying
} // namespace jmsf
