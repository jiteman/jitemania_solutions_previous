#pragma once


#include "Memory_address.hxx"

//#include "jmsf/typeing/internals/internal_types.h"

#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/texting/Ansii_text.hxx"
#include "jmsf/texting/Ansii_allocating_assistor.hxx"
#include "jmsf/pointing/cShared.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/typeing/Boolean.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace memorying {


// pointer to void
class JMSF_SHARED_INTERFACE Memory_address {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	typeing::internals::platform_byte *take();
//	const typeing::internals::platform_byte *get() const;
	typeing::Memory_natural get() const noexcept;

	void set( typeing::Memory_natural an_address ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean operator ==( const Memory_address &another ) const noexcept;
	typeing::Boolean operator !=( const Memory_address &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	pointing::cShared< texting::Ansii_text > to_ansii_text( const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Memory_address() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_address() noexcept;

public:
//	static Memory_pointer create( typeing::internals::platform_byte *a_memory ) noexcept;

//	template< class A_type >
	static Memory_address create_from_pointer( const void *a_memory );

	static Memory_address create_from_address( typeing::Memory_natural an_address );

private:
	Memory_address( typeing::Memory_natural an_address ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_address( const Memory_address &another ) noexcept;
	const Memory_address &operator =( const Memory_address &another ) noexcept;

	Memory_address( Memory_address &&another ) noexcept;
	Memory_address &operator =( Memory_address &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
//	typeing::internals::platform_byte *_the_memory;
	typeing::Memory_natural _the_address;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
