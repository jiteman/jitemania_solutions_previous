#pragma once

#include "Reference_counted_omp.hxx"


#include "jmsf/memorying/Omp.hin"
#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/texting/Ansii_text.hxx"
#include "jmsf/texting/Ansii_allocating_assistor.hxx"
#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/typeing/Boolean.hxx"


namespace jmsf {
namespace pointing {
namespace internalling {


template< class A_type >
class Reference_counted_omp {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Memory_natural increase_strong_reference_counter();
	typeing::Memory_natural decrease_strong_reference_counter();
	typeing::Memory_natural increase_weak_reference_counter();
	typeing::Memory_natural decrease_weak_reference_counter();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const A_type &get_object() const;
	A_type &take_object();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Memory_natural get_both_reference_counters_value() const noexcept;
	typeing::Memory_natural get_strong_reference_counter_value() const noexcept;
	typeing::Memory_natural get_weak_reference_counter_value() const noexcept;
	typeing::Boolean are_both_reference_counters_nill() const noexcept;
	typeing::Boolean is_strong_reference_counter_nill() const noexcept;
	typeing::Boolean is_weak_reference_counter_nill() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean operator ==( const Reference_counted_omp &another ) const noexcept;
	typeing::Boolean operator !=( const Reference_counted_omp &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cShared< texting::Ansii_text > to_ansii_text( const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Reference_counted_omp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Reference_counted_omp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Reference_counted_omp, Reference_counted_omp >;
	Reference_counted_omp( const memorying::Omp< A_type > &object_memory_pointer ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static
		memorying::Omp< Reference_counted_omp >
			create(
				const memorying::Womp< memorying::Allocator > &reference_counted_omp_allocator,
				const memorying::Omp< A_type > &object_memory_pointer );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Reference_counted_omp( const Reference_counted_omp &another ) noexcept = delete;
	const Reference_counted_omp &operator =( const Reference_counted_omp &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Reference_counted_omp( Reference_counted_omp &&another ) noexcept = delete;
	Reference_counted_omp &operator =( Reference_counted_omp &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Omp< A_type > _object_memory_pointer;
	typeing::Memory_natural _strong_reference_counter;
	typeing::Memory_natural _weak_reference_counter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace internalling_dev
} // namespace pointing
} // namespace jmsf
