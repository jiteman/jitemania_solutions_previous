#pragma once

#include "Omp.hxx"


#include "internalling/Omp_data.hpp"
#include "Womp.hpp"
#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/texting/Ansii_allocating_assistor.hxx"
#include "Allocator.hxx"
#include "jmsf/typeing/Boolean.hxx"
#include "Memory_address.hxx"


namespace jmsf {
namespace memorying {


// Seinsei: future idea - will hold object pointer, allocator and object control pointer (allocation)
//		and reference counter interface for shared object
template< class A_type >
class Omp {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

	// Seinsei: todonext - remove get and take, then rename get_memory to get
	const A_type &operator *() const;
	const A_type *operator ->() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_type &operator *();
	A_type *operator ->();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_address get_object_address() const;
	Womp< Allocator > get_allocator() const;
	typeing::Memory_natural get_alignment() const;
	typeing::Memory_natural get_displacement() const;
	Womp< A_type > get_as_womp() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean operator ==( const Omp &another ) const noexcept;
	typeing::Boolean operator !=( const Omp &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	pointing::cShared< texting::Ansii_text > to_ansii_text( const Womp< texting::Ansii_allocating_assistor > &an_aaa ) const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Omp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Omp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Omp(
		const internalling::Omp_data< A_type > &an_omp_data,
		const Womp< Allocator > &an_allocator,
		typeing::Memory_natural an_alignment ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

	template< class A_created_type >
	static Omp create(
		const Memory_address &a_memory_address,
		const Womp< Allocator > &an_allocator,
		typeing::Memory_natural an_alignment );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Omp( const Omp &another ) noexcept;
	const Omp &operator =( const Omp &another ) noexcept;

	Omp( Omp &&another ) noexcept;
	const Omp &operator =( Omp &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internalling::Omp_data< A_type > _the_omp_data;
	Womp< Allocator > _the_allocator;
	typeing::Memory_natural _the_alignment;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
