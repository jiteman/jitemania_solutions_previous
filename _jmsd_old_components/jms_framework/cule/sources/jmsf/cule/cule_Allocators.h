#pragma once


#include "jmsf/Allocator_set.h"
#include "jmsf/patterning/Singleton.hpp"

#include "jmsf/texting/Ansii_allocating_assistor.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/memorying/Destructor.hxx"


#include "jmsf/cule/cule.h"


namespace jmsf {
namespace cule {


class JMSF_CULE_SHARED_INTERFACE cule_Allocators :
	public Allocator_set,
	public patterning::Singleton< cule_Allocators >
{

public:
//	virtual const memorying::Womp< memorying::Allocator > &_get_subsystem_allocator() const noexcept = 0;
//	virtual const memorying::Womp< memorying::Allocator > &get_character_array_allocator() const noexcept = 0;
//	virtual const memorying::Womp< memorying::Allocator > &get_constant_pointer_list_node_allocator() const noexcept = 0;
//	virtual const memorying::Womp< memorying::Allocator > &get_reference_counters_allocator() const noexcept = 0;
//	virtual const memorying::Womp< texting::Ansii_allocating_assistor > &get_ansii_allocating_assistor() const noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend memorying::Destructor< cule_Allocators >;
	virtual ~cule_Allocators() noexcept = 0;

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


} // namespace cule
} // namespace jmsf
