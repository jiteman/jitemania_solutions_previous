#pragma once

#include "Should.hxx"


#include "excepting/exception_Should.h"
#include "jmsf/texting/Ansii_text.hxx"
#include "jmsf/texting/String_literal.hxx"
#include "File_and_line.hxx"
//#include "jmsf/pointing/Proxy.hxx"
//#include "jmsf/pointing/Constant_proxy.hxx"
//#include "jmsf/pointing/Pointer.hxx"
//#include "jmsf/pointing/Constant_pointer.hxx"

#include "jmsf/pointing/Weak.hxx"
#include "jmsf/pointing/cWeak.hxx"
#include "jmsf/pointing/Shared.hxx"
#include "jmsf/pointing/cShared.hxx"
#include "jmsf/pointing/Nonlinked.hxx"
#include "jmsf/pointing/cNonlinked.hxx"
#include "jmsf/pointing/Scoped.hxx"
#include "jmsf/pointing/cScoped.hxx"

#include "jmsf/memorying/Awamp.hxx"
#include "jmsf/memorying/Wamp.hxx"
#include "jmsf/memorying/Amp.hxx"
#include "jmsf/memorying/Owomp.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Object_pointer.hxx"
#include "jmsf/typeing/Boolean.hxx"
//#include "jmsf/memorying/Allocator.hxx"

#include "jmsf/typeing/internals/internal_types.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {


// Seinsei: todonext - rename null to empty for always_be and never_be (except pointers)
// Seinsei: todonext - or to empty
class JMSF_SHARED_INTERFACE Should {

public:
	static void always_be( typeing::Boolean expression_result, const File_and_line &file_and_line );
	static void always_be( typeing::Boolean expression_result, const char *type_name, const File_and_line &file_and_line );
	static void never_be( typeing::Boolean expression_result, const File_and_line &file_and_line );
	static void never_be( typeing::Boolean expression_result, const char *type_name, const File_and_line &file_and_line );

	static void always_be_null_native_pointer( const void *native_pointer, const File_and_line &file_and_line );
	static void always_be_null_native_pointer( const void *native_pointer, const char *type_name, const File_and_line &file_and_line );
	static void never_be_null_native_pointer( const void *native_pointer, const File_and_line &file_and_line );
	static void never_be_null_native_pointer( const void *native_pointer, const char *type_name, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const memorying::Object_pointer< A_type > &an_object_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const memorying::Object_pointer< A_type > &an_object_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const memorying::Omp< A_type > &object_memory_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const memorying::Omp< A_type > &object_memory_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const memorying::Womp< A_type > &weak_object_memory_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const memorying::Womp< A_type > &weak_object_memory_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const memorying::Owomp< A_type > &object_weak_object_memory_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const memorying::Owomp< A_type > &object_weak_object_memory_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const memorying::Amp< A_type > &array_memory_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const memorying::Amp< A_type > &array_memory_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const memorying::Wamp< A_type > &weak_array_memory_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const memorying::Wamp< A_type > &weak_array_memory_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const memorying::Awamp< A_type > &array_weak_array_memory_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const memorying::Awamp< A_type > &array_weak_array_memory_pointer, const File_and_line &file_and_line );


	template< class A_type >
	static void always_be_empty( const pointing::Weak< A_type > &a_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const pointing::Weak< A_type > &a_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const pointing::cWeak< A_type > &a_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const pointing::cWeak< A_type > &a_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const pointing::Shared< A_type > &a_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const pointing::Shared< A_type > &a_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const pointing::cShared< A_type > &a_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const pointing::cShared< A_type > &a_pointer, const File_and_line &file_and_line );


	template< class A_type >
	static void always_be_empty( const pointing::Nonlinked< A_type > &a_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const pointing::Nonlinked< A_type > &a_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const pointing::cNonlinked< A_type > &a_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const pointing::cNonlinked< A_type > &a_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const pointing::Scoped< A_type > &a_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const pointing::Scoped< A_type > &a_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_empty( const pointing::cScoped< A_type > &a_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_empty( const pointing::cScoped< A_type > &a_pointer, const File_and_line &file_and_line );

//	// Seinsei: todonext - next two method should sound like "always/never be null" with parameters Proxy and Constant_proxy +
//	// method "never be null pointer" with parameters Proxy and Constant_proxy
//	template< class A_type >
//	static void always_be_null( const pointing::Proxy< A_type > &a_proxy, const File_and_line &file_and_line );
//	template< class A_type >
//	static void never_be_null( const pointing::Proxy< A_type > &a_proxy, const File_and_line &file_and_line );

//	template< class A_type >
//	static void always_be_null( const pointing::Constant_proxy< A_type > &a_constant_proxy, const File_and_line &file_and_line );
//	template< class A_type >
//	static void never_be_null( const pointing::Constant_proxy< A_type > &a_constant_proxy, const File_and_line &file_and_line );

//	template< class A_type >
//	static void never_be_null_pointer( const pointing::Proxy< A_type > &a_proxy, const File_and_line &file_and_line );
//	template< class A_type >
//	static void never_be_null_pointer( const pointing::Constant_proxy< A_type > &a_constant_proxy, const File_and_line &file_and_line );

//	template< class A_type >
//	static void always_be_null_object( const A_type *pointer, const File_and_line &file_and_line );
//	template< class A_type >
//	static void never_be_null_object( const A_type *pointer, const File_and_line &file_and_line );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	static void never_reach_here_with_reason( const typeing::internals::platform_character *reason, const File_and_line &file_and_line );
	static void never_reach_here_with_reason( const typeing::internals::platform_character *reason, const char *type_name, const File_and_line &file_and_line );
	static void never_reach_here_void( const File_and_line &file_and_line );
	static void never_reach_here_void( const char *type_name, const File_and_line &file_and_line );
	static void never_violate_copy_prohibition_with_reason( const typeing::internals::platform_character *place, const File_and_line &file_and_line );
	static void never_violate_copy_prohibition_with_reason( const typeing::internals::platform_character *place, const char *type_name, const File_and_line &file_and_line );
	static void never_violate_copy_prohibition_void( const File_and_line &file_and_line );
	static void never_violate_copy_prohibition_void( const char *type_name, const File_and_line &file_and_line );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~Should() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Should() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Should( const Should &other ) noexcept;
	const Should &operator =( const Should &other ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static void throw_exception(
		const pointing::cShared< texting::Ansii_text > &ansii_text_reason,
		const File_and_line &file_and_line );

	static void throw_exception(
		const texting::String_literal &string_literal_reason,
		const File_and_line &file_and_line );

	static void throw_exception_with_type(
		const pointing::cShared< texting::Ansii_text > &ansii_text_reason,
		const pointing::cShared< texting::Ansii_text > &ansii_text_detailed_description,
		const pointing::cShared< texting::Ansii_text > &ansii_text_type_information,
		const File_and_line &file_and_line );

	static void throw_exception_with_type(
		const texting::String_literal &string_literal_reason,
		const texting::String_literal &string_literal_detailed_description,
		const texting::String_literal &string_literal_type_information,
		const File_and_line &file_and_line );

};


} // namespace validating
} // namespace jmsf
