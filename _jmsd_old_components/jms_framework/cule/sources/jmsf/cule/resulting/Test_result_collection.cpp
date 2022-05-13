#include "Test_result_collection.h"


#include "Test_fault.h"

#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Womp.hin"


namespace jmsf {
namespace cule {
namespace resulting {


const ::std::vector< pointing::cShared< Test_fault > > &Test_result_collection::get_test_failure_container() const {
	return _test_failures;
}

const ::std::vector< pointing::cShared< Test_fault > > &Test_result_collection::get_test_error_container() const {
	return _test_errors;
}

const ::std::vector< pointing::cShared< Test_fault > > &Test_result_collection::get_test_foreign_error_container() const {
	return _test_foreign_errors;
}

const ::std::vector< pointing::cShared< Test_fault > > &Test_result_collection::get_disabled_test_container() const {
	return _disabled_tests;
}

typeing::Natural Test_result_collection::get_total_testing_duration() const noexcept {
	return _totalTestingDuration;
}

typeing::Natural Test_result_collection::get_number_of_runned_tests() const noexcept {
	return _numberOfRunnedTests;
}

typeing::Natural Test_result_collection::get_number_of_disabled_tests() const noexcept {
	return _number_of_disabled_tests;
}

void Test_result_collection::add_test() {
	_numberOfRunnedTests += typeing::Natural_one;
}

void Test_result_collection::increase_test_counter() {
	++_numberOfRunnedTests;
}

void Test_result_collection::add_test_result_failure( const pointing::cShared< Test_fault > &test_fault ) {
	_test_failures.push_back( test_fault );
}

void Test_result_collection::add_test_result_error( const pointing::cShared< Test_fault > &test_fault ) {
	_test_errors.push_back( test_fault );
}

void Test_result_collection::add_test_result_foreign_error( const pointing::cShared< Test_fault > &test_fault ) {
	_test_foreign_errors.push_back( test_fault );
}

void Test_result_collection::add_disabled_test( const pointing::cShared< Test_fault > &disabled_test ) {
	_disabled_tests.push_back( disabled_test );
}

void Test_result_collection::set_total_testing_duration( typeing::Natural total_test_duration_in_ms ) {
	_totalTestingDuration = total_test_duration_in_ms;
}

Test_result_collection::~Test_result_collection()
{}

Test_result_collection::Test_result_collection() {
	_numberOfRunnedTests = typeing::Natural_nil;
}

// static
pointing::Shared< Test_result_collection > Test_result_collection::create(
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &test_result_collection_allocator )
{
	return
		pointing::Shared< resulting::Test_result_collection >::create(
			reference_counters_allocator,
			memorying::Constructor< resulting::Test_result_collection, resulting::Test_result_collection >::construct(
				test_result_collection_allocator ) );
}

Test_result_collection::Test_result_collection( const Test_result_collection &/*another*/ )
{}

const Test_result_collection &Test_result_collection::operator=( const Test_result_collection &another ) {
	if ( this == &another ) return *this;

	// copy
	return *this;
}


} // namespace
}
}
