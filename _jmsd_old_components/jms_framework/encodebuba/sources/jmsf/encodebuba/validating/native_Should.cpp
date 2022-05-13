#include "native_Should.h"


#include "jmsf/encodebuba/validating/excepting/exception_native_Should.h"
#include "jmsf/encodebuba/validating/excepting/exception_native_Should_with_type_information.h"

#include <utility>


namespace jmsf {
namespace encodebuba {
namespace validating {


// static
void native_Should::always_be(
	const nativing::native_boolean an_expression_result,
	native_File_and_line &&a_file_and_line )
{
	if ( an_expression_result ) return;

	throw excepting::exception_native_Should( "native_Should::always_be( false )", ::std::move( a_file_and_line  ) );
}

// static
void native_Should::always_be(
	const nativing::native_boolean an_expression_result,
	const nativing::native_character *const a_type_name,
	native_File_and_line &&a_file_and_line )
{
	if ( an_expression_result ) return;

	throw excepting::exception_native_Should_with_type_information( "native_Should::always_be( false, type )", a_type_name, ::std::move( a_file_and_line  ) );
}

// static
void native_Should::never_be(
	const nativing::native_boolean an_expression_result,
	native_File_and_line &&a_file_and_line )
{
	if ( !an_expression_result ) return;

	throw excepting::exception_native_Should( "native_Should::never_be( true )", ::std::move( a_file_and_line  ) );
}

// static
void native_Should::never_be(
	const nativing::native_boolean an_expression_result,
	const nativing::native_character *const a_type_name,
	native_File_and_line &&a_file_and_line )
{
	if ( !an_expression_result ) return;

	throw excepting::exception_native_Should_with_type_information( "native_Should::never_be( true, type )", a_type_name, ::std::move( a_file_and_line  ) );
}

// static
void native_Should::always_be_null_native_pointer(
	const void *const a_native_pointer,
	native_File_and_line &&a_file_and_line )
{
	if ( a_native_pointer == nullptr ) return;

	throw excepting::exception_native_Should( "native_Should::always_be_null_native_pointer( !nullptr )", ::std::move( a_file_and_line  ) );
}

// static
void native_Should::always_be_null_native_pointer(
	const void *const a_native_pointer,
	const nativing::native_character *const a_type_name,
	native_File_and_line &&a_file_and_line )
{
	if ( a_native_pointer == nullptr ) return;

	throw excepting::exception_native_Should_with_type_information( "native_Should::always_be_null_native_pointer( !nullptr, type )", a_type_name, ::std::move( a_file_and_line  ) );
}

// static
void native_Should::never_be_null_native_pointer(
	const void *const a_native_pointer,
	native_File_and_line &&a_file_and_line )
{
	if ( a_native_pointer != nullptr ) return;

	throw excepting::exception_native_Should( "native_Should::never_be_null_native_pointer( nullptr )", ::std::move( a_file_and_line  ) );
}

// static
void native_Should::never_be_null_native_pointer(
	const void *const a_native_pointer,
	const nativing::native_character *const a_type_name,
	native_File_and_line &&a_file_and_line )
{
	if ( a_native_pointer != nullptr ) return;

	throw excepting::exception_native_Should_with_type_information( "native_Should::never_be_null_native_pointer( nullptr, type )", a_type_name, ::std::move( a_file_and_line  ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// static
void native_Should::never_reach_here_with_reason(
	const nativing::native_character *const a_reason,
	native_File_and_line &&a_file_and_line )
{
	throw excepting::exception_native_Should( a_reason, ::std::move( a_file_and_line  ) );
}

// static
void native_Should::never_reach_here_with_reason(
	const nativing::native_character *const a_reason,
	const nativing::native_character *const a_type_name,
	native_File_and_line &&a_file_and_line )
{
	throw excepting::exception_native_Should_with_type_information( a_reason, a_type_name, ::std::move( a_file_and_line  ) );
}

// static
void native_Should::never_reach_here_void( native_File_and_line &&a_file_and_line ) {
	throw excepting::exception_native_Should( "native_Should::never_reach_here_empty()", ::std::move( a_file_and_line  ) );
}

// static
void native_Should::never_reach_here_void(
	const nativing::native_character *const a_type_name,
	native_File_and_line &&a_file_and_line )
{
	throw excepting::exception_native_Should_with_type_information( "native_Should::never_reach_here_empty( type )", a_type_name, ::std::move( a_file_and_line  ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace validating
} // namespace encodebuba
} // namespace jmsf
