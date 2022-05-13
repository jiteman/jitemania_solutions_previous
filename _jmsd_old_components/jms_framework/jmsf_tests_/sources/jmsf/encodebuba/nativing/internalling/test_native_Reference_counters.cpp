#include "jmsf/cule/macroses_Test.h"


#include "jmsf/encodebuba/nativing/internalling/native_Reference_counters.h"

#include "jmsf/encodebuba/nativing/native_Scoped.hin"
#include "jmsf/encodebuba/validating/excepting/exception_native_Should.h"


namespace jmsf {
namespace encodebuba {
namespace nativing {
namespace internalling {


native_Scoped< native_Reference_counters > create_scoped_native_reference_counters();


CULE_TEST( native_Reference_counters, should_not_have_nil_counters_after_creation ) {
	native_Scoped< native_Reference_counters > reference_counters = create_scoped_native_reference_counters();

	Cule_this_native( reference_counters->is_shared_counter_nil() ).should_not_be();
	Cule_this_native( reference_counters->is_total_counter_nil() ).should_not_be();
}

CULE_TEST( native_Reference_counters, should_have_nil_counters_after_decreasing_the_last_shared_counter_only ) {
	native_Scoped< native_Reference_counters > reference_counters = create_scoped_native_reference_counters();

	reference_counters->decrease_shared_counter();

	Cule_this_native( reference_counters->is_shared_counter_nil() ).should_be();
	Cule_this_native( reference_counters->is_total_counter_nil() ).should_be();
}

CULE_TEST( native_Reference_counters, should_have_no_nil_total_counter_after_increasing_weak_counter ) {
	native_Scoped< native_Reference_counters > reference_counters = create_scoped_native_reference_counters();

	reference_counters->increase_weak_counter();

	Cule_this_native( reference_counters->is_shared_counter_nil() ).should_not_be();
	Cule_this_native( reference_counters->is_total_counter_nil() ).should_not_be();
}

CULE_TEST( native_Reference_counters, should_have_total_counter_equal_to_sum_of_shared_and_weak_counters ) {
	native_Scoped< native_Reference_counters > reference_counters = create_scoped_native_reference_counters();

	reference_counters->increase_shared_counter();
	reference_counters->increase_shared_counter();
	reference_counters->increase_weak_counter();
	reference_counters->increase_weak_counter();
	reference_counters->increase_weak_counter();

	Cule_this_native( reference_counters->get_shared_counter() ).should_be_equal_to( 3 );
	Cule_this_native( reference_counters->get_total_counter() ).should_be_equal_to( 6 );
}

CULE_TEST_E(
	native_Reference_counters,
	should_not_decrease_shared_reference_counter_if_it_is_nil,
	::jmsf::encodebuba::validating::excepting::exception_native_Should )
{
	native_Scoped< native_Reference_counters > reference_counters = create_scoped_native_reference_counters();

	reference_counters->decrease_shared_counter();
	reference_counters->decrease_shared_counter();
}

CULE_TEST_E(
	native_Reference_counters,
	should_not_decrease_weak_reference_counter_if_it_is_nil,
	::jmsf::encodebuba::validating::excepting::exception_native_Should )
{
	native_Scoped< native_Reference_counters > reference_counters = create_scoped_native_reference_counters();

	reference_counters->decrease_weak_counter();
}

CULE_TEST_E(
	native_Reference_counters,
	should_not_increase_shared_reference_counter_if_it_is_nil,
	::jmsf::encodebuba::validating::excepting::exception_native_Should )
{
	native_Scoped< native_Reference_counters > reference_counters = create_scoped_native_reference_counters();

	reference_counters->decrease_shared_counter();
	reference_counters->increase_shared_counter();
}

CULE_TEST_E(
	native_Reference_counters,
	should_not_increase_weak_reference_counter_if_it_is_nil,
	::jmsf::encodebuba::validating::excepting::exception_native_Should )
{
	native_Scoped< native_Reference_counters > reference_counters = create_scoped_native_reference_counters();

	reference_counters->decrease_shared_counter();
	reference_counters->increase_weak_counter();
}

CULE_TEST( native_Reference_counters, should_increase_weak_reference_counter_if_it_is_not_nil_while_shared_counter_is_nil )
{
	native_Scoped< native_Reference_counters > reference_counters = create_scoped_native_reference_counters();

	reference_counters->increase_weak_counter();
	reference_counters->decrease_shared_counter();
	reference_counters->increase_weak_counter();
}


} // namespace internalling
} // namespace nativing
} // namespace encodebuba
} // namespace jmsf


namespace jmsf {
namespace encodebuba {
namespace nativing {
namespace internalling {


native_Scoped< native_Reference_counters > create_scoped_native_reference_counters() {
	return native_Scoped< native_Reference_counters >::create( native_Reference_counters::create_new() );
}


} // namespace internalling
} // namespace nativing
} // namespace encodebuba
} // namespace jmsf
