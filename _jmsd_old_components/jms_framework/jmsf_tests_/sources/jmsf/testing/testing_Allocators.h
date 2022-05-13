#pragma once

//#include "tests_Allocators.hxx"


#include "jmsf/Allocator_set.h"
#include "jmsf/patterning/Singleton.hpp"

#include "jmsf/texting/Ansii_allocating_assistor.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace testing {


class testing_Allocators :
	public Allocator_set,
	public ::jmsf::patterning::Singleton< testing_Allocators >
{

public:
	virtual const memorying::Womp< memorying::Allocator > &get_testing_object_allocator() const noexcept = 0;

//	virtual const memorying::Womp< memorying::Allocator > &get_subsystem_allocator() const noexcept = 0;
//	virtual const memorying::Womp< memorying::Allocator > &get_character_array_allocator() const noexcept = 0;
//	virtual const memorying::Womp< memorying::Allocator > &get_constant_pointer_list_node_allocator() const noexcept = 0;
//	virtual const memorying::Womp< memorying::Allocator > &get_reference_counters_allocator() const noexcept = 0;
//	virtual const memorying::Womp< texting::Ansii_allocating_assistor > &get_ansii_allocating_assistor() const noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals ::jmsf::patterning::Singleton
	//~virtuals ::jmsf::patterning::Singleton

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend memorying::Destructor< testing_Allocators >;
	// virtual ::jmsf::patterning::Singleton
	~testing_Allocators() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	testing_Allocators() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	testing_Allocators( const testing_Allocators &another ) noexcept;
	const testing_Allocators &operator =( const testing_Allocators &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace testing
} // namespace jmsf
