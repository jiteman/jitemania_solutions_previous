#pragma once

#include "realization_System_allocator.hxx"


#include "../Allocator.h"

#include "jmsf/realizing/realization_jmsf_Environment.hxx"
#include "jmsf/memorying/Womp.hxx"


namespace jmsf {
namespace memorying {
namespace realizing {


class realization_System_allocator :
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
public:
	~realization_System_allocator() noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_System_allocator() noexcept;

private: friend ::jmsf::realizing::realization_jmsf_Environment;
	static Womp< Allocator > create() noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_System_allocator( const realization_System_allocator &another ) noexcept;
	const realization_System_allocator &operator =( const realization_System_allocator &another ) noexcept;

	// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace memorying
} // namespace jmsf
