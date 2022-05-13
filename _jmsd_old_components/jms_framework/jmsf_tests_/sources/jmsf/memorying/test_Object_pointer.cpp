#include "jmsf/cule/macroses_Test.h"


#include "testing/Memorying_testing_class.h"

#include "jmsf/testing/testing_Allocators.h"
//#include "jmsf/texting/Ansii_allocating_assistor.h"
//#include "jmsf/texting/Ansii_stream.hin"
//#include "jmsf/texting/Ansii_text.h"
//#include "jmsf/pointing/Shared.hin"
//#include "jmsf/pointing/cShared.hin"

//#include "jmsf/pointing/cScoped.hin"

#include "jmsf/memorying/Object_pointer.hin"

//#include "jmsf/typeing/Naturals.hin"
//#include "jmsf/typeing/Boolean.h"

#include "jmsf/validating/excepting/exception_Should_with_type_information.h"

//#include <utility>


namespace jmsf {
namespace memorying {


CULE_TEST( Object_pointer, should_create_empty ) {
	Object_pointer< testing::Memorying_testing_class > empty_object_pointer;

	this_object_should_be_empty( empty_object_pointer );
	this_should_not_be( empty_object_pointer.is_not_empty() );
}

CULE_TEST( Object_pointer, should_delete_empty ) {
	{
		Object_pointer< testing::Memorying_testing_class > empty_object_pointer;
	}
}

CULE_TEST( Object_pointer, should_be_equal_empty_empty ) {
	const Object_pointer< testing::Memorying_testing_class > empty_object_pointer;
	these_solids_should_be_equal( Object_pointer< testing::Memorying_testing_class >(), Object_pointer< testing::Memorying_testing_class >() );
	these_solids_should_be_equal( empty_object_pointer, empty_object_pointer );
	these_solids_should_be_equal( empty_object_pointer, Object_pointer< testing::Memorying_testing_class >() );
	these_solids_should_be_equal( Object_pointer< testing::Memorying_testing_class >(), empty_object_pointer );
}

CULE_TEST( Object_pointer, should_copy_empty ) {
	Object_pointer< testing::Memorying_testing_class > empty_object_pointer;
	Object_pointer< testing::Memorying_testing_class > object_pointer_to_empty;
	object_pointer_to_empty = empty_object_pointer;

	this_object_should_be_empty( object_pointer_to_empty );
	this_object_should_be_empty( empty_object_pointer );
	these_solids_should_be_equal( empty_object_pointer, object_pointer_to_empty );
}

CULE_TEST( Object_pointer, should_copy_construct_empty ) {
	Object_pointer< testing::Memorying_testing_class > empty_object_pointer;
	Object_pointer< testing::Memorying_testing_class > object_pointer_to_empty = empty_object_pointer;

	this_object_should_be_empty( object_pointer_to_empty );
	this_object_should_be_empty( empty_object_pointer );
	these_solids_should_be_equal( empty_object_pointer, object_pointer_to_empty );
}

CULE_TEST_E( Object_pointer, should_not_get_address_of_empty, validating::excepting::exception_Should_with_type_information ) {
	Object_pointer< testing::Memorying_testing_class >().get_address();
}


CULE_TEST_E( Object_pointer, should_not_get_empty, validating::excepting::exception_Should_with_type_information ) {
	Object_pointer< testing::Memorying_testing_class >().get();
}

CULE_TEST_E( Object_pointer, should_not_take_empty, validating::excepting::exception_Should_with_type_information ) {
	Object_pointer< testing::Memorying_testing_class >().take();
}

CULE_TEST( Object_pointer, should_convert_empty_to_ansii_text ) {
	const pointing::cShared< texting::Ansii_text > nill_ansii_text =
		texting::Aaa_sl(
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor(),
			JMSF_SL( "0" ) );

	these_ansii_texts_should_be_equal(
		nill_ansii_text,
		Object_pointer< testing::Memorying_testing_class >().to_ansii_text(
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor() ) );
}

CULE_TEST( Object_pointer, should_create_from_pointer ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

	const testing::Memorying_testing_class *deadcode =
		typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf );

	const Object_pointer< testing::Memorying_testing_class > filled_object_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer( deadcode );

	this_object_should_not_be_empty( filled_object_pointer );
	these_pointers_should_be_equal( deadcode, filled_object_pointer.get() );
}

CULE_TEST( Object_pointer, should_not_delete_the_object ) {
	{
		const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

		Object_pointer< testing::Memorying_testing_class > filled_object_pointer =
			Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
				typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf ) );
	}
}

CULE_TEST( Object_pointer, should_be_equal_filled_filled ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

	const Object_pointer< testing::Memorying_testing_class > filled_object_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
				typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf ) );

	const Object_pointer< testing::Memorying_testing_class > memory_object_to_fill = filled_object_pointer;

	these_solids_should_be_equal( filled_object_pointer, filled_object_pointer );
	these_solids_should_be_equal( filled_object_pointer, memory_object_to_fill );
	these_solids_should_be_equal( filled_object_pointer, filled_object_pointer );
	these_solids_should_be_equal( filled_object_pointer, memory_object_to_fill );
}

CULE_TEST( Object_pointer, should_be_equal_equally_filled ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

	const Object_pointer< testing::Memorying_testing_class > filled_object_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf )  );

	const Object_pointer< testing::Memorying_testing_class > filled_object_pointer_1 =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf )  );

	these_solids_should_be_equal( filled_object_pointer_1, filled_object_pointer );
	these_solids_should_be_equal( filled_object_pointer, filled_object_pointer_1 );
}

