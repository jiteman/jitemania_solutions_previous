#include "jmsf/cule/macroses_Test.h"


#include "testing/Memorying_testing_class.h"
#include "jmsf/testing/testing_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/pointing/cScoped.hin"

//#include "jmsf/memorying/Memory_pointer.hin"

#include "jmsf/typeing/Naturals.hin"
#include "jmsf/typeing/Boolean.h"

#include "jmsf/validating/excepting/exception_Should.h"

#include <utility>


namespace jmsf {
namespace memorying {


CULE_TEST( Memory_address, should_create_empty ) {
	Memory_address empty_memory_pointer;

	this_object_should_be_empty( empty_memory_pointer );
	this_should_not_be( empty_memory_pointer.is_not_empty() );
}

CULE_TEST( Memory_address, should_delete_empty ) {
	{
		Memory_address empty_memory_pointer;
	}
}

CULE_TEST( Memory_address, should_be_equal_empty_empty ) {
	const Memory_address empty_memory_pointer;
	these_solids_should_be_equal( Memory_address(), Memory_address() );
	these_solids_should_be_equal( empty_memory_pointer, empty_memory_pointer );
	these_solids_should_be_equal( empty_memory_pointer, Memory_address() );
	these_solids_should_be_equal( Memory_address(), empty_memory_pointer );
}

CULE_TEST( Memory_address, should_copy_empty ) {
	Memory_address empty_memory_pointer;
	Memory_address memory_pointer_to_empty;
	memory_pointer_to_empty = empty_memory_pointer;

	this_object_should_be_empty( memory_pointer_to_empty );
	this_object_should_be_empty( empty_memory_pointer );
	these_solids_should_be_equal( empty_memory_pointer, memory_pointer_to_empty );
}

CULE_TEST( Memory_address, should_copy_construct_empty ) {
	Memory_address empty_memory_pointer;
	Memory_address memory_pointer_to_empty = empty_memory_pointer;

	this_object_should_be_empty( memory_pointer_to_empty );
	this_object_should_be_empty( empty_memory_pointer );
	these_solids_should_be_equal( empty_memory_pointer, memory_pointer_to_empty );
}

//TEST_EXCEPTION( Memory_pointer, should_not_get_empty, validating::excepting::exception_Should ) {
//	Memory_pointer().get();
//}

//TEST_EXCEPTION( Memory_pointer, should_not_take_empty, validating::excepting::exception_Should ) {
//	Memory_pointer().take();
//}

CULE_TEST( Memory_address, should_get_empty_address ) {
	these_solids_should_be_equal( typeing::Memory_natural_nil, Memory_address().get() );
}

CULE_TEST( Memory_address, should_convert_empty_to_ansii_text ) {
	const pointing::cShared< texting::Ansii_text > nill_ansii_text =
		texting::Aaa_sl(
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor(),
			JMSF_SL( "0" ) );

	these_ansii_texts_should_be_equal( nill_ansii_text, Memory_address().to_ansii_text( ::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor() ) );
}

CULE_TEST( Memory_address, should_set_address_on_empty ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
//	const void *deadcode = typeing::get_pointer_from_Memory_natural< void * >( deadbeaf );
	Memory_address empty_memory_pointer;
	empty_memory_pointer.set( deadbeaf );

	this_object_should_not_be_empty( empty_memory_pointer );
	these_solids_should_be_equal( deadbeaf, empty_memory_pointer.get() );
//	these_pointers_should_be_equal( deadcode, empty_memory_pointer.get() );
//	these_pointers_should_be_equal( deadcode, empty_memory_pointer.take() );
}

CULE_TEST( Memory_address, should_create_from_address ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
//	const void *deadcode = typeing::get_pointer_from_Memory_natural< void * >( deadbeaf );
	Memory_address filled_memory_pointer = Memory_address::create_from_address( deadbeaf );

	this_object_should_not_be_empty( filled_memory_pointer );
	these_solids_should_be_equal( deadbeaf, filled_memory_pointer.get() );
//	these_pointers_should_be_equal( deadcode, filled_memory_pointer.get() );
//	these_pointers_should_be_equal( deadcode, filled_memory_pointer.take() );
}

CULE_TEST( Memory_address, should_create_from_pointer ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	const void *deadcode = typeing::get_pointer_from_Memory_natural< void * >( deadbeaf );
	Memory_address filled_memory_pointer = Memory_address::create_from_pointer( deadcode );

	this_object_should_not_be_empty( filled_memory_pointer );
	these_solids_should_be_equal( deadbeaf, filled_memory_pointer.get() );
//	these_pointers_should_be_equal( deadcode, filled_memory_pointer.get() );
//	these_pointers_should_be_equal( deadcode, filled_memory_pointer.take() );
}

CULE_TEST( Memory_address, should_not_delete_the_object ) {
	{
		Memory_address filled_memory_pointer = Memory_address::create_from_address( typeing::Memory_natural::create( 0xDEADBEAF ) );
	}
}

CULE_TEST( Memory_address, should_be_equal_filled_filled ) {
	const Memory_address filled_memory_pointer = Memory_address::create_from_address( typeing::Memory_natural_one );
	const Memory_address memory_pointer_to_fill = filled_memory_pointer;
	these_solids_should_be_equal( filled_memory_pointer, filled_memory_pointer );
	these_solids_should_be_equal( filled_memory_pointer, memory_pointer_to_fill );
	these_solids_should_be_equal( filled_memory_pointer, filled_memory_pointer );
	these_solids_should_be_equal( filled_memory_pointer, memory_pointer_to_fill );
}

CULE_TEST( Memory_address, should_be_equal_equally_filled ) {
	const Memory_address filled_memory_pointer = Memory_address::create_from_address( typeing::Memory_natural_one );
	const Memory_address filled_memory_pointer_1 = Memory_address::create_from_address( typeing::Memory_natural_one );
	these_solids_should_be_equal( filled_memory_pointer, filled_memory_pointer );
	these_solids_should_be_equal( filled_memory_pointer, filled_memory_pointer_1 );
}

CULE_TEST( Memory_address, should_not_be_equal_filled_empty ) {
	const Memory_address empty_memory_pointer;
	const Memory_address filled_memory_pointer = Memory_address::create_from_address( typeing::Memory_natural_one );
	these_solids_should_not_be_equal( filled_memory_pointer, Memory_address() );
	these_solids_should_not_be_equal( Memory_address(), filled_memory_pointer );
	these_solids_should_not_be_equal( filled_memory_pointer, empty_memory_pointer );
	these_solids_should_not_be_equal( empty_memory_pointer, filled_memory_pointer );
}

CULE_TEST( Memory_address, should_copy ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	const Memory_address filled_memory_pointer = Memory_address::create_from_address( deadbeaf );
	Memory_address memory_pointer_to_fill;
	memory_pointer_to_fill = filled_memory_pointer;

	this_object_should_not_be_empty( memory_pointer_to_fill );
	this_object_should_not_be_empty( filled_memory_pointer );
	these_solids_should_be_equal( filled_memory_pointer, memory_pointer_to_fill );
}

CULE_TEST( Memory_address, should_copy_construct ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	const Memory_address filled_memory_pointer = Memory_address::create_from_address( deadbeaf );
	const Memory_address memory_pointer_to_fill = filled_memory_pointer;

	this_object_should_not_be_empty( memory_pointer_to_fill );
	this_object_should_not_be_empty( filled_memory_pointer );
	these_solids_should_be_equal( filled_memory_pointer, memory_pointer_to_fill );
}

CULE_TEST( Memory_address, should_move ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	Memory_address filled_memory_pointer = Memory_address::create_from_address( deadbeaf );
	Memory_address memory_pointer_to_fill;
	memory_pointer_to_fill = ::std::move( filled_memory_pointer );

	this_object_should_not_be_empty( memory_pointer_to_fill );
	these_solids_should_be_equal( deadbeaf, memory_pointer_to_fill.get() );
	this_object_should_be_empty( filled_memory_pointer );
	these_solids_should_not_be_equal( filled_memory_pointer, memory_pointer_to_fill );
}

CULE_TEST( Memory_address, should_move_construct ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	Memory_address filled_memory_pointer = Memory_address::create_from_address( deadbeaf );
	const Memory_address memory_pointer_to_fill = ::std::move( filled_memory_pointer );

	this_object_should_not_be_empty( memory_pointer_to_fill );
	these_solids_should_be_equal( deadbeaf, memory_pointer_to_fill.get() );
	this_object_should_be_empty( filled_memory_pointer );
	these_solids_should_not_be_equal( filled_memory_pointer, memory_pointer_to_fill );
}

CULE_TEST( Memory_address, should_copy_itself_and_same ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	Memory_address filled_memory_pointer = Memory_address::create_from_address( deadbeaf );

	filled_memory_pointer = filled_memory_pointer;
	Memory_address memory_pointer_to_fill = filled_memory_pointer;
	memory_pointer_to_fill = filled_memory_pointer;

	this_object_should_not_be_empty( memory_pointer_to_fill );
	this_object_should_not_be_empty( filled_memory_pointer );
	these_solids_should_be_equal( filled_memory_pointer, memory_pointer_to_fill );
}

CULE_TEST( Memory_address, should_move_itself ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	Memory_address filled_memory_pointer = Memory_address::create_from_address( deadbeaf );
	filled_memory_pointer = ::std::move( filled_memory_pointer );

	this_object_should_not_be_empty( filled_memory_pointer );
	these_solids_should_be_equal( deadbeaf, filled_memory_pointer.get() );
}

//CULE_TEST( Memory_pointer, should_take ) {
//	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
//	const void *deadcode = typeing::get_pointer_from_Memory_natural< void * >( deadbeaf );
//	Memory_pointer filled_memory_pointer = Memory_pointer::create_from_address( deadbeaf );

//	these_pointers_should_be_equal( deadcode, filled_memory_pointer.take() );
//}

//CULE_TEST( Memory_pointer, should_get ) {
//	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
//	const void *deadcode = typeing::get_pointer_from_Memory_natural< void * >( deadbeaf );
//	const Memory_pointer filled_memory_pointer = Memory_pointer::create_from_address( deadbeaf );

//	these_pointers_should_be_equal( deadcode, filled_memory_pointer.get() );
//}

CULE_TEST( Memory_address, should_get ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	const Memory_address filled_memory_pointer = Memory_address::create_from_address( deadbeaf );

	these_solids_should_be_equal( deadbeaf, filled_memory_pointer.get() );
}

CULE_TEST( Memory_address, should_get_new_address_after_setting_new_address ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	const typeing::Memory_natural deadcode = typeing::Memory_natural::create( 0xDEADC0DE );
	Memory_address filled_memory_pointer = Memory_address::create_from_address( deadbeaf );
	filled_memory_pointer.set( deadcode );

	these_solids_should_be_equal( deadcode, filled_memory_pointer.get() );
}

CULE_TEST( Memory_address, should_convert_to_ansii_text ) {
	const pointing::cShared< texting::Ansii_text > deadbeaf_ansii_text =
		texting::Aaa_sl(
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor(),
			JMSF_SL( "DEADBEAF" ) );

	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );
	const Memory_address filled_memory_pointer = Memory_address::create_from_address( deadbeaf );

	these_ansii_texts_should_be_equal( deadbeaf_ansii_text, filled_memory_pointer.to_ansii_text( ::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor() ) );
}


} // namespace memorying
} // namespace jmsf
