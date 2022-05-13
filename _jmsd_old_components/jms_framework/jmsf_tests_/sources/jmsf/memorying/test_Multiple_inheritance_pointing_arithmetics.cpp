#include "jmsf/cule/macroses_Test.h"


#include "testing_mipa/Diamond_child.h"
#include "testing_mipa/sensing_mipa/sensation_of_mipa_Construction_and_destruction.h"

#include "jmsf/testing/testing_Allocators.h"

#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cScoped.hin"

#include "jmsf/memorying/Amp.hin"
#include "jmsf/memorying/Awa_iterator.hin"

#include "jmsf/typeing/Naturals.hin"


namespace jmsf {
namespace memorying {


CULE_TEST( Multiple_ingeritance_pointer_arithmetics, should_do ) {
	pointing::Shared< testing_mipa::sensing_mipa::sensation_of_mipa_Construction_and_destruction > the_sensor =
		testing_mipa::sensing_mipa::sensation_of_mipa_Construction_and_destruction::create();

	{
		memorying::Omp< testing_mipa::Interface_parent > interface_omp =
			memorying::Constructor< testing_mipa::Interface_parent, testing_mipa::Diamond_child >::construct(
				::jmsf::testing::testing_Allocators::instance()->get_subsystem_allocator(),
				1,
				2,
				3,
				the_sensor );

		pointing::cScoped< testing_mipa::Interface_parent > scoped_interface =
			pointing::cScoped< testing_mipa::Interface_parent >::create( interface_omp );

		these_solids_should_be_equal( typeing::Memory_integer::create( 6 ), typeing::Memory_integer::create( interface_omp->interface_get_integer_sum() ) );
		these_solids_should_be_equal( typeing::Memory_natural::create( 6 ), the_sensor.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 6 ), the_sensor.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 0 ), the_sensor.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, the_sensor->get_diamond_destruction_counter() );
	these_solids_should_be_equal( typeing::Memory_natural_one, the_sensor->get_diamond_construction_counter() );

	these_solids_should_be_equal( typeing::Memory_natural_one, the_sensor->get_interface_destruction_counter() );
	these_solids_should_be_equal( typeing::Memory_natural_one, the_sensor->get_interface_construction_counter() );

	these_solids_should_be_equal( typeing::Memory_natural_one, the_sensor->get_mixin_destruction_counter() );
	these_solids_should_be_equal( typeing::Memory_natural_one, the_sensor->get_mixin_construction_counter() );

	these_solids_should_be_equal( typeing::Memory_natural_one, the_sensor->get_template_destruction_counter() );
	these_solids_should_be_equal( typeing::Memory_natural_one, the_sensor->get_template_construction_counter() );

	these_solids_should_be_equal( typeing::Memory_natural_one, the_sensor->get_virtual_destruction_counter() );
	these_solids_should_be_equal( typeing::Memory_natural_one, the_sensor->get_virtual_construction_counter() );

