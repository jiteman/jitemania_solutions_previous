#pragma once


#include "jmsf/texting/String_literal.h"

#include "jmsf/texting/Ansii_text.hxx"

#include "jmsf/pointing/cWeak.hxx"
#include "jmsf/pointing/cShared.hxx"

#include "jmsf/typeing/Naturals.hxx"
#include "jmsf/typeing/Boolean.hxx"
#include "jmsf/validating/File_and_line.hxx"

#include "jmsf/cule/cule_Allocators.h"


#include "jmsf/cule/cule.h"


namespace jmsf {
namespace cule {
namespace asserting {
namespace deprecating {


// Seinsei: for TEST_EXCEPTION only
void JMSF_CULE_SHARED_INTERFACE Assert_throw_cule_exception( const pointing::cShared< texting::Ansii_text > &message, const ::jmsf::validating::File_and_line &file_and_line );


class JMSF_CULE_SHARED_INTERFACE Assert {

public:
	static void this_is_not_implemented_yet( const texting::String_literal &message, const ::jmsf::validating::File_and_line &file_and_line, const texting::String_literal &type_name );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static void should_be( typeing::Boolean actual, const ::jmsf::validating::File_and_line &file_and_line );
	static void should_not_be( typeing::Boolean actual, const ::jmsf::validating::File_and_line &file_and_line );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static void pointers_should_be_equal( const void *expected_pointer, const void *actual_pointer, const ::jmsf::validating::File_and_line &file_and_line );
	static void pointers_should_not_be_equal( const void *expected_pointer, const void *actual_pointer, const ::jmsf::validating::File_and_line &file_and_line );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	template< class A_type >
	static void object_should_be_empty( const A_type &an_object, const ::jmsf::validating::File_and_line &file_and_line );
	template< class A_type >
	static void object_should_not_be_empty( const A_type &an_object, const ::jmsf::validating::File_and_line &file_and_line );

	template< class A_type >
	static void solids_should_be_equal_by_operator( const A_type &expected_object, const A_type &actual_object, const ::jmsf::validating::File_and_line &file_and_line );
	template< class A_type >
	static void solids_should_not_be_equal_by_operator( const A_type &expected_object, const A_type &actual_object, const ::jmsf::validating::File_and_line &file_and_line );

	template< class A_type >
	static void objects_should_be_equal( const A_type &expected_object, const A_type &actual_object, const ::jmsf::validating::File_and_line &file_and_line );
	template< class A_type >
	static void objects_should_not_be_equal( const A_type &expected_object, const A_type &actual_object, const ::jmsf::validating::File_and_line &file_and_line );

	template< class A_type >
	static void objects_should_be_same( const A_type &expected_object, const A_type &actual_object, const ::jmsf::validating::File_and_line &file_and_line );
	template< class A_type >
	static void objects_should_not_be_same( const A_type &expected_object, const A_type &actual_object, const ::jmsf::validating::File_and_line &file_and_line );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static void ansii_texts_should_be_equal(
		const pointing::cShared< texting::Ansii_text > &expected_object,
		const pointing::cShared< texting::Ansii_text > &actual_object,
		const ::jmsf::validating::File_and_line &file_and_line );

	static void ansii_texts_should_not_be_equal(
		const pointing::cShared< texting::Ansii_text > &expected_object,
		const pointing::cShared< texting::Ansii_text > &actual_object,
		const ::jmsf::validating::File_and_line &file_and_line );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend void JMSF_CULE_SHARED_INTERFACE Assert_throw_cule_exception( const pointing::cShared< texting::Ansii_text > &message, const ::jmsf::validating::File_and_line &file_and_line );
	static void throw_cule_exception( const pointing::cShared< texting::Ansii_text > &message, const ::jmsf::validating::File_and_line &file_and_line );

};


} // namespace deprecating
} // namespace asserting
} // namespace cule
} // namespace jmsf


// ============================================================================================================================
// ----------------------------------------------------------------------------------------------------------------------------
// empty (Ansii_string)
#define this_behaviour_is_not_implemented_yet( message ) \
	::jmsf::cule::asserting::deprecating::Assert::this_is_not_implemented_yet( ( message ), JMSF_FILE_AND_LINE, JMSF_SL( "behaviour" ) )

#define this_test_is_not_implemented_yet( message ) \
	::jmsf::cule::asserting::deprecating::Assert::this_is_not_implemented_yet( ( message ), JMSF_FILE_AND_LINE, JMSF_SL( "test" ) )

// my types: Boolean, Integers, Naturals, Reals

// ----------------------------------------------------------------------------------------------------------------------------
// ::jmsf::typeing::Boolean
#define this_should_be( actual ) \
	::jmsf::cule::asserting::deprecating::Assert::should_be( ( actual ), JMSF_FILE_AND_LINE )

#define this_should_not_be( actual ) \
	::jmsf::cule::asserting::deprecating::Assert::should_not_be( ( actual ), JMSF_FILE_AND_LINE )

// ----------------------------------------------------------------------------------------------------------------------------
// native pointers
#define these_pointers_should_be_equal( expected, actual ) \
	::jmsf::cule::asserting::deprecating::Assert::pointers_should_be_equal( ( expected ), ( actual ), JMSF_FILE_AND_LINE )
