#pragma once

#include "realization_new_System_allocator.hxx"


#include "../new_Allocator.h"

#include "jmsf/realizing/realization_jmsf_Environment.hxx"
#include "jmsf/memorying/Womp.hxx"


namespace jmsf {
namespace memorying {
namespace realizing {


class realization_new_System_allocator :
		public new_Allocator
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
	~realization_new_System_allocator() noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_new_System_allocator() noexcept;

private: friend ::jmsf::realizing::realization_jmsf_Environment;
	static Womp< new_Allocator > create() noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_new_System_allocator( const realization_new_System_allocator &another ) noexcept;
	const realization_new_System_allocator &operator =( const realization_new_System_allocator &another ) noexcept;

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
