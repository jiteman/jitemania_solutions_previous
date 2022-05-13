#pragma once

#include "default_Comparator.hxx"


#include "jmsf/algorithming/Comparator.hpp"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace algorithming {
namespace defaulting {


template< class A_type >
class default_Comparator :
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
	~default_Comparator() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Comparator< A_type >, default_Comparator >;
	default_Comparator() noexcept;

public:
	static memorying::Omp< Comparator< A_type > > create( const memorying::Womp< memorying::Allocator > &default_comparator_allocator );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	default_Comparator( const default_Comparator &another ) noexcept = delete;
	const default_Comparator &operator =( const default_Comparator &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	default_Comparator( default_Comparator &&another ) noexcept = delete;
	default_Comparator &operator =( default_Comparator &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace defaulting
} // namespace algorithming
} // namespace jmsf
