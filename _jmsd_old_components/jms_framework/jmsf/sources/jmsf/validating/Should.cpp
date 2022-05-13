#include "Should.h"


#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/String_literal.h"
#include "File_and_line.h"

//#include "jmsf/pointing/Proxy.hxx"
//#include "jmsf/pointing/Constant_proxy.hxx"
//#include "jmsf/pointing/Pointer.hin"
//#include "jmsf/pointing/Constant_pointer.hin"

#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

//#include "jmsf/memorying/Awamp.hxx"
//#include "jmsf/memorying/Wamp.hxx"
//#include "jmsf/memorying/Amp.hxx"
//#include "jmsf/memorying/Owomp.hxx"
#include "jmsf/patterning/Singleton.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/typeing/Boolean.h"


#include "jmsf/jmsf_Allocators.h"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Allocator.h"

#include "excepting/exception_Should.h"
#include "excepting/exception_Should_with_type_information.h"
//#include "jmsf/typeing/Ansii_string_stream.h"
//

#include "jmsf/jmsf_logging_macroses.h"


namespace jmsf {
namespace validating {


void Should::always_be( const typeing::Boolean expression_result, const File_and_line &file_and_line ) {
	if ( expression_result.inversion() ) {
		JMSF_PRE_ERROR_LOG_OUTPUT( "Should::always_be" );

		throw_exception(
			JMSF_SL( "Should::always_be( false )" ),
			file_and_line );
	}
}

void Should::always_be( const typeing::Boolean expression_result, const char *const type_name, const File_and_line &file_and_line ) {
	if ( expression_result.inversion() ) {
		JMSF_PRE_ERROR_LOG_OUTPUT_TYPED( "Should::always_be", type_name );

		throw_exception_with_type(
			JMSF_SL( "expression is false" ),
			JMSF_SL( "Should::always_be( boolean expression )" ),
			JMSF_SL( type_name ),
			file_and_line );
	}
}

void Should::never_be( const typeing::Boolean expression_result, const File_and_line &file_and_line ) {
	if ( expression_result ) {
		JMSF_PRE_ERROR_LOG_OUTPUT( "Should::never_be" );

		throw_exception(
			JMSF_SL( "Should::never_be( true )" ),
			file_and_line );
	}
}

void Should::never_be( const typeing::Boolean expression_result, const char *const type_name, const File_and_line &file_and_line ) {
	if ( expression_result ) {
		JMSF_PRE_ERROR_LOG_OUTPUT_TYPED( "Should::never_be", type_name );

		throw_exception_with_type(
			JMSF_SL( "expression is true" ),
			JMSF_SL( "Should::never_be( boolean expression )" ),
			JMSF_SL( type_name ),
			file_and_line );
	}
}

void Should::always_be_null_native_pointer( const void *const native_pointer, const File_and_line &file_and_line ) {
	if ( native_pointer != nullptr ) {
		JMSF_PRE_ERROR_LOG_OUTPUT( "Should::always_be_null_native_pointer" );

		throw_exception(
			JMSF_SL( "Should::always_be_null_native_pointer( not nullptr )" ),
			file_and_line );
	}
}

void Should::always_be_null_native_pointer( const void *const native_pointer, const char *const type_name, const File_and_line &file_and_line ) {
	if ( native_pointer != nullptr ) {
		JMSF_PRE_ERROR_LOG_OUTPUT_TYPED( "Should::always_be_null_native_pointer", type_name );

		throw_exception_with_type(
			JMSF_SL( "pointer is not null" ),
			JMSF_SL( "Should::always_be_null_native_pointer( pointer )" ),
			JMSF_SL( type_name ),
			file_and_line );
	}
}

void Should::never_be_null_native_pointer( const void *const native_pointer, const File_and_line &file_and_line ) {
	if ( native_pointer == nullptr ) {
		JMSF_PRE_ERROR_LOG_OUTPUT( "Should::never_be_null_native_pointer" );

		throw_exception(
			JMSF_SL( "Should::never_be_null_native_pointer( nullptr )" ),
			file_and_line );
	}
}

void Should::never_be_null_native_pointer( const void *const native_pointer, const char *const type_name, const File_and_line &file_and_line ) {
	if ( native_pointer == nullptr ) {
		JMSF_PRE_ERROR_LOG_OUTPUT_TYPED( "Should::never_be_null_native_pointer", type_name );

		throw_exception_with_type(
			JMSF_SL( "pointer is null" ),
			JMSF_SL( "Should::never_be_null_native_pointer( nullptr )" ),
			JMSF_SL( type_name ),
			file_and_line );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Should::never_reach_here_with_reason( const typeing::internals::platform_character *reason, const File_and_line &file_and_line ) {
	JMSF_PRE_ERROR_LOG_OUTPUT( "Should::neverReachHere_with_reason()" );

	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = jmsf_Allocators::instance()->get_ansii_allocating_assistor();
	pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "Should::neverReachHere_with_reason() - " ) ) );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( reason ) ) );

	throw_exception(
		texting::Aaa_cs( aaa, ansii_stream ),
		file_and_line );
}

