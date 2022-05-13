#pragma once


#include "../cule_Allocators.h"

#include "jmsf/memorying/Owomp.hpp"

#include "realization_cule_Environment.hxx"
#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace cule {
namespace realizing {


class realization_cule_Allocators :
		public cule_Allocators
{

public:
	// virtuals Allocator_set
	const memorying::Womp< memorying::Allocator > &get_subsystem_allocator() const noexcept;
	const memorying::Womp< memorying::Allocator > &get_character_array_allocator() const noexcept;
	const memorying::Womp< memorying::Allocator > &get_constant_pointer_list_node_allocator() const noexcept;
	const memorying::Womp< memorying::Allocator > &get_reference_counters_allocator() const noexcept;
	const memorying::Womp< texting::Ansii_allocating_assistor > &get_ansii_allocating_assistor() const noexcept;
	//~virtuals Allocator_set

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~realization_cule_Allocators() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< cule_Allocators, realization_cule_Allocators >;
	realization_cule_Allocators(
		const memorying::Omp< memorying::Allocator > &subsystem_allocator,
		const memorying::Omp< texting::Ansii_allocating_assistor > &ansii_allocating_assistor ) noexcept;

private: friend realization_cule_Environment;
	static void create_instance( const memorying::Womp< memorying::Allocator > &application_allocator );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_cule_Allocators( const realization_cule_Allocators &another ) noexcept;
	const realization_cule_Allocators &operator =( const realization_cule_Allocators &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Owomp< memorying::Allocator > _subsystem_allocator;
	memorying::Owomp< texting::Ansii_allocating_assistor > _ansii_allocating_assistor;
//	memorying::Omp< memorying::Allocator > _global_allocator;
//	memorying::Womp< memorying::Allocator > _global_allocator_reference;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace cule
} // namespace jmsf