	these_solids_should_be_equal( typeing::Memory_natural::create( 5 ), the_sensor->get_total_construction_counter() );
	these_solids_should_be_equal( typeing::Memory_natural::create( 5 ), the_sensor->get_total_destruction_counter() );
}

CULE_TEST( Multiple_ingeritance_pointer_arithmetics, should_do_amp ) {
	pointing::Shared< testing_mipa::sensing_mipa::sensation_of_mipa_Construction_and_destruction > the_sensor =
		testing_mipa::sensing_mipa::sensation_of_mipa_Construction_and_destruction::create();

	const typeing::Memory_natural quantity = typeing::Memory_natural::create( 3 );

	{
		memorying::Amp< testing_mipa::Interface_parent > interface_amp =
			memorying::Constructor< testing_mipa::Interface_parent, testing_mipa::Diamond_child >::construct_as_array(
				::jmsf::testing::testing_Allocators::instance()->get_subsystem_allocator(),
				quantity,
				1,
				2,
				3,
				the_sensor );

		for (
			memorying::Awa_iterator< testing_mipa::Interface_parent > iterator = interface_amp.get();
			iterator.is_in_range();
			++iterator )
		{
			these_solids_should_be_equal( typeing::Memory_integer::create( 6 ), typeing::Memory_integer::create( iterator->interface_get_integer_sum() ) );
		}

		these_solids_should_be_equal(
			typeing::Memory_natural::create( 5 ) * quantity + typeing::Memory_natural_one,
			the_sensor.get_connectivity().get_total_connectivity() );

		these_solids_should_be_equal( typeing::Memory_natural::create( 5 ) * quantity + typeing::Memory_natural_one, the_sensor.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_nil, the_sensor.get_connectivity().get_weak_connectivity() );

		memorying::Destructor< testing_mipa::Interface_parent >::destruct( interface_amp );
	}

	these_solids_should_be_equal( quantity, the_sensor->get_diamond_destruction_counter() );
	these_solids_should_be_equal( quantity, the_sensor->get_diamond_construction_counter() );

	these_solids_should_be_equal( quantity, the_sensor->get_interface_destruction_counter() );
	these_solids_should_be_equal( quantity, the_sensor->get_interface_construction_counter() );

	these_solids_should_be_equal( quantity, the_sensor->get_mixin_destruction_counter() );
	these_solids_should_be_equal( quantity, the_sensor->get_mixin_construction_counter() );

	these_solids_should_be_equal( quantity, the_sensor->get_template_destruction_counter() );
	these_solids_should_be_equal( quantity, the_sensor->get_template_construction_counter() );

	these_solids_should_be_equal( quantity, the_sensor->get_virtual_destruction_counter() );
	these_solids_should_be_equal( quantity, the_sensor->get_virtual_construction_counter() );

	these_solids_should_be_equal( typeing::Memory_natural::create( 5 ) * quantity, the_sensor->get_total_construction_counter() );
	these_solids_should_be_equal( typeing::Memory_natural::create( 5 ) * quantity, the_sensor->get_total_destruction_counter() );
}

//CULE_TEST( jmsf_Template, should_create_empty ) {
//	create empty_something;

//	this_object_should_be_empty( empty_something );
//}

//CULE_TEST( jmsf_Template, should_delete_empty ) {
//	{
//		create empty_something;
//	}
//}

//CULE_TEST( jmsf_Template, should_be_equal_empty_empty ) {
//	create empty_something;
//	these_solids_should_be_equal( something(), something() );
//	these_solids_should_be_equal( empty_something, empty_something );
//	these_solids_should_be_equal( empty_something, something() );
//	these_solids_should_be_equal( something(), empty_something );
//}

//CULE_TEST( jmsf_Template, should_copy_empty ) {
//	create empty_something;
//	create something_to_empty;
//	something_to_empty = empty_something;

//	this_object_should_be_empty( something_to_empty );
//	this_object_should_be_empty( empty_something );
//	these_solids_should_be_equal( empty_something, something_to_empty );
//}

//CULE_TEST( jmsf_Template, should_copy_construct_empty ) {
//	create empty_something;
//	create something_to_empty = empty_something;

//	this_object_should_be_empty( something_to_empty );
//	this_object_should_be_empty( empty_something );
//	these_solids_should_be_equal( empty_something, something_to_empty );
//}

//TEST_EXCEPTION( jmsf_Template, should_not_const_dereference_empty, validating::excepting::exception_Should ) {
//	create empty_something;
//	access empty_something;
//}

//TEST_EXCEPTION( jmsf_Template, should_not_dereference_empty, validating::excepting::exception_Should ) {
//	create empty_something;
//	access empty_something;
//}

//CULE_TEST( jmsf_Template, should_convert_empty_to_ansii_text ) {
//	const pointing::cShared< texting::Ansii_text > nill_ansii_text =
//		texting::Aaa_sl(
//			jmsf_Allocators::instance()->get_ansii_allocating_assistor(),
//			JMSF_SL( "0" ) );

//	these_ansii_texts_should_be_equal( nill_ansii_text, jmsf_Template().to_ansii_text() );
//}

//CULE_TEST( jmsf_Template, should_do_something_special_with_empty ) {
//	create empty_something;
//	do something special with empty_something;
//	this_should_be( check something special with empty_something );
//}

//CULE_TEST( jmsf_Template, should_create ) {
//	create filled_something;
//	this_object_should_not_be_empty( filled_something );
//}

//CULE_TEST( jmsf_Template, should_delete_the_object ) {
//	{
//		create filled_something;
//	}

//	this_should_be( check deletion of filled_something );
//}

//CULE_TEST( jmsf_Template, should_not_be_equal_filled_empty ) {
//	create empty_something;
//	create filled_something;
//	these_solids_should_not_be_equal( filled_something, something() );
//	these_solids_should_not_be_equal( something(), filled_something );
//	these_solids_should_not_be_equal( filled_something, empty_something );
//	these_solids_should_not_be_equal( empty_something, filled_something );
//}

//CULE_TEST( jmsf_Template, should_be_equal_equally_filled ) {
//	create filled_something = value;
//	create filled_something_1 = value;
//	these_solids_should_be_equal( filled_something, filled_something );
//	these_solids_should_be_equal( filled_something, filled_something_1 );
//	these_solids_should_be_equal( filled_something_1, filled_something );
//	these_solids_should_be_equal( filled_something_1, filled_something_1 );
//}

//CULE_TEST( jmsf_Template, should_not_be_equal_differently_filled ) {
//	create filled_something = value;
//	create filled_something_1 = value_1;
//	these_solids_should_be_equal( filled_something, filled_something );
//	these_solids_should_not_be_equal( filled_something, filled_something_1 );
//	these_solids_should_not_be_equal( filled_something_1, filled_something );
//	these_solids_should_be_equal( filled_something_1, filled_something_1 );
//}

//CULE_TEST( jmsf_Template, should_copy ) {
//	create filled_something;
//	create something_to_fill;
//	empty_something = filled_something;

//	this_object_should_not_be_empty( something_to_fill );
//	this_object_should_not_be_empty( filled_something );
//	these_solids_should_be_equal( filled_something, something_to_fill );
//}

//CULE_TEST( jmsf_Template, should_copy_construct ) {
//	create filled_something;
//	create something_to_fill = filled_something;

//	this_object_should_not_be_empty( something_to_fill );
//	this_object_should_not_be_empty( filled_something );
//	these_solids_should_be_equal( filled_something, something_to_fill );
//}

//CULE_TEST( jmsf_Template, should_move ) {
//	create filled_something;
//	create something_to_fill;
//	something_to_fill = ::std::move( filled_something );

//	this_object_should_not_be_empty( something_to_fill );
//	this_object_should_be_empty( filled_something );
//	these_solids_should_not_be_equal( filled_something, something_to_fill );
//}

//CULE_TEST( jmsf_Template, should_move_construct ) {
//	create filled_something;
//	create something_to_fill = ::std::move( filled_something );

//	this_object_should_not_be_empty( something_to_fill );
//	this_object_should_be_empty( filled_something );
//	these_solids_should_not_be_equal( filled_something, something_to_fill );
//}

//CULE_TEST( jmsf_Template, should_copy_itself_and_same ) {
//	create filled_something;
//	filled_something = filled_something;
//	create something_to_fill = filled_something;
//	something_to_fill = filled_something;

//	this_object_should_not_be_empty( something_to_fill );
//	this_object_should_not_be_empty( filled_something );
//	these_solids_should_be_equal( filled_something, something_to_fill );
//}

//CULE_TEST( jmsf_Template, should_not_move_itself ) {
//	create filled_something;
//	filled_something = ::std::move( filled_something );

//	this_object_should_not_be_empty( filled_something );
//}

//CULE_TEST( jmsf_Template, should_dereference ) {
//	create filled_something;
//	access filled_something;
//}

//CULE_TEST( jmsf_Template, should_convert_to_ansii_text ) {
//	const pointing::cShared< texting::Ansii_text > deadbeaf_ansii_text =
//		texting::Aaa_sl(
//			jmsf_Allocators::instance()->get_ansii_allocating_assistor(),
//			JMSF_SL( "DEADBEAF" ) );

//	const Memory_pointer filled_template = jmsf_Template::create_from_address( deadbeaf );

//	these_ansii_texts_should_be_equal( deadbeaf_ansii_text, filled_template.to_ansii_text() );
//}

//CULE_TEST( jmsf_Template, should_do_something_special ) {
//	create filled_something;
//	do something special with filled_something;

//	this_should_be( check something special with filled_something );
//}


} // namespace memorying
} // namespace jmsf
