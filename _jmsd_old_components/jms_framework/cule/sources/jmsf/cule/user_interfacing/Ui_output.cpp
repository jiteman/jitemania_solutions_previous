#include "Ui_output.h"


#include "jmsf/cule/cule_Allocators.h"

#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/String_literal.h"

#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Womp.hin"
#include "jmsf/typeing/Naturals.hin"

#include "jmsf/typeing/Reals.hin"


namespace jmsf {
namespace cule {
namespace user_interfaces {


const texting::String_literal Ui_output::TEST_START_INDICATOR = JMSF_SL( "." );
const texting::String_literal Ui_output::FAILURE_INDICATOR = JMSF_SL( "F\n" );
const texting::String_literal Ui_output::ERROR_INDICATOR = JMSF_SL( "E\n" );
const texting::String_literal Ui_output::UNKNOWN_ERROR_INDICATOR = JMSF_SL( "U\n" );
const texting::String_literal Ui_output::BLANK_LINE = JMSF_SL( "\n" );


Ui_output::~Ui_output() noexcept
{}

Ui_output::Ui_output() noexcept
{}

void Ui_output::indicate_testing_started() {
	print( JMSF_SL( "\nCpp Unit Lite Enchanced - [Cule] started\n" ) );
}

void Ui_output::indicate_test_start() {
	print( TEST_START_INDICATOR );
}

void Ui_output::indicate_failure() {
	print( FAILURE_INDICATOR );
}

void Ui_output::indicate_error() {
	print( ERROR_INDICATOR );
}

void Ui_output::indicate_unknown_error() {
	print( UNKNOWN_ERROR_INDICATOR );
}

void Ui_output::print_blank_line() {
	print( BLANK_LINE );
}

void Ui_output::print_test_failure_caption( const typeing::Natural quantity, const pointing::cShared< texting::Ansii_text > &name ) {
	memorying::Womp< texting::Ansii_allocating_assistor > aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();
	pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();

	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "There " ) ) );
	ansii_stream->put( texting::Aaa_sl( aaa, ( ( quantity > typeing::Natural_one ) ? JMSF_SL("were " ) : JMSF_SL( "was " ) ) ) );
	ansii_stream->put( quantity );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( " " ) ) );
	ansii_stream->put( name );

	if ( quantity > typeing::Natural_one ) {
		ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "s" ) ) );
	}

	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( ":\n" ) ) );
	print( texting::Aaa_cs( aaa, ansii_stream ) );
}

void Ui_output::print_test_failure(
	const typeing::Memory_natural number,
	const pointing::cShared< texting::Ansii_text > &file_and_line_summary,
	const pointing::cShared< texting::Ansii_text > &message )
{
	memorying::Womp< texting::Ansii_allocating_assistor > aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();
	pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();

	ansii_stream->put( number );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "> " ) ) );
	ansii_stream->put( file_and_line_summary );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( ": " ) ) );
	ansii_stream->put( message );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "\n" ) ) );
	print( texting::Aaa_cs( aaa, ansii_stream ) );
}


void Ui_output::print_no_fault() {
	print_blank_line();
	print_blank_line();
	print( texting::Aaa_sl( cule_Allocators::instance()->get_ansii_allocating_assistor(), JMSF_SL( "There were no test failures." ) ) );
	print_blank_line();
}

void Ui_output::print_total_testing_duration( const typeing::Natural quantity_of_runned_tests, const typeing::Natural duration_in_ms ) {
	const typeing::Short_real one_second = typeing::Short_real::create( 1000.0f );
	const typeing::Natural tests_per_test_case = typeing::Natural::create( 26 );
	const typeing::Short_real real_duration = typeing::Short_real::create( static_cast< float >( duration_in_ms.get_native_value() ) );
	const typeing::Boolean duration_is_longer_than_second = real_duration > one_second;
	const typeing::Short_real duration_to_print = duration_is_longer_than_second ? real_duration / one_second : real_duration;

	memorying::Womp< texting::Ansii_allocating_assistor > aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();
	pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();

	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "Runned: " ) ) );
	ansii_stream->put( quantity_of_runned_tests );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( " test" ) ) );

	if ( quantity_of_runned_tests > typeing::Natural_one ) {
		ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "s" ) ) );
	}

	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( ", execution time: " ) ) );
	ansii_stream->put( duration_to_print );
	ansii_stream->put( texting::Aaa_sl( aaa, ( ( duration_is_longer_than_second ) ? JMSF_SL(" seconds" ) : JMSF_SL(" milliseconds" ) ) ) );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "\n\n" ) ) );

	const typeing::Short_real tests_per_second =
		typeing::Short_real::create_from_natural( quantity_of_runned_tests ) *
		one_second /
		typeing::Short_real::create_from_natural( duration_in_ms );

	const typeing::Short_real test_case_per_second = tests_per_second / typeing::Short_real::create_from_natural( tests_per_test_case );

	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "Test execution rate is: " ) ) );
	ansii_stream->put( tests_per_second );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( " tests per second" ) ) );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "\n" ) ) );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "Test case execution rate for " ) ) );
	ansii_stream->put( tests_per_test_case );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( " tests per test case is: " ) ) );
	ansii_stream->put( test_case_per_second );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( " test cases per second" ) ) );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "\n\n" ) ) );

	print_blank_line();
	print( texting::Aaa_cs( aaa, ansii_stream ) );
}


} // namespace
}
}
