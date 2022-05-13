#pragma once

#include "researching_Avl_tree.hxx"


#include "researching_Avl_tree_node.hxx"

#include "jmsf_researching.h"


namespace jmsf {
namespace researching {


// move all node operations into tree_node (including the rotation)
class JMSF_RESEARCHING_SHARED_INTERFACE researching_Avl_tree {

	researching_Avl_tree_node *_the_root;

public:
	/* Constructor & destructor */
	researching_Avl_tree();
	~researching_Avl_tree();

	researching_Avl_tree_node *insert( int key_and_data );
	researching_Avl_tree_node *find( int key_and_data );
	void remove( int key_and_data );
	void remove( researching_Avl_tree_node *a_node );

	void debug_tree() const;

private:
	void debug_tree( const researching_Avl_tree_node *a_node ) const;

public:
	static void test_avl_tree_example();

};


} // namespace researching
} // namespace jmsf
