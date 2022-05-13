#include "Assert.hpp"


#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/pointing/Weak.hin"
#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Womp.hin"

#include "jmsf/cule/excepting/Test_fault_exception.h"
#include "jmsf/cule/cule_Allocators.h"


namespace jmsf {
namespace cule {
namespace asserting {
namespace deprecating {


// static
void Assert::this_is_not_implemented_yet( const texting::String_literal &message, const ::jmsf::validating::File_and_line &file_and_line, const texting::String_literal &type_name ) {
	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();

	pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "manual warning: " ) ) );
	ansii_stream->put( texting::Aaa_sl( aaa, message ) );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( " this " ) ) );
	ansii_stream->put( texting::Aaa_sl( aaa, type_name ) );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( " is not implemented yet" ) ) );

	throw_cule_exception( texting::Aaa_cs( aaa, ansii_stream ), file_and_line );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
void Assert::should_be( const typeing::Boolean actual, const ::jmsf::validating::File_and_line &file_and_line ) {
	if ( actual ) return;

	throw_cule_exception(
		texting::Aaa_sl( cule_Allocators::instance()->get_ansii_allocating_assistor(), JMSF_SL( "this is False, but it was expected to be True" ) ),
		file_and_line );
}

// static
void Assert::should_not_be( const typeing::Boolean actual, const ::jmsf::validating::File_and_line &file_and_line ) {
	if ( !actual ) return;

	throw_cule_exception(
		texting::Aaa_sl( cule_Allocators::instance()->get_ansii_allocating_assistor(), JMSF_SL( "this is True, but it was expected to be False" ) ),
		file_and_line );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
void Assert::pointers_should_be_equal( const void *expected_pointer, const void *actual_pointer, const ::jmsf::validating::File_and_line &file_and_line ) {
	if ( expected_pointer == actual_pointer ) return;

	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();
	pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();

	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "the actual pointer is: [" ) ) );
	ansii_stream->put( typeing::create_address_from_pointer( actual_pointer ), typeing::True );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "], but it was expected to be [" ) ) );
	ansii_stream->put( typeing::create_address_from_pointer( expected_pointer ), typeing::True );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "]" ) ) );

	throw_cule_exception( texting::Aaa_cs( aaa, ansii_stream ), file_and_line );
}

// static
void Assert::pointers_should_not_be_equal( const void *expected_pointer, const void *actual_pointer, const ::jmsf::validating::File_and_line &file_and_line ) {
	if ( expected_pointer != actual_pointer ) return;

	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();
	pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();

	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "the actual pointer is: [" ) ) );
	ansii_stream->put( typeing::create_address_from_pointer( actual_pointer ), typeing::True );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "], but it was expected to be different" ) ) );

	throw_cule_exception( texting::Aaa_cs( aaa, ansii_stream ), file_and_line );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
void Assert::ansii_texts_should_be_equal(
	const pointing::cShared< texting::Ansii_text > &expected_object,
	const pointing::cShared< texting::Ansii_text > &actual_object,
	const ::jmsf::validating::File_and_line &file_and_line )
{
	if ( *expected_object == *actual_object ) return;

	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();
	pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();

	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "the actual ansii text is: \"" ) ) );
	ansii_stream->put( actual_object );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "\", but it was expected to be equal to: \"" ) ) );
	ansii_stream->put( expected_object );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "\"" ) ) );

	throw_cule_exception( texting::Aaa_cs( aaa, ansii_stream ), file_and_line );
}

// static
void Assert::ansii_texts_should_not_be_equal(
	const pointing::cShared< texting::Ansii_text > &expected_object,
	const pointing::cShared< texting::Ansii_text > &actual_object,
	const ::jmsf::validating::File_and_line &file_and_line )
{
	if ( *expected_object != *actual_object ) return;

	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();
	pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();

	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "the actual ansii text is: \"" ) ) );
	ansii_stream->put( actual_object );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "\", but it was expected to be different" ) ) );

	throw_cule_exception( texting::Aaa_cs( aaa, ansii_stream ), file_and_line );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// static
void Assert::throw_cule_exception( const pointing::cShared< texting::Ansii_text > &message, const ::jmsf::validating::File_and_line &file_and_line ) {
	throw excepting::Test_fault_exception( message, file_and_line );
}

//// void Assert::real_shouldNotTakeLongerThan( const natural expectedDuration, const validating::File_and_line &file_and_line ) {
//// 	const natural duration = TestStopWatch::instance()->getLocalDuration();
////
//// 	if ( duration >= expectedDuration ) {
//// 		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
//// 		textStream->put( CONSTANT_TEXT_STRING( "expected duration less than: " ) )->putNatural( expectedDuration )->put( CONSTANT_TEXT_STRING( " ms" ) );
//// 		textStream->put( CONSTANT_TEXT_STRING( ", but was: " ) )->putNatural( duration )->put( CONSTANT_TEXT_STRING( " ms" ) );
//// 		free::Throw_cule_exception( textStream.getNonlinkedConstant(), lineNumber );
//// 	}
//// }

void Assert_throw_cule_exception( const pointing::cShared< texting::Ansii_text > &message, const ::jmsf::validating::File_and_line &file_and_line ) {
	Assert::throw_cule_exception( message, file_and_line );
}


} // namespace deprecating
} // namespace asserting
} // namespace cule
} // namespace jmsf