// static
void Should::never_reach_here_with_reason( const typeing::internals::platform_character *reason, const char *const type_name, const File_and_line &file_and_line ) {
	JMSF_PRE_ERROR_LOG_OUTPUT_TYPED( "Should::neverReachHere_with_reason()", type_name );

	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = jmsf_Allocators::instance()->get_ansii_allocating_assistor();
	pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "Should::neverReachHere_with_reason() - " ) ) );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( reason ) ) );

	throw_exception_with_type(
		texting::Aaa_sl( aaa, JMSF_SL( "undesired code reached" ) ),
		texting::Aaa_cs( aaa, ansii_stream ),
		texting::Aaa_sl( aaa, JMSF_SL( type_name ) ),
		file_and_line );
}

// static
void Should::never_reach_here_void( const File_and_line &file_and_line ) {
	JMSF_PRE_ERROR_LOG_OUTPUT( "Should::never_reach_here_empty()" );

	throw_exception(
		JMSF_SL( "Should::never_reach_here_empty()" ),
		file_and_line );
}

// static
void Should::never_reach_here_void( const char *const type_name, const File_and_line &file_and_line ) {
	JMSF_PRE_ERROR_LOG_OUTPUT_TYPED( "Should::never_reach_here_empty()", type_name );

	throw_exception_with_type(
		JMSF_SL( "undesired code reached" ),
		JMSF_SL( "Should::never_reach_here_empty()" ),
		JMSF_SL( type_name ),
		file_and_line );
}

void Should::never_violate_copy_prohibition_with_reason( const typeing::internals::platform_character *place, const File_and_line &file_and_line ) {
	JMSF_PRE_ERROR_LOG_OUTPUT( "Should::never_violate_copy_prohibition_with_reason()" );

	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = jmsf_Allocators::instance()->get_ansii_allocating_assistor();
	pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "Should::never_violate_copy_prohibition_with_reason() - " ) ) );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( place ) ) );

	throw_exception(
		texting::Aaa_cs( aaa, ansii_stream ),
		file_and_line );
}

void Should::never_violate_copy_prohibition_with_reason( const typeing::internals::platform_character *place, const char *const type_name, const File_and_line &file_and_line ) {
	JMSF_PRE_ERROR_LOG_OUTPUT_TYPED( "Should::never_violate_copy_prohibition()", type_name );

	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = jmsf_Allocators::instance()->get_ansii_allocating_assistor();
	pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( "Should::never_violate_copy_prohibition_with_reason() - " ) ) );
	ansii_stream->put( texting::Aaa_sl( aaa, JMSF_SL( place ) ) );

	throw_exception_with_type(
		texting::Aaa_sl( aaa, JMSF_SL( "copy prohibition violated" ) ),
		texting::Aaa_cs( aaa, ansii_stream ),
		texting::Aaa_sl( aaa, JMSF_SL( type_name ) ),
		file_and_line );
}

void Should::never_violate_copy_prohibition_void( const File_and_line &file_and_line ) {
	JMSF_PRE_ERROR_LOG_OUTPUT( "Should::never_violate_copy_prohibition_empty()" );

	throw_exception(
		JMSF_SL( "Should::never_violate_copy_prohibition_empty()" ),
		file_and_line );
}

void Should::never_violate_copy_prohibition_void( const char *const type_name, const File_and_line &file_and_line ) {
	JMSF_PRE_ERROR_LOG_OUTPUT_TYPED( "Should::never_violate_copy_prohibition_empty()", type_name );

	throw_exception_with_type(
		JMSF_SL( "copy prohibition violated" ),
		JMSF_SL( "Should::never_violate_copy_prohibition_empty()" ),
		JMSF_SL( type_name ),
		file_and_line );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Should::~Should() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Should::Should() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Should::Should( const Should & ) noexcept // other
{}

const Should &Should::operator =( const Should &other ) noexcept {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
void Should::throw_exception(
	const pointing::cShared< texting::Ansii_text > &ansii_text_reason,
	const File_and_line &file_and_line )
{
	throw
		excepting::exception_Should(
			ansii_text_reason,
			file_and_line );
}

// static
void Should::throw_exception(
	const texting::String_literal &string_literal_reason,
	const File_and_line &file_and_line )
{
	throw_exception(
		texting::Aaa_sl( jmsf_Allocators::instance()->get_ansii_allocating_assistor(), string_literal_reason ),
		file_and_line );
}

// static
void Should::throw_exception_with_type(
	const pointing::cShared< texting::Ansii_text > &ansii_text_reason,
	const pointing::cShared< texting::Ansii_text > &ansii_text_detailed_description,
	const pointing::cShared< texting::Ansii_text > &ansii_text_type_information,
	const File_and_line &file_and_line )
{
	throw
		excepting::exception_Should_with_type_information(
			ansii_text_reason,
			ansii_text_detailed_description,
			ansii_text_type_information,
			file_and_line );
}

// static
void Should::throw_exception_with_type(
	const texting::String_literal &string_literal_reason,
	const texting::String_literal &string_literal_detailed_description,
	const texting::String_literal &string_literal_type_information,
	const File_and_line &file_and_line )
{
	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = jmsf_Allocators::instance()->get_ansii_allocating_assistor();

	throw_exception_with_type(
		texting::Aaa_sl( aaa, string_literal_reason ),
		texting::Aaa_sl( aaa, string_literal_detailed_description ),
		texting::Aaa_sl( aaa, string_literal_type_information ),
		file_and_line );
}


} // namespace validating
} // namespace jmsf
