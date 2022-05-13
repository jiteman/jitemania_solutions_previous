#pragma once

#include "realization_Application_allocator.hxx"


#include "../Allocator.h"

#include "jmsf/memorying/Womp.hpp"

#include "jmsf/realizing/realization_jmsf_Environment.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Constructor.hxx"
//#include "jmsf/memorying/Destructor.hxx"


namespace jmsf {
namespace memorying {
namespace realizing { // Seinsei: todonext - refactor to singleton


class realization_Application_allocator :
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
	~realization_Application_allocator() noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Allocator, realization_Application_allocator >;
	realization_Application_allocator( const Womp< Allocator > &system_allocator ) noexcept;

private: friend ::jmsf::realizing::realization_jmsf_Environment;
	static Omp< Allocator > create( const Womp< Allocator > &system_allocator ) noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_Application_allocator( const realization_Application_allocator &another ) noexcept;
	const realization_Application_allocator &operator =( const realization_Application_allocator &another ) noexcept;

	// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Womp< Allocator > _system_allocator;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace memorying
} // namespace jmsf
