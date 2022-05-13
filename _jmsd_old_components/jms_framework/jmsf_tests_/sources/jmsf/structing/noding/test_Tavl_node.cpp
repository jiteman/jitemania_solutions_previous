#include "jmsf/cule/macroses_Test.h"


#include "jmsf/structing/noding/Tavl_node.hin" // what to test


#include "jmsf/testing/Testing_object_creator.hin"

#include "jmsf/pointing/Scoped.hin"
#include "jmsf/typeing/Naturals.hin"


namespace jmsf {
namespace structing {
namespace noding {


typedef Tavl_node< typeing::Memory_natural > Mn_tavl_node;
typedef memorying::Omp< Mn_tavl_node > Mn_tavl_node_omp;
typedef pointing::Scoped< Mn_tavl_node > Mn_tavl_node_scoped;
typedef testing::Testing_object_creator< Mn_tavl_node > Mn_tavl_node_factory;


CULE_TEST( Tavl_node, should_create_empty ) {
	Mn_tavl_node empty_node;

	Cule_this( empty_node ).should_be_empty();
}

CULE_TEST( Tavl_node, should_delete_empty ) {
	{
		Mn_tavl_node empty_node;
	}
}

CULE_TEST( Tavl_node, should_be_equal_empty_empty ) {
	Mn_tavl_node empty_node;

	Cule_this( Mn_tavl_node() ).should_be_equal_to( Mn_tavl_node() );
	Cule_this( empty_node ).should_be_equal_to( empty_node );
	Cule_this( empty_node ).should_be_equal_to( Mn_tavl_node() );
	Cule_this( Mn_tavl_node() ).should_be_equal_to( empty_node );
}

CULE_TEST( Tavl_node, should_maintain_left_child ) {
	Mn_tavl_node_omp left_node = Mn_tavl_node_factory::create_omp( typeing::Memory_natural_nil );
	Mn_tavl_node_scoped scoped_left_node = Mn_tavl_node_scoped::create( left_node );
	Mn_tavl_node_omp the_node = Mn_tavl_node_factory::create_omp( typeing::Memory_natural_nil );
	Mn_tavl_node_scoped scoped_the_node = Mn_tavl_node_scoped::create( the_node );

	the_node->set_left_child( left_node );

	Cule_this( the_node->get_left_child() ).should_be_equal_to( left_node );
}

CULE_TEST( Tavl_node, should_maintain_right_child ) {
	Mn_tavl_node_omp right_node = Mn_tavl_node_factory::create_omp( typeing::Memory_natural_nil );
	Mn_tavl_node_scoped scoped_right_node = Mn_tavl_node_scoped::create( right_node );
	Mn_tavl_node_omp the_node = Mn_tavl_node_factory::create_omp( typeing::Memory_natural_nil );
	Mn_tavl_node_scoped scoped_the_node = Mn_tavl_node_scoped::create( the_node );

	the_node->set_right_child( right_node );

	Cule_this( the_node->get_right_child() ).should_be_equal_to( right_node );
}


} // namespace noding
} // namespace structing
} // namespace jmsf
