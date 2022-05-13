#include "Test_failure_printer.h"


#include "jmsf/cule/user_interfacing/Ui_output.h"
#include "jmsf/cule/resulting/Test_fault.h"

#include "jmsf/cule/cule_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"


// #include "jmsf/validating/macroses_Should.h"
#include "jmsf/validating/Exception_information.h"
#include "jmsf/validating/Exception_information_summarizer.h"


namespace jmsf {
namespace cule {
namespace printing {


Test_failure_printer::~Test_failure_printer() {
}

Test_failure_printer::Test_failure_printer( const pointing::Shared< user_interfaces::Ui_output > &ui_output )
	:
		_ui_output( ui_output )
{}

void Test_failure_printer::print_test_fault( const typeing::Memory_natural number, const pointing::cShared< resulting::Test_fault > &test_fault ) {
	print_test_failure_information( number, test_fault );

	if ( test_fault->get_exception_information().is_empty() ) return;

	const pointing::cShared< validating::Exception_information > exception_information =
		test_fault->get_exception_information().get_as_cshared();

	print_main_exception_information( number, exception_information );
	print_detailed_description( number, exception_information );
	print_type_information( number, exception_information );
	print_exception_hierarchy( number, exception_information );
}

void Test_failure_printer::print_test_failure_information(
	const typeing::Memory_natural number,
	const pointing::cShared< resulting::Test_fault > &test_fault )
{
	_ui_output->print_test_failure(
		number,
		validating::Exception_information_summarizer::create_file_and_line_summary(
			cule_Allocators::instance()->get_ansii_allocating_assistor(),
			test_fault->get_test_file_name().get_as_cshared(),
			test_fault->get_test_line_number() ),
		test_fault->get_test_name().get_as_cshared() );
}

void Test_failure_printer::print_main_exception_information(
	const typeing::Memory_natural number,
	const pointing::cShared< validating::Exception_information > &exception_information )
{
	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();
	const validating::Exception_information_summarizer eis( exception_information );

	_ui_output->print_test_failure(
		number,
		eis.get_file_and_line_summary( aaa ),
		eis.get_reason_description_summary( aaa ) );
}

void Test_failure_printer::print_detailed_description(
	const typeing::Memory_natural number,
	const pointing::cShared< validating::Exception_information > &exception_information )
{
	if ( exception_information->get_detailed_description().is_empty() ) return;

	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();
	const validating::Exception_information_summarizer eis( exception_information );

	_ui_output->print_test_failure(
		number,
		eis.get_file_and_line_summary( aaa ),
		eis.get_detailed_description_summary( aaa ) );
}

void Test_failure_printer::print_type_information(
	const typeing::Memory_natural number,
	const pointing::cShared< validating::Exception_information > &exception_information )
{
	if ( exception_information->get_type_information().is_empty() ) return;

	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();
	const validating::Exception_information_summarizer eis( exception_information );

	_ui_output->print_test_failure(
		number,
		eis.get_file_and_line_summary( aaa ),
		eis.get_type_information_summary( aaa ) );
}

void Test_failure_printer::print_exception_hierarchy(
	const typeing::Memory_natural number,
	const pointing::cShared< validating::Exception_information > &exception_information )
{
	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();
	const validating::Exception_information_summarizer eis( exception_information );

	_ui_output->print_test_failure(
		number,
		eis.get_file_and_line_summary( aaa ),
		eis.get_exception_hierarchy_summary( aaa ) );
}


} // namespace
}
}
