#pragma once

#include "Awa_iterator.hxx"


#include "internalling/Amp_data.hpp"
#include "Memory_address.h"
#include "Object_pointer.hpp"

#include "Amp.hxx"


namespace jmsf {
namespace memorying {


template< class A_type >
class Awa_iterator {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

	typeing::Boolean is_in_range() const noexcept;
	typeing::Boolean is_out_of_range() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_address get_memory_pointer() const;

	const A_type &operator *() const;
	const A_type *operator ->() const;

	A_type &operator *();
	A_type *operator ->();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Awa_iterator &operator ++() noexcept;
	Awa_iterator operator ++( int ) noexcept;
	Awa_iterator &operator --() noexcept;
	Awa_iterator operator --( int ) noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Awa_iterator() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Awa_iterator() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Awa_iterator(
		const internalling::Amp_data< A_type > &an_amp_data,
		typeing::Memory_natural a_quantity ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static
		Awa_iterator create(
			const internalling::Amp_data< A_type > &an_amp_data,
			typeing::Memory_natural a_quantity );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Awa_iterator( const Awa_iterator &another ) noexcept;
	const Awa_iterator &operator =( const Awa_iterator &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Awa_iterator( Awa_iterator &&another ) noexcept;
	Awa_iterator &operator =( Awa_iterator &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internalling::Amp_data< A_type > _the_amp_data;
	typeing::Memory_natural _the_quantity;
	mutable typeing::Memory_natural _the_position;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	typeing::Memory_natural get_current_object_address() const noexcept;
	typeing::Memory_natural get_current_begin_address() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
