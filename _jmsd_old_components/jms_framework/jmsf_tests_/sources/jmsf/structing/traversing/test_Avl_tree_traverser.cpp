#include "jmsf/cule/macroses_Test.h"


#include "jmsf/structing/containing/Avl_tree.hin"
#include "jmsf/structing/traversing/Avl_tree_traverser.hin"

#include "jmsf/testing/testing_Allocators.h"


namespace jmsf {
namespace structing {
namespace traversing {


CULE_TEST_FIXTURE( Avl_tree_traverser ) {

public:
	void set_up() override {
		const memorying::Womp< memorying::Allocator > &testing_object_allocator =
			testing::testing_Allocators::instance()->get_testing_object_allocator();

		dummy_avl_tree =
			containing::Avl_tree< typeing::Memory_natural >::create(
				testing_object_allocator,
				testing_object_allocator,
				testing_object_allocator );

		node_with_1 = noding::Avl_tree_node< typeing::Memory_natural >::create( testing_object_allocator, value_1 );

		parent =
			traversing::Avl_tree_traverser< typeing::Memory_natural >::create(
				dummy_avl_tree.get_as_womp(),
				noding::Avl_tree_node< typeing::Memory_natural >::create( testing_object_allocator, value_2 ) );

		left_child =
			traversing::Avl_tree_traverser< typeing::Memory_natural >::create(
				dummy_avl_tree.get_as_womp(),
				noding::Avl_tree_node< typeing::Memory_natural >::create( testing_object_allocator, value_1 ) );

		right_child =
			traversing::Avl_tree_traverser< typeing::Memory_natural >::create(
				dummy_avl_tree.get_as_womp(),
				noding::Avl_tree_node< typeing::Memory_natural >::create( testing_object_allocator, value_3 ) );

		parent.take_node()->set_left_child( left_child.take_node() );
		left_child.take_node()->set_parent( parent.take_node() );
		parent.take_node()->set_right_child( right_child.take_node() );
		right_child.take_node()->set_parent( parent.take_node() );
	}

	void tear_down() override {
		noding::Avl_tree_node< typeing::Memory_natural >::destroy( node_with_1 );
		noding::Avl_tree_node< typeing::Memory_natural >::destroy( parent.take_node() );
		noding::Avl_tree_node< typeing::Memory_natural >::destroy( left_child.take_node() );
		noding::Avl_tree_node< typeing::Memory_natural >::destroy( right_child.take_node() );

		dummy_avl_tree->destroy( dummy_avl_tree );
	}

	Avl_tree_traverser< typeing::Memory_natural > traverser;

	Avl_tree_traverser< typeing::Memory_natural > parent;
	Avl_tree_traverser< typeing::Memory_natural > left_child;
	Avl_tree_traverser< typeing::Memory_natural > right_child;

	const typeing::Memory_natural value_0;
	const typeing::Memory_natural value_1 = typeing::Memory_natural_one;
	const typeing::Memory_natural value_2 = typeing::Memory_natural::create( 2 );
	const typeing::Memory_natural value_3 = typeing::Memory_natural::create( 3 );
	const typeing::Memory_natural value_4 = typeing::Memory_natural::create( 4 );
	const typeing::Memory_natural value_5 = typeing::Memory_natural::create( 5 );

	memorying::Omp< noding::Avl_tree_node< typeing::Memory_natural > > node_with_1;
	memorying::Omp< containing::Avl_tree< typeing::Memory_natural > > dummy_avl_tree;

};

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
CULE_TEST_F( Avl_tree_traverser, should_be_empty_after_creation ) {
	Cule_this( fx_.traverser ).should_be_empty();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( Avl_tree_traverser, should_not_be_empty_when_holds_an_object ) {
	fx_.traverser = Avl_tree_traverser< typeing::Memory_natural >::create( fx_.dummy_avl_tree.get_as_womp(), fx_.node_with_1 );

	Cule_this( fx_.traverser ).should_not_be_empty();
}

CULE_TEST_F( Avl_tree_traverser, should_return_object_it_holds ) {
	fx_.traverser = Avl_tree_traverser< typeing::Memory_natural >::create( fx_.dummy_avl_tree.get_as_womp(), fx_.node_with_1 );
	Avl_tree_traverser< typeing::Memory_natural > traverser = Avl_tree_traverser< typeing::Memory_natural >::create( fx_.dummy_avl_tree.get_as_womp(), fx_.node_with_1 );

	Cule_this( fx_.traverser.get_object() ).should_be_equal_to( fx_.value_1 );
	Cule_this( fx_.traverser.get_object() ).should_not_be_equal_to( fx_.value_0 );
	Cule_this( traverser.get_object() ).should_be_equal_to( fx_.value_1 );
	Cule_this( traverser.get_object() ).should_not_be_equal_to( fx_.value_2 );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( Avl_tree_traverser, should_navigate_to_left_child ) {
	fx_.traverser = fx_.parent;

	fx_.traverser.move_one_step_down_left();

	Cule_this( fx_.traverser.get_object() ).should_be_equal_to( fx_.left_child.get_object() );
	Cule_this( fx_.traverser.take_object() ).should_be_equal_to( fx_.left_child.get_object() );
}

CULE_TEST_F( Avl_tree_traverser, should_navigate_to_right_child ) {
	fx_.traverser = fx_.parent;

	fx_.traverser.move_one_step_down_right();

	Cule_this( fx_.traverser.get_object() ).should_be_equal_to( fx_.right_child.get_object() );
	Cule_this( fx_.traverser.take_object() ).should_be_equal_to( fx_.right_child.get_object() );
}

CULE_TEST_F( Avl_tree_traverser, should_navigate_to_parent_from_left_child ) {
	fx_.traverser = fx_.left_child;

	fx_.traverser.move_one_step_up();

	Cule_this( fx_.traverser.get_object() ).should_be_equal_to( fx_.parent.get_object() );
	Cule_this( fx_.traverser.take_object() ).should_be_equal_to( fx_.parent.get_object() );
}

CULE_TEST_F( Avl_tree_traverser, should_navigate_to_parent_from_right_child ) {
	fx_.traverser = fx_.right_child;

	fx_.traverser.move_one_step_up();

	Cule_this( fx_.traverser.get_object() ).should_be_equal_to( fx_.parent.get_object() );
	Cule_this( fx_.traverser.take_object() ).should_be_equal_to( fx_.parent.get_object() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( Avl_tree_traverser, should_navigate_back_and_forth ) {
	fx_.traverser = fx_.left_child;

	fx_.traverser.move_one_step_up();
	Cule_this( fx_.traverser.get_object() ).should_be_equal_to( fx_.parent.get_object() );

	fx_.traverser.move_one_step_down_right();
	Cule_this( fx_.traverser.get_object() ).should_be_equal_to( fx_.right_child.get_object() );

	fx_.traverser.move_one_step_up();
	Cule_this( fx_.traverser.get_object() ).should_be_equal_to( fx_.parent.get_object() );

	fx_.traverser.move_one_step_down_left();
	Cule_this( fx_.traverser.get_object() ).should_be_equal_to( fx_.left_child.get_object() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( Avl_tree_traverser, should_not_navigate_outside_the_parent_node ) {
	fx_.traverser = fx_.parent;

	fx_.traverser.move_one_step_up();

	Cule_this( fx_.traverser ).should_be_empty();
}

CULE_TEST_F( Avl_tree_traverser, should_not_navigate_outside_the_left_child_node_to_the_left ) {
	fx_.traverser = fx_.left_child;

	fx_.traverser.move_one_step_down_left();

	Cule_this( fx_.traverser ).should_be_empty();
}

CULE_TEST_F( Avl_tree_traverser, should_not_navigate_outside_the_left_child_node_to_the_right ) {
	fx_.traverser = fx_.left_child;

	fx_.traverser.move_one_step_down_right();

	Cule_this( fx_.traverser ).should_be_empty();
}

CULE_TEST_F( Avl_tree_traverser, should_not_navigate_outside_the_right_child_node_to_the_left ) {
	fx_.traverser = fx_.right_child;

	fx_.traverser.move_one_step_down_left();

	Cule_this( fx_.traverser ).should_be_empty();
}

CULE_TEST_F( Avl_tree_traverser, should_not_navigate_outside_the_right_child_node_to_the_right ) {
	fx_.traverser = fx_.right_child;

	fx_.traverser.move_one_step_down_right();

	Cule_this( fx_.traverser ).should_be_empty();
}



} // namespace traversing
} // namespace structing
} // namespace jmsf
