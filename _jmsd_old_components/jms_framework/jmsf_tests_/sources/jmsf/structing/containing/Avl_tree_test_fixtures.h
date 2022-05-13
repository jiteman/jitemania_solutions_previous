#pragma once

#include "jmsf/cule/macroses_Test.h"

#include  "jmsf/testing/typeing/testing_Natural_values.hin"


#include "jmsf/structing/containing/Avl_tree.hin"


#include "jmsf/testing/testing_Allocators.h"
#include "jmsf/typeing/Naturals.hin"


namespace jmsf {
namespace structing {
namespace containing {


CULE_TEST_FIXTURE( Avl_tree_empty ),
	public ::jmsf::testing::typeing::testing_Natural_values< typeing::Memory_natural >
{

public:
	void set_up() override {
		{
			const memorying::Womp< memorying::Allocator > &testing_allocator = testing::testing_Allocators::instance()->get_testing_object_allocator();
			avl_tree = Avl_tree< typeing::Memory_natural >::create( testing_allocator, testing_allocator, testing_allocator );
		}
	}

	void tear_down() override {
//		avl_tree.destroy( avl_tree );
		Avl_tree< typeing::Memory_natural >::destroy( avl_tree );
	}

public:
	memorying::Omp< Avl_tree< typeing::Memory_natural > > avl_tree;

};


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
CULE_TEST_FIXTURE( Avl_tree_filled ),
	public ::jmsf::testing::typeing::testing_Natural_values< typeing::Memory_natural >
{

public:
	void set_up() override {
		{
			const memorying::Womp< memorying::Allocator > &testing_allocator = testing::testing_Allocators::instance()->get_testing_object_allocator();
			avl_tree = Avl_tree< typeing::Memory_natural >::create( testing_allocator, testing_allocator, testing_allocator );
		}

		avl_tree->insert( natural_4 );
		avl_tree->insert( natural_5 );
		avl_tree->insert( natural_1 );
		avl_tree->insert( natural_3 );
		avl_tree->insert( natural_2 );
	}

	void tear_down() override {
//		avl_tree.destroy( avl_tree );
		Avl_tree< typeing::Memory_natural >::destroy( avl_tree );
	}

public:
	memorying::Omp< Avl_tree< typeing::Memory_natural > > avl_tree;

};


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
CULE_TEST_FIXTURE( Avl_tree_rebalancing ),
	public ::jmsf::testing::typeing::testing_Natural_values< typeing::Memory_natural >
{

public:
	void set_up() override {
		testing_allocator = testing::testing_Allocators::instance()->get_testing_object_allocator();
		avl_tree = Avl_tree< typeing::Memory_natural >::create( testing_allocator, testing_allocator, testing_allocator );
	}

	void tear_down() override {
//		avl_tree.destroy( avl_tree );
		Avl_tree< typeing::Memory_natural >::destroy( avl_tree );
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	typeing::Boolean tree_has_correct_childs_after_balancing_involving_root() {
		traversing::Avl_tree_traverser< typeing::Memory_natural > traverser = avl_tree->find( natural_20 );

		// root node 20
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_object() ).should_be_equal_to( natural_20 );
		Cule_this( traverser.get_node()->get_left_child() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_left_child()->get_object() ).should_be_equal_to( natural_10 );
		Cule_this( traverser.get_node()->get_right_child() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_right_child()->get_object() ).should_be_equal_to( natural_30 );

		// node 10
		traverser.move_one_step_down_left();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_object() ).should_be_equal_to( natural_10 );
		Cule_this( traverser.get_node()->get_left_child() ).should_be_empty();
		Cule_this( traverser.get_node()->get_right_child() ).should_be_empty();

		// node 30
		traverser.move_one_step_up();
		traverser.move_one_step_down_right();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_object() ).should_be_equal_to( natural_30 );
		Cule_this( traverser.get_node()->get_left_child() ).should_be_empty();
		Cule_this( traverser.get_node()->get_right_child() ).should_be_empty();

		return typeing::True;
	}

	typeing::Boolean tree_has_correct_parents_after_balancing_involving_root() {
		traversing::Avl_tree_traverser< typeing::Memory_natural > traverser = avl_tree->find( natural_20 );

		// root node 20
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent() ).should_be_empty();

		// node 10
		traverser.move_one_step_down_left();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent()->get_object() ).should_be_equal_to( natural_20 );

