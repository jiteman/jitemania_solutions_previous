#pragma once


#include "Constructor.hxx"

#include "Allocator.hxx"
#include "Omp.hxx"
#include "Amp.hxx"
#include "Womp.hxx"

#include "jmsf/typeing/Naturals.hxx"


namespace jmsf {
namespace memorying {


template< class A_type, class A_creating_type > // class A_creating_type : public A_type
class Constructor {

public:
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator ) noexcept; // default construction
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_creating_type &original ) noexcept; // copy construction

	template< class A_first >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first ) noexcept;

	template< class A_first, class A_second >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second ) noexcept;

	template< class A_first, class A_second, class A_third >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third ) noexcept;

	template< class A_first, class A_second, class A_third, class A_fourth >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth ) noexcept;

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth ) noexcept;

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth ) noexcept;

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh ) noexcept;

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh, class An_eighth >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh, const An_eighth &eighth ) noexcept;


	static Amp< A_type > construct_default_as_array( const Womp< Allocator > &an_allocator, typeing::Memory_natural quantity_of_objects ) noexcept; // default array construction
	static Amp< A_type > construct_copy_as_array( const Womp< Allocator > &an_allocator, typeing::Memory_natural quantity_of_objects, const A_creating_type &original ) noexcept; // array copy construction

	template< class A_first >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typeing::Memory_natural quantity_of_objects, const A_first &first ) noexcept;

	template< class A_first, class A_second >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typeing::Memory_natural quantity_of_objects, const A_first &first, const A_second &second ) noexcept;

	template< class A_first, class A_second, class A_third >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typeing::Memory_natural quantity_of_objects, const A_first &first, const A_second &second, const A_third &third ) noexcept;

	template< class A_first, class A_second, class A_third, class A_fourth >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typeing::Memory_natural quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth ) noexcept;

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typeing::Memory_natural quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth ) noexcept;

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typeing::Memory_natural quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth ) noexcept;

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typeing::Memory_natural quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh ) noexcept;

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh, class An_eighth >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typeing::Memory_natural quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh, const An_eighth &eighth ) noexcept;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf

