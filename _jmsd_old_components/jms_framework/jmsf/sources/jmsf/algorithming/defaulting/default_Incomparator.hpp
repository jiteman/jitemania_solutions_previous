#pragma once

#include "default_Incomparator.hxx"


#include "jmsf/algorithming/Comparator.hpp"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace algorithming {
namespace defaulting {


// Seinsei: Reversed comparator
template< class A_type >
class default_Incomparator :
	public Comparator< A_type >
{

public:
	// virtuals Comparator< A_type >
	typeing::Comparison_result compare( const A_type &first, const A_type &second ) const override;
	//~virtuals Comparator< A_type >

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Comparator< A_type >
	~default_Incomparator() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Comparator< A_type >, default_Incomparator >;
	default_Incomparator() noexcept;

public:
	static memorying::Omp< Comparator< A_type > > create( const memorying::Womp< memorying::Allocator > &default_incomparator_allocator );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	default_Incomparator( const default_Incomparator &another ) noexcept = delete;
	const default_Incomparator &operator =( const default_Incomparator &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	default_Incomparator( default_Incomparator &&another ) noexcept = delete;
	default_Incomparator &operator =( default_Incomparator &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace algorithming
} // namespace defaulting
} // namespace jmsf
