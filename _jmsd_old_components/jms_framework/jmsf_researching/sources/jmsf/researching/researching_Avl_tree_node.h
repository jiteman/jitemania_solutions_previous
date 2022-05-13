#pragma once

#include "researching_Avl_tree_node.hxx"


#include "jmsf/typeing/Boolean.hxx"

#include <cstddef>


namespace jmsf {
namespace researching {


// move all node operations into tree_node (including the rotation)
class researching_Avl_tree_node {

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// DEBUGGING
	static size_t _balancing_counter;
	static size_t _rotation_counter;
	static size_t _height_updating_counter;
	static size_t _creation_counter;
	static size_t _deletion_counter;

public:
	static void reset_counters() noexcept;
	static size_t get_balancing_counter() noexcept;
	static size_t get_rotation_counter() noexcept;
	static size_t get_height_updating_counter() noexcept;
	static size_t get_creation_counter() noexcept;
	static size_t get_deletion_counter() noexcept;
//~DEBUGGING
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

public:
	const int &get_key_and_data() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean has_left_child() const;
	typeing::Boolean has_right_child() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // Seinsei: todonext - replace with traverser
	researching_Avl_tree_node *REMOVE_take_left_child() noexcept;
	researching_Avl_tree_node *REMOVE_take_right_child() noexcept;

public:
	researching_Avl_tree_node *REMOVE_remove( researching_Avl_tree_node **a_root_node_pointer );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void DEBUG_dump_node() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~researching_Avl_tree_node() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	researching_Avl_tree_node() noexcept;

	researching_Avl_tree_node( int key_and_data, researching_Avl_tree_node *parent_node ) noexcept;

public:
	static researching_Avl_tree_node *create_as_root( int key_and_data );

	static researching_Avl_tree_node *create_as_left_child(
		int key_and_data,
		researching_Avl_tree_node *parent_node,
		researching_Avl_tree_node **a_root_node_pointer );

	static researching_Avl_tree_node *create_as_right_child(
		int key_and_data,
		researching_Avl_tree_node *parent_node,
		researching_Avl_tree_node **a_root_node_pointer );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	researching_Avl_tree_node( const researching_Avl_tree_node &another ) noexcept = delete;
	const researching_Avl_tree_node &operator =( const researching_Avl_tree_node &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	researching_Avl_tree_node( researching_Avl_tree_node &&another ) noexcept = delete;
	researching_Avl_tree_node &operator =( researching_Avl_tree_node &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	int _key_and_data;
	size_t _node_height;
	researching_Avl_tree_node *_parent_node;
	researching_Avl_tree_node *_left_child_node;
	researching_Avl_tree_node *_right_child_node;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // Seinsei: todonext - encapsulate
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

private:
	typeing::Boolean is_root() const;
	typeing::Boolean is_not_root() const;

	typeing::Boolean is_left_child() const;
	typeing::Boolean is_right_child() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	void perform_balancing( researching_Avl_tree_node **a_root_node_pointer );
	ptrdiff_t get_balance_factor() const;
	size_t get_left_subtree_height() const;
	size_t get_right_subtree_height() const;
	typeing::Boolean is_disbalanced() const;
	researching_Avl_tree_node *update_height_up_to_disbalanced_node();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	void perform_balancing_if_necessary( researching_Avl_tree_node **a_root_node_pointer );
	researching_Avl_tree_node *find_leftmost();
	researching_Avl_tree_node *find_rightmost();
	void replace_with_its_child( researching_Avl_tree_node *a_replacement_child );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	void perform_left_rotation( researching_Avl_tree_node **a_root_node );
	void perform_right_rotation( researching_Avl_tree_node **a_root_node );

	void perform_rotation(
		researching_Avl_tree_node **pivot_node_destination_child_and_rotating_node,
		researching_Avl_tree_node **rotating_node_source_child,
		researching_Avl_tree_node **a_root_node );

};


} // namespace researching
} // namespace jmsf
