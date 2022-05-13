#pragma once


#include "Doubly_linked_node.hxx"
#include "jmsf/memorying/Omp.hpp"
#include "jmsf/memorying/Womp.hxx"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace structing {
namespace noding {


template< class A_type >
class Doubly_linked_node {

public:
	A_type &take_object() noexcept;
	const A_type &get_object() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	memorying::Omp< Doubly_linked_node > &take_previous_node() noexcept;
	const memorying::Omp< Doubly_linked_node > &get_previous_node() const noexcept;

	memorying::Omp< Doubly_linked_node > &take_next_node() noexcept;
	const memorying::Omp< Doubly_linked_node > &get_next_node() const noexcept;

	void set_previous_node( const memorying::Omp< Doubly_linked_node > &previous_node ) noexcept;
	void set_next_node( const memorying::Omp< Doubly_linked_node > &next_node ) noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< Doubly_linked_node >;
	~Doubly_linked_node() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static memorying::Omp< Doubly_linked_node< A_type > > create( const memorying::Womp< memorying::Allocator > &an_allocator );
	static memorying::Omp< Doubly_linked_node< A_type > > create( const A_type &an_object, const memorying::Womp< memorying::Allocator > &an_allocator );

	static memorying::Omp< Doubly_linked_node< A_type > > create(
		const A_type &an_object,
		const memorying::Omp< Doubly_linked_node > &previous_node,
		const memorying::Omp< Doubly_linked_node > &next_node,
		const memorying::Womp< memorying::Allocator > &an_allocator );

private: friend memorying::Constructor< Doubly_linked_node, Doubly_linked_node >;
	Doubly_linked_node() noexcept;
	Doubly_linked_node( const A_type &an_object ) noexcept;
	Doubly_linked_node( const A_type &an_object, const memorying::Omp< Doubly_linked_node > &previous_node, const memorying::Omp< Doubly_linked_node > &next_node ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Doubly_linked_node( const Doubly_linked_node &another ) noexcept;
	const Doubly_linked_node &operator =( const Doubly_linked_node &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Omp< Doubly_linked_node > _previous_node;
	memorying::Omp< Doubly_linked_node > _next_node;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	A_type _the_object;

};


} // namespace noding
} // namespace structing
} // namespace jmsf
