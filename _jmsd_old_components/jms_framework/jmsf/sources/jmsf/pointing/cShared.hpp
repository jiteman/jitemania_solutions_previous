#pragma once

#include "cShared.hxx"


#include "jmsf/memorying/Omp.hpp"

#include "Weak.hxx"
#include "cWeak.hxx"
#include "Shared.hxx"
#include "jmsf/memorying/Allocator.hxx"

#include "internalling/Reference_counted_omp.hxx"
#include "internalling/Reference_counters_connectivity.hxx"


namespace jmsf {
namespace pointing {


template< class A_type >
class cShared {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

	const A_type &operator *();
	const A_type *operator ->();

	const A_type &operator *() const;
	const A_type *operator ->() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cWeak< A_type > get_as_cweak() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean operator ==( const cShared &another ) const noexcept;
	typeing::Boolean operator !=( const cShared &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cShared< texting::Ansii_text > to_ansii_text( const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	internalling::Reference_counters_connectivity get_connectivity() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~cShared() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cShared() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	cShared( const memorying::Omp< internalling::Reference_counted_omp< A_type > > &reference_counted_omp_omp ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static cShared create(
		const memorying::Womp< memorying::Allocator > &reference_counted_omp_allocator,
		const memorying::Omp< A_type > &object_memory_pointer );

private: friend Weak< A_type >;
	static cShared create_from_weak( const memorying::Omp< internalling::Reference_counted_omp< A_type > > &reference_counted_omp_omp ) noexcept;

private: friend cWeak< A_type >;
	static cShared create_from_cweak( const memorying::Omp< internalling::Reference_counted_omp< A_type > > &reference_counted_omp_omp ) noexcept;

private: friend Shared< A_type >;
	static cShared create_from_shared( const memorying::Omp< internalling::Reference_counted_omp< A_type > > &reference_counted_omp_omp ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cShared( const cShared &another ) noexcept;
	const cShared &operator =( const cShared &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cShared( cShared &&another ) noexcept;
	cShared &operator =( cShared &&another ) noexcept;

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
