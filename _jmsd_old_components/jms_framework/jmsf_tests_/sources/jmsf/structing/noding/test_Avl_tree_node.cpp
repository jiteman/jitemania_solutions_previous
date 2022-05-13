#include "jmsf/cule/macroses_Test.h"


#include "jmsf/structing/noding/Avl_tree_node.hin"

#include "jmsf/testing/testing_Allocators.h"


#include "Avl_tree_node_test_fixture.h"


namespace jmsf {
namespace structing {
namespace noding {

// Avl_tree_node_fixture
// ---------------- 4 ----------------
// ----- 1 ----------------- 5 -------
// ----------- 3 ---------------------
// -------- 2 ------------------------
//
// disconnected_0
// left_child_1
// left_child_of_right_child_of_left_child_2
// right_child_of_left_child_3
// parent_4
// right_child_5


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
CULE_TEST( Avl_tree_node, should_be_empty_after_creation ) {
	Avl_tree_node< typeing::Memory_natural > empty_avl_tree_node;

	Cule_this( empty_avl_tree_node ).should_be_empty();
}

CULE_TEST_F( Avl_tree_node, should_return_constant_empties_for_absent_relatives ) {
	Cule_this( fx_.parent_4->get_parent() ).should_be_empty();
	Cule_this( fx_.left_child_1->get_left_child() ).should_be_empty();
	Cule_this( fx_.right_child_of_left_child_3->get_right_child() ).should_be_empty();
	Cule_this( fx_.left_child_of_right_child_of_left_child_2->get_left_child() ).should_be_empty();
	Cule_this( fx_.left_child_of_right_child_of_left_child_2->get_right_child() ).should_be_empty();
	Cule_this( fx_.right_child_5->get_left_child() ).should_be_empty();
	Cule_this( fx_.right_child_5->get_right_child() ).should_be_empty();
}

CULE_TEST_F( Avl_tree_node, should_return_inconstant_empties_for_absent_relatives ) {
	Cule_this( fx_.parent_4->take_parent() ).should_be_empty();
	Cule_this( fx_.left_child_1->take_left_child() ).should_be_empty();
	Cule_this( fx_.right_child_of_left_child_3->take_right_child() ).should_be_empty();
	Cule_this( fx_.left_child_of_right_child_of_left_child_2->take_left_child() ).should_be_empty();
	Cule_this( fx_.left_child_of_right_child_of_left_child_2->take_right_child() ).should_be_empty();
	Cule_this( fx_.right_child_5->take_left_child() ).should_be_empty();
	Cule_this( fx_.right_child_5->take_right_child() ).should_be_empty();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( Avl_tree_node, should_have_height_of_1_when_just_created ) {
	Cule_this( fx_.parent_4->get_height() ).should_be_equal_to( fx_.natural_1 );
	Cule_this( fx_.left_child_1->get_height() ).should_be_equal_to( fx_.natural_1 );
	Cule_this( fx_.right_child_of_left_child_3->get_height() ).should_be_equal_to( fx_.natural_1 );
	Cule_this( fx_.right_child_5->get_height() ).should_be_equal_to( fx_.natural_1 );
}

CULE_TEST_F( Avl_tree_node, should_recalculate_their_height_on_demand ) {
	fx_.left_child_of_right_child_of_left_child_2->recalculate_height();
	fx_.right_child_of_left_child_3->recalculate_height();
	fx_.left_child_1->recalculate_height();
	fx_.right_child_5->recalculate_height();
	fx_.parent_4->recalculate_height();

	Cule_this( fx_.parent_4->get_height() ).should_be_equal_to( fx_.natural_4 );
	Cule_this( fx_.left_child_1->get_height() ).should_be_equal_to( fx_.natural_3 );
	Cule_this( fx_.right_child_of_left_child_3->get_height() ).should_be_equal_to( fx_.natural_2 );
	Cule_this( fx_.left_child_of_right_child_of_left_child_2->get_height() ).should_be_equal_to( fx_.natural_1 );
	Cule_this( fx_.right_child_5->get_height() ).should_be_equal_to( fx_.natural_1 );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( Avl_tree_node, should_return_correct_constant_childs ) {
	Cule_this( fx_.parent_4->get_left_child()->get_object() ).should_be_equal_to( fx_.left_child_1->get_object() );
	Cule_this( fx_.left_child_1->get_right_child()->get_object() ).should_be_equal_to( fx_.right_child_of_left_child_3->get_object() );
	Cule_this( fx_.right_child_of_left_child_3->get_left_child()->get_object() ).should_be_equal_to( fx_.left_child_of_right_child_of_left_child_2->get_object() );
	Cule_this( fx_.parent_4->get_right_child()->get_object() ).should_be_equal_to( fx_.right_child_5->get_object() );
}

CULE_TEST_F( Avl_tree_node, should_return_correct_inconstant_childs ) {
	Cule_this( fx_.parent_4->take_left_child()->take_object() ).should_be_equal_to( fx_.left_child_1->get_object() );
	Cule_this( fx_.left_child_1->take_right_child()->take_object() ).should_be_equal_to( fx_.right_child_of_left_child_3->get_object() );
	Cule_this( fx_.right_child_of_left_child_3->take_left_child()->take_object() ).should_be_equal_to( fx_.left_child_of_right_child_of_left_child_2->get_object() );
	Cule_this( fx_.parent_4->take_right_child()->take_object() ).should_be_equal_to( fx_.right_child_5->get_object() );
}

CULE_TEST_F( Avl_tree_node, should_return_corect_constant_parent ) {
	Cule_this( fx_.left_child_of_right_child_of_left_child_2->get_parent()->get_object() ).should_be_equal_to( fx_.right_child_of_left_child_3->get_object() );
	Cule_this( fx_.right_child_of_left_child_3->get_parent()->get_object() ).should_be_equal_to( fx_.left_child_1->get_object() );
	Cule_this( fx_.left_child_1->get_parent()->get_object() ).should_be_equal_to( fx_.parent_4->get_object() );
	Cule_this( fx_.right_child_5->get_parent()->get_object() ).should_be_equal_to( fx_.parent_4->get_object() );
}

CULE_TEST_F( Avl_tree_node, should_return_corect_inconstant_parent ) {
	Cule_this( fx_.left_child_of_right_child_of_left_child_2->take_parent()->take_object() ).should_be_equal_to( fx_.right_child_of_left_child_3->get_object() );
	Cule_this( fx_.right_child_of_left_child_3->take_parent()->take_object() ).should_be_equal_to( fx_.left_child_1->get_object() );
	Cule_this( fx_.left_child_1->take_parent()->take_object() ).should_be_equal_to( fx_.parent_4->get_object() );
	Cule_this( fx_.right_child_5->take_parent()->take_object() ).should_be_equal_to( fx_.parent_4->get_object() );
}

CULE_TEST_F( Avl_tree_node, should_return_the_same_parent ) {
	Cule_this( fx_.left_child_1->get_parent() ).should_be_equal_to( fx_.right_child_5->get_parent() );
	Cule_this( fx_.left_child_1->take_parent() ).should_be_equal_to( fx_.right_child_5->take_parent() );
	Cule_this( fx_.right_child_of_left_child_3->get_parent() ).should_be_equal_to( fx_.parent_4->get_left_child() );
	Cule_this( fx_.right_child_of_left_child_3->take_parent() ).should_be_equal_to( fx_.parent_4->take_left_child() );
}


} // namespace noding
} // namespace structing
} // namespace jmsf
