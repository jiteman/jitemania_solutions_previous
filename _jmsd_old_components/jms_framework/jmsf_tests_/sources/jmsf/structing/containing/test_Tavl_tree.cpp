#include "jmsf/cule/macroses_Test.h"


#include "jmsf/structing/containing/Tavl_tree.hin" // what to test
#include "jmsf/structing/noding/Tavl_node.hin"
#include "jmsf/structing/noding/testing_Tavl_node_typedefs.hxx"

#include "jmsf/researching/researching_Avl_tree.h"

#include "jmsf/testing/Testing_object_creator.hin"
#include "jmsf/typeing/Naturals.hin"


namespace jmsf {
namespace structing {
namespace containing {


typedef Tavl_tree< typeing::Memory_natural > Mn_tavl_tree;
typedef memorying::Omp< Mn_tavl_tree > Mn_tavl_tree_omp;
typedef pointing::Scoped< Mn_tavl_tree > Mn_tavl_tree_scoped;
typedef testing::Testing_object_creator< Mn_tavl_tree > Mn_tavl_tree_factory;


class Tavl_tree_fixture {

public:
	void set_up() {
		first_node = noding::Mn_tavl_node_factory::create_omp( typeing::Memory_natural_one );
		first_node_scoped = noding::Mn_tavl_node_scoped::create( first_node );
	}

	void tear_down() {
		first_node = noding::Mn_tavl_node_omp();
		first_node_scoped = noding::Mn_tavl_node_scoped();
	}

	noding::Mn_tavl_node_omp first_node;
	noding::Mn_tavl_node_scoped first_node_scoped;

};


CULE_TEST( Tavl_tree, should_create_empty ) {
	Mn_tavl_tree empty_tavl_tree;

	Cule_this( empty_tavl_tree ).should_be_empty();
}

CULE_TEST( Tavl_tree, should_delete_empty ) {
	{
		Mn_tavl_tree empty_tavl_tree;
	}
}

CULE_TEST( Tavl_tree, should_run_test_for_avl_tree_example ) {
	researching::researching_Avl_tree::test_avl_tree_example();
}

//CULE_TEST( Tavl_tree, should_maintain_one_object ) {
//	Mn_tavl_tree_scoped tavl_tree = Mn_tavl_tree_factory::create_scoped();

//	tavl_tree->insert( testing::testing_Allocators::instance()->get_testing_object_allocator(), typeing::Memory_natural_one );

//	Cule_this( **tavl_tree->find( typeing::Memory_natural_one ) ).should_be_equal_to( typeing::Memory_natural_one );
//}

//CULE_TEST( Tavl_tree, should_maintain_3_objects ) {
//	Mn_tavl_tree_scoped tavl_tree = Mn_tavl_tree_factory::create_scoped();

//	noding::Mn_tavl_node_omp tavl_node_1 = noding::Mn_tavl_node_factory::create_omp( typeing::Memory_natural_one );
//	noding::Mn_tavl_node_scoped tavl_node_scoped_1 = noding::Mn_tavl_node_scoped::create( tavl_node_1 );

//	tavl_tree->insert( tavl_node );

//	Cule_this( *tavl_tree->find( typeing::Memory_natural_one ) ).should_be_equal_to( *tavl_node );
//}


} // namespace containing
} // namespace structing
} // namespace jmsf
