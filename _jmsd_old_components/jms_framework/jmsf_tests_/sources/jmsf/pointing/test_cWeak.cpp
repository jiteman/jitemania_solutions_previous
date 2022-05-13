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


CULE_TEST( cWeak, should_create_empty ) {
	const cWeak< testing::Pointing_testing_class > empty_cweak;

	this_object_should_be_empty( empty_cweak );
	this_should_not_be( empty_cweak.is_not_empty() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_cweak.get_connectivity().get_total_connectivity() );
}

CULE_TEST( cWeak, should_delete_empty ) {
	{
		const cWeak< testing::Pointing_testing_class > empty_cweak;
	}
}

CULE_TEST( cWeak, should_be_equal_empty_empty ) {
	const cWeak< testing::Pointing_testing_class > empty_cweak;

	Cule_this( cWeak< testing::Pointing_testing_class >() ).should_be_equal_to( cWeak< testing::Pointing_testing_class >() );
	Cule_this( empty_cweak ).should_be_equal_to( empty_cweak );
	Cule_this( empty_cweak ).should_be_equal_to( cWeak< testing::Pointing_testing_class >() );
	Cule_this( cWeak< testing::Pointing_testing_class >() ).should_be_equal_to( empty_cweak );
}

CULE_TEST( cWeak, should_copy_empty ) {
	const cWeak< testing::Pointing_testing_class > empty_cweak;
	cWeak< testing::Pointing_testing_class > empty_cweak_1;
	empty_cweak_1 = empty_cweak;

	this_object_should_be_empty( empty_cweak );
	this_object_should_be_empty( empty_cweak_1 );
	this_should_not_be( empty_cweak_1.is_not_empty() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_cweak_1.get_connectivity().get_total_connectivity() );
}

CULE_TEST( cWeak, should_copy_construct_empty ) {
	const cWeak< testing::Pointing_testing_class > empty_cweak;
	const cWeak< testing::Pointing_testing_class > empty_cweak_1 = empty_cweak;

	this_object_should_be_empty( empty_cweak );
	this_object_should_be_empty( empty_cweak_1 );
	this_should_not_be( empty_cweak_1.is_not_empty() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_cweak_1.get_connectivity().get_total_connectivity() );
}

CULE_TEST_E( cWeak, should_not_const_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	const cWeak< testing::Pointing_testing_class > empty_cweak;
	*empty_cweak.get_as_cshared();
}

CULE_TEST_E( cWeak, should_not_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	cWeak< testing::Pointing_testing_class > empty_cweak;
	*empty_cweak.get_as_cshared();
}

CULE_TEST_E( cWeak, should_not_const_access_empty, validating::excepting::exception_Should_with_type_information ) {
	const cWeak< testing::Pointing_testing_class > empty_cweak;
	empty_cweak.get_as_cshared().operator ->();
}

CULE_TEST_E( cWeak, should_not_access_empty, validating::excepting::exception_Should_with_type_information ) {
	cWeak< testing::Pointing_testing_class > empty_cweak;
	empty_cweak.get_as_cshared().operator ->();
}

CULE_TEST( cWeak, should_share_empty_to_paired ) {
	const cWeak< testing::Pointing_testing_class > empty_cweak;
	const cShared< testing::Pointing_testing_class > empty_cshared = empty_cweak.get_as_cshared();

	this_object_should_be_empty( empty_cshared );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_cshared.get_connectivity().get_total_connectivity() );
}

CULE_TEST( cWeak, should_create ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	const cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();

	this_object_should_not_be_empty( filled_cweak );
	this_should_be( filled_cweak.is_not_empty() );
	this_should_not_be( filled_cweak.is_empty() );
	these_solids_should_be_equal( typeing::Memory_natural_one, testing::Pointing_testing_class::get_object_counter_value() );

	these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cshared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( filled_cshared.get_connectivity().get_total_connectivity(), filled_cweak.get_connectivity().get_total_connectivity() );

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_weak_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cweak.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cweak.get_connectivity().get_weak_connectivity() );
}

CULE_TEST( cWeak, should_not_delete_the_object ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();

	{
		const cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
	}

	*filled_cshared;

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, filled_cshared.get_connectivity().get_weak_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, testing::Pointing_testing_class::get_object_counter_value() );
}

CULE_TEST( cWeak, should_not_be_equal_filled_empty ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();

	const cWeak< testing::Pointing_testing_class > empty_cweak;
	const cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
	these_solids_should_not_be_equal( filled_cweak, cWeak< testing::Pointing_testing_class >() );
	these_solids_should_not_be_equal( cWeak< testing::Pointing_testing_class >(), filled_cweak );
	these_solids_should_not_be_equal( filled_cweak, empty_cweak );
	these_solids_should_not_be_equal( empty_cweak, filled_cweak );
}

