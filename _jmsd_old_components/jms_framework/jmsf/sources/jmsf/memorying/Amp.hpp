#pragma once


#include "Amp.hxx"

#include "Memory_address.h"
#include "internalling/Amp_data.hpp"
#include "jmsf/typeing/Naturals.hpp"
#include "Womp.hpp"

#include "Wamp.hxx"
#include "Awa_iterator.hxx"
#include "Allocator.hxx"
#include "jmsf/typeing/Boolean.hxx"


namespace jmsf {
namespace memorying {


template< class A_type >
class Amp {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

	Awa_iterator< A_type > get() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Awa_iterator< A_type > take();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_address get_object_address() const;
	typeing::Memory_natural get_quantity() const noexcept;
	Womp< Allocator > get_allocator() const noexcept;
	typeing::Memory_natural get_alignment() const noexcept;
	typeing::Memory_natural get_displacement() const noexcept;
	typeing::Memory_natural get_size() const noexcept;
	Wamp< A_type > get_wamp() const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Amp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Amp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Amp(
		const internalling::Amp_data< A_type > &an_amp_data,
		const Womp< Allocator > &an_allocator,
		typeing::Memory_natural an_alignment,
		typeing::Memory_natural a_quantity ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	template< class A_created_type >
	static Amp create(
		const Memory_address &a_memory_address,
		const Womp< Allocator > &an_allocator,
		typeing::Memory_natural an_alignment,
		typeing::Memory_natural a_quantity );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Amp( const Amp &another ) noexcept;
	const Amp &operator =( const Amp &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Amp( Amp &&another ) noexcept;
	Amp &operator =( Amp &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internalling::Amp_data< A_type > _the_amp_data;
	Womp< Allocator > _the_allocator;
	typeing::Memory_natural _the_alignment;
	typeing::Memory_natural _the_quantity;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
