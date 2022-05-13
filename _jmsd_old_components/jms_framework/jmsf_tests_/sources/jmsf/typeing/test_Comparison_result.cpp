#include "jmsf/cule/macroses_Test.h"


#include "jmsf/typeing/Comparison_result.h"


namespace jmsf {
namespace typeing {


CULE_TEST( Comparison_result, should_be_empty_if_created_by_default ) {
	Cule_this( Comparison_result() ).should_be_empty();
}

CULE_TEST( Comparison_result, should_not_be_empty_if_not_created_by_default ) {
	Cule_this( Comparison_result::create_equal() ).should_not_be_empty();
	Cule_this( Comparison_result::create_greater() ).should_not_be_empty();
	Cule_this( Comparison_result::create_less() ).should_not_be_empty();
}

CULE_TEST( Comparison_result, should_not_return_any_true_if_empty ) {
	const Comparison_result empty;

	Cule_this( empty.is_equal() ).should_not_be();
	Cule_this( empty.is_not_equal() ).should_not_be();
	Cule_this( empty.is_greater() ).should_not_be();
	Cule_this( empty.is_not_greater() ).should_not_be();
	Cule_this( empty.is_less() ).should_not_be();
	Cule_this( empty.is_not_less() ).should_not_be();
}

CULE_TEST( Comparison_result, should_be_equal_if_created_as_equal ) {
	Comparison_result equal_result = Comparison_result::create_equal();

	Cule_this( equal_result ).should_not_be_empty();
	Cule_this( equal_result.is_equal() ).should_be();
	Cule_this( equal_result.is_not_equal() ).should_not_be();
}

CULE_TEST( Comparison_result, should_be_greater_if_created_as_greater ) {
	Comparison_result greater_result = Comparison_result::create_greater();

	Cule_this( greater_result ).should_not_be_empty();
	Cule_this( greater_result.is_greater() ).should_be();
	Cule_this( greater_result.is_not_greater() ).should_not_be();
}

CULE_TEST( Comparison_result, should_be_less_if_created_as_less ) {
	Comparison_result less_result = Comparison_result::create_less();

	Cule_this( less_result ).should_not_be_empty();
	Cule_this( less_result.is_less() ).should_be();
	Cule_this( less_result.is_not_less() ).should_not_be();
}

CULE_TEST( Comparison_result, should_be_neither_greater_nor_less_if_created_as_equal ) {
	Comparison_result equal_result = Comparison_result::create_equal();

	Cule_this( equal_result.is_greater() ).should_not_be();
	Cule_this( equal_result.is_less() ).should_not_be();
}

CULE_TEST( Comparison_result, should_be_neither_equal_nor_less_if_created_as_greater ) {
	Comparison_result greater_result = Comparison_result::create_greater();

	Cule_this( greater_result.is_equal() ).should_not_be();
	Cule_this( greater_result.is_less() ).should_not_be();
}

CULE_TEST( Comparison_result, should_be_neither_equal_nor_greater_if_created_as_less ) {
	Comparison_result less_result = Comparison_result::create_less();

	Cule_this( less_result.is_equal() ).should_not_be();
	Cule_this( less_result.is_greater() ).should_not_be();
}


} // namespace typeing
} // namespace jmsf
