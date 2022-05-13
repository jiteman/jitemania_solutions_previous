#include "jmsf/cule/macroses_Test.h"


#include "jmsf/typeing/Boolean.h"


namespace jmsf {


CULE_TEST( New_notation, should_be_true_false_correct ) {
	const typeing::Boolean true_value = typeing::True;
	const typeing::Boolean false_value = typeing::False;

	Cule_this( true_value ).should_not_be_equal_to( false_value );
}


} // namespace jmsf
