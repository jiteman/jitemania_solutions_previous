#include "jmsf/cule/macroses_Test.h"

#include "jmsf/algorithming/defaulting/default_Incomparator.hin"

#include "jmsf/testing/typeing/testing_Natural_values.hin"
#include "jmsf/testing/typeing/testing_Integer_values.hin"

#include "jmsf/testing/testing_Allocators.h"

#include "jmsf/memorying/Omp.hin"
#include "jmsf/memorying/Womp.hin"

#include "jmsf/typeing/Naturals.hin"
#include "jmsf/typeing/Integers.hin"
//#include "jmsf/typeing/Reals.hin"


namespace jmsf {
namespace typeing {
namespace comparing {


CULE_TEST_FIXTURE( default_Incomparator_for_naturals ),
	public ::jmsf::testing::typeing::testing_Natural_values< typeing::Memory_natural >
{

public:
	void set_up() override {
		comparator =
			algorithming::defaulting::default_Incomparator< typeing::Memory_natural >::create(
				testing::testing_Allocators::instance()->get_testing_object_allocator() );
	}

	void tear_down() override {
//		comparator->destroy( comparator );
		algorithming::Comparator< typeing::Memory_natural >::destroy( comparator );
	}

public:
	memorying::Omp< algorithming::Comparator< typeing::Memory_natural > > comparator;

};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Naturals
CULE_TEST_F( default_Incomparator_for_naturals, should_return_equal_result_if_values_are_equal ) {
	Cule_this( fx_.comparator->compare( fx_.natural_0, fx_.natural_0 ).is_equal() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.natural_3, fx_.natural_3 ).is_equal() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.natural_7, fx_.natural_7 ).is_equal() ).should_be();
}

CULE_TEST_F( default_Incomparator_for_naturals, should_return_less_result_if_first_value_is_greater_than_second_one ) {
	Cule_this( fx_.comparator->compare( fx_.natural_1, fx_.natural_0 ).is_less() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.natural_5, fx_.natural_3 ).is_less() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.natural_7, fx_.natural_6 ).is_less() ).should_be();
}

CULE_TEST_F( default_Incomparator_for_naturals, should_return_greater_result_if_first_value_is_less_than_second_one ) {
	Cule_this( fx_.comparator->compare( fx_.natural_0, fx_.natural_1 ).is_greater() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.natural_3, fx_.natural_5 ).is_greater() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.natural_6, fx_.natural_7 ).is_greater() ).should_be();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
CULE_TEST_FIXTURE( default_Incomparator_for_integers ),
	public ::jmsf::testing::typeing::testing_Integer_values< typeing::Memory_integer >
{

public:
	void set_up() override {
		comparator =
			algorithming::defaulting::default_Incomparator< typeing::Memory_integer >::create(
				testing::testing_Allocators::instance()->get_testing_object_allocator() );
	}

	void tear_down() override {
//		comparator->destroy( comparator );
		algorithming::Comparator< typeing::Memory_integer >::destroy( comparator );
	}

public:
	memorying::Omp< algorithming::Comparator< typeing::Memory_integer > > comparator;

};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Integers (positive)
CULE_TEST_F( default_Incomparator_for_integers, should_return_equal_result_if_values_are_equal ) {
	Cule_this( fx_.comparator->compare( fx_.integer_0, fx_.integer_0 ).is_equal() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_3, fx_.integer_3 ).is_equal() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_7, fx_.integer_7 ).is_equal() ).should_be();
}

CULE_TEST_F( default_Incomparator_for_integers, should_return_less_result_if_first_value_is_greater_than_second_one ) {
	Cule_this( fx_.comparator->compare( fx_.integer_1, fx_.integer_0 ).is_less() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_5, fx_.integer_3 ).is_less() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_7, fx_.integer_6 ).is_less() ).should_be();
}

CULE_TEST_F( default_Incomparator_for_integers, should_return_greater_result_if_first_value_is_less_than_second_one ) {
	Cule_this( fx_.comparator->compare( fx_.integer_0, fx_.integer_1 ).is_greater() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_3, fx_.integer_5 ).is_greater() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_6, fx_.integer_7 ).is_greater() ).should_be();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Integers (negative)
CULE_TEST_F( default_Incomparator_for_integers, should_return_equal_result_if_negative_values_are_equal ) {
	Cule_this( fx_.comparator->compare( fx_.integer_0, fx_.integer_0 ).is_equal() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_3m, fx_.integer_3m ).is_equal() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_7m, fx_.integer_7m ).is_equal() ).should_be();
}

CULE_TEST_F( default_Incomparator_for_integers, should_return_less_result_if_first_negative_value_is_greater_than_second_negative_one ) {
	Cule_this( fx_.comparator->compare( fx_.integer_0, fx_.integer_1m ).is_less() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_3m, fx_.integer_5m ).is_less() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_6m, fx_.integer_7m ).is_less() ).should_be();
}

CULE_TEST_F( default_Incomparator_for_integers, should_return_greater_result_if_first_negative_value_is_less_than_second_negative_one ) {
	Cule_this( fx_.comparator->compare( fx_.integer_1m, fx_.integer_0 ).is_greater() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_5m, fx_.integer_3m ).is_greater() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_7m, fx_.integer_6m ).is_greater() ).should_be();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Integers (positive and negative)
CULE_TEST_F( default_Incomparator_for_integers, should_return_less_result_if_first_value_is_positive_and_second_one_is_negative ) {
	Cule_this( fx_.comparator->compare( fx_.integer_1, fx_.integer_1m ).is_less() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_3, fx_.integer_3m ).is_less() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_6, fx_.integer_6m ).is_less() ).should_be();
}

CULE_TEST_F( default_Incomparator_for_integers, should_return_greater_result_if_first_value_is_negative_and_second_one_is_positive ) {
	Cule_this( fx_.comparator->compare( fx_.integer_1m, fx_.integer_1 ).is_greater() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_5m, fx_.integer_5 ).is_greater() ).should_be();
	Cule_this( fx_.comparator->compare( fx_.integer_7m, fx_.integer_7 ).is_greater() ).should_be();
}


} // namespace comparing
} // namespace typeing
} // namespace jmsf
