#pragma once

#include "Avl_tree_node.hxx"


#include "jmsf/memorying/Omp.hpp"
#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/typeing/Integers.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/typeing/Boolean.hxx"


namespace jmsf {
namespace structing {
namespace noding {


template< class A_type >
class Avl_tree_node {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const A_type &get_object() const;
	A_type &take_object();

	void set_left_child( const memorying::Omp< Avl_tree_node< A_type > > &a_left_child );
	memorying::Omp< Avl_tree_node< A_type > > &take_left_child();
	const memorying::Omp< Avl_tree_node< A_type > > &get_left_child() const;

	void set_right_child( const memorying::Omp< Avl_tree_node< A_type > > &a_right_child );
	memorying::Omp< Avl_tree_node< A_type > > &take_right_child();
	const memorying::Omp< Avl_tree_node< A_type > > &get_right_child() const;

	void set_parent( const memorying::Omp< Avl_tree_node< A_type > > &a_parent );
	memorying::Omp< Avl_tree_node< A_type > > &take_parent();
	const memorying::Omp< Avl_tree_node< A_type > > &get_parent() const;

	typeing::Memory_natural get_height() const noexcept;
	void recalculate_height() noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Avl_tree_node() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Avl_tree_node() noexcept;
	Avl_tree_node( const A_type &an_object ) noexcept;
//	Avl_tree_node( const A_type &an_object, memorying::Omp< Avl_tree_node > &a_parent ) noexcept;

	static memorying::Omp< Avl_tree_node< A_type > > create(
		const memorying::Womp< memorying::Allocator > &avl_tree_node_allocator,
		const A_type &an_object );

	static void destroy( const memorying::Omp< Avl_tree_node< A_type > > &avl_tree_node );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Avl_tree_node( const Avl_tree_node &another ) noexcept = delete;
	const Avl_tree_node &operator =( const Avl_tree_node &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Avl_tree_node( Avl_tree_node &&another ) noexcept = delete;
	Avl_tree_node &operator =( Avl_tree_node &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _the_object;
	memorying::Omp< Avl_tree_node< A_type > > _parent_node;
	memorying::Omp< Avl_tree_node< A_type > > _left_child_node;
	memorying::Omp< Avl_tree_node< A_type > > _right_child_node;
	typeing::Memory_natural _the_height;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace noding
} // namespace structing
} // namespace jmsf
