#include "researching_Avl_tree_node.h"


#include "researching_Math.h"

#include "jmsf/typeing/Boolean.h"

#include "jmsf/validating/macroses_Should.h"

#include <iostream>


namespace jmsf {
namespace researching {


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// DEBUGGING

// static
size_t researching_Avl_tree_node::_balancing_counter = 0;
// static
size_t researching_Avl_tree_node::_rotation_counter = 0;
// static
size_t researching_Avl_tree_node::_height_updating_counter = 0;
// static
size_t researching_Avl_tree_node::_creation_counter = 0;
// static
size_t researching_Avl_tree_node::_deletion_counter = 0;

// static
void researching_Avl_tree_node::reset_counters() noexcept {
	_balancing_counter = 0;
	_rotation_counter = 0;
	_height_updating_counter = 0;
//	_creation_counter = 0;
//	_deletion_counter = 0;
}

// static
size_t researching_Avl_tree_node::get_balancing_counter() noexcept {
	return _balancing_counter;
}

// static
size_t researching_Avl_tree_node::get_rotation_counter() noexcept {
	return _rotation_counter;
}

// static
size_t researching_Avl_tree_node::get_height_updating_counter() noexcept {
	return _height_updating_counter;
}

// static
size_t researching_Avl_tree_node::get_creation_counter() noexcept {
	return _creation_counter;
}

// static
size_t researching_Avl_tree_node::get_deletion_counter() noexcept {
	return _deletion_counter;
}
//~DEBUGGING
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

const int &researching_Avl_tree_node::get_key_and_data() const {
	jmsf_Should_never_be( is_empty() );

	return _key_and_data;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
researching_Avl_tree_node *researching_Avl_tree_node::REMOVE_take_left_child() noexcept {
	return _left_child_node;
}

researching_Avl_tree_node *researching_Avl_tree_node::REMOVE_take_right_child() noexcept {
	return _right_child_node;
}

researching_Avl_tree_node *researching_Avl_tree_node::REMOVE_remove( researching_Avl_tree_node **const a_root_node_pointer ) {
	jmsf_Should_never_be_empty_native_pointer( a_root_node_pointer );

	researching_Avl_tree_node *node_to_delete = nullptr;

	const size_t left_subtree_height = get_left_subtree_height();
	const size_t right_subtree_height = get_right_subtree_height();

	if ( left_subtree_height < right_subtree_height ) { // move leftmost node of the right subtree up to this node position
		researching_Avl_tree_node *leftmost_node = _right_child_node->find_leftmost();
		_key_and_data = leftmost_node->_key_and_data;
		leftmost_node->replace_with_its_child( leftmost_node->_right_child_node );
		leftmost_node->_parent_node->perform_balancing_if_necessary( a_root_node_pointer );
		node_to_delete = leftmost_node;
	} else if ( left_subtree_height > right_subtree_height ) { // move rightmost node of the left subtree up to this node position
		researching_Avl_tree_node *rightmost_node = _left_child_node->find_rightmost();
		_key_and_data = rightmost_node->_key_and_data;
		rightmost_node->replace_with_its_child( rightmost_node->_left_child_node );
		rightmost_node->_parent_node->perform_balancing_if_necessary( a_root_node_pointer );
		node_to_delete = rightmost_node;
	} else { // equal (both empty or realy equal)
		if ( !( has_left_child() || has_right_child() ) ) { // no children
			if ( !is_root() ) {
				if ( is_left_child() ) {
					_parent_node->_left_child_node = nullptr;
				} else if ( is_right_child() ) {
					_parent_node->_right_child_node = nullptr;
				} else {
					_jmsf_Should_never_reach_here_void();
				}

				_parent_node->perform_balancing_if_necessary( a_root_node_pointer );
			} else { // the last node is the root
				*a_root_node_pointer = nullptr;
			}

			node_to_delete = this;
		} else { // has both left and right child with equal height
			researching_Avl_tree_node *leftmost_node = _right_child_node->find_leftmost();
			researching_Avl_tree_node *rightmost_node = _left_child_node->find_rightmost();

			if ( _node_height - leftmost_node->_node_height > _node_height - rightmost_node->_node_height ) { // deepest node is in the right subtree
				_key_and_data = leftmost_node->_key_and_data;
				leftmost_node->replace_with_its_child( leftmost_node->_right_child_node );
				leftmost_node->_parent_node->perform_balancing_if_necessary( a_root_node_pointer );
				node_to_delete = leftmost_node;
			} else { // deepest node is in the left subtree or there is no difference
				_key_and_data = rightmost_node->_key_and_data;
				rightmost_node->replace_with_its_child( rightmost_node->_left_child_node );
				rightmost_node->_parent_node->perform_balancing_if_necessary( a_root_node_pointer );
				node_to_delete = rightmost_node;
			}
		}
	}

	node_to_delete->_key_and_data = 0;
	node_to_delete->_node_height = 0;
	node_to_delete->_parent_node = nullptr;
	node_to_delete->_left_child_node = nullptr;
	node_to_delete->_right_child_node = nullptr;

	return node_to_delete;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void researching_Avl_tree_node::DEBUG_dump_node() const noexcept {
	::std::cout <<
		"Key: " << _key_and_data << " " <<
		"Balance: " << get_balance_factor() << " " <<
		"[ " << _node_height << " ] " <<
		"Parent: " << ( is_root() ? 0 : _parent_node->_key_and_data ) << " " <<
		"[ " << ( is_root() ? 0 : _parent_node->_node_height ) << " ] " <<
		"Left: " << ( has_left_child() ? _left_child_node->_key_and_data : 0 ) << " " <<
		"[ " << get_left_subtree_height() << " ] " <<
		"Right: " << ( has_right_child() ? _right_child_node->_key_and_data : 0 ) << " " <<
		"[ " << get_right_subtree_height() << " ]" << ::std::endl;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
researching_Avl_tree_node::~researching_Avl_tree_node() noexcept {
	++_deletion_counter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
researching_Avl_tree_node::researching_Avl_tree_node() noexcept {
	++_creation_counter;
}

researching_Avl_tree_node::researching_Avl_tree_node(
	const int key_and_data,
	researching_Avl_tree_node *const parent_node ) noexcept
	:
		_key_and_data( key_and_data ),
		_parent_node( parent_node ),
		_node_height( 1 ),
		_left_child_node( nullptr ),
		_right_child_node( nullptr )
{
	++_creation_counter;
}

// static
researching_Avl_tree_node *researching_Avl_tree_node::create_as_root(
	const int key_and_data )
{
	return new researching_Avl_tree_node( key_and_data, nullptr );
}

// static
researching_Avl_tree_node * researching_Avl_tree_node::create_as_left_child(
	const int key_and_data,
	researching_Avl_tree_node *const parent_node,
	researching_Avl_tree_node **const a_root_node_pointer )
{
	jmsf_Should_never_be_empty_native_pointer( a_root_node_pointer );
	jmsf_Should_never_be( parent_node->is_empty() );
	jmsf_Should_never_be( parent_node->has_left_child() );

	researching_Avl_tree_node *new_node = new researching_Avl_tree_node( key_and_data, parent_node );
	parent_node->_left_child_node = new_node;
	parent_node->perform_balancing_if_necessary( a_root_node_pointer );

	return new_node;
}

// static
researching_Avl_tree_node * researching_Avl_tree_node::create_as_right_child(
	const int key_and_data,
	researching_Avl_tree_node *const parent_node,
	researching_Avl_tree_node **const a_root_node_pointer )
{
	jmsf_Should_never_be_empty_native_pointer( a_root_node_pointer );
	jmsf_Should_never_be( parent_node->is_empty() );
	jmsf_Should_never_be( parent_node->has_right_child() );

	researching_Avl_tree_node *new_node = new researching_Avl_tree_node( key_and_data, parent_node );
	parent_node->_right_child_node = new_node;
	parent_node->perform_balancing_if_necessary( a_root_node_pointer );

	return new_node;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//researching_Avl_tree_node::researching_Avl_tree_node( const researching_Avl_tree_node &/*another*/ ) noexcept {
//}

//const researching_Avl_tree_node &researching_Avl_tree_node::operator =( const researching_Avl_tree_node &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy
//	return *this;
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//researching_Avl_tree_node::researching_Avl_tree_node( researching_Avl_tree_node &&/*another*/ ) noexcept {
//}

//researching_Avl_tree_node &researching_Avl_tree_node::operator =( researching_Avl_tree_node &&another ) noexcept {
//	if ( &another == this ) return *this;

//	// move
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
typeing::Boolean researching_Avl_tree_node::has_left_child() const {
	return _left_child_node->is_not_empty();
}

typeing::Boolean researching_Avl_tree_node::has_right_child() const {
	return _right_child_node->is_not_empty();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
typeing::Boolean researching_Avl_tree_node::is_empty() const noexcept {
	const researching_Avl_tree_node *this_pointer = this;
	return typeing::Boolean::create( this_pointer == nullptr );
}

typeing::Boolean researching_Avl_tree_node::is_not_empty() const noexcept {
	return !is_empty();
}

typeing::Boolean researching_Avl_tree_node::is_root() const {
	jmsf_Should_never_be( is_empty() );

	return _parent_node->is_empty();
}

typeing::Boolean researching_Avl_tree_node::is_not_root() const {
	return !is_root();
}

typeing::Boolean researching_Avl_tree_node::is_left_child() const {
	jmsf_Should_never_be( is_empty() );
	jmsf_Should_never_be( is_root() );

	return typeing::Boolean::create( _parent_node->_left_child_node == this );
}

typeing::Boolean researching_Avl_tree_node::is_right_child() const {
	jmsf_Should_never_be( is_empty() );
	jmsf_Should_never_be( is_root() );

	return typeing::Boolean::create( _parent_node->_right_child_node == this );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void researching_Avl_tree_node::perform_balancing( researching_Avl_tree_node **const a_root_node_pointer ) {
	++_balancing_counter;
	jmsf_Should_never_be_empty_native_pointer( a_root_node_pointer );
	jmsf_Should_never_be( ( *a_root_node_pointer )->is_empty() );

	if ( get_balance_factor() == -2 ) { // unbalanced to the left, right rotation is needed
		jmsf_Should_always_be( has_left_child() ); // should have a left child ('cause it is unbalanced to the left )

		if ( _left_child_node->get_balance_factor() > 0 ) {
			researching_Avl_tree_node *previous_left_child_node = _left_child_node;
			_left_child_node->perform_left_rotation( a_root_node_pointer );

			{
				const researching_Avl_tree_node *disbalanced_node = previous_left_child_node->update_height_up_to_disbalanced_node();
				jmsf_Should_never_be_empty_native_pointer( disbalanced_node );
			}

			perform_right_rotation( a_root_node_pointer );

			const researching_Avl_tree_node *disbalanced_node = update_height_up_to_disbalanced_node();
			jmsf_Should_always_be_empty_native_pointer( disbalanced_node );
		} else if ( _left_child_node->get_balance_factor() <= 0 ) {
			perform_right_rotation( a_root_node_pointer );

			const researching_Avl_tree_node *disbalanced_node = update_height_up_to_disbalanced_node();
			jmsf_Should_always_be_empty_native_pointer( disbalanced_node );
		}
	} else if ( get_balance_factor() == 2 ) { // unbalanced to the right, left rotation is needed
		jmsf_Should_always_be( has_right_child() ); // should have a right child ('cause it is unbalanced to the right)

		if ( _right_child_node->get_balance_factor() < 0 ) {
			researching_Avl_tree_node *previous_right_child_node = _right_child_node;
			_right_child_node->perform_right_rotation( a_root_node_pointer );

			{
				const researching_Avl_tree_node *disbalanced_node = previous_right_child_node->update_height_up_to_disbalanced_node();
				jmsf_Should_never_be_empty_native_pointer( disbalanced_node );
			}

			perform_left_rotation( a_root_node_pointer );

			const researching_Avl_tree_node *disbalanced_node = update_height_up_to_disbalanced_node();
			jmsf_Should_always_be_empty_native_pointer( disbalanced_node );
		} else if ( _right_child_node->get_balance_factor() >= 0 ) {
			perform_left_rotation( a_root_node_pointer );

			const researching_Avl_tree_node *disbalanced_node = update_height_up_to_disbalanced_node();
			jmsf_Should_always_be_empty_native_pointer( disbalanced_node );
		}
	} else {
		_jmsf_Should_never_reach_here_void();
	}
}

ptrdiff_t researching_Avl_tree_node::get_balance_factor() const {
	return static_cast< ptrdiff_t >( get_right_subtree_height() ) - static_cast< ptrdiff_t >( get_left_subtree_height() );
}

size_t researching_Avl_tree_node::get_left_subtree_height() const {
	if ( _left_child_node->is_empty() ) return 0;

	return _left_child_node->_node_height;
}

size_t researching_Avl_tree_node::get_right_subtree_height() const {
	if ( _right_child_node->is_empty() ) return 0;

	return _right_child_node->_node_height;
}

typeing::Boolean researching_Avl_tree_node::is_disbalanced() const {
	jmsf_Should_never_be( is_empty() );

	return typeing::Boolean::create( Math::absolute( get_balance_factor() ) == 2 );
}

researching_Avl_tree_node *researching_Avl_tree_node::update_height_up_to_disbalanced_node() {
	::std::cout << "researching_Avl_tree_node::update_height_up_to_disbalanced_node()" << ::std::endl;
	++_height_updating_counter;
	researching_Avl_tree_node *node_traverser = this;

	while ( node_traverser->is_not_empty() ) {
		node_traverser->_node_height = 1 + Math::maximum( node_traverser->get_left_subtree_height(), node_traverser->get_right_subtree_height() );

		if ( node_traverser->is_disbalanced() ) {
			return node_traverser;
		}

		node_traverser = node_traverser->_parent_node;
	}

	return nullptr;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void researching_Avl_tree_node::perform_balancing_if_necessary( researching_Avl_tree_node **a_root_node_pointer ) {
	researching_Avl_tree_node *disbalanced_node = update_height_up_to_disbalanced_node();

	if ( disbalanced_node->is_not_empty() ) {
		disbalanced_node->perform_balancing( a_root_node_pointer );
	}
}

researching_Avl_tree_node *researching_Avl_tree_node::find_leftmost() {
	jmsf_Should_never_be( is_empty() );

	researching_Avl_tree_node *leftmost_node = nullptr;
	{
		researching_Avl_tree_node *leftmost_node_traverser = this;

		do {
			leftmost_node = leftmost_node_traverser;
			leftmost_node_traverser = leftmost_node_traverser->_left_child_node;
		} while ( leftmost_node_traverser->is_not_empty() );
	}

	return leftmost_node;
}

researching_Avl_tree_node *researching_Avl_tree_node::find_rightmost() {
	jmsf_Should_never_be( is_empty() );

	researching_Avl_tree_node *rightmost_node = nullptr;
	{
		researching_Avl_tree_node *rightmost_node_traverser = this;

		do {
			rightmost_node = rightmost_node_traverser;
			rightmost_node_traverser = rightmost_node_traverser->_right_child_node;
		} while ( rightmost_node_traverser->is_not_empty() );
	}

	return rightmost_node;
}

void researching_Avl_tree_node::replace_with_its_child( researching_Avl_tree_node *a_replacement_child ) {
	jmsf_Should_never_be( is_empty() );
	jmsf_Should_never_be( is_root() );

	if ( is_left_child() ) {
		_parent_node->_left_child_node = a_replacement_child;

		if ( _parent_node->has_left_child() ) {
			_parent_node->_left_child_node->_parent_node = _parent_node;
		}

	} else if ( is_right_child() ) {
		_parent_node->_right_child_node = a_replacement_child;

		if ( _parent_node->has_right_child() ) {
			_parent_node->_right_child_node->_parent_node = _parent_node;
		}
	} else {
		_jmsf_Should_never_reach_here_void();
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void researching_Avl_tree_node::perform_left_rotation( researching_Avl_tree_node **a_root_node ) {
	jmsf_Should_never_be( is_empty() );
	jmsf_Should_never_be( _right_child_node->is_empty() );
	jmsf_Should_never_be_empty_native_pointer( a_root_node );
	jmsf_Should_never_be( ( *a_root_node )->is_empty() );

	perform_rotation( &_right_child_node, &_right_child_node->_left_child_node, a_root_node );
}

void researching_Avl_tree_node::perform_right_rotation( researching_Avl_tree_node **a_root_node ) {
	jmsf_Should_never_be( is_empty() );
	jmsf_Should_never_be( _left_child_node->is_empty() );
	jmsf_Should_never_be_empty_native_pointer( a_root_node );
	jmsf_Should_never_be( ( *a_root_node )->is_empty() );

	perform_rotation( &_left_child_node, &_left_child_node->_right_child_node, a_root_node );
}

// static
void researching_Avl_tree_node::perform_rotation(
	researching_Avl_tree_node **const pivot_node_destination_child_and_rotating_node,
	researching_Avl_tree_node **const rotating_node_source_child,
	researching_Avl_tree_node **const a_root_node )
{
	jmsf_Should_never_be( is_empty() );
	jmsf_Should_never_be_empty_native_pointer( pivot_node_destination_child_and_rotating_node );
	jmsf_Should_never_be( ( *pivot_node_destination_child_and_rotating_node )->is_empty() );
	jmsf_Should_never_be_empty_native_pointer( rotating_node_source_child );
	jmsf_Should_never_be_empty_native_pointer( a_root_node );
	jmsf_Should_never_be( ( *a_root_node )->is_empty() );

	++_rotation_counter;

	// update child of the parent
	if ( is_not_root() ) {
		if ( is_left_child() ) {
			_parent_node->_left_child_node = *pivot_node_destination_child_and_rotating_node;
		} else if ( is_right_child() ) {
			_parent_node->_right_child_node = *pivot_node_destination_child_and_rotating_node;
		} else {
			_jmsf_Should_never_reach_here_void();
		}
	}

	// move child up (to the node's place)
	( *pivot_node_destination_child_and_rotating_node )->_parent_node = _parent_node;
	_parent_node = *pivot_node_destination_child_and_rotating_node;

	// updating root if necessary
	if ( ( *pivot_node_destination_child_and_rotating_node )->is_root() ) {
		*a_root_node = *pivot_node_destination_child_and_rotating_node;
	}

	// move child's child to node's opposite
	*pivot_node_destination_child_and_rotating_node = *rotating_node_source_child;

	if ( *pivot_node_destination_child_and_rotating_node != nullptr ) {
		// change new node's parent to a node
		( *pivot_node_destination_child_and_rotating_node )->_parent_node = this;
	}

	// set child's child to a node
	*rotating_node_source_child = this;
}


} // namespace researching
} // namespace jmsf
