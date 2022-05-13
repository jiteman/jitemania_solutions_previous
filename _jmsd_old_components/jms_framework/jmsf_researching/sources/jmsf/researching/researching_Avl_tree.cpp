#include "researching_Avl_tree.h"


#include "researching_Avl_tree_node.h"

#include "jmsf/typeing/Boolean.h"

#include "jmsf/validating/macroses_Should.h"

#include <vector>
#include <iostream>


namespace jmsf {
namespace researching {


researching_Avl_tree::researching_Avl_tree() {
	_the_root = nullptr;
}

researching_Avl_tree::~researching_Avl_tree() {
	while ( _the_root->is_not_empty() ) {
		remove( _the_root );
	}

	_the_root = nullptr;
}

researching_Avl_tree_node *researching_Avl_tree::insert( const int key_and_data ) {
	if ( !_the_root ) {
		_the_root = researching_Avl_tree_node::create_as_root( key_and_data );
		return _the_root;
	}

	researching_Avl_tree_node *new_node = nullptr;

	{
		researching_Avl_tree_node *new_node_parent_traverser = _the_root;

		for ( ;; ) {
			if ( key_and_data == new_node_parent_traverser->get_key_and_data() ) {
				break; // key already exists
			} else if ( key_and_data < new_node_parent_traverser->get_key_and_data() ) {
				if ( !new_node_parent_traverser->has_left_child() ) {
					new_node = researching_Avl_tree_node::create_as_left_child( key_and_data, new_node_parent_traverser, &_the_root );
					break;
				} else {
					new_node_parent_traverser = new_node_parent_traverser->REMOVE_take_left_child();
				}
			} else if ( key_and_data > new_node_parent_traverser->get_key_and_data() ) {
				if ( !new_node_parent_traverser->has_right_child() ) {
					new_node = researching_Avl_tree_node::create_as_right_child( key_and_data, new_node_parent_traverser, &_the_root );
					break;
				} else {
					new_node_parent_traverser = new_node_parent_traverser->REMOVE_take_right_child();
				}
			}
		}
	}

	return new_node;
}

researching_Avl_tree_node *researching_Avl_tree::find( const int key_and_data ) {
	researching_Avl_tree_node *node_parent_traverser = _the_root;

	while ( node_parent_traverser->is_not_empty() ) {
		if ( node_parent_traverser->get_key_and_data() == key_and_data ) {
			return node_parent_traverser;
		} else if ( key_and_data < node_parent_traverser->get_key_and_data() ) {
			if ( node_parent_traverser->has_left_child() ) {
				node_parent_traverser = node_parent_traverser->REMOVE_take_left_child();
			} else {
				break;
			}
		} else if ( key_and_data > node_parent_traverser->get_key_and_data() ) {
			if ( node_parent_traverser->has_right_child() ) {
				node_parent_traverser = node_parent_traverser->REMOVE_take_right_child();
			} else {
				break;
			}
		}
	}

	return nullptr;
}

void researching_Avl_tree::remove( const int key_and_data ) {
	researching_Avl_tree_node *node_parent_traverser = find( key_and_data );

	jmsf_Should_never_be_empty_native_pointer( node_parent_traverser );

	remove( node_parent_traverser );
}

void researching_Avl_tree::remove( researching_Avl_tree_node *a_node ) {
	jmsf_Should_always_be( typeing::Boolean::create( a_node == find( a_node->get_key_and_data() ) ) );

	researching_Avl_tree_node *node_to_delete = a_node->REMOVE_remove( &_the_root );

	delete node_to_delete;
}

void researching_Avl_tree::debug_tree() const {
	debug_tree( _the_root );
}

void researching_Avl_tree::debug_tree( const researching_Avl_tree_node *const node ) const {
	if ( node == nullptr ) return;

	node->DEBUG_dump_node();

	debug_tree( const_cast< researching_Avl_tree_node * >( node )->REMOVE_take_left_child() );
	debug_tree( const_cast< researching_Avl_tree_node * >( node )->REMOVE_take_right_child() );
}

void researching_Avl_tree::test_avl_tree_example() {
//	::std::cout << ::std::endl << ::std::endl;

//	const ::std::vector< int > keys_to_insert { 10, 15, 20, 5, 22, 7, 6, 21, 7, 17, 16, 1, 11, 3, 13, 19 };
//	const ::std::vector< int > keys_to_find { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
//	const ::std::vector< int > keys_to_remove { 19, 13, 3, 11, 1, 16, 17, 21, 6, 22, 7, 5, 20, 15, 10 };

////	const ::std::vector< int > keys_to_insert { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
////	const ::std::vector< int > keys_to_find { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
////	const ::std::vector< int > keys_to_remove { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };

//	{
//		researching_Avl_tree avl_tree;

//		{ // debug insert
//			::std::size_t key_counter = 0;
//			for ( auto key_iterator = keys_to_insert.begin(); key_iterator != keys_to_insert.end(); ++key_iterator ) {
//				::std::cout << "Value #" << key_counter << ": " << *key_iterator << ::std::endl;
//				avl_tree.insert( *key_iterator );
//				++key_counter;
//			}

//			::std::cout << ::std::endl;

//			avl_tree.debug_tree();
//		}

//		const size_t insert_balancing_counter = researching_Avl_tree_node::get_balancing_counter();
//		const size_t insert_rotation_counter = researching_Avl_tree_node::get_rotation_counter();
//		const size_t insert_height_updating_counter = researching_Avl_tree_node::get_height_updating_counter();

//		::std::cout <<
//			"Balancing: " << insert_balancing_counter <<
//			" Rotations: " << insert_rotation_counter <<
//			" Height updates: " << insert_height_updating_counter << ::std::endl;

//		{ // debug find
//			for ( auto key_iterator = keys_to_find.begin(); key_iterator != keys_to_find.end(); ++key_iterator ) {
//				{
//					researching_Avl_tree_node *lesser_avl_tree_node = avl_tree.find( *key_iterator - 1 );

//					if ( lesser_avl_tree_node->is_not_empty() ) {
//						::std::cout << "Value " << *key_iterator - 1 << " is found as " << lesser_avl_tree_node->get_key_and_data() << ::std::endl;
//					} else {
//						::std::cout << "Value " << *key_iterator - 1 << " is not found" << ::std::endl;
//					}
//				}

//				{
//					researching_Avl_tree_node *exact_avl_tree_node = avl_tree.find( *key_iterator );

//					if ( exact_avl_tree_node->is_not_empty() ) {
//						::std::cout << "Value " << *key_iterator << " is found as " << exact_avl_tree_node->get_key_and_data() << ::std::endl;
//					} else {
//						::std::cout << "Value " << *key_iterator << " is not found" << ::std::endl;
//					}
//				}

//				{
//					researching_Avl_tree_node *greater_avl_tree_node = avl_tree.find( *key_iterator + 1 );

//					if ( greater_avl_tree_node->is_not_empty() ) {
//						::std::cout << "Value " << *key_iterator + 1 << " is found as " << greater_avl_tree_node->get_key_and_data() << ::std::endl;
//					} else {
//						::std::cout << "Value " << *key_iterator + 1 << " is not found" << ::std::endl;
//					}
//				}
//			}
//		}

//		researching_Avl_tree_node::reset_counters();

//		{ // debug remove
//			for ( auto key_iterator = keys_to_remove.rbegin(); key_iterator != keys_to_remove.rend(); ++key_iterator ) {
//				::std::cout << ::std::endl << "Value " << *key_iterator << ": is being removed...";
//				avl_tree.remove( *key_iterator );
//				::std::cout << " succesful" << ::std::endl;
//				avl_tree.debug_tree();
//			}
//		}

//		const size_t delete_balancing_counter = researching_Avl_tree_node::get_balancing_counter();
//		const size_t delete_rotation_counter = researching_Avl_tree_node::get_rotation_counter();
//		const size_t delete_height_updating_counter = researching_Avl_tree_node::get_height_updating_counter();

//		::std::cout <<
//			"Balancing: " << delete_balancing_counter <<
//			" Rotations: " << delete_rotation_counter <<
//			" Height updates: " << delete_height_updating_counter << ::std::endl;

//		researching_Avl_tree_node::reset_counters();
//	}

//	const size_t autodelete_balancing_counter = researching_Avl_tree_node::get_balancing_counter();
//	const size_t autodelete_rotation_counter = researching_Avl_tree_node::get_rotation_counter();
//	const size_t autodelete_height_updating_counter = researching_Avl_tree_node::get_height_updating_counter();

//	::std::cout << ::std::endl <<
//		"Balancing: " << autodelete_balancing_counter <<
//		" Rotations: " << autodelete_rotation_counter <<
//		" Height updates: " << autodelete_height_updating_counter << ::std::endl;

//	::std::cout << ::std::endl <<
//		"Created: " << researching_Avl_tree_node::get_creation_counter() <<
//		" nodes, Deleted: " << researching_Avl_tree_node::get_deletion_counter() << " nodes." << ::std::endl;
}


} // namespace researching
} // namespace jmsf