		// node 30
		traverser.move_one_step_up();
		traverser.move_one_step_down_right();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent()->get_object() ).should_be_equal_to( natural_20 );

		return typeing::True;
	}

	typeing::Boolean tree_nodes_has_correct_height_after_balancing_involving_root() {
		traversing::Avl_tree_traverser< typeing::Memory_natural > traverser = avl_tree->find( natural_20 );

		// root node 20
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_height() ).should_be_equal_to( natural_2 );

		// node 10
		traverser.move_one_step_down_left();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_height() ).should_be_equal_to( natural_1 );

		// node 30
		traverser.move_one_step_up();
		traverser.move_one_step_down_right();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_height() ).should_be_equal_to( natural_1 );

		return typeing::True;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	typeing::Boolean tree_has_correct_childs_after_balancing_without_involving_root() {
		traversing::Avl_tree_traverser< typeing::Memory_natural > traverser = avl_tree->find( natural_40 );

		// root node 40
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_object() ).should_be_equal_to( natural_40 );
		Cule_this( traverser.get_node()->get_left_child() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_left_child()->get_object() ).should_be_equal_to( natural_20 );
		Cule_this( traverser.get_node()->get_right_child() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_right_child()->get_object() ).should_be_equal_to( natural_60 );

		// node 20
		traverser.move_one_step_down_left();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_object() ).should_be_equal_to( natural_20 );
		Cule_this( traverser.get_node()->get_left_child() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_left_child()->get_object() ).should_be_equal_to( natural_10 );
		Cule_this( traverser.get_node()->get_right_child() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_right_child()->get_object() ).should_be_equal_to( natural_30 );

		// node 10
		traverser.move_one_step_down_left();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_object() ).should_be_equal_to( natural_10 );
		Cule_this( traverser.get_node()->get_left_child() ).should_be_empty();
		Cule_this( traverser.get_node()->get_right_child() ).should_be_empty();

		// node 30
		traverser.move_one_step_up();
		traverser.move_one_step_down_right();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_object() ).should_be_equal_to( natural_30 );
		Cule_this( traverser.get_node()->get_left_child() ).should_be_empty();
		Cule_this( traverser.get_node()->get_right_child() ).should_be_empty();

		// node 60
		traverser.move_one_step_up();
		traverser.move_one_step_up();
		traverser.move_one_step_down_right();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_object() ).should_be_equal_to( natural_60 );
		Cule_this( traverser.get_node()->get_left_child() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_left_child()->get_object() ).should_be_equal_to( natural_50 );
		Cule_this( traverser.get_node()->get_right_child() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_right_child()->get_object() ).should_be_equal_to( natural_70 );

		// node 50
		traverser.move_one_step_down_left();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_object() ).should_be_equal_to( natural_50 );
		Cule_this( traverser.get_node()->get_left_child() ).should_be_empty();
		Cule_this( traverser.get_node()->get_right_child() ).should_be_empty();

		// node 70
		traverser.move_one_step_up();
		traverser.move_one_step_down_right();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_object() ).should_be_equal_to( natural_70 );
		Cule_this( traverser.get_node()->get_left_child() ).should_be_empty();
		Cule_this( traverser.get_node()->get_right_child() ).should_be_empty();

		return typeing::True;
	}

	typeing::Boolean tree_has_correct_parents_after_balancing_without_involving_root() {
		traversing::Avl_tree_traverser< typeing::Memory_natural > traverser = avl_tree->find( natural_40 );

		// root node 40
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent() ).should_be_empty();

		// node 20
		traverser.move_one_step_down_left();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent()->get_object() ).should_be_equal_to( natural_40 );

		// node 10
		traverser.move_one_step_down_left();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent()->get_object() ).should_be_equal_to( natural_20 );

		// node 30
		traverser.move_one_step_up();
		traverser.move_one_step_down_right();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent()->get_object() ).should_be_equal_to( natural_20 );

		// node 60
		traverser.move_one_step_up();
		traverser.move_one_step_up();
		traverser.move_one_step_down_right();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent()->get_object() ).should_be_equal_to( natural_40 );

		// node 50
		traverser.move_one_step_down_left();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent()->get_object() ).should_be_equal_to( natural_60 );

		// node 70
		traverser.move_one_step_up();
		traverser.move_one_step_down_right();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent() ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_parent()->get_object() ).should_be_equal_to( natural_60 );

		return typeing::True;
	}

	typeing::Boolean tree_nodes_has_correct_height_after_balancing_without_involving_root() {
		traversing::Avl_tree_traverser< typeing::Memory_natural > traverser = avl_tree->find( natural_40 );

		// root node 40
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_height() ).should_be_equal_to( natural_3 );

		// node 20
		traverser.move_one_step_down_left();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_height() ).should_be_equal_to( natural_2 );

		// node 10
		traverser.move_one_step_down_left();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_height() ).should_be_equal_to( natural_1 );

		// node 30
		traverser.move_one_step_up();
		traverser.move_one_step_down_right();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_height() ).should_be_equal_to( natural_1 );

		// node 60
		traverser.move_one_step_up();
		traverser.move_one_step_up();
		traverser.move_one_step_down_right();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_height() ).should_be_equal_to( natural_2 );

		// node 50
		traverser.move_one_step_down_left();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_height() ).should_be_equal_to( natural_1 );

		// node 70
		traverser.move_one_step_up();
		traverser.move_one_step_down_right();
		Cule_this( traverser ).should_not_be_empty();
		Cule_this( traverser.get_node()->get_height() ).should_be_equal_to( natural_1 );

		return typeing::True;
	}

