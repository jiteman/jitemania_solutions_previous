#include "jmsf/cule/macroses_Test.h"


#include "jmsf/structing/traversing/Tavl_traverser.hin" // what to test

#include "jmsf/typeing/Naturals.hin"


namespace jmsf {
namespace structing {
namespace traversing {


CULE_TEST( jmsf_Template, should_create_empty ) {
	Tavl_traverser< typeing::Memory_natural > empty_tavl_traverser;

	this_object_should_be_empty( empty_tavl_traverser );
}

CULE_TEST( jmsf_Template, should_delete_empty ) {
	{
		Tavl_traverser< typeing::Memory_natural > empty_tavl_traverser;
	}
}


} // namespace traversing
} // namespace structing
} // namespace jmsf
