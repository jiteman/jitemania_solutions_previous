#include "jmsf/cule/macroses_Test.h"


#include "testing/Memorying_testing_class.h"
#include "jmsf/testing/testing_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/pointing/Scoped.hin"
#include "jmsf/pointing/cScoped.hin"

#include "jmsf/testing/testing_Allocators.h"

#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Omp.hin"
//#include "jmsf/memorying/Memory_pointer.hin"

#include "jmsf/typeing/Aso.hin"
#include "jmsf/typeing/Naturals.hin"
#include "jmsf/typeing/Boolean.h"

#include "jmsf/validating/excepting/exception_Should_with_type_information.h"

#include <utility>


namespace jmsf {
namespace memorying {


CULE_TEST( Omp, should_create_empty ) {
	const memorying::Omp< testing::Memorying_testing_class > empty_omp;
	this_object_should_be_empty( empty_omp );
}

CULE_TEST( Omp, should_delete_empty ) {
	{
		const memorying::Omp< testing::Memorying_testing_class > empty_omp;
	}
}

CULE_TEST( jmsf_Template, should_be_equal_empty_empty ) {
	const memorying::Omp< testing::Memorying_testing_class > empty_omp;
	these_solids_should_be_equal( memorying::Omp< testing::Memorying_testing_class >(), memorying::Omp< testing::Memorying_testing_class >() );
	these_solids_should_be_equal( empty_omp, empty_omp );
	these_solids_should_be_equal( empty_omp, memorying::Omp< testing::Memorying_testing_class >() );
	these_solids_should_be_equal( memorying::Omp< testing::Memorying_testing_class >(), empty_omp );
}

CULE_TEST( Omp, should_copy_empty ) {
	const memorying::Omp< testing::Memorying_testing_class > empty_omp;
	memorying::Omp< testing::Memorying_testing_class > omp_to_empty;
	omp_to_empty = empty_omp;

	this_object_should_be_empty( omp_to_empty );
	this_object_should_be_empty( empty_omp );
	these_solids_should_be_equal( empty_omp, omp_to_empty );
}

CULE_TEST( Omp, should_copy_construct_empty ) {
	const memorying::Omp< testing::Memorying_testing_class > empty_omp;
	const memorying::Omp< testing::Memorying_testing_class > omp_to_empty = empty_omp;

	this_object_should_be_empty( omp_to_empty );
	this_object_should_be_empty( empty_omp );
	these_solids_should_be_equal( empty_omp, omp_to_empty );

	Cule_this( omp_to_empty ).should_be_equal_to( empty_omp );
}

//TEST_EXCEPTION( Omp, should_not_get_empty, validating::excepting::exception_Should_with_type_information ) {
//	const memorying::Omp< testing::Memorying_testing_class > empty_omp;
//	empty_omp.get();
//}

//TEST_EXCEPTION( Omp, should_not_take_empty, validating::excepting::exception_Should_with_type_information ) {
//	memorying::Omp< testing::Memorying_testing_class > empty_omp;
//	empty_omp.take();
//}

CULE_TEST_E( Omp, should_not_const_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	const memorying::Omp< testing::Memorying_testing_class > empty_omp;
	*empty_omp;
}

CULE_TEST_E( Omp, should_not_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	memorying::Omp< testing::Memorying_testing_class > empty_omp;
	*empty_omp;
}

CULE_TEST_E( Omp, should_not_const_access_empty, validating::excepting::exception_Should_with_type_information ) {
	const memorying::Omp< testing::Memorying_testing_class > empty_omp;
	empty_omp.operator ->();
}

CULE_TEST_E( Omp, should_not_access_empty, validating::excepting::exception_Should_with_type_information ) {
	memorying::Omp< testing::Memorying_testing_class > empty_omp;
	empty_omp.operator ->();
}

CULE_TEST( Omp, should_convert_empty_to_ansii_text ) {
	const pointing::cShared< texting::Ansii_text > nill_ansii_text =
		texting::Aaa_sl(
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor(),
			JMSF_SL( "[ 0, [ 0 ], 0 ]" ) );

	these_ansii_texts_should_be_equal(
		nill_ansii_text,
		Omp< testing::Memorying_testing_class >().to_ansii_text(
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor() ) );
}

CULE_TEST_E( Omp, should_not_return_empty_allocator, validating::excepting::exception_Should_with_type_information ) {
	Omp< testing::Memorying_testing_class >().get_allocator();
}

CULE_TEST_E( Omp, should_not_return_empty_object_address, validating::excepting::exception_Should_with_type_information ) {
	Omp< testing::Memorying_testing_class >().get_object_address();
}

CULE_TEST_E( Omp, should_not_return_empty_alignment, validating::excepting::exception_Should_with_type_information ) {
	Omp< testing::Memorying_testing_class >().get_alignment();
}

CULE_TEST_E( Omp, should_not_return_empty_womp, validating::excepting::exception_Should_with_type_information ) {
	Omp< testing::Memorying_testing_class >().get_as_womp();
}

////CULE_TEST( Omp, should_do_something_special_with_empty ) {
////	create empty_something;
////	do something special with empty_something;

////	this_should_be( check something special with empty_something );
////}

CULE_TEST( Omp, should_create ) {
	const Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > filled_scoped = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	this_object_should_not_be_empty( filled_omp );
}

CULE_TEST( Omp, should_not_delete_the_object ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	{
		const Omp< testing::Memorying_testing_class > filled_omp = testing_object_omp;
	}

	this_object_should_not_be_empty( testing_object_omp );
	these_solids_should_be_equal( typeing::Memory_natural_one, testing::Memorying_testing_class::get_object_counter_value() );
	these_solids_should_be_equal( typeing::Memory_natural_one, testing_object->get_object_number_value() );
}

CULE_TEST( Omp, should_be_equal_filled_filled ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	const Omp< testing::Memorying_testing_class > filled_omp = testing_object_omp;
	const Omp< testing::Memorying_testing_class > filled_omp_1 = filled_omp;
	these_solids_should_be_equal( filled_omp, filled_omp );
	these_solids_should_be_equal( filled_omp, filled_omp_1 );
	these_solids_should_be_equal( filled_omp_1, filled_omp );
	these_solids_should_be_equal( filled_omp_1, filled_omp_1 );
}

CULE_TEST( Omp, should_be_equal_equally_filled ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	const Omp< testing::Memorying_testing_class > filled_omp = testing_object_omp;
	const Omp< testing::Memorying_testing_class > filled_omp_1 = testing_object_omp;
	these_solids_should_be_equal( filled_omp, filled_omp );
	these_solids_should_be_equal( filled_omp, filled_omp_1 );
	these_solids_should_be_equal( filled_omp_1, filled_omp );
	these_solids_should_be_equal( filled_omp_1, filled_omp_1 );
}

CULE_TEST( Omp, should_not_be_equal_filled_empty ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	const Omp< testing::Memorying_testing_class > empty_omp;
	const Omp< testing::Memorying_testing_class > filled_omp = testing_object_omp;
	these_solids_should_not_be_equal( filled_omp, Omp< testing::Memorying_testing_class >() );
	these_solids_should_not_be_equal( Omp< testing::Memorying_testing_class >(), filled_omp );
	these_solids_should_not_be_equal( filled_omp, empty_omp );
	these_solids_should_not_be_equal( empty_omp, filled_omp );
}

CULE_TEST( Omp, should_copy ) {
	const Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	Omp< testing::Memorying_testing_class > omp_to_fill;
	omp_to_fill = filled_omp;

	this_object_should_not_be_empty( filled_omp );
	this_object_should_not_be_empty( omp_to_fill );
	these_solids_should_be_equal( filled_omp, omp_to_fill );
}

CULE_TEST( Omp, should_copy_construct ) {
	const Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	const Omp< testing::Memorying_testing_class > omp_to_fill = filled_omp;

	this_object_should_not_be_empty( filled_omp );
	this_object_should_not_be_empty( omp_to_fill );
	these_solids_should_be_equal( filled_omp, omp_to_fill );
}

CULE_TEST( Omp, should_move ) {
	Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	Omp< testing::Memorying_testing_class > omp_to_fill;
	omp_to_fill = ::std::move( filled_omp );

	this_object_should_not_be_empty( omp_to_fill );
	this_object_should_be_empty( filled_omp );
	these_solids_should_not_be_equal( filled_omp, omp_to_fill );
}

CULE_TEST( Omp, should_move_construct ) {
	Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	const Omp< testing::Memorying_testing_class > omp_to_fill = ::std::move( filled_omp );

	this_object_should_not_be_empty( omp_to_fill );
	this_object_should_be_empty( filled_omp );
	these_solids_should_not_be_equal( filled_omp, omp_to_fill );
}

CULE_TEST( Omp, should_copy_itself_and_same ) {
	Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	filled_omp = filled_omp;

	Omp< testing::Memorying_testing_class > omp_to_fill;
	omp_to_fill = filled_omp;

	this_object_should_not_be_empty( omp_to_fill );
	this_object_should_not_be_empty( filled_omp );
	these_solids_should_be_equal( filled_omp, omp_to_fill );
}

CULE_TEST( Omp, should_not_move_itself ) {
	Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	filled_omp = ::std::move( filled_omp );

	this_object_should_not_be_empty( filled_omp );
}

////CULE_TEST( Omp, should_dereference ) {
////	create filled_something;
////	access filled_something;
////}

CULE_TEST( Omp, should_get ) {
	const Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	these_solids_should_be_equal( testing_object->get_object_number_value(), filled_omp->get_object_number_value() );
}

CULE_TEST( Omp, should_take ) {
	Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	pointing::Scoped< testing::Memorying_testing_class > testing_object = pointing::Scoped< testing::Memorying_testing_class >::create( filled_omp );

	these_solids_should_be_equal( testing_object->get_object_number_value(), filled_omp->get_object_number_value() );
}

CULE_TEST( Omp, should_const_dereference ) {
	const Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	*filled_omp;
}

CULE_TEST( Omp, should_dereference ) {
	Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	*filled_omp;
}

CULE_TEST( Omp, should_const_access ) {
	const Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	filled_omp.operator ->();
}

CULE_TEST( Omp, should_access ) {
	Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	filled_omp.operator ->();
}

CULE_TEST( Omp, should_convert_to_ansii_text ) {
	const Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	const memorying::Womp< texting::Ansii_allocating_assistor > aaa = ::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor();

	pointing::cShared< texting::Ansii_text > object_memory_pointer_ansii_text;
	{
		const pointing::cShared< texting::Ansii_text > comma_and_space = texting::Aaa_sl( aaa, JMSF_SL( ", " ) );
		const pointing::cShared< texting::Ansii_text > square_bracket_and_space = texting::Aaa_sl( aaa, JMSF_SL( "[ " ) );
		const pointing::cShared< texting::Ansii_text > space_and_square_bracket = texting::Aaa_sl( aaa, JMSF_SL( " ]" ) );
		pointing::Shared< texting::Ansii_stream > ansii_stream = aaa->create_ansii_stream();

		ansii_stream->put( square_bracket_and_space );
		ansii_stream->put( filled_omp.get_object_address().to_ansii_text( aaa ) );
		ansii_stream->put( comma_and_space );
		ansii_stream->put( filled_omp.get_allocator().to_ansii_text( aaa ) );
		ansii_stream->put( comma_and_space );
		ansii_stream->put( filled_omp.get_alignment().to_ansii_text( aaa ) );
		ansii_stream->put( space_and_square_bracket );

		object_memory_pointer_ansii_text = texting::Aaa_cs( aaa, ansii_stream );
	}

	const pointing::cShared< texting::Ansii_text > filled_omp_ansii_text = filled_omp.to_ansii_text( aaa );

	these_ansii_texts_should_be_equal( object_memory_pointer_ansii_text, filled_omp_ansii_text );
}

CULE_TEST( Omp, should_return_allocator ) {
	const Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	these_solids_should_be_equal( ::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator(), filled_omp.get_allocator() );
}

CULE_TEST( Omp, should_return_memory_pointer ) {
	const Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	these_pointers_should_be_equal( testing_object.operator ->(), reinterpret_cast< const testing::Memorying_testing_class * >( filled_omp.get_object_address().get().get_native_value() ) );
}

CULE_TEST( Omp, should_return_alignment ) {
	const Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	these_solids_should_be_equal( typeing::size_of< testing::Memorying_testing_class >(), filled_omp.get_alignment() );
}

CULE_TEST( Omp, should_return_womp ) {
	const Omp< testing::Memorying_testing_class > filled_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( filled_omp );

	these_solids_should_be_equal(
		Womp< testing::Memorying_testing_class >::create( Object_pointer< testing::Memorying_testing_class >::create_from_pointer( filled_omp.operator ->() ) ),
		filled_omp.get_as_womp() );
}

////CULE_TEST( Omp, should_do_something_special ) {
////	create filled_something;
////	do something special with filled_something;

////	this_should_be( check something special with filled_something );
////}

} // namespace memorying
} // namespace jmsf
