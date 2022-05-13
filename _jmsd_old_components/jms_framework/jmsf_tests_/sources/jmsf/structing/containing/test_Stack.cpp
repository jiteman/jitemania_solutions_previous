#include "jmsf/cule/macroses_Test.h"


#include "jmsf/structing/containing/Stack.hin"


namespace jmsf {
namespace structing {
namespace containing {


CULE_TEST_FIXTURE( Stack ) {

public:
};


CULE_TEST( Stack, should_be_empty_after_creation ) {
	Stack< typeing::Memory_natural > empty_stack;

	Cule_this( empty_stack ).should_be_empty();
	Cule_this( empty_stack.get_quantity() ).should_be_equal_to( typeing::Memory_natural_nil );
}

CULE_TEST( Stack, should_be_empty_when_its_size_is_zero ) {
	Stack< typeing::Memory_natural > empty_stack;

	Cule_this( empty_stack ).should_be_empty();
	Cule_this( empty_stack.get_quantity() ).should_be_equal_to( typeing::Memory_natural_nil );
}

CULE_TEST( Stack, should_have_nill_quantity_when_after_creation ) {
	Stack< typeing::Memory_natural > empty_stack;

	Cule_this( empty_stack.get_quantity() ).should_be_equal_to( typeing::Memory_natural_nil );
}


} // namespace containing
} // namespace structing
} // namespace jmsf
