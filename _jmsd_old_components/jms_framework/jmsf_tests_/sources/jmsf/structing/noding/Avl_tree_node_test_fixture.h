#pragma once


#include "jmsf/cule/macroses_Test.h"


namespace jmsf {
namespace structing {
namespace noding {


// Avl_tree_node_fixture
// ---------------- 4 ----------------
// ----- 1 ----------------- 5 -------
// ----------- 3 ---------------------
// -------- 2 ------------------------
// disconnected_0
// left_child_1
// left_child_of_right_child_of_left_child_2
// right_child_of_left_child_3
// parent_4
// right_child_5

CULE_TEST_FIXTURE( Avl_tree_node ) {

public:
	void set_up() override {
		const memorying::Womp< memorying::Allocator > &testing_object_allocator =
			testing::testing_Allocators::instance()->get_testing_object_allocator();

		parent_4 = Avl_tree_node< typeing::Memory_natural >::create( testing_object_allocator, natural_4 );
		left_child_1 = Avl_tree_node< typeing::Memory_natural >::create( testing_object_allocator, natural_1 );
		right_child_of_left_child_3 = Avl_tree_node< typeing::Memory_natural >::create( testing_object_allocator, natural_3 );
		left_child_of_right_child_of_left_child_2 = Avl_tree_node< typeing::Memory_natural >::create( testing_object_allocator, natural_2 );
		right_child_5 = Avl_tree_node< typeing::Memory_natural >::create( testing_object_allocator, natural_5 );
		disconnected_0 = Avl_tree_node< typeing::Memory_natural >::create( testing_object_allocator, natural_0 );

		parent_4->set_left_child( left_child_1 );
		left_child_1->set_parent( parent_4 );
		left_child_1->set_right_child( right_child_of_left_child_3 );
		right_child_of_left_child_3->set_parent( left_child_1 );
		parent_4->set_right_child( right_child_5 );
		right_child_of_left_child_3->set_left_child( left_child_of_right_child_of_left_child_2 );
		left_child_of_right_child_of_left_child_2->set_parent( right_child_of_left_child_3 );
		right_child_5->set_parent( parent_4 );
	}

	void tear_down() override {
		Avl_tree_node< typeing::Memory_natural >::destroy( parent_4 );
		Avl_tree_node< typeing::Memory_natural >::destroy( left_child_1 );
		Avl_tree_node< typeing::Memory_natural >::destroy( right_child_of_left_child_3 );
		Avl_tree_node< typeing::Memory_natural >::destroy( left_child_of_right_child_of_left_child_2 );
		Avl_tree_node< typeing::Memory_natural >::destroy( right_child_5 );
		Avl_tree_node< typeing::Memory_natural >::destroy( disconnected_0 );
	}

	typeing::Memory_natural natural_0 = typeing::Memory_natural::create( 0 );
	typeing::Memory_natural natural_1 = typeing::Memory_natural::create( 1 );
	typeing::Memory_natural natural_2 = typeing::Memory_natural::create( 2 );
	typeing::Memory_natural natural_3 = typeing::Memory_natural::create( 3 );
	typeing::Memory_natural natural_4 = typeing::Memory_natural::create( 4 );
	typeing::Memory_natural natural_5 = typeing::Memory_natural::create( 5 );


	typeing::Memory_integer integer_4m = typeing::Memory_integer::create( -4 );
	typeing::Memory_integer integer_3m = typeing::Memory_integer::create( -3 );
	typeing::Memory_integer integer_2m = typeing::Memory_integer::create( -2 );
	typeing::Memory_integer integer_1m = typeing::Memory_integer::create( -1 );
	typeing::Memory_integer integer_0 = typeing::Memory_integer::create( 0 );
	typeing::Memory_integer integer_1 = typeing::Memory_integer::create( 1 );
	typeing::Memory_integer integer_2 = typeing::Memory_integer::create( 2 );
	typeing::Memory_integer integer_3 = typeing::Memory_integer::create( 3 );
	typeing::Memory_integer integer_4 = typeing::Memory_integer::create( 4 );

	memorying::Omp< Avl_tree_node< typeing::Memory_natural > > parent_4;
	memorying::Omp< Avl_tree_node< typeing::Memory_natural > > left_child_1;
	memorying::Omp< Avl_tree_node< typeing::Memory_natural > > right_child_of_left_child_3;
	memorying::Omp< Avl_tree_node< typeing::Memory_natural > > left_child_of_right_child_of_left_child_2;
	memorying::Omp< Avl_tree_node< typeing::Memory_natural > > right_child_5;
	memorying::Omp< Avl_tree_node< typeing::Memory_natural > > disconnected_0;

};


} // namespace noding
} // namespace structing
} // namespace jmsf
