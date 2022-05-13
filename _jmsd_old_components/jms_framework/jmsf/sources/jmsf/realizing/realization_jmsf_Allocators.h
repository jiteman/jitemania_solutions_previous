#pragma once

#include "realization_jmsf_Allocators.hxx"


#include "../jmsf_Allocators.h"

#include "jmsf/memorying/Owomp.hpp"

#include "jmsf/realizing/realization_jmsf_Environment.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace realizing {


class realization_jmsf_Allocators :
	public jmsf_Allocators
{

public:
	// virtuals Allocator_set
//	const memorying::Womp< memorying::Allocator > &get_application_allocator() const noexcept;
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
	~realization_jmsf_Allocators() noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< jmsf_Allocators, realization_jmsf_Allocators >;
	realization_jmsf_Allocators(
//		const memorying::Womp< memorying::Allocator > &system_allocator,
//		const memorying::Omp< memorying::Allocator > &application_allocator,
		const memorying::Omp< memorying::Allocator > &subsystem_allocator,
		const memorying::Omp< texting::Ansii_allocating_assistor > &ansii_allocating_assistor ) noexcept;

private: friend ::jmsf::realizing::realization_jmsf_Environment;
	static void create_instance( const memorying::Womp< memorying::Allocator > &application_allocator );

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_jmsf_Allocators( const realization_jmsf_Allocators &another ) noexcept;
	const realization_jmsf_Allocators &operator =( const realization_jmsf_Allocators &another ) noexcept;

	// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
//	memorying::Owomp< memorying::Allocator > _system_allocator;
//	memorying::Womp< memorying::Allocator > _application_allocator;
	memorying::Owomp< memorying::Allocator > _subsystem_allocator;
	memorying::Owomp< texting::Ansii_allocating_assistor > _ansii_allocating_assistor;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace jmsf
