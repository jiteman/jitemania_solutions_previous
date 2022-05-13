#pragma once

#include "native_Should.hxx"


#include "jmsf/encodebuba/nativing/native_types.h"

#include "native_File_and_line.hxx"

#include "jmsf/encodebuba/encodebuba.h"


namespace jmsf {
namespace encodebuba {
namespace validating {


// Seinsei: todonext - rename null to empty for always_be and never_be (except pointers)
// Seinsei: todonext - or to empty
class JMSF_ENCODEBUBA_SHARED_INTERFACE native_Should {

public:
	static void always_be( nativing::native_boolean an_expression_result, native_File_and_line &&a_file_and_line );
	static void always_be( nativing::native_boolean an_expression_result, const nativing::native_character *a_type_name, native_File_and_line &&a_file_and_line );
	static void never_be( nativing::native_boolean an_expression_result, native_File_and_line &&a_file_and_line );
	static void never_be( nativing::native_boolean an_expression_result, const nativing::native_character *a_type_name, native_File_and_line &&a_file_and_line );

	static void always_be_null_native_pointer( const void *a_native_pointer, native_File_and_line &&a_file_and_line );
	static void always_be_null_native_pointer( const void *a_native_pointer, const nativing::native_character *a_type_name, native_File_and_line &&a_file_and_line );
	static void never_be_null_native_pointer( const void *a_native_pointer, native_File_and_line &&a_file_and_line );
	static void never_be_null_native_pointer( const void *a_native_pointer, const nativing::native_character *a_type_name, native_File_and_line &&a_file_and_line );

//	template< class A_type >
//	static void always_be_empty( const memorying::Object_pointer< A_type > &an_object_pointer, const File_and_line &file_and_line );
//	template< class A_type >
//	static void never_be_empty( const memorying::Object_pointer< A_type > &an_object_pointer, const File_and_line &file_and_line );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	static void never_reach_here_with_reason( const nativing::native_character *a_reason, native_File_and_line &&a_file_and_line );
	static void never_reach_here_with_reason( const nativing::native_character *a_reason, const nativing::native_character *a_type_name, native_File_and_line &&a_file_and_line );
	static void never_reach_here_void( native_File_and_line &&a_file_and_line );
	static void never_reach_here_void( const nativing::native_character *a_type_name, native_File_and_line &&a_file_and_line );
//	static void never_violate_copy_prohibition_with_reason( const typeing::internals::platform_character *place, const File_and_line &file_and_line );
//	static void never_violate_copy_prohibition_with_reason( const typeing::internals::platform_character *place, const char *type_name, const File_and_line &file_and_line );
//	static void never_violate_copy_prohibition_empty( const File_and_line &file_and_line );
//	static void never_violate_copy_prohibition_empty( const char *type_name, const File_and_line &file_and_line );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~native_Should() noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	native_Should() noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	native_Should( const native_Should &other ) noexcept = delete;
	native_Should &operator =( const native_Should &other ) noexcept = delete;

private:
	native_Should( native_Should &&other ) noexcept = delete;
	native_Should &operator =( native_Should &&other ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace validating
} // namespace encodebuba
} // namespace jmsf