public:
	memorying::Omp< Avl_tree< typeing::Memory_natural > > avl_tree;
	memorying::Womp< memorying::Allocator > testing_allocator;

};


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
CULE_TEST_FIXTURE( Avl_tree_imprecise_find ),
	public testing::typeing::testing_Natural_values< typeing::Memory_natural >
{

public:
	void set_up() override {
		{
			testing_allocator = testing::testing_Allocators::instance()->get_testing_object_allocator();
			avl_tree = Avl_tree< typeing::Memory_natural >::create( testing_allocator, testing_allocator, testing_allocator );
		}

		avl_tree->insert( natural_40 );
		avl_tree->insert( natural_20 );
		avl_tree->insert( natural_60 );
		avl_tree->insert( natural_10 );
		avl_tree->insert( natural_30 );
		avl_tree->insert( natural_50 );
		avl_tree->insert( natural_70 );
	}

	void tear_down() override {
//		avl_tree.destroy( avl_tree );
		Avl_tree< typeing::Memory_natural >::destroy( avl_tree );
	}

public:
	memorying::Omp< Avl_tree< typeing::Memory_natural > > avl_tree;
	memorying::Womp< memorying::Allocator > testing_allocator;

};

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
CULE_TEST_FIXTURE( Avl_tree_remove ),
	public testing::typeing::testing_Natural_values< typeing::Memory_natural >
{

public:
	void set_up() override {
		{
			testing_allocator = testing::testing_Allocators::instance()->get_testing_object_allocator();
			avl_tree = Avl_tree< typeing::Memory_natural >::create( testing_allocator, testing_allocator, testing_allocator );
		}

		avl_tree->insert( natural_40 );
		avl_tree->insert( natural_20 );
		avl_tree->insert( natural_60 );
		avl_tree->insert( natural_10 );
		avl_tree->insert( natural_30 );
		avl_tree->insert( natural_50 );
		avl_tree->insert( natural_70 );
	}

	void tear_down() override {
//		avl_tree.destroy( avl_tree );
		Avl_tree< typeing::Memory_natural >::destroy( avl_tree );
	}

	typeing::Boolean all_nodes_are_inplace_except( const typeing::Memory_natural an_object ) {
		if ( an_object != natural_10 ) {
			Cule_this( avl_tree->find( natural_10 ).get_object() ).should_be_equal_to( natural_10 );
		}

		if ( an_object != natural_20 ) {
			Cule_this( avl_tree->find( natural_20 ).get_object() ).should_be_equal_to( natural_20 );
		}

		if ( an_object != natural_30 ) {
			Cule_this( avl_tree->find( natural_30 ).get_object() ).should_be_equal_to( natural_30 );
		}

		if ( an_object != natural_40 ) {
			Cule_this( avl_tree->find( natural_40 ).get_object() ).should_be_equal_to( natural_40 );
		}

		if ( an_object != natural_50 ) {
			Cule_this( avl_tree->find( natural_50 ).get_object() ).should_be_equal_to( natural_50 );
		}

		if ( an_object != natural_60 ) {
			Cule_this( avl_tree->find( natural_60 ).get_object() ).should_be_equal_to( natural_60 );
		}

		if ( an_object != natural_70 ) {
			Cule_this( avl_tree->find( natural_70 ).get_object() ).should_be_equal_to( natural_70 );
		}

		return typeing::True;
	}

public:
	memorying::Omp< Avl_tree< typeing::Memory_natural > > avl_tree;
	memorying::Womp< memorying::Allocator > testing_allocator;

};


} // namespace containing
} // namespace structing
} // namespace jmsf
