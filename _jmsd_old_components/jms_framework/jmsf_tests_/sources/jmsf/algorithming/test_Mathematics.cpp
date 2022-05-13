#include "jmsf/cule/macroses_Test.h"


#include "jmsf/algorithming/Mathematics.hin"


namespace jmsf {
namespace algorithming {


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// integers
CULE_TEST_FIXTURE( integer_Mathematics ) {

public:
	typeing::Memory_integer integer_2m = typeing::Memory_integer::create( -2 );
	typeing::Memory_integer integer_1m = typeing::Memory_integer::create( -1 );
	typeing::Memory_integer integer_0 = typeing::Memory_integer::create( 0 );
	typeing::Memory_integer integer_1 = typeing::Memory_integer::create( 1 );
	typeing::Memory_integer integer_2 = typeing::Memory_integer::create( 2 );
};

// absolute for integers
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( integer_Mathematics, should_return_zero_value_for_zero_argument ) {
	Cule_this( Mathematics::absolute( fx_.integer_0 ) ).should_be_equal_to( fx_.integer_0 );
}

CULE_TEST_F( integer_Mathematics, should_return_absolute_value_for_positive_argument ) {
	Cule_this( Mathematics::absolute( fx_.integer_1 ) ).should_be_equal_to( fx_.integer_1 );
	Cule_this( Mathematics::absolute( fx_.integer_2 ) ).should_be_equal_to( fx_.integer_2 );
}

CULE_TEST_F( integer_Mathematics, should_return_absolute_value_for_negative_argument ) {
	Cule_this( Mathematics::absolute( fx_.integer_1m ) ).should_be_equal_to( fx_.integer_1 );
	Cule_this( Mathematics::absolute( fx_.integer_2m ) ).should_be_equal_to( fx_.integer_2 );
}

// maximum for integers
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( integer_Mathematics, should_return_zero_value_for_both_zero_arguments ) {
	Cule_this( Mathematics::maximum( fx_.integer_0, fx_.integer_0 ) ).should_be_equal_to( fx_.integer_0 );
}

CULE_TEST_F( integer_Mathematics, should_return_maximum_of_two_positive_arguments ) {
	Cule_this( Mathematics::maximum( fx_.integer_0, fx_.integer_1 ) ).should_be_equal_to( fx_.integer_1 );
	Cule_this( Mathematics::maximum( fx_.integer_2, fx_.integer_0 ) ).should_be_equal_to( fx_.integer_2 );
	Cule_this( Mathematics::maximum( fx_.integer_1, fx_.integer_2 ) ).should_be_equal_to( fx_.integer_2 );
	Cule_this( Mathematics::maximum( fx_.integer_2, fx_.integer_1 ) ).should_be_equal_to( fx_.integer_2 );
}

CULE_TEST_F( integer_Mathematics, should_return_maximum_of_two_negative_arguments ) {
	Cule_this( Mathematics::maximum( fx_.integer_0, fx_.integer_1m ) ).should_be_equal_to( fx_.integer_0 );
	Cule_this( Mathematics::maximum( fx_.integer_2m, fx_.integer_0 ) ).should_be_equal_to( fx_.integer_0 );
	Cule_this( Mathematics::maximum( fx_.integer_1m, fx_.integer_2m ) ).should_be_equal_to( fx_.integer_1m );
	Cule_this( Mathematics::maximum( fx_.integer_2m, fx_.integer_1m ) ).should_be_equal_to( fx_.integer_1m );
}

CULE_TEST_F( integer_Mathematics, should_return_maximum_of_one_positive_and_one_negative_argument ) {
	Cule_this( Mathematics::maximum( fx_.integer_1, fx_.integer_2m ) ).should_be_equal_to( fx_.integer_1 );
	Cule_this( Mathematics::maximum( fx_.integer_2m, fx_.integer_1 ) ).should_be_equal_to( fx_.integer_1 );
	Cule_this( Mathematics::maximum( fx_.integer_1m, fx_.integer_2 ) ).should_be_equal_to( fx_.integer_2 );
	Cule_this( Mathematics::maximum( fx_.integer_2, fx_.integer_1m ) ).should_be_equal_to( fx_.integer_2 );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// naturals (no absolute)
CULE_TEST_FIXTURE( natural_Mathematics ) {

public:
	typeing::Memory_natural natural_0 = typeing::Memory_natural::create( 0 );
	typeing::Memory_natural natural_1 = typeing::Memory_natural::create( 1 );
	typeing::Memory_natural natural_2 = typeing::Memory_natural::create( 2 );
};

// maximum for naturals
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( natural_Mathematics, should_return_zero_value_for_both_zero_arguments ) {
	Cule_this( Mathematics::maximum( fx_.natural_0, fx_.natural_0 ) ).should_be_equal_to( fx_.natural_0 );
}

CULE_TEST_F( natural_Mathematics, should_return_maximum_of_two_arguments ) {
	Cule_this( Mathematics::maximum( fx_.natural_0, fx_.natural_1 ) ).should_be_equal_to( fx_.natural_1 );
	Cule_this( Mathematics::maximum( fx_.natural_2, fx_.natural_0 ) ).should_be_equal_to( fx_.natural_2 );
	Cule_this( Mathematics::maximum( fx_.natural_1, fx_.natural_2 ) ).should_be_equal_to( fx_.natural_2 );
	Cule_this( Mathematics::maximum( fx_.natural_2, fx_.natural_1 ) ).should_be_equal_to( fx_.natural_2 );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// reals
CULE_TEST_FIXTURE( real_Mathematics ) {

public:
	typeing::Real real_2m = typeing::Real::create( -2 );
	typeing::Real real_1m = typeing::Real::create( -1 );
	typeing::Real real_0 = typeing::Real::create( 0 );
	typeing::Real real_1 = typeing::Real::create( 1 );
	typeing::Real real_2 = typeing::Real::create( 2 );
};

// absolute for reals
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( real_Mathematics, should_return_absolute_value_for_zero_argument ) {
	Cule_this( Mathematics::absolute( fx_.real_0 ) ).should_be_equal_to( fx_.real_0 );
}

CULE_TEST_F( real_Mathematics, should_return_absolute_value_for_positive_argument ) {
	Cule_this( Mathematics::absolute( fx_.real_1 ) ).should_be_equal_to( fx_.real_1 );
	Cule_this( Mathematics::absolute( fx_.real_2 ) ).should_be_equal_to( fx_.real_2 );
}

CULE_TEST_F( real_Mathematics, should_return_absolute_value_for_negative_argument ) {
	Cule_this( Mathematics::absolute( fx_.real_1m ) ).should_be_equal_to( fx_.real_1 );
	Cule_this( Mathematics::absolute( fx_.real_2m ) ).should_be_equal_to( fx_.real_2 );
}

// maximum for reals
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
CULE_TEST_F( real_Mathematics, should_return_zero_value_for_both_zero_arguments ) {
	Cule_this( Mathematics::maximum( fx_.real_0, fx_.real_0 ) ).should_be_equal_to( fx_.real_0 );
}

CULE_TEST_F( real_Mathematics, should_return_maximum_of_two_positive_arguments ) {
	Cule_this( Mathematics::maximum( fx_.real_0, fx_.real_1 ) ).should_be_equal_to( fx_.real_1 );
	Cule_this( Mathematics::maximum( fx_.real_2, fx_.real_0 ) ).should_be_equal_to( fx_.real_2 );
	Cule_this( Mathematics::maximum( fx_.real_1, fx_.real_2 ) ).should_be_equal_to( fx_.real_2 );
	Cule_this( Mathematics::maximum( fx_.real_2, fx_.real_1 ) ).should_be_equal_to( fx_.real_2 );
}

CULE_TEST_F( real_Mathematics, should_return_maximum_of_two_negative_arguments ) {
	Cule_this( Mathematics::maximum( fx_.real_0, fx_.real_1m ) ).should_be_equal_to( fx_.real_0 );
	Cule_this( Mathematics::maximum( fx_.real_2m, fx_.real_0 ) ).should_be_equal_to( fx_.real_0 );
	Cule_this( Mathematics::maximum( fx_.real_1m, fx_.real_2m ) ).should_be_equal_to( fx_.real_1m );
	Cule_this( Mathematics::maximum( fx_.real_2m, fx_.real_1m ) ).should_be_equal_to( fx_.real_1m );
}

CULE_TEST_F( real_Mathematics, should_return_maximum_of_one_positive_and_one_negative_argument ) {
	Cule_this( Mathematics::maximum( fx_.real_1, fx_.real_2m ) ).should_be_equal_to( fx_.real_1 );
	Cule_this( Mathematics::maximum( fx_.real_2m, fx_.real_1 ) ).should_be_equal_to( fx_.real_1 );
	Cule_this( Mathematics::maximum( fx_.real_1m, fx_.real_2 ) ).should_be_equal_to( fx_.real_2 );
	Cule_this( Mathematics::maximum( fx_.real_2, fx_.real_1m ) ).should_be_equal_to( fx_.real_2 );
}


} // namespace algorithming
} // namespace jmsf
