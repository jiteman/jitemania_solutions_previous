#pragma once

#include "native_Should.h"


#include "macroses_File_and_line.h"
#include "macroses_Type_name.h"
#include "jmsf/encodebuba/encodebuba_logging_flags_.h"


// Seinsei: todonext - transfer all call to Sould to macroses
#if defined( JMSF_ENCODEBUBA_VALIDATING_SHOULD_IS_UNCONDITIONAL )

	#define jmsf_native_Should_always_be( boolean_expression ) \
		::jmsf::encodebuba::validating::native_Should::always_be( ( boolean_expression ), JMSF_ENCODEBUBA_FILE_AND_LINE )

	#define jmsf_native_Should_always_be_with_type( boolean_expression, type ) \
		::jmsf::encodebuba::validating::native_Should::always_be( ( boolean_expression ), ( type ), JMSF_ENCODEBUBA_FILE_AND_LINE )

	#define jmsf_native_Should_never_be( boolean_expression ) \
		::jmsf::encodebuba::validating::native_Should::never_be( ( boolean_expression ), JMSF_ENCODEBUBA_FILE_AND_LINE )

	#define jmsf_native_Should_never_be_with_type( boolean_expression, type ) \
		::jmsf::encodebuba::validating::native_Should::never_be( ( boolean_expression ), ( type ), JMSF_ENCODEBUBA_FILE_AND_LINE )

	#define jmsf_native_Should_always_be_null_native_pointer( native_pointer ) \
		::jmsf::encodebuba::validating::native_Should::always_be_null_native_pointer( ( native_pointer ), JMSF_ENCODEBUBA_FILE_AND_LINE )

	#define jmsf_native_Should_always_be_null_native_pointer_with_type( native_pointer, type ) \
		::jmsf::encodebuba::validating::native_Should::always_be_null_native_pointer( ( native_pointer ), ( type ), JMSF_ENCODEBUBA_FILE_AND_LINE )

	#define jmsf_native_Should_never_be_null_native_pointer( native_pointer ) \
		::jmsf::encodebuba::validating::native_Should::never_be_null_native_pointer( ( native_pointer ), JMSF_ENCODEBUBA_FILE_AND_LINE )

	#define jmsf_native_Should_never_be_null_native_pointer_with_type( native_pointer, type ) \
		::jmsf::encodebuba::validating::native_Should::never_be_null_native_pointer( ( native_pointer ), ( type ), JMSF_ENCODEBUBA_FILE_AND_LINE )

	#define jmsf_native_Should_always_be_empty( some_jmsf_pointer ) \
		::jmsf::encodebuba::validating::native_Should::always_be_null( ( some_jmsf_pointer ), JMSF_ENCODEBUBA_FILE_AND_LINE )

	#define jmsf_native_Should_never_be_empty( some_jmsf_pointer ) \
		::jmsf::encodebuba::validating::native_Should::never_be_null( ( some_jmsf_pointer ), JMSF_ENCODEBUBA_FILE_AND_LINE )

#else // #if defined( JMSF_ENCODEBUBA_VALIDATING_SHOULD_IS_UNCONDITIONAL )

	#define jmsf_native_Should_always_be( boolean_expression ) \
		if ( ( boolean_expression ) ) { ::jmsf::encodebuba::validating::native_Should::always_be( ( boolean_expression ), JMSF_ENCODEBUBA_FILE_AND_LINE ); }

	#define jmsf_native_Should_always_be_with_type( boolean_expression, type ) \
		if ( ( boolean_expression ) ) { ::jmsf::encodebuba::validating::native_Should::always_be( ( boolean_expression ), ( type ), JMSF_ENCODEBUBA_FILE_AND_LINE ); }

	#define jmsf_native_Should_never_be( boolean_expression ) \
		if ( ( boolean_expression ) ) { ::jmsf::encodebuba::validating::native_Should::never_be( ( boolean_expression ), JMSF_ENCODEBUBA_FILE_AND_LINE ); }

	#define jmsf_native_Should_never_be_with_type( boolean_expression, type ) \
		if ( ( boolean_expression ) ) { ::jmsf::encodebuba::validating::native_Should::never_be( ( boolean_expression ), ( type ), JMSF_ENCODEBUBA_FILE_AND_LINE ); }

	#define jmsf_native_Should_always_be_null_native_pointer( native_pointer ) \
		if ( ( native_pointer ) != nullptr ) { ::jmsf::encodebuba::validating::native_Should::always_be_null_native_pointer( ( native_pointer ), JMSF_ENCODEBUBA_FILE_AND_LINE ); }

	#define jmsf_native_Should_always_be_null_native_pointer_with_type( native_pointer, type ) \
		if ( ( native_pointer ) != nullptr ) { ::jmsf::encodebuba::validating::native_Should::always_be_null_native_pointer( ( native_pointer ), ( type ), JMSF_ENCODEBUBA_FILE_AND_LINE ); }

	#define jmsf_native_Should_never_be_null_native_pointer( native_pointer ) \
		if ( ( native_pointer ) == nullptr ) { ::jmsf::encodebuba::validating::native_Should::never_be_null_native_pointer( ( native_pointer ), JMSF_ENCODEBUBA_FILE_AND_LINE ); }

	#define jmsf_native_Should_never_be_null_native_pointer_with_type( native_pointer, type ) \
		if ( ( native_pointer ) == nullptr ) { ::jmsf::encodebuba::validating::native_Should::never_be_null_native_pointer( ( native_pointer ), ( type ), JMSF_ENCODEBUBA_FILE_AND_LINE ); }

	#define jmsf_native_Should_always_be_empty( some_jmsf_pointer ) \
		if ( ( some_jmsf_pointer ).is_not_empty() ) { ::jmsf::encodebuba::validating::native_Should::always_be_null( ( some_jmsf_pointer ), JMSF_ENCODEBUBA_FILE_AND_LINE ); }

	#define jmsf_native_Should_never_be_empty( some_jmsf_pointer ) \
		if ( ( some_jmsf_pointer ).is_empty() ) { ::jmsf::encodebuba::validating::native_Should::never_be_null( ( some_jmsf_pointer ), JMSF_ENCODEBUBA_FILE_AND_LINE ); }

#endif // #if defined( JMSF_VALIDATING_SHOULD_IS_UNCONDITIONAL )


#define _jmsf_native_Should_never_reach_here( a_reason ) \
	::jmsf::encodebuba::validating::native_Should::never_reach_here_with_reason( ( a_reason ), JMSF_ENCODEBUBA_FILE_AND_LINE )

#define _jmsf_native_Should_never_reach_here_with_type( a_reason, type ) \
	::jmsf::encodebuba::validating::native_Should::never_reach_here_with_reason( ( a_reason ), ( type ), JMSF_ENCODEBUBA_FILE_AND_LINE )

#define _jmsf_native_Should_never_reach_here_void() \
	::jmsf::encodebuba::validating::native_Should::never_reach_here_void( JMSF_ENCODEBUBA_FILE_AND_LINE )

#define _jmsf_native_Should_never_reach_here_void_with_type( type ) \
	::jmsf::encodebuba::validating::native_Should::never_reach_here_void( ( type ), JMSF_ENCODEBUBA_FILE_AND_LINE )


#include "native_Should.hin"
