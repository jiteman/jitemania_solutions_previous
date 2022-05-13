#include "jmsf/cule/macroses_Test.h"


#include "Avl_tree_test_fixtures.h"
#include "jmsf/structing/containing/Avl_tree.hin"


namespace jmsf {
namespace structing {
namespace containing {


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// simple tests of empty tree
CULE_TEST_F( Avl_tree_empty, should_be_empty_after_creation ) {
	Cule_this( *fx_.avl_tree ).should_be_empty();
}

CULE_TEST_F( Avl_tree_empty, should_have_zero_quantity_after_creation ) {
	Cule_this( fx_.avl_tree->get_quantity() ).should_be_equal_to( fx_.natural_0 );
}

CULE_TEST_F( Avl_tree_empty, should_be_empty_when_its_size_is_zero ) {
	Cule_this( *fx_.avl_tree ).should_be_empty();
	Cule_this( fx_.avl_tree->get_quantity() ).should_be_equal_to( fx_.natural_0 );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( Avl_tree_empty, should_not_be_empty_after_inserting_any_object ) {
	fx_.avl_tree->insert( fx_.natural_1 );

	Cule_this( fx_.avl_tree ).should_not_be_empty();
}

CULE_TEST_F( Avl_tree_empty, should_have_nonzero_quantity_after_inserting_any_object ) {
	fx_.avl_tree->insert( fx_.natural_1 );

	Cule_this( fx_.avl_tree->get_quantity() ).should_not_be_equal_to( fx_.natural_0 );
}

CULE_TEST_F( Avl_tree_empty, should_not_be_empty_when_its_size_is_nonzero ) {
	fx_.avl_tree->insert( fx_.natural_1 );

	Cule_this( fx_.avl_tree ).should_not_be_empty();
	Cule_this( fx_.avl_tree->get_quantity() ).should_not_be_equal_to( fx_.natural_0 );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( Avl_tree_empty, should_have_quantity_1_after_1_object_insertion ) {
	fx_.avl_tree->insert( fx_.natural_1 );

	Cule_this( fx_.avl_tree->get_quantity() ).should_be_equal_to( fx_.natural_1 );
}

CULE_TEST_F( Avl_tree_empty, should_have_quantity_equal_to_quantity_of_inserted_unique_objects ) {
	fx_.avl_tree->insert( fx_.natural_1 );
	fx_.avl_tree->insert( fx_.natural_1 );
	fx_.avl_tree->insert( fx_.natural_2 );
	fx_.avl_tree->insert( fx_.natural_2 );
	fx_.avl_tree->insert( fx_.natural_3 );

	Cule_this( fx_.avl_tree->get_quantity() ).should_be_equal_to( fx_.natural_3 );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( Avl_tree_empty, should_find_inserted_object ) {
	fx_.avl_tree->insert( fx_.natural_1 );

	Cule_this( fx_.avl_tree->find( fx_.natural_1 ).get_object() ).should_be_equal_to( fx_.natural_1 );
}

CULE_TEST_F( Avl_tree_empty, should_find_two_inserted_objects ) {
	fx_.avl_tree->insert( fx_.natural_1 );
	fx_.avl_tree->insert( fx_.natural_2 );

	Cule_this( fx_.avl_tree->find( fx_.natural_1 ) ).should_not_be_empty();
	Cule_this( fx_.avl_tree->find( fx_.natural_1 ).get_object() ).should_be_equal_to( fx_.natural_1 );
	Cule_this( fx_.avl_tree->find( fx_.natural_2 ) ).should_not_be_empty();
	Cule_this( fx_.avl_tree->find( fx_.natural_2 ).get_object() ).should_be_equal_to( fx_.natural_2 );
}

CULE_TEST_F( Avl_tree_empty, should_not_find_not_inserted_objects_and_should_return_empty_result ) {
	fx_.avl_tree->insert( fx_.natural_3 );
	fx_.avl_tree->insert( fx_.natural_4 );

	Cule_this( fx_.avl_tree->find( fx_.natural_1 ) ).should_be_empty();
	Cule_this( fx_.avl_tree->find( fx_.natural_2 ) ).should_be_empty();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// simple test of filled tree
CULE_TEST_F( Avl_tree_filled, should_find_all_inserted_objects_and_no_others ) {
	fx_.avl_tree->insert( fx_.natural_3 );
	fx_.avl_tree->insert( fx_.natural_4 );

	Cule_this( fx_.avl_tree->find( fx_.natural_0 ) ).should_be_empty();
	Cule_this( fx_.avl_tree->find( fx_.natural_1 ) ).should_not_be_empty();
	Cule_this( fx_.avl_tree->find( fx_.natural_1 ).get_object() ).should_be_equal_to( fx_.natural_1 );
	Cule_this( fx_.avl_tree->find( fx_.natural_2 ) ).should_not_be_empty();
	Cule_this( fx_.avl_tree->find( fx_.natural_2 ).get_object() ).should_be_equal_to( fx_.natural_2 );
	Cule_this( fx_.avl_tree->find( fx_.natural_3 ) ).should_not_be_empty();
	Cule_this( fx_.avl_tree->find( fx_.natural_3 ).get_object() ).should_be_equal_to( fx_.natural_3 );
	Cule_this( fx_.avl_tree->find( fx_.natural_4 ) ).should_not_be_empty();
	Cule_this( fx_.avl_tree->find( fx_.natural_4 ).get_object() ).should_be_equal_to( fx_.natural_4 );
	Cule_this( fx_.avl_tree->find( fx_.natural_5 ) ).should_not_be_empty();
	Cule_this( fx_.avl_tree->find( fx_.natural_5 ).get_object() ).should_be_equal_to( fx_.natural_5 );
}

CULE_TEST_F( Avl_tree_filled, should_ignore_already_inserted_objects ) {
	traversing::Avl_tree_traverser< typeing::Memory_natural > traverser_3 = fx_.avl_tree->find( fx_.natural_3 );
	traversing::Avl_tree_traverser< typeing::Memory_natural > traverser_4 = fx_.avl_tree->find( fx_.natural_4 );

	fx_.avl_tree->insert( fx_.natural_3 );
	fx_.avl_tree->insert( fx_.natural_4 );

	Cule_this( fx_.avl_tree->find( fx_.natural_3 ).take_node() ).should_be_equal_to( traverser_3.take_node() );
	Cule_this( fx_.avl_tree->find( fx_.natural_4 ).take_node() ).should_be_equal_to( traverser_4.take_node() );
}

CULE_DISABLED_TEST_F( Avl_tree_filled, should_have_an_appropriate_node_structure ) {
	traversing::Avl_tree_traverser< typeing::Memory_natural > traverser = fx_.avl_tree->find( fx_.natural_4 );

	traverser.move_one_step_down_right();
	Cule_this( traverser.get_object() ).should_be_equal_to( fx_.natural_5 );
	traverser.move_one_step_up();
	Cule_this( traverser.get_object() ).should_be_equal_to( fx_.natural_4 );
	traverser.move_one_step_down_left();
	Cule_this( traverser.get_object() ).should_be_equal_to( fx_.natural_1 );
	traverser.move_one_step_down_right();
	Cule_this( traverser.get_object() ).should_be_equal_to( fx_.natural_3 );
	traverser.move_one_step_down_left();
	Cule_this( traverser.get_object() ).should_be_equal_to( fx_.natural_2 );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_DISABLED_TEST_F( Avl_tree_filled, should_recalculate_nodes_heights_after_inserting_new_node ) {
	Cule_this( fx_.avl_tree->find( fx_.natural_1 ).take_node()->get_height() ).should_be_equal_to( fx_.natural_3 );
	Cule_this( fx_.avl_tree->find( fx_.natural_2 ).take_node()->get_height() ).should_be_equal_to( fx_.natural_1 );
	Cule_this( fx_.avl_tree->find( fx_.natural_3 ).take_node()->get_height() ).should_be_equal_to( fx_.natural_2 );
	Cule_this( fx_.avl_tree->find( fx_.natural_4 ).take_node()->get_height() ).should_be_equal_to( fx_.natural_4 );
	Cule_this( fx_.avl_tree->find( fx_.natural_5 ).take_node()->get_height() ).should_be_equal_to( fx_.natural_1 );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// simple rotations
CULE_TEST_F( Avl_tree_rebalancing, should_perform_rebalancing_using_simple_left_rotation_without_involving_root ) {
	fx_.avl_tree->insert( fx_.natural_40 );
	fx_.avl_tree->insert( fx_.natural_20 );
	fx_.avl_tree->insert( fx_.natural_50 );
	fx_.avl_tree->insert( fx_.natural_10 );
	fx_.avl_tree->insert( fx_.natural_30 );
	fx_.avl_tree->insert( fx_.natural_60 );
	fx_.avl_tree->insert( fx_.natural_70 ); // rebalance triggering insert

	Cule_this( fx_.tree_has_correct_childs_after_balancing_without_involving_root() ).should_be();
	Cule_this( fx_.tree_has_correct_parents_after_balancing_without_involving_root() ).should_be();
	Cule_this( fx_.tree_nodes_has_correct_height_after_balancing_without_involving_root() ).should_be();
}

CULE_TEST_F( Avl_tree_rebalancing, should_perform_rebalancing_using_simple_right_rotation_without_involving_root ) {
	fx_.avl_tree->insert( fx_.natural_40 );
	fx_.avl_tree->insert( fx_.natural_60 );
	fx_.avl_tree->insert( fx_.natural_30);
	fx_.avl_tree->insert( fx_.natural_50 );
	fx_.avl_tree->insert( fx_.natural_70 );
	fx_.avl_tree->insert( fx_.natural_20 );
	fx_.avl_tree->insert( fx_.natural_10 ); // rebalance triggering insert

	Cule_this( fx_.tree_has_correct_childs_after_balancing_without_involving_root() ).should_be();
	Cule_this( fx_.tree_has_correct_parents_after_balancing_without_involving_root() ).should_be();
	Cule_this( fx_.tree_nodes_has_correct_height_after_balancing_without_involving_root() ).should_be();
}

CULE_TEST_F( Avl_tree_rebalancing, should_perform_rebalancing_using_simple_left_rotation_involving_root ) {
	fx_.avl_tree->insert( fx_.natural_10 );
	fx_.avl_tree->insert( fx_.natural_20 );
	fx_.avl_tree->insert( fx_.natural_30 ); // rebalance triggering insert

	Cule_this( fx_.tree_has_correct_childs_after_balancing_involving_root() ).should_be();
	Cule_this( fx_.tree_has_correct_parents_after_balancing_involving_root() ).should_be();
	Cule_this( fx_.tree_nodes_has_correct_height_after_balancing_involving_root() ).should_be();
}

CULE_TEST_F( Avl_tree_rebalancing, should_perform_rebalancing_using_simple_right_rotation_involving_root ) {
	fx_.avl_tree->insert( fx_.natural_30 );
	fx_.avl_tree->insert( fx_.natural_20 );
	fx_.avl_tree->insert( fx_.natural_10 ); // rebalance triggering insert

	Cule_this( fx_.tree_has_correct_childs_after_balancing_involving_root() ).should_be();
	Cule_this( fx_.tree_has_correct_parents_after_balancing_involving_root() ).should_be();
	Cule_this( fx_.tree_nodes_has_correct_height_after_balancing_involving_root() ).should_be();
}

// complex rotations
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( Avl_tree_rebalancing, should_perform_rebalancing_using_complex_left_rotation_without_involving_root ) {
	fx_.avl_tree->insert( fx_.natural_40 );
	fx_.avl_tree->insert( fx_.natural_20 );
	fx_.avl_tree->insert( fx_.natural_50 );
	fx_.avl_tree->insert( fx_.natural_10 );
	fx_.avl_tree->insert( fx_.natural_30 );
	fx_.avl_tree->insert( fx_.natural_70 );
	fx_.avl_tree->insert( fx_.natural_60 ); // rebalance triggering insert

	Cule_this( fx_.tree_has_correct_childs_after_balancing_without_involving_root() ).should_be();
	Cule_this( fx_.tree_has_correct_parents_after_balancing_without_involving_root() ).should_be();
	Cule_this( fx_.tree_nodes_has_correct_height_after_balancing_without_involving_root() ).should_be();
}

CULE_TEST_F( Avl_tree_rebalancing, should_perform_rebalancing_using_complex_right_rotation_without_involving_root ) {
	fx_.avl_tree->insert( fx_.natural_40 );
	fx_.avl_tree->insert( fx_.natural_30 );
	fx_.avl_tree->insert( fx_.natural_60 );
	fx_.avl_tree->insert( fx_.natural_50 );
	fx_.avl_tree->insert( fx_.natural_70 );
	fx_.avl_tree->insert( fx_.natural_10 );
	fx_.avl_tree->insert( fx_.natural_20 ); // rebalance triggering insert

	Cule_this( fx_.tree_has_correct_childs_after_balancing_without_involving_root() ).should_be();
	Cule_this( fx_.tree_has_correct_parents_after_balancing_without_involving_root() ).should_be();
	Cule_this( fx_.tree_nodes_has_correct_height_after_balancing_without_involving_root() ).should_be();
}

CULE_TEST_F( Avl_tree_rebalancing, should_perform_rebalancing_using_complex_left_rotation_involving_root ) {
	fx_.avl_tree->insert( fx_.natural_10 );
	fx_.avl_tree->insert( fx_.natural_30 );
	fx_.avl_tree->insert( fx_.natural_20 ); // rebalance triggering insert

	Cule_this( fx_.tree_has_correct_childs_after_balancing_involving_root() ).should_be();
	Cule_this( fx_.tree_has_correct_parents_after_balancing_involving_root() ).should_be();
	Cule_this( fx_.tree_nodes_has_correct_height_after_balancing_involving_root() ).should_be();
}

CULE_TEST_F( Avl_tree_rebalancing, should_perform_rebalancing_using_complex_right_rotation_involving_root ) {
	fx_.avl_tree->insert( fx_.natural_30 );
	fx_.avl_tree->insert( fx_.natural_10 );
	fx_.avl_tree->insert( fx_.natural_20 ); // rebalance triggering insert

	Cule_this( fx_.tree_has_correct_childs_after_balancing_involving_root() ).should_be();
	Cule_this( fx_.tree_has_correct_parents_after_balancing_involving_root() ).should_be();
	Cule_this( fx_.tree_nodes_has_correct_height_after_balancing_involving_root() ).should_be();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// imprecise find
CULE_TEST_F( Avl_tree_imprecise_find, should_find_max_less_and_min_greater_and_no_exact ) {
	const algorithming::Imprecise_find_result< traversing::Avl_tree_traverser< typeing::Memory_natural > > imprecise_result =
		fx_.avl_tree->find_imprecise( typeing::Memory_natural::create( 35 ) );

	Cule_this( imprecise_result.get_maximum_less() ).should_not_be_empty();
	Cule_this( imprecise_result.get_maximum_less().get_object() ).should_be_equal_to( fx_.natural_30 );
	Cule_this( imprecise_result.get_minimum_greater() ).should_not_be_empty();
	Cule_this( imprecise_result.get_minimum_greater().get_object() ).should_be_equal_to( fx_.natural_40 );
	Cule_this( imprecise_result.get_exact() ).should_be_empty();
}

CULE_TEST_F( Avl_tree_imprecise_find, should_find_max_less_and_min_greater_and_no_exact_in_corner_node ) {
	const typeing::Memory_natural new_node_value = typeing::Memory_natural::create( 63 );
	fx_.avl_tree->insert( new_node_value );

	const algorithming::Imprecise_find_result< traversing::Avl_tree_traverser< typeing::Memory_natural > > imprecise_result =
		fx_.avl_tree->find_imprecise( typeing::Memory_natural::create( 67 ) );

	Cule_this( imprecise_result.get_maximum_less() ).should_not_be_empty();
	Cule_this( imprecise_result.get_maximum_less().get_object() ).should_be_equal_to( new_node_value );
	Cule_this( imprecise_result.get_minimum_greater() ).should_not_be_empty();
	Cule_this( imprecise_result.get_minimum_greater().get_object() ).should_be_equal_to( fx_.natural_70 );
	Cule_this( imprecise_result.get_exact() ).should_be_empty();
}

CULE_TEST_F( Avl_tree_imprecise_find, should_find_max_less_only_in_right_corner_node ) {
	const algorithming::Imprecise_find_result< traversing::Avl_tree_traverser< typeing::Memory_natural > > imprecise_result =
		fx_.avl_tree->find_imprecise( typeing::Memory_natural::create( 75 ) );

	Cule_this( imprecise_result.get_maximum_less() ).should_not_be_empty();
	Cule_this( imprecise_result.get_maximum_less().get_object() ).should_be_equal_to( fx_.natural_70 );
	Cule_this( imprecise_result.get_minimum_greater() ).should_be_empty();
	Cule_this( imprecise_result.get_exact() ).should_be_empty();
}

CULE_TEST_F( Avl_tree_imprecise_find, should_find_min_greater_only_in_left_corner_node ) {
	const algorithming::Imprecise_find_result< traversing::Avl_tree_traverser< typeing::Memory_natural > > imprecise_result =
		fx_.avl_tree->find_imprecise( typeing::Memory_natural::create( 5 ) );

	Cule_this( imprecise_result.get_minimum_greater() ).should_not_be_empty();
	Cule_this( imprecise_result.get_minimum_greater().get_object() ).should_be_equal_to( fx_.natural_10 );
	Cule_this( imprecise_result.get_maximum_less() ).should_be_empty();
	Cule_this( imprecise_result.get_exact() ).should_be_empty();
}

CULE_TEST_F( Avl_tree_imprecise_find, should_find_max_less_and_min_greater_and_exact ) {
	const algorithming::Imprecise_find_result< traversing::Avl_tree_traverser< typeing::Memory_natural > > imprecise_result_30 =
		fx_.avl_tree->find_imprecise( typeing::Memory_natural::create( 30 ) );

	Cule_this( imprecise_result_30.get_maximum_less() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_maximum_less().get_object() ).should_be_equal_to( fx_.natural_20 );
	Cule_this( imprecise_result_30.get_minimum_greater() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_minimum_greater().get_object() ).should_be_equal_to( fx_.natural_40 );
	Cule_this( imprecise_result_30.get_exact() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_exact().get_object() ).should_be_equal_to( fx_.natural_30 );
}

CULE_DISABLED_TEST_F( Avl_tree_imprecise_find, should_find_max_less_and_min_greater_and_exact_in_middle_node ) {
	const algorithming::Imprecise_find_result< traversing::Avl_tree_traverser< typeing::Memory_natural > > imprecise_result_60 =
		fx_.avl_tree->find_imprecise( typeing::Memory_natural::create( 60 ) );

	Cule_this( imprecise_result_60.get_maximum_less() ).should_not_be_empty();
	Cule_this( imprecise_result_60.get_maximum_less().get_object() ).should_be_equal_to( fx_.natural_50 );
	Cule_this( imprecise_result_60.get_minimum_greater() ).should_not_be_empty();
	Cule_this( imprecise_result_60.get_minimum_greater().get_object() ).should_be_equal_to( fx_.natural_70 );
	Cule_this( imprecise_result_60.get_exact() ).should_not_be_empty();
	Cule_this( imprecise_result_60.get_exact().get_object() ).should_be_equal_to( fx_.natural_60 );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// remove by object
CULE_DISABLED_TEST_F( Avl_tree_remove, should_remove_leftmost_leaf_only ) {
//	fx_.avl_tree->remove( fx_.natural_10 );

	Cule_this( fx_.all_nodes_are_inplace_except( fx_.natural_10 ) ).should_be();
}

CULE_DISABLED_TEST_F( Avl_tree_remove, should_remove_rightmost_leaf_only ) {
	const algorithming::Imprecise_find_result< traversing::Avl_tree_traverser< typeing::Memory_natural > > imprecise_result_30 =
		fx_.avl_tree->find_imprecise( typeing::Memory_natural::create( 30 ) );

	Cule_this( imprecise_result_30.get_maximum_less() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_maximum_less().get_object() ).should_be_equal_to( fx_.natural_20 );
	Cule_this( imprecise_result_30.get_minimum_greater() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_minimum_greater().get_object() ).should_be_equal_to( fx_.natural_40 );
	Cule_this( imprecise_result_30.get_exact() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_exact().get_object() ).should_be_equal_to( fx_.natural_30 );
}

CULE_DISABLED_TEST_F( Avl_tree_remove, should_remove_rightmost_leaf_of_left_subtree_only ) {
	const algorithming::Imprecise_find_result< traversing::Avl_tree_traverser< typeing::Memory_natural > > imprecise_result_30 =
		fx_.avl_tree->find_imprecise( typeing::Memory_natural::create( 30 ) );

	Cule_this( imprecise_result_30.get_maximum_less() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_maximum_less().get_object() ).should_be_equal_to( fx_.natural_20 );
	Cule_this( imprecise_result_30.get_minimum_greater() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_minimum_greater().get_object() ).should_be_equal_to( fx_.natural_40 );
	Cule_this( imprecise_result_30.get_exact() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_exact().get_object() ).should_be_equal_to( fx_.natural_30 );
}

CULE_DISABLED_TEST_F( Avl_tree_remove, should_remove_leftmost_leaf_of_right_subtree_only ) {
	const algorithming::Imprecise_find_result< traversing::Avl_tree_traverser< typeing::Memory_natural > > imprecise_result_30 =
		fx_.avl_tree->find_imprecise( typeing::Memory_natural::create( 30 ) );

	Cule_this( imprecise_result_30.get_maximum_less() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_maximum_less().get_object() ).should_be_equal_to( fx_.natural_20 );
	Cule_this( imprecise_result_30.get_minimum_greater() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_minimum_greater().get_object() ).should_be_equal_to( fx_.natural_40 );
	Cule_this( imprecise_result_30.get_exact() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_exact().get_object() ).should_be_equal_to( fx_.natural_30 );
}

CULE_DISABLED_TEST_F( Avl_tree_remove, should_remove_root_node_only ) {
	const algorithming::Imprecise_find_result< traversing::Avl_tree_traverser< typeing::Memory_natural > > imprecise_result_30 =
		fx_.avl_tree->find_imprecise( typeing::Memory_natural::create( 30 ) );

	Cule_this( imprecise_result_30.get_maximum_less() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_maximum_less().get_object() ).should_be_equal_to( fx_.natural_20 );
	Cule_this( imprecise_result_30.get_minimum_greater() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_minimum_greater().get_object() ).should_be_equal_to( fx_.natural_40 );
	Cule_this( imprecise_result_30.get_exact() ).should_not_be_empty();
	Cule_this( imprecise_result_30.get_exact().get_object() ).should_be_equal_to( fx_.natural_30 );
}


} // namespace containing
} // namespace structing
} // namespace jmsf
