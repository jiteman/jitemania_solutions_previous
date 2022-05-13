#pragma once

#include "Should.h"


#include "macroses_File_and_line.h"
#include "jmsf/encodebuba/encodebuba_logging_flags_.h"


// Seinsei: todonext - transfer all call to Sould to macroses
#if defined( JMSF_VALIDATING_SHOULD_IS_UNCONDITIONAL )

	#define jmsf_Should_always_be( boolean_expression ) \
		::jmsf::validating::Should::always_be( ( boolean_expression ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_always_be_with_type( boolean_expression, type ) \
		::jmsf::validating::Should::always_be( ( boolean_expression ), ( type ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_never_be( boolean_expression ) \
		::jmsf::validating::Should::never_be( ( boolean_expression ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_never_be_with_type( boolean_expression, type ) \
		::jmsf::validating::Should::never_be( ( boolean_expression ), ( type ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_always_be_empty_native_pointer( native_pointer ) \
		::jmsf::validating::Should::always_be_null_native_pointer( ( native_pointer ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_always_be_empty_native_pointer_with_type( native_pointer, type ) \
		::jmsf::validating::Should::always_be_null_native_pointer( ( native_pointer ), ( type ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_never_be_empty_native_pointer( native_pointer ) \
		::jmsf::validating::Should::never_be_null_native_pointer( ( native_pointer ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_never_be_empty_native_pointer_with_type( native_pointer, type ) \
		::jmsf::validating::Should::never_be_null_native_pointer( ( native_pointer ), ( type ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_always_be_empty( some_jmsf_pointer ) \
		::jmsf::validating::Should::always_be_empty( ( some_jmsf_pointer ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_never_be_empty( some_jmsf_pointer ) \
		::jmsf::validating::Should::never_be_empty( ( some_jmsf_pointer ), JMSF_FILE_AND_LINE )

#else // #if defined( JMSF_VALIDATING_SHOULD_IS_UNCONDITIONAL )

	#define jmsf_Should_always_be( boolean_expression ) \
		if ( ( boolean_expression ) ) { ::jmsf::validating::Should::always_be( ( boolean_expression ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_always_be_with_type( boolean_expression, type ) \
		if ( ( boolean_expression ) ) { ::jmsf::validating::Should::always_be( ( boolean_expression ), ( type ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_never_be( boolean_expression ) \
		if ( ( boolean_expression ) ) { ::jmsf::validating::Should::never_be( ( boolean_expression ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_never_be_with_type( boolean_expression, type ) \
		if ( ( boolean_expression ) ) { ::jmsf::validating::Should::never_be( ( boolean_expression ), ( type ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_always_be_empty_native_pointer( native_pointer ) \
		if ( ( native_pointer ) != nullptr ) { ::jmsf::validating::Should::always_be_null_native_pointer( ( native_pointer ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_always_be_empty_native_pointer_with_type( native_pointer, type ) \
		if ( ( native_pointer ) != nullptr ) { ::jmsf::validating::Should::always_be_null_native_pointer( ( native_pointer ), ( type ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_never_be_empty_native_pointer( native_pointer ) \
		if ( ( native_pointer ) == nullptr ) { ::jmsf::validating::Should::never_be_null_native_pointer( ( native_pointer ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_never_be_empty_native_pointer_with_type( native_pointer, type ) \
		if ( ( native_pointer ) == nullptr ) { ::jmsf::validating::Should::never_be_null_native_pointer( ( native_pointer ), ( type ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_always_be_empty( some_jmsf_pointer ) \
		if ( ( some_jmsf_pointer ).is_not_empty() ) { ::jmsf::validating::Should::always_be_empty( ( some_jmsf_pointer ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_never_be_empty( some_jmsf_pointer ) \
		if ( ( some_jmsf_pointer ).is_empty() ) { ::jmsf::validating::Should::never_be_empty( ( some_jmsf_pointer ), JMSF_FILE_AND_LINE ); }

#endif // #if defined( JMSF_VALIDATING_SHOULD_IS_UNCONDITIONAL )


#define _jmsf_Should_never_reach_here( a_reason ) \
	::jmsf::validating::Should::never_reach_here_with_reason( ( a_reason ), JMSF_FILE_AND_LINE )

#define _jmsf_Should_never_reach_here_with_type( a_reason, type ) \
	::jmsf::validating::Should::never_reach_here_with_reason( ( a_reason ), ( type ), JMSF_FILE_AND_LINE )

#define _jmsf_Should_never_reach_here_void() \
	::jmsf::validating::Should::never_reach_here_void( JMSF_FILE_AND_LINE )

#define _jmsf_Should_never_reach_here_void_with_type( type ) \
	::jmsf::validating::Should::never_reach_here_void( ( type ), JMSF_FILE_AND_LINE )

#define _jmsf_Should_never_violate_copy_prohibition( a_place ) \
	::jmsf::validating::Should::never_violate_copy_prohibition_with_reason( ( a_place ), JMSF_FILE_AND_LINE )

#define _jmsf_Should_never_violate_copy_prohibition_with_type( a_place, type ) \
	::jmsf::validating::Should::never_violate_copy_prohibition_with_reason( ( a_place ), ( type ), JMSF_FILE_AND_LINE )

#define _jmsf_Should_never_violate_copy_prohibition_void() \
	::jmsf::validating::Should::never_violate_copy_prohibition_void( JMSF_FILE_AND_LINE )

#define _jmsf_Should_never_violate_copy_prohibition_void_with_type( type ) \
	::jmsf::validating::Should::never_violate_copy_prohibition_void( ( type ), JMSF_FILE_AND_LINE )



#include "Should.hin"
