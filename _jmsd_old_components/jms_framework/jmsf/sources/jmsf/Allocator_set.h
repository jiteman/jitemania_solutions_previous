#pragma once

#include "Allocator_set.hxx"


#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/texting/Ansii_allocating_assistor.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {


class JMSF_SHARED_INTERFACE Allocator_set {

public:
	virtual const memorying::Womp< memorying::Allocator > &get_subsystem_allocator() const noexcept = 0;
	virtual const memorying::Womp< memorying::Allocator > &get_character_array_allocator() const noexcept = 0;
	virtual const memorying::Womp< memorying::Allocator > &get_constant_pointer_list_node_allocator() const noexcept = 0;
	virtual const memorying::Womp< memorying::Allocator > &get_reference_counters_allocator() const noexcept = 0;
	virtual const memorying::Womp< texting::Ansii_allocating_assistor > &get_ansii_allocating_assistor() const noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	virtual ~Allocator_set() noexcept = 0;

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