CULE_TEST( cWeak, should_be_equal_equally_filled ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();

	const cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
	const cWeak< testing::Pointing_testing_class > filled_cweak_1 = filled_cshared.get_as_cweak();

	Cule_this( filled_cweak ).should_be_equal_to( filled_cweak );
	Cule_this( filled_cweak ).should_be_equal_to( filled_cweak_1 );
	Cule_this( filled_cweak_1 ).should_be_equal_to( filled_cweak );
	Cule_this( filled_cweak_1 ).should_be_equal_to( filled_cweak_1 );
}

CULE_TEST( cWeak, should_not_be_equal_differently_filled ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	const cShared< testing::Pointing_testing_class > filled_cshared_1 = testing::Pointing_testing_class::create_cshared_testing_object();

	const cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
	const cWeak< testing::Pointing_testing_class > filled_cweak_1 = filled_cshared_1.get_as_cweak();

	Cule_this( filled_cweak ).should_be_equal_to( filled_cweak );
	Cule_this( filled_cweak ).should_not_be_equal_to( filled_cweak_1 );
	Cule_this( filled_cweak_1 ).should_not_be_equal_to( filled_cweak );
	Cule_this( filled_cweak_1 ).should_be_equal_to( filled_cweak_1 );
}

CULE_TEST( cWeak, should_copy ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();

	{
		const cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
		cWeak< testing::Pointing_testing_class > filled_cweak_1;
		filled_cweak_1 = filled_cweak;

		this_object_should_not_be_empty( filled_cweak );
		this_object_should_not_be_empty( filled_cweak_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_cweak.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_cweak.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cweak.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_total_connectivity() );
}

CULE_TEST( cWeak, should_copy_construct ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();

	{
		const cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
		const cWeak< testing::Pointing_testing_class > filled_cweak_1 = filled_cweak;

		this_object_should_not_be_empty( filled_cweak );
		this_object_should_not_be_empty( filled_cweak_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_cweak.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_cweak.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cweak.get_connectivity().get_weak_connectivity() );

	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_total_connectivity() );
}

CULE_TEST( cWeak, should_copy_itself ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();

	{
		cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
		filled_cweak = filled_cweak;
		cWeak< testing::Pointing_testing_class > filled_cweak_1 = filled_cweak;
		filled_cweak_1 = filled_cweak;

		this_object_should_not_be_empty( filled_cweak );
		this_object_should_not_be_empty( filled_cweak_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_cweak.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_cweak.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cweak.get_connectivity().get_weak_connectivity() );

	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_total_connectivity() );
}

CULE_TEST( cWeak, should_clear_itself_on_copy ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	const cShared< testing::Pointing_testing_class > filled_cshared_1 = testing::Pointing_testing_class::create_cshared_testing_object();

	{
		const cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
		cWeak< testing::Pointing_testing_class > filled_cweak_1 = filled_cshared_1.get_as_cweak();
		filled_cweak_1 = filled_cweak;

		this_object_should_not_be_empty( filled_cweak );
		this_object_should_not_be_empty( filled_cweak_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_cweak.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_cweak.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cweak.get_connectivity().get_weak_connectivity() );

		these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_cshared.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cshared.get_connectivity().get_weak_connectivity() );

		these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared_1.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared_1.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_nil, filled_cshared_1.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_total_connectivity() );
}

CULE_TEST( cWeak, should_const_dereference ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	const cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
	*filled_cweak.get_as_cshared();
}

CULE_TEST( cWeak, should_dereference ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
	*filled_cweak.get_as_cshared();
}

CULE_TEST( cWeak, should_const_access ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	const cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
	filled_cweak.get_as_cshared().operator ->();
}

CULE_TEST( cWeak, should_access ) {
	const cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
	filled_cweak.get_as_cshared().operator ->();
}

CULE_TEST( cWeak, should_share_to_paired ) {
	cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
	cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();

	this_object_should_not_be_empty( filled_cweak );

	cShared< testing::Pointing_testing_class > filled_cshared_2 = filled_cweak.get_as_cshared();

	this_object_should_not_be_empty( filled_cshared_2 );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared_2->get_object_number_value() );
	these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_cshared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_cshared.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared.get_connectivity().get_weak_connectivity() );
}

CULE_TEST( cWeak, should_correctly_share_emptied_to_empty_paired ) {
	cWeak< testing::Pointing_testing_class > empty_cweak;

	{
		cShared< testing::Pointing_testing_class > filled_cshared = testing::Pointing_testing_class::create_cshared_testing_object();
		empty_cweak = filled_cshared.get_as_cweak();

		this_object_should_not_be_empty( empty_cweak );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared->get_object_number_value() );
		these_solids_should_be_equal( typeing::Memory_natural_one, testing::Pointing_testing_class::get_object_counter_value() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_nil, testing::Pointing_testing_class::get_object_counter_value() );

	cShared< testing::Pointing_testing_class > empty_shared = empty_cweak.get_as_cshared();

	this_object_should_be_empty( empty_shared );
	this_object_should_be_empty( empty_cweak );

	these_solids_should_be_equal( typeing::Memory_natural_one, empty_cweak.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_cweak.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, empty_cweak.get_connectivity().get_weak_connectivity() );
}


} // namespace pointing
} // namespace jmsf
