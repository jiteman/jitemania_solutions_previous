#pragma once

#include "../testing_Allocators.h"


#include "jmsf/memorying/Owomp.hpp"

#include "realization_testing_Environment.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace testing {
namespace realizing {


class realizing_testing_Allocators :
	public testing_Allocators
{

public:
	// virtuals tests_Allocators
	const memorying::Womp< memorying::Allocator > &get_testing_object_allocator() const noexcept;
	//~virtuals tests_Allocators

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Allocator_set
	const memorying::Womp< memorying::Allocator > &get_subsystem_allocator() const noexcept;
	const memorying::Womp< memorying::Allocator > &get_character_array_allocator() const noexcept;
	const memorying::Womp< memorying::Allocator > &get_constant_pointer_list_node_allocator() const noexcept;
	const memorying::Womp< memorying::Allocator > &get_reference_counters_allocator() const noexcept;
	const memorying::Womp< texting::Ansii_allocating_assistor > &get_ansii_allocating_assistor() const noexcept;
	//~virtuals Allocator_set

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< testing_Allocators >;
	// virtual tests_Allocators
	~realizing_testing_Allocators() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< testing_Allocators, realizing_testing_Allocators >;
	realizing_testing_Allocators(
		const memorying::Omp< memorying::Allocator > &subsystem_allocator,
		const memorying::Omp< texting::Ansii_allocating_assistor > &ansii_allocating_assistor ) noexcept;

private: friend realization_testing_Environment;
	static void create_instance( const memorying::Womp< memorying::Allocator > &application_allocator );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realizing_testing_Allocators( const realizing_testing_Allocators &another ) noexcept;
	const realizing_testing_Allocators &operator =( const realizing_testing_Allocators &another ) noexcept;

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
} // namespace testing
} // namespace jmsf
