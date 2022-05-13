#include "jmsf/cule/macroses_Test.h"


#include "testing/Memorying_testing_class.h"
#include "jmsf/testing/testing_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/pointing/cScoped.hin"

#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Omp.hin"
//#include "jmsf/memorying/Memory_pointer.hin"

#include "jmsf/typeing/Naturals.hin"
#include "jmsf/typeing/Boolean.h"

#include "jmsf/validating/excepting/exception_Should_with_type_information.h"

#include <utility>


namespace jmsf {
namespace memorying {


CULE_TEST( Womp, should_create_empty ) {
	const memorying::Womp< testing::Memorying_testing_class > empty_womp;
	this_object_should_be_empty( empty_womp );
}

CULE_TEST( Womp, should_delete_empty ) {
	{
		const memorying::Womp< testing::Memorying_testing_class > empty_womp;
	}
}

CULE_TEST( Womp, should_be_equal_empty_empty ) {
	const memorying::Womp< testing::Memorying_testing_class > empty_womp;
	these_solids_should_be_equal( memorying::Womp< testing::Memorying_testing_class >(), memorying::Womp< testing::Memorying_testing_class >() );
	these_solids_should_be_equal( empty_womp, empty_womp );
	these_solids_should_be_equal( empty_womp, memorying::Womp< testing::Memorying_testing_class >() );
	these_solids_should_be_equal( memorying::Womp< testing::Memorying_testing_class >(), empty_womp );
}

CULE_TEST( Womp, should_copy_empty ) {
	const memorying::Womp< testing::Memorying_testing_class > empty_womp;
	memorying::Womp< testing::Memorying_testing_class > womp_to_empty;
	womp_to_empty = empty_womp;

	this_object_should_be_empty( womp_to_empty );
	this_object_should_be_empty( empty_womp );
	these_solids_should_be_equal( empty_womp, womp_to_empty );
}

CULE_TEST( Womp, should_copy_construct_empty ) {
	const memorying::Womp< testing::Memorying_testing_class > empty_womp;
	const memorying::Womp< testing::Memorying_testing_class > womp_to_empty = empty_womp;

	this_object_should_be_empty( womp_to_empty );
	this_object_should_be_empty( empty_womp );
	these_solids_should_be_equal( empty_womp, womp_to_empty );
}

//TEST_EXCEPTION( Womp, should_not_get_empty, validating::excepting::exception_Should_with_type_information ) {
//	const memorying::Womp< testing::Memorying_testing_class > empty_womp;
//	empty_womp.get();
//}

//TEST_EXCEPTION( Womp, should_not_take_empty, validating::excepting::exception_Should_with_type_information ) {
//	memorying::Womp< testing::Memorying_testing_class > empty_womp;
//	empty_womp.take();
//}

CULE_TEST_E( Womp, should_not_const_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	const memorying::Womp< testing::Memorying_testing_class > empty_womp;
	*empty_womp;
}

CULE_TEST_E( Womp, should_not_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	memorying::Womp< testing::Memorying_testing_class > empty_womp;
	*empty_womp;
}

CULE_TEST_E( Womp, should_not_const_access_empty, validating::excepting::exception_Should_with_type_information ) {
	const memorying::Womp< testing::Memorying_testing_class > empty_womp;
	empty_womp.operator ->();
}

CULE_TEST_E( Womp, should_not_access_empty, validating::excepting::exception_Should_with_type_information ) {
	memorying::Womp< testing::Memorying_testing_class > empty_womp;
	empty_womp.operator ->();
}

// Seinsei: todonext - add to_ansii_text test for non-empty Womp
CULE_TEST( Womp, should_convert_empty_to_ansii_text ) {
	const pointing::cShared< texting::Ansii_text > nill_ansii_text =
		texting::Aaa_sl(
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor(),
			JMSF_SL( "[ 0 ]" ) );

	these_ansii_texts_should_be_equal(
		nill_ansii_text,
		Womp< testing::Memorying_testing_class >().to_ansii_text(
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor() ) );
}

//CULE_TEST( Womp, should_do_something_special_with_empty ) {
//	create empty_something;
//	do something special with empty_something;

//	this_should_be( check something special with empty_something );
//}

CULE_TEST( Womp, should_create ) {
	const typeing::Memory_natural deadbeaf = typeing::Memory_natural::create( 0xDEADBEAF );

	const Womp< testing::Memorying_testing_class > filled_womp =
		Womp< testing::Memorying_testing_class >::create(
			Object_pointer< testing::Memorying_testing_class >::create_from_address(
				deadbeaf ) );

	this_object_should_not_be_empty( filled_womp );
	these_solids_should_be_equal( deadbeaf, filled_womp.get_object_address() );
}

CULE_TEST( Womp, should_not_delete_the_object ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	{
		const Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	}

	this_object_should_not_be_empty( testing_object_omp );
	these_solids_should_be_equal( typeing::Memory_natural_one, testing::Memorying_testing_class::get_object_counter_value() );
	these_solids_should_be_equal( typeing::Memory_natural_one, testing_object->get_object_number_value() );
}

CULE_TEST( Womp, should_be_equal_filled_filled ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	const Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	const Womp< testing::Memorying_testing_class > filled_womp_1 = filled_womp;
	these_solids_should_be_equal( filled_womp, filled_womp );
	these_solids_should_be_equal( filled_womp, filled_womp_1 );
	these_solids_should_be_equal( filled_womp_1, filled_womp );
	these_solids_should_be_equal( filled_womp_1, filled_womp_1 );
}

CULE_TEST( Womp, should_be_equal_equally_filled ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	const Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	const Womp< testing::Memorying_testing_class > filled_womp_1 = testing_object_omp.get_as_womp();
	these_solids_should_be_equal( filled_womp, filled_womp );
	these_solids_should_be_equal( filled_womp, filled_womp_1 );
	these_solids_should_be_equal( filled_womp_1, filled_womp );
	these_solids_should_be_equal( filled_womp_1, filled_womp_1 );
}

CULE_TEST( Womp, should_not_be_equal_filled_empty ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	const Womp< testing::Memorying_testing_class > empty_womp;
	const Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	these_solids_should_not_be_equal( filled_womp, Womp< testing::Memorying_testing_class >() );
	these_solids_should_not_be_equal( Womp< testing::Memorying_testing_class >(), filled_womp );
	these_solids_should_not_be_equal( filled_womp, empty_womp );
	these_solids_should_not_be_equal( empty_womp, filled_womp );
}

CULE_TEST( Womp, should_copy ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	const Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	Womp< testing::Memorying_testing_class > womp_to_fill;
	womp_to_fill = filled_womp;

	this_object_should_not_be_empty( filled_womp );
	this_object_should_not_be_empty( womp_to_fill );
	these_solids_should_be_equal( filled_womp, womp_to_fill );
}

CULE_TEST( Womp, should_copy_construct ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	const Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	const Womp< testing::Memorying_testing_class > womp_to_fill = filled_womp;

	this_object_should_not_be_empty( womp_to_fill );
	this_object_should_not_be_empty( filled_womp );
	these_solids_should_be_equal( filled_womp, womp_to_fill );
}

CULE_TEST( Womp, should_move ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	Womp< testing::Memorying_testing_class > womp_to_fill;
	womp_to_fill = ::std::move( filled_womp );

	this_object_should_not_be_empty( womp_to_fill );
	this_object_should_be_empty( filled_womp );
	these_solids_should_not_be_equal( filled_womp, womp_to_fill );
}

CULE_TEST( Womp, should_move_construct ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	const Womp< testing::Memorying_testing_class > womp_to_fill = ::std::move( filled_womp );

	this_object_should_not_be_empty( womp_to_fill );
	this_object_should_be_empty( filled_womp );
	these_solids_should_not_be_equal( filled_womp, womp_to_fill );
}

CULE_TEST( Womp, should_copy_itself_and_same ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	filled_womp = filled_womp;

	Womp< testing::Memorying_testing_class > womp_to_fill;
	womp_to_fill = filled_womp;

	this_object_should_not_be_empty( womp_to_fill );
	this_object_should_not_be_empty( filled_womp );
	these_solids_should_be_equal( filled_womp, womp_to_fill );
}

CULE_TEST( Womp, should_not_move_itself ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	filled_womp = ::std::move( filled_womp );

	this_object_should_not_be_empty( filled_womp );
}

//CULE_TEST( Womp, should_dereference ) {
//	create filled_something;
//	access filled_something;
//}

//CULE_TEST( Womp, should_get ) {
//	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
//	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

//	const memorying::Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
//	these_pointers_should_be_equal( testing_object_omp.get(), filled_womp.get() );
//}

//CULE_TEST( Womp, should_take ) {
//	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
//	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

//	memorying::Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
//	these_pointers_should_be_equal( testing_object_omp.get(), filled_womp.take() );
//}

CULE_TEST( Womp, should_const_dereference ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	const memorying::Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	*filled_womp;
}

CULE_TEST( Womp, should_dereference ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	memorying::Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	*filled_womp;
}

CULE_TEST( Womp, should_const_access ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	const memorying::Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	filled_womp.operator ->();
}

CULE_TEST( Womp, should_access ) {
	const Omp< testing::Memorying_testing_class > testing_object_omp = testing::Memorying_testing_class::create_testing_object_omp();
	const pointing::cScoped< testing::Memorying_testing_class > testing_object = pointing::cScoped< testing::Memorying_testing_class >::create( testing_object_omp );

	memorying::Womp< testing::Memorying_testing_class > filled_womp = testing_object_omp.get_as_womp();
	filled_womp.operator ->();
}

//CULE_TEST( Womp, should_do_something_special ) {
//	create filled_something;
//	do something special with filled_something;

//	this_should_be( check something special with filled_something );
//}

} // namespace memorying
} // namespace jmsf