#define these_pointers_should_not_be_equal( expected, actual ) \
	::jmsf::cule::asserting::deprecating::Assert::pointers_should_not_be_equal( ( expected ), ( actual ), JMSF_FILE_AND_LINE )

// ----------------------------------------------------------------------------------------------------------------------------
// any object with methods: is_empty() and is_not_empty()
// my metatypes: Omp, Womp, Amp, Awamp, Owomp, [xc]Weak, [xc]Shared, [xc]Nonlinked, [xc]Scoped
// other types: Memory_pointer
#define this_object_should_be_empty( actual ) \
	::jmsf::cule::asserting::deprecating::Assert::object_should_be_empty( ( actual ), JMSF_FILE_AND_LINE )
#define this_object_should_not_be_empty( actual ) \
	::jmsf::cule::asserting::deprecating::Assert::object_should_not_be_empty( ( actual ), JMSF_FILE_AND_LINE )

// ----------------------------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------------------------------
// any object with operators: ==, !=
#define these_solids_should_be_equal( expected, actual ) \
	::jmsf::cule::asserting::deprecating::Assert::solids_should_be_equal_by_operator( ( expected ), ( actual ), JMSF_FILE_AND_LINE )
#define these_solids_should_not_be_equal( expected, actual  ) \
	::jmsf::cule::asserting::deprecating::Assert::solids_should_not_be_equal_by_operator( ( expected ), ( actual ), JMSF_FILE_AND_LINE )

//// any object with methods: is_equal_to(), is_not_equal_to()
#define these_objects_should_be_equal( expected, actual ) \
	::jmsf::cule::asserting::deprecating::Assert::objects_should_be_equal( ( expected ), ( actual ), JMSF_FILE_AND_LINE )
#define these_objects_should_not_be_equal( expected, actual  ) \
	::jmsf::cule::asserting::deprecating::Assert::objects_should_not_be_equal( ( expected ), ( actual ), JMSF_FILE_AND_LINE )

// any object with methods: is_the_same_as(), is_not_the_same_as()
#define these_objects_should_be_same( expected, actual ) \
	::jmsf::cule::asserting::deprecating::Assert::objects_should_be_same( ( expected ), ( actual ), JMSF_FILE_AND_LINE )
#define these_objects_should_not_be_same( expected, actual  ) \
	::jmsf::cule::asserting::deprecating::Assert::objects_should_not_be_same( ( expected ), ( actual ), JMSF_FILE_AND_LINE )

// Ansii_text
// parameters: ( cShared< Ansii_text >, cShared< Ansii_text > ) or ( cShared< Ansii_text >, cWeak< Ansii_text > )
#define these_ansii_texts_should_be_equal( expected, actual ) \
	::jmsf::cule::asserting::deprecating::Assert::ansii_texts_should_be_equal( ( expected ), ( actual ), JMSF_FILE_AND_LINE )
#define these_ansii_texts_should_not_be_equal( expected, actual ) \
	::jmsf::cule::asserting::deprecating::Assert::ansii_texts_should_not_be_equal( ( expected ), ( actual ), JMSF_FILE_AND_LINE )

// integral types: bool, integer char...long long, natural char...long long, pointer
// integral real types: float, double


// this_integral_should_be, this_integral_should_not_be for bool

// this_integral_pointer_should_be_null, this_integral_pointer_should_not_be_null for pointer
// these_integral_pointers_should_be_the_same, these_integral_pointers_should_not_be_the_same for pointer

// this_pointer_should_be_null, this_pointer_should_not_be_null for Pointer
// these_pointers_should_be_the_same, these_pointers_should_not_be_the_same for Pointer

// this_proxy_should_be_null, this_integral_should_not_null for Proxy
// these_proxies_should_be_the_same, these_proxies_should_not_be_the_same for Proxy

// these_should_be_equal, these_should_not_be_equal for Integers and Naturals
// these_integral_should_be_equal, these_integral_should_not_be_equal for integers and naturals

// these_reals_should_be_equal, these_reals_should_not_be_equal for Reals // with tolerance
// these_integral_reals_should_be_equal, these_integral_reals_should_not_be_equal for float and double // with tolerance


//-----------------------------------------------------------------------------------------------------------------------------
// ::jmsf::typeing::Integers
//#define these_integers_should_be_equal( expected, actual )
//	::jmsf::cule::asserting::deprecating::Assert::integers_should_be_equal( ( expected ), ( actual ), FILE_AND_LINE )

//#define these_integers_should_not_be_equal( actual )
//	::jmsf::cule::asserting::deprecating::Assert::integers_should_be_equal( ( expected ), ( actual ), FILE_AND_LINE )

//-----------------------------------------------------------------------------------------------------------------------------
// ::jmsf::typeing::Naturals
//#define these_naturals_should_be_equal( expected, actual )
//	::jmsf::cule::asserting::deprecating::Assert::naturals_should_be_equal( ( expected ), ( actual ), FILE_AND_LINE )

//#define these_naturals_should_not_be_equal( actual )
//	::jmsf::cule::asserting::deprecating::Assert::naturals_should_be_equal( ( expected ), ( actual ), FILE_AND_LINE )

//-----------------------------------------------------------------------------------------------------------------------------
// bool
//#define this_integral_should_be( actual )
//	::jmsf::cule::asserting::deprecating::Assert::integral_should_be( ( actual ), FILE_AND_LINE )
