#include "jmsf/cule/macroses_Test.h"


#include "testing/Pointing_testing_class.h"

#include "jmsf/pointing/Weak.hin"
#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"
#include "jmsf/typeing/Naturals.hin"

#include "jmsf/validating/excepting/exception_Should_with_type_information.h"


namespace jmsf {
namespace pointing {


CULE_TEST( cShared, should_create_empty ) {
	cShared< testing::Pointing_testing_class > empty_cshared;

	Cule_this( empty_cshared ).should_be_empty();
	Cule_this( empty_cshared.is_not_empty() ).should_not_be();
	Cule_this( typeing::Memory_natural_nil ).should_be_equal_to( empty_cshared.get_connectivity().get_total_connectivity() );
}

CULE_TEST( cShared, should_delete_empty ) {
	{
		cShared< testing::Pointing_testing_class > empty_cshared;
	}
}

CULE_TEST( cShared, should_be_equal_empty_empty ) {
	const cShared< testing::Pointing_testing_class > empty_cshared;

	Cule_this( cShared< testing::Pointing_testing_class >() ).should_be_equal_to( cShared< testing::Pointing_testing_class >() );
	Cule_this( empty_cshared ).should_be_equal_to( empty_cshared );
	Cule_this( empty_cshared ).should_be_equal_to( cShared< testing::Pointing_testing_class >() );
	Cule_this( cShared< testing::Pointing_testing_class >() ).should_be_equal_to( empty_cshared );
}

CULE_TEST( cShared, should_copy_empty ) {
	cShared< testing::Pointing_testing_class > empty_cshared;
	cShared< testing::Pointing_testing_class > empty_cshared_1;

	empty_cshared_1 = empty_cshared;

	this_object_should_be_empty( empty_cshared );
	this_object_should_be_empty( empty_cshared_1 );
	this_should_not_be( empty_cshared_1.is_not_empty() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_cshared_1.get_connectivity().get_total_connectivity() );
}

CULE_TEST( cShared, should_copy_construct_empty ) {
	cShared< testing::Pointing_testing_class > empty_cshared;
	cShared< testing::Pointing_testing_class > empty_cshared_1 = empty_cshared;

	this_object_should_be_empty( empty_cshared );
	this_object_should_be_empty( empty_cshared_1 );
	this_should_not_be( empty_cshared_1.is_not_empty() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_cshared_1.get_connectivity().get_total_connectivity() );
}

CULE_TEST_E( cShared, should_not_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	cShared< testing::Pointing_testing_class > empty_cshared;

	*empty_cshared;
}

CULE_TEST( cShared, should_share_empty_to_paired ) {
	cShared< testing::Pointing_testing_class > empty_cshared;
	cWeak< testing::Pointing_testing_class > empty_cweak = empty_cshared.get_as_cweak();

	this_object_should_be_empty( empty_cweak );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_cweak.get_connectivity().get_total_connectivity() );
}

CULE_TEST( cShared, should_create ) {
	cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();

	this_object_should_not_be_empty( filled_cshared );
	this_should_be( filled_cshared.is_not_empty() );
	this_should_not_be( filled_cshared.is_empty() );
	these_solids_should_be_equal( typeing::Memory_natural_one, testing::Pointing_testing_class::get_object_counter_value() );

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, filled_cshared.get_connectivity().get_weak_connectivity() );
}

CULE_TEST( cShared, should_delete_the_object ) {
	{
		cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	}

	these_solids_should_be_equal( typeing::Memory_natural_nil, testing::Pointing_testing_class::get_object_counter_value() );
}

CULE_TEST( cShared, should_be_equal_equally_filled ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();

	const cShared< testing::Pointing_testing_class > filled_cshared_1 = filled_cshared.get_as_cweak().get_as_cshared();
	const cShared< testing::Pointing_testing_class > filled_cshared_2 = filled_cshared.get_as_cweak().get_as_cshared();

	Cule_this( filled_cshared_1 ).should_be_equal_to( filled_cshared_1 );
	Cule_this( filled_cshared_1 ).should_be_equal_to( filled_cshared_2 );
	Cule_this( filled_cshared_2 ).should_be_equal_to( filled_cshared_1 );
	Cule_this( filled_cshared_2 ).should_be_equal_to( filled_cshared_2 );
}

CULE_TEST( cShared, should_not_be_equal_differently_filled ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	const cShared< testing::Pointing_testing_class > filled_cshared_1 = testing::Pointing_testing_class::create_cshared_testing_object();

	Cule_this( filled_cshared ).should_be_equal_to( filled_cshared );
	Cule_this( filled_cshared ).should_not_be_equal_to( filled_cshared_1 );
	Cule_this( filled_cshared_1 ).should_not_be_equal_to( filled_cshared );
	Cule_this( filled_cshared_1 ).should_be_equal_to( filled_cshared_1 );
}

CULE_TEST( cShared, should_copy ) {
	cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();

	{
		cShared< testing::Pointing_testing_class > filled_cshared_1;
		filled_cshared_1 = filled_cshared;

		this_object_should_not_be_empty( filled_cshared );
		this_object_should_not_be_empty( filled_cshared_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cshared_1.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cshared_1.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_nil, filled_cshared_1.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_strong_connectivity() );
}

CULE_TEST( cShared, should_copy_construct ) {
	cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();

	{
		cShared< testing::Pointing_testing_class > filled_cshared_1 = filled_cshared;

		this_object_should_not_be_empty( filled_cshared );
		this_object_should_not_be_empty( filled_cshared_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cshared_1.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cshared_1.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_nil, filled_cshared_1.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_strong_connectivity() );
}

CULE_TEST( cShared, should_copy_itself_and_same ) {
	cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	filled_cshared = filled_cshared;

	{
		cShared< testing::Pointing_testing_class > filled_cshared_1 = filled_cshared;
		filled_cshared_1 = filled_cshared;

		this_object_should_not_be_empty( filled_cshared );
		this_object_should_not_be_empty( filled_cshared_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cshared_1.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cshared_1.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_nil, filled_cshared_1.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_strong_connectivity() );
}

CULE_TEST( cShared, should_clear_itself_on_copy ) {
	cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();

	{
		cShared< testing::Pointing_testing_class > filled_cshared_1 = testing::Pointing_testing_class::create_cshared_testing_object();
		filled_cshared_1 = filled_cshared;

		this_object_should_not_be_empty( filled_cshared );
		this_object_should_not_be_empty( filled_cshared_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cshared_1.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cshared_1.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_nil, filled_cshared_1.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_strong_connectivity() );
}


CULE_TEST( cShared, should_dereference ) {
	cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	*filled_cshared;
}

CULE_TEST( cShared, should_share_to_paired ) {
	cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();

	this_object_should_not_be_empty( filled_cweak );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared->get_object_number_value() );
	these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cweak.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cweak.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cweak.get_connectivity().get_weak_connectivity() );
}

CULE_TEST( cShared, should_correctly_share_emptied_to_empty_paired ) {
	cShared< testing::Pointing_testing_class > emptied_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	emptied_cshared = cShared< testing::Pointing_testing_class >();

	this_object_should_be_empty( emptied_cshared );

	cWeak< testing::Pointing_testing_class > empty_cweak = emptied_cshared.get_as_cweak();

	this_object_should_be_empty( empty_cweak );
}


} // namespace pointing
} // namespace jmsf
