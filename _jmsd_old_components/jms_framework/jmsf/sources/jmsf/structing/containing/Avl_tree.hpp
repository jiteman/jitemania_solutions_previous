#pragma once

#include "Avl_tree.hxx"


#include "jmsf/structing/traversing/Avl_tree_traverser.hxx"
#include "jmsf/structing/noding/Avl_tree_node.hxx"

#include "jmsf/algorithming/defaulting/default_Comparator.hpp"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Omp.hpp"
#include "jmsf/typeing/Naturals.hpp"


#include "jmsf/algorithming/Imprecise_find_result.hxx"
#include "jmsf/typeing/Integers.hxx"
#include "jmsf/typeing/Boolean.hxx"


namespace jmsf {
namespace structing {
namespace containing {


// Seinsei: todonext - move all unrelated operation into avl_tree_algorithms, i.e.
//		all complex operations, which does not modify the root
template< class A_type >
class Avl_tree {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

	typeing::Memory_natural get_quantity() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void insert( const A_type &an_object );

	traversing::Avl_tree_traverser< A_type > find( const A_type &an_object ) const;
	traversing::Avl_tree_traverser< A_type > find( const A_type &an_object );
	algorithming::Imprecise_find_result< traversing::Avl_tree_traverser< A_type > > find_imprecise( const A_type &an_object ) const;
	algorithming::Imprecise_find_result< traversing::Avl_tree_traverser< A_type > > find_imprecise( const A_type &an_object );

//	void remove( const A_type &an_object );
//	void remove( const traversing::Avl_tree_traverser< A_type > &a_traverser );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Avl_tree() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Avl_tree() = delete;

private: friend memorying::Constructor< Avl_tree, Avl_tree >;
	Avl_tree(
		const memorying::Womp< memorying::Allocator > &avl_tree_node_allocator,
		const memorying::Omp< algorithming::Comparator< A_type > > &a_comparator ) noexcept;

public:
	static memorying::Omp< Avl_tree > create(
		const memorying::Womp< memorying::Allocator > &avl_tree_allocator,
		const memorying::Womp< memorying::Allocator > &avl_tree_node_allocator,
		const memorying::Womp< memorying::Allocator > &default_comparator_allocator );

	static memorying::Omp< Avl_tree > create(
		const memorying::Womp< memorying::Allocator > &avl_tree_allocator,
		const memorying::Womp< memorying::Allocator > &avl_tree_node_allocator,
		const memorying::Omp< algorithming::Comparator< A_type > > &a_comparator );

	static void destroy( const memorying::Omp< Avl_tree > &avl_tree_omp );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Avl_tree( const Avl_tree &another ) noexcept = delete;
	const Avl_tree &operator =( const Avl_tree &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Avl_tree( Avl_tree &&another ) noexcept = delete;
	Avl_tree &operator =( Avl_tree &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Womp< memorying::Allocator > _the_avl_tree_node_allocator;
	memorying::Omp< algorithming::Comparator< A_type > > _the_comparator;
	typeing::Memory_natural _the_quantity;
	memorying::Womp< Avl_tree > _this_womp;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	memorying::Omp< noding::Avl_tree_node< A_type > > _the_root;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	traversing::Avl_tree_traverser< A_type > find_exact_or_previous_node( const A_type &an_object ) const;

	traversing::Avl_tree_traverser< A_type > find_leftmost_node( const traversing::Avl_tree_traverser< A_type > &a_traverser ) const;
	traversing::Avl_tree_traverser< A_type > find_rightmost_node( const traversing::Avl_tree_traverser< A_type > &a_traverser ) const;

	static void insert_left_child(
		const memorying::Womp< memorying::Allocator > &avl_tree_node_allocator,
		const memorying::Omp< noding::Avl_tree_node< A_type > > &a_parent_node,
		const A_type &an_object );

	static void insert_right_child(
		const memorying::Womp< memorying::Allocator > &avl_tree_node_allocator,
		const memorying::Omp< noding::Avl_tree_node< A_type > > &a_parent_node,
		const A_type &an_object );

	static traversing::Avl_tree_traverser< A_type > recalculate_height_upward_and_return_unbalanced_node_if_present(
		const traversing::Avl_tree_traverser< A_type > &a_parent_traverser );

	static typeing::Boolean is_unbalanced( const memorying::Omp< noding::Avl_tree_node< A_type > > &a_node );
	static typeing::Memory_integer calculate_balance( const memorying::Omp< noding::Avl_tree_node< A_type > > &a_node );

	// Seinsei: todonext - possible point for optimization:
	//		for complex rotation one of the participating nodes recalculates its height twice
	void perform_left_rotation( const memorying::Omp< noding::Avl_tree_node< A_type > > &a_node );
	void perform_right_rotation( const memorying::Omp< noding::Avl_tree_node< A_type > > &a_node );

	static void delete_all_nodes( const memorying::Omp< noding::Avl_tree_node< A_type > > &a_parent );

};


} // namespace containing
} // namespace structing
} // namespace jmsf
