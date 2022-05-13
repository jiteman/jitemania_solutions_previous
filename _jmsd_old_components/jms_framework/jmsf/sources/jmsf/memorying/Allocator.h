#pragma once


//#include "jmsf/patterning/mixing/mixin_null_Object.hxx"
//#include "jmsf/patterning/mixing/mixin_exception_Object.hxx"
//#include "jmsf/patterning/mixing/mixin_Object.hxx"
#include "Destructor.hxx"

#include "Memory_address.hxx"

#include "jmsf/typeing/Naturals.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace memorying {


// Seinsei: todonext - create allocator subtypes - like with exceptions (application, subsystem, etc.) +
// realizations to mix them into final allocator (like cule_subsystem_allocator)
class JMSF_SHARED_INTERFACE Allocator {

public:
	virtual Memory_address allocate_memory( typeing::Memory_natural a_size, typeing::Memory_natural an_alignment ) = 0;
	virtual void deallocate_memory( const Memory_address &a_memory, typeing::Memory_natural an_alignment ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
//	friend patterning::mixing::mixin_null_Object;
//	friend patterning::mixing::mixin_exception_Object;
//	friend patterning::mixing::mixin_Object;
	friend memorying::Destructor< memorying::Allocator >;
	virtual ~Allocator() noexcept = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};



} // namespace memorying
} // namespace jmsf
