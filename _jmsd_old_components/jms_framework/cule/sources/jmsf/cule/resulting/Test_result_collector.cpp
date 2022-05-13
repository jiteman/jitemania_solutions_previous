#include "Test_result_collector.h"


#include "jmsf/cule/user_interfacing/Ui_output.h"
#include "jmsf/cule/executing/Test_stop_watch.h"
#include "Test_result_collection.h"

#include "jmsf/patterning/Singleton.hin"

#include "jmsf/pointing/Weak.hin"
#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Destructor.hin"
#include "jmsf/memorying/Womp.hin"

#include "jmsf/validating/macroses_Should.h"


namespace jmsf {
namespace cule {
namespace resulting {


const pointing::cWeak< Test_result_collection > Test_result_collector::get_collected_results() const {
	if ( _test_result_collection.is_empty() ) return pointing::cWeak< Test_result_collection >();

	return _test_result_collection.get_as_cweak();
}

void Test_result_collector::testing_started() {
	jmsf_Should_never_be_empty( _ui_output );

	_ui_output->indicate_testing_started();
	executing::Test_stop_watch::instance()->start_global();
}

void Test_result_collector::testing_finished() {
	jmsf_Should_never_be_empty( _test_result_collection );

	_test_result_collection->set_total_testing_duration( executing::Test_stop_watch::instance()->get_global_duration() );
}

void Test_result_collector::one_more_test_running() {
	jmsf_Should_never_be_empty( _ui_output );
	jmsf_Should_never_be_empty( _test_result_collection );

	_test_result_collection->increase_test_counter();
	_ui_output->indicate_test_start();
}

void Test_result_collector::add_test_failure( const pointing::cShared< Test_fault > &test_fault ) {
	jmsf_Should_never_be_empty( _ui_output );
	jmsf_Should_never_be_empty( _test_result_collection );

	_test_result_collection->add_test_result_failure( test_fault );
	_ui_output->indicate_failure();
}

void Test_result_collector::add_test_error( const pointing::cShared< Test_fault > &test_fault ) {
	jmsf_Should_never_be_empty( _ui_output );
	jmsf_Should_never_be_empty( _test_result_collection );

	_test_result_collection->add_test_result_error( test_fault );
	_ui_output->indicate_error();
}

void Test_result_collector::add_test_foreign_error( const pointing::cShared< Test_fault > &test_fault ) {
	jmsf_Should_never_be_empty( _ui_output );
	jmsf_Should_never_be_empty( _test_result_collection );

	_test_result_collection->add_test_result_foreign_error( test_fault );
	_ui_output->indicate_error();
}

void Test_result_collector::add_disabled_test( const pointing::cShared< Test_fault > &disabled_test ) {
	jmsf_Should_never_be_empty( _test_result_collection );

	_test_result_collection->add_disabled_test( disabled_test );
}

Test_result_collector::~Test_result_collector()
{}

Test_result_collector::Test_result_collector(
	const pointing::Shared< user_interfaces::Ui_output > &ui_output,
	const pointing::Shared< Test_result_collection > &new_test_result_collection ) noexcept
	:
		_ui_output( ui_output ),
		_test_result_collection( new_test_result_collection )
{}

pointing::Shared< Test_result_collector > Test_result_collector::create(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &test_result_collector_allocator,
		const pointing::Shared< user_interfaces::Ui_output > &ui_output,
		const pointing::Shared< Test_result_collection > &test_result_collection )
{
	jmsf_Should_never_be_empty( reference_counters_allocator );
	jmsf_Should_never_be_empty( test_result_collector_allocator );
	jmsf_Should_never_be_empty( ui_output );
	jmsf_Should_never_be_empty( test_result_collection );

	return
		pointing::Shared< Test_result_collector >::create(
			reference_counters_allocator,
			memorying::Constructor< Test_result_collector, Test_result_collector >::construct(
				test_result_collector_allocator,
				ui_output,
				test_result_collection ) );
}

Test_result_collector::Test_result_collector( const Test_result_collector &/*another*/ )
{}

const Test_result_collector &Test_result_collector::operator=( const Test_result_collector &another ) {
	if ( this == &another ) return *this;

	// copy
	return *this;
}


} // namespace
}
}
