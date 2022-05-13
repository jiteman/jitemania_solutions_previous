#pragma once

#include "Weak.hxx"


#include "jmsf/memorying/Omp.hpp"

#include "jmsf/texting/Ansii_text.hxx"
#include "jmsf/texting/Ansii_allocating_assistor.hxx"
#include "Shared.hxx"
#include "cShared.hxx"
#include "cWeak.hxx"
#include "jmsf/memorying/Womp.hxx"

#include "internalling/Reference_counted_omp.hxx"
#include "internalling/Reference_counters_connectivity.hxx"


namespace jmsf {
namespace pointing {


template< class A_type >
class Weak {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Shared< A_type > get_as_shared() noexcept;
	cShared< A_type > get_as_cshared() const noexcept;
	cWeak< A_type > get_as_cweak() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean operator ==( const Weak &another ) const noexcept;
	typeing::Boolean operator !=( const Weak &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cShared< texting::Ansii_text > to_ansii_text( const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	internalling::Reference_counters_connectivity get_connectivity() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Weak() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Weak() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	Weak(
//		const memorying::Omp< internalling_dev::new_Reference_counters > &reference_counters,
//		const memorying::Omp< A_type > &object_memory_pointer ) noexcept;
	Weak( const memorying::Omp< internalling::Reference_counted_omp< A_type > > &reference_counted_omp_omp ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Shared< A_type >;
//	static Weak create_from_shared(
//		const memorying::Omp< internalling_dev::new_Reference_counters > &reference_counters,
//		const memorying::Omp< A_type > &object_memory_pointer ) noexcept;

	static Weak create_from_shared( const memorying::Omp< internalling::Reference_counted_omp< A_type > > &reference_counted_omp_omp ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Weak( const Weak &another ) noexcept;
	const Weak &operator =( const Weak &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Weak( Weak &&another ) noexcept;
	Weak &operator =( Weak &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Omp< internalling::Reference_counted_omp< A_type > > _reference_counted_omp_omp;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace pointing
} // namespace jmsf

