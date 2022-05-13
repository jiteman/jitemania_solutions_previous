#pragma once


#include "List.hxx"

#include "List_agent.hpp"

#include "jmsf/memorying/Omp.hpp"
#include "jmsf/typeing/Naturals.hpp"
#include "jmsf/typeing/Boolean.h"

#include "../traversing/List_traverser.hxx"
#include "../noding/Doubly_linked_node.hxx"

#include "jmsf/algorithming/Comparator.hxx"


#include "jmsf/validating/Exception.hxx"

#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace structing {
namespace containing {


template< class A_type >
class List :
	public List_agent< A_type >
{

public: // common getters
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;
	typeing::Memory_natural get_quantity_of_elements() const noexcept;
	typeing::Boolean is_sorted() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	void append_to_begin( const memorying::Womp< memorying::Allocator > &node_allocator, const A_type &an_object ) noexcept;
	void append_to_end( const memorying::Womp< memorying::Allocator > &node_allocator, const A_type &an_object ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // sorting
	void sort( const algorithming::Comparator< A_type > &a_comparator ) noexcept;
	void append_sorted( const memorying::Womp< memorying::Allocator > &node_allocator, const algorithming::Comparator< A_type > &a_comparator, const A_type &an_object ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	traversing::List_traverser< A_type > create_traverser_at_begin();
	traversing::List_traverser< A_type > create_traverser_at_begin() const;
	traversing::List_traverser< A_type > create_traverser_at_end();
	traversing::List_traverser< A_type > create_traverser_at_end() const;
	traversing::List_traverser< A_type > create_traverser_from_begin( typeing::Memory_natural an_index );
	traversing::List_traverser< A_type > create_traverser_from_begin( typeing::Memory_natural an_index ) const;
	traversing::List_traverser< A_type > create_traverser_from_end( typeing::Memory_natural an_index );
	traversing::List_traverser< A_type > create_traverser_from_end( typeing::Memory_natural an_index ) const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: // friend traversing::List_traverser< A_type >
	// virtuals List_agent< A_type >
	memorying::Omp< noding::Doubly_linked_node< A_type > > &take_begin() noexcept;
	memorying::Omp< noding::Doubly_linked_node< A_type > > &take_end() noexcept;
	typeing::Memory_natural &take_quantity() noexcept;
	//~virtuals List_agent< A_type >

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~List() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	List() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	List( const List &another ) noexcept;
	const List &operator =( const List &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Omp< noding::Doubly_linked_node< A_type > > _the_begin;
	memorying::Omp< noding::Doubly_linked_node< A_type > > _the_end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	typeing::Memory_natural _quantity_of_elements;
	typeing::Boolean _is_sorted;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace containing
} // namespace sructing
} // namespace jmsf
