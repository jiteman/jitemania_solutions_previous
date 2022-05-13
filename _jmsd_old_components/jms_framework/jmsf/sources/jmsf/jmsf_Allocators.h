#pragma once

#include "jmsf_Allocators.hxx"


#include "Allocator_set.h"
#include "patterning/Singleton.hpp"

#include "jmsf/texting/Ansii_allocating_assistor.hxx"
#include "memorying/Womp.hxx"
#include "memorying/Allocator.hxx"
#include "memorying/Destructor.hxx"


#include "jmsf.h"


namespace jmsf {


class JMSF_SHARED_INTERFACE jmsf_Allocators :
	public Allocator_set,
	public patterning::Singleton< jmsf_Allocators >
{

public:
//	virtual const memorying::Womp< memorying::Allocator > &get_application_allocator() const noexcept = 0;
//	virtual const memorying::Womp< memorying::Allocator > &get_subsystem_allocator() const noexcept = 0;
//	virtual const memorying::Womp< memorying::Allocator > &get_character_array_allocator() const noexcept = 0;
//	virtual const memorying::Womp< memorying::Allocator > &get_constant_pointer_list_node_allocator() const noexcept = 0;
//	virtual const memorying::Womp< memorying::Allocator > &get_reference_counters_allocator() const noexcept = 0;
//	virtual const memorying::Womp< texting::Ansii_allocating_assistor > &get_ansii_allocating_assistor() const noexcept = 0;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

	// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend memorying::Destructor< jmsf_Allocators >;
	virtual ~jmsf_Allocators() noexcept = 0;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

	// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace jmsf
