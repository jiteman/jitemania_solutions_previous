#include "Test_result_printer.h"


#include "jmsf/cule/resulting/Test_result_collection.h"
#include "jmsf/cule/user_interfacing/Ui_output.h"
#include "jmsf/cule/resulting/Test_fault.h"
#include "Test_failure_printer.h"

#include "jmsf/cule/cule_Allocators.h"

#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/String_literal.h"

//#include "jmsf/pointing/Pointer.hin"
//#include "jmsf/pointing/Constant_pointer.hin"

#include "jmsf/pointing/Weak.hin"
#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Womp.hin"

#include "jmsf/typeing/Boolean.h"


namespace jmsf {
namespace cule {
namespace printing {


void Test_result_printer::print() {
	if ( _test_result_collection.is_empty() ) return;

	const typeing::Boolean there_is_no_fault =
		typeing::Boolean::create( _test_result_collection->get_test_error_container().empty() ) &&
		typeing::Boolean::create( _test_result_collection->get_test_foreign_error_container().empty() ) &&
		typeing::Boolean::create( _test_result_collection->get_test_failure_container().empty() );

	if ( there_is_no_fault ) {
		_ui_output->print_no_fault();
	} else {
		memorying::Womp< texting::Ansii_allocating_assistor > aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();

		print_test_faults( _test_result_collection->get_test_foreign_error_container(), texting::Aaa_sl( aaa, FOREIGN_ERROR_NAME ) );
		print_test_faults( _test_result_collection->get_test_error_container(), texting::Aaa_sl( aaa, ERROR_NAME ) );
		print_test_faults( _test_result_collection->get_test_failure_container(), texting::Aaa_sl( aaa, FAILURE_NAME ) );
	}

	if ( !_test_result_collection->get_disabled_test_container().empty() ) {
		print_test_faults(
			_test_result_collection->get_disabled_test_container(),
			texting::Aaa_sl(
				cule_Allocators::instance()->get_ansii_allocating_assistor(),
				DISABLED_NAME ) );
	}

	_ui_output->print_blank_line();

	_ui_output->print_total_testing_duration(
		_test_result_collection->get_number_of_runned_tests(),
		_test_result_collection->get_total_testing_duration() );
}

Test_result_printer::~Test_result_printer()
{}

Test_result_printer::Test_result_printer(
	const pointing::Shared< user_interfaces::Ui_output > &ui_output,
	const pointing::cShared< resulting::Test_result_collection > &test_result_collection )
	:
		_ui_output( ui_output ),
		_test_result_collection( test_result_collection )
{}

Test_result_printer::Test_result_printer( const Test_result_printer &/*another*/ )
{}

const Test_result_printer &Test_result_printer::operator=( const Test_result_printer &another ) {
	if ( this == &another ) return *this;

	// copy
	return *this;
}

void Test_result_printer::print_test_faults( const ::std::vector< pointing::cShared< resulting::Test_fault > > &vector, const pointing::cShared< texting::Ansii_text > &name ) {
	if ( !vector.empty() ) {
		typeing::Memory_natural number = typeing::Memory_natural_one;

		_ui_output->print_blank_line();
		_ui_output->print_blank_line();

		pointing::Shared< Test_failure_printer > test_failure_printer =
			pointing::Shared< Test_failure_printer >::create(
				cule_Allocators::instance()->get_reference_counters_allocator(),
				memorying::Constructor< Test_failure_printer, Test_failure_printer >::construct(
					cule_Allocators::instance()->get_subsystem_allocator(),
					_ui_output ) );

		if ( name.is_not_empty() ) {
			_ui_output->print_test_failure_caption( typeing::Natural::create( static_cast< typeing::Natural::my_natural_integral_type >( vector.size() ) ), name );
		}

		for (
			auto test_fault_iterator = vector.begin();
			test_fault_iterator != vector.end();
			++test_fault_iterator )
		{
			_ui_output->print_blank_line();
			test_failure_printer->print_test_fault( number, *test_fault_iterator );
			number += typeing::Memory_natural_one;
		}
	}
}


} // namespace
}
}
