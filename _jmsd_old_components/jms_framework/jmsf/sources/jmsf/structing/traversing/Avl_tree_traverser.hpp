#pragma once

#include "Avl_tree_traverser.hxx"


#include "jmsf/memorying/Omp.hpp"

#include "jmsf/structing/containing/Avl_tree.hxx"
#include "jmsf/structing/noding/Avl_tree_node.hxx"

#include "jmsf/typeing/Boolean.hxx"


namespace jmsf {
namespace structing {
namespace traversing {


template< class A_type >
class Avl_tree_traverser {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const A_type &get_object() const;
	A_type &take_object();

	const memorying::Omp< noding::Avl_tree_node< A_type > > &get_node() const noexcept;
	memorying::Omp< noding::Avl_tree_node< A_type > > &take_node() const noexcept;

	void move_one_step_up() const;
	void move_one_step_up();
	void move_one_step_down_left() const;
	void move_one_step_down_left();
	void move_one_step_down_right() const;
	void move_one_step_down_right();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const memorying::Womp< structing::containing::Avl_tree< A_type > > &get_tree() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Avl_tree_traverser() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Avl_tree_traverser() noexcept;

private:
	Avl_tree_traverser(
		const memorying::Womp< structing::containing::Avl_tree< A_type > > &an_avl_tree,
		const memorying::Omp< noding::Avl_tree_node< A_type > > &a_node_pointer ) noexcept;

public:
	static Avl_tree_traverser create(
		const memorying::Womp< structing::containing::Avl_tree< A_type > > &an_avl_tree,
		const memorying::Omp< noding::Avl_tree_node< A_type > > &a_node_pointer );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//private:
//	Avl_tree_traverser( const Avl_tree_traverser &another ) noexcept = delete;
//	const Avl_tree_traverser &operator =( const Avl_tree_traverser &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//private:
//	Avl_tree_traverser( Avl_tree_traverser &&another ) noexcept = delete;
//	Avl_tree_traverser &operator =( Avl_tree_traverser &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	mutable memorying::Omp< noding::Avl_tree_node< A_type > > _the_node_pointer;
	memorying::Womp< structing::containing::Avl_tree< A_type > > _the_avl_tree;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace traversing
} // namespace structing
} // namespace jmsf