CULE_TEST( Object_pointer, should_not_be_equal_filled_empty ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

	const Object_pointer< testing::Memorying_testing_class > empty_memory_pointer;

	const Object_pointer< testing::Memorying_testing_class > filled_memory_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf )  );

	these_solids_should_not_be_equal( filled_memory_pointer, Object_pointer< testing::Memorying_testing_class >() );
	these_solids_should_not_be_equal( Object_pointer< testing::Memorying_testing_class >(), filled_memory_pointer );
	these_solids_should_not_be_equal( filled_memory_pointer, empty_memory_pointer );
	these_solids_should_not_be_equal( empty_memory_pointer, filled_memory_pointer );
}

CULE_TEST( Object_pointer, should_be_equal_differently_filled ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	const typeing::Memory_natural deadcode = typeing::Memory_natural::create( 0xDEADC0DE );

	const Object_pointer< testing::Memorying_testing_class > filled_object_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf ) );

	const Object_pointer< testing::Memorying_testing_class > filled_object_pointer_1 =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadcode ) );

	these_solids_should_not_be_equal( filled_object_pointer_1, filled_object_pointer );
	these_solids_should_not_be_equal( filled_object_pointer, filled_object_pointer_1 );
}

CULE_TEST( Object_pointer, should_copy ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

	const Object_pointer< testing::Memorying_testing_class > filled_object_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf ) );

	Object_pointer< testing::Memorying_testing_class > object_pointer_to_fill;
	object_pointer_to_fill = filled_object_pointer;

	this_object_should_not_be_empty( object_pointer_to_fill );
	this_object_should_not_be_empty( filled_object_pointer );
	these_solids_should_be_equal( filled_object_pointer, object_pointer_to_fill );
}

CULE_TEST( Object_pointer, should_copy_construct ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

	const Object_pointer< testing::Memorying_testing_class > filled_object_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf ) );

	const Object_pointer< testing::Memorying_testing_class > memory_object_to_fill = filled_object_pointer;

	this_object_should_not_be_empty( memory_object_to_fill );
	this_object_should_not_be_empty( filled_object_pointer );
	these_solids_should_be_equal( filled_object_pointer, memory_object_to_fill );
}

CULE_TEST( Object_pointer, should_move ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

	Object_pointer< testing::Memorying_testing_class > filled_object_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf ) );

	Object_pointer< testing::Memorying_testing_class > object_pointer_to_fill;
	object_pointer_to_fill = ::std::move( filled_object_pointer );

	this_object_should_not_be_empty( object_pointer_to_fill );
	these_solids_should_be_equal( deadbeaf,  typeing::create_address_from_pointer( object_pointer_to_fill.get() ) );
	this_object_should_be_empty( filled_object_pointer );
	these_solids_should_not_be_equal( filled_object_pointer, object_pointer_to_fill );
}

CULE_TEST( Object_pointer, should_move_construct ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

	Object_pointer< testing::Memorying_testing_class > filled_object_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf ) );

	const Object_pointer< testing::Memorying_testing_class > object_pointer_to_fill = ::std::move( filled_object_pointer );

	this_object_should_not_be_empty( object_pointer_to_fill );
	these_solids_should_be_equal( deadbeaf, typeing::create_address_from_pointer( object_pointer_to_fill.get() ) );
	this_object_should_be_empty( filled_object_pointer );
	these_solids_should_not_be_equal( filled_object_pointer, object_pointer_to_fill );
}

CULE_TEST( Object_pointer, should_copy_itself_and_same ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

	Object_pointer< testing::Memorying_testing_class > filled_object_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf ) );

	filled_object_pointer = filled_object_pointer;
	Object_pointer< testing::Memorying_testing_class > object_pointer_to_fill = filled_object_pointer;
	object_pointer_to_fill = filled_object_pointer;

	this_object_should_not_be_empty( object_pointer_to_fill );
	this_object_should_not_be_empty( filled_object_pointer );
	these_solids_should_be_equal( filled_object_pointer, object_pointer_to_fill );
}

CULE_TEST( Object_pointer, should_move_itself ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

	Object_pointer< testing::Memorying_testing_class > filled_object_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf ) );

	filled_object_pointer = ::std::move( filled_object_pointer );

	this_object_should_not_be_empty( filled_object_pointer );
	these_solids_should_be_equal( deadbeaf, typeing::create_address_from_pointer( filled_object_pointer.get() ) );
}

CULE_TEST( Object_pointer, should_take ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	const testing::Memorying_testing_class *deadcode = typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf );

	Object_pointer< testing::Memorying_testing_class > filled_memory_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			deadcode );

	these_pointers_should_be_equal( deadcode, filled_memory_pointer.take() );
}

CULE_TEST( Object_pointer, should_get ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	const testing::Memorying_testing_class *deadcode = typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf );

	const Object_pointer< testing::Memorying_testing_class > filled_memory_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			deadcode );

	these_pointers_should_be_equal( deadcode, filled_memory_pointer.get() );
}

CULE_TEST( Object_pointer, should_convert_to_ansii_text ) {
	const pointing::cShared< texting::Ansii_text > deadbeaf_ansii_text =
		texting::Aaa_sl(
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor(),
			JMSF_SL( "DEADBEAF" ) );

	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

	const Object_pointer< testing::Memorying_testing_class > filled_object_pointer =
		Object_pointer< testing::Memorying_testing_class >::create_from_pointer(
			typeing::get_pointer_from_Memory_natural< testing::Memorying_testing_class >( deadbeaf ) );

	these_ansii_texts_should_be_equal(
		deadbeaf_ansii_text,
		filled_object_pointer.to_ansii_text(
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor() ) );
}


} // namespace memorying
} // jmsf
