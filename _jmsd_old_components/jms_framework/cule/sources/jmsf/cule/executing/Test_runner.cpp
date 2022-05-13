#include "Test_runner.h"


#include "jmsf/cule/testing/Test.h"
#include "jmsf/cule/resulting/Test_result_collector.h"
#include "jmsf/cule/resulting/Test_result_collection.h"
#include "jmsf/cule/resulting/Test_fault.h"
#include "jmsf/cule/user_interfacing/Ui_output.h"
#include "jmsf/cule/registering/Test_registry.h"
#include "Single_test_runner.h"
#include "jmsf/cule/printing/Test_result_printer.h"

#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/Native_C_string.h"
#include "jmsf/texting/String_literal.h"

#include "jmsf/pointing/Weak.hin"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"
#include "jmsf/pointing/cNonlinked.hin"

#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Constructor.hin"
#include "jmsf/cule/cule_Allocators.h"
#include "jmsf/memorying/Omp.hin"

#include "jmsf/validating/Exception_information.h"


namespace jmsf {
namespace cule {
namespace executing {


Test_runner::~Test_runner()
{}

//TestRunner::TestRunner( const pointing::Pointer< user_interfaces::UiOutput > &uiOutput )
Test_runner::Test_runner( const pointing::Shared< user_interfaces::Ui_output > &uiOutput )
	:
		_uiOutput( uiOutput )
{}

void Test_runner::run() {
	pointing::Shared< resulting::Test_result_collector > test_fault_collector =
		resulting::Test_result_collector::create(
			cule_Allocators::instance()->get_reference_counters_allocator(),
			cule_Allocators::instance()->get_subsystem_allocator(),
			_uiOutput,
			resulting::Test_result_collection::create(
				cule_Allocators::instance()->get_reference_counters_allocator(),
				cule_Allocators::instance()->get_subsystem_allocator() ) );

	{
		const ::std::vector< pointing::cNonlinked< testing::Test > > &disabled_tests = testing::Test::get_test_registry().get_registered_disabled_tests();

		for (
			auto disabled_test_iterator = disabled_tests.begin();
			disabled_test_iterator != disabled_tests.end();
			++disabled_test_iterator )
		{
			test_fault_collector->add_disabled_test(
				resulting::Test_fault::create(
					cule_Allocators::instance()->get_reference_counters_allocator(),
					cule_Allocators::instance()->get_subsystem_allocator(),
					*disabled_test_iterator,
					pointing::cShared< ::jmsf::validating::Exception_information >() ) );
		}
	}

	const ::std::vector< pointing::cNonlinked< testing::Test > > &registered_tests = testing::Test::get_test_registry().get_registered_tests();
	test_fault_collector->testing_started();

	for (
//		::std::vector< pointing::cNonlinked< testing::Test > >::const_iterator test_iterator = registered_tests.begin();
		auto test_iterator = registered_tests.begin();
		test_iterator != registered_tests.end();
		++test_iterator )
	{
		Single_rest_runner( test_fault_collector, *test_iterator ).run_the_test();
	}

	test_fault_collector->testing_finished();

	if ( test_fault_collector->get_collected_results().is_not_empty() ) {
		new_print( test_fault_collector->get_collected_results().get_as_cshared() );
	}
}

void Test_runner::new_print( const pointing::cShared< resulting::Test_result_collection > &testResult ) {
	pointing::Shared< printing::Test_result_printer >::create(
		cule_Allocators::instance()->get_reference_counters_allocator(),
		memorying::Constructor< printing::Test_result_printer, printing::Test_result_printer >::construct(
			cule_Allocators::instance()->get_subsystem_allocator(),
			_uiOutput,
			testResult ) )->print();

}


} // namespace
}
}
