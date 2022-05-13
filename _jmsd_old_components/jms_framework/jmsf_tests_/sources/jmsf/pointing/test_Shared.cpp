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


CULE_TEST( Shared, should_create_empty ) {
	Shared< testing::Pointing_testing_class > empty_shared;

	Cule_this( empty_shared ).should_be_empty();
	Cule_this( empty_shared.is_not_empty() );
	Cule_this( typeing::Memory_natural_nil ).should_be_equal_to( empty_shared.get_connectivity().get_total_connectivity() );
}

CULE_TEST( Shared, should_delete_empty ) {
	{
		Shared< testing::Pointing_testing_class > empty_shared;
	}
}

CULE_TEST( Shared, should_be_equal_empty_empty ) {
	const Shared< testing::Pointing_testing_class > empty_shared;

	Cule_this( Shared< testing::Pointing_testing_class >() ).should_be_equal_to( Shared< testing::Pointing_testing_class >() );
	Cule_this( empty_shared ).should_be_equal_to( empty_shared );
	Cule_this( empty_shared ).should_be_equal_to( Shared< testing::Pointing_testing_class >() );
	Cule_this( Shared< testing::Pointing_testing_class >() ).should_be_equal_to( empty_shared );
}

CULE_TEST( Shared, should_copy_empty ) {
	Shared< testing::Pointing_testing_class > empty_shared;
	Shared< testing::Pointing_testing_class > empty_shared_1;
	empty_shared_1 = empty_shared;

	Cule_this( empty_shared ).should_be_empty();
	Cule_this( empty_shared_1 ).should_be_empty();
	Cule_this( empty_shared_1.is_not_empty() ).should_not_be();
	Cule_this( typeing::Memory_natural_nil ).should_be_equal_to( empty_shared_1.get_connectivity().get_total_connectivity() );
}

CULE_TEST( Shared, should_copy_construct_empty ) {
	Shared< testing::Pointing_testing_class > empty_shared;
	Shared< testing::Pointing_testing_class > empty_shared_1 = empty_shared;

	Cule_this( empty_shared ).should_be_empty();
	Cule_this( empty_shared_1 ).should_be_empty();
	Cule_this( empty_shared_1.is_not_empty() ).should_not_be();
	Cule_this( typeing::Memory_natural_nil).should_be_equal_to( empty_shared_1.get_connectivity().get_total_connectivity() );
}

CULE_TEST_E( Shared, should_not_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
//TEST_EXCEPTION( tests_Shared, should_not_dereference_empty, validating::excepting::exception_Should ) {
	Shared< testing::Pointing_testing_class > empty_shared;
	*empty_shared;
}

CULE_TEST( Shared, should_share_empty_to_paired ) {
	Shared< testing::Pointing_testing_class > empty_shared;
	Weak< testing::Pointing_testing_class > empty_weak = empty_shared.get_as_weak();

	this_object_should_be_empty( empty_weak );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_weak.get_connectivity().get_total_connectivity() );
}

CULE_TEST( Shared, should_create ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();

	this_object_should_not_be_empty( filled_shared );
	this_should_be( filled_shared.is_not_empty() );
	this_should_not_be( filled_shared.is_empty() );
	these_solids_should_be_equal( typeing::Memory_natural_one, testing::Pointing_testing_class::get_object_counter_value() );

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, filled_shared.get_connectivity().get_weak_connectivity() );
}

CULE_TEST( Shared, should_delete_the_object ) {
	{
		Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
	}

	these_solids_should_be_equal( typeing::Memory_natural_nil, testing::Pointing_testing_class::get_object_counter_value() );
}

CULE_TEST( Shared, should_be_equal_equally_filled ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();

	const Shared< testing::Pointing_testing_class > filled_shared_1 = filled_shared.get_as_weak().get_as_shared();
	const Shared< testing::Pointing_testing_class > filled_shared_2 = filled_shared.get_as_weak().get_as_shared();

	Cule_this( filled_shared_1 ).should_be_equal_to( filled_shared_1 );
	Cule_this( filled_shared_1 ).should_be_equal_to( filled_shared_2 );
	Cule_this( filled_shared_2 ).should_be_equal_to( filled_shared_1 );
	Cule_this( filled_shared_2 ).should_be_equal_to( filled_shared_2 );
}

CULE_TEST( Shared, should_not_be_equal_differently_filled ) {
	const Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
	const Shared< testing::Pointing_testing_class > filled_shared_1 = testing::Pointing_testing_class::create_shared_testing_object();

	Cule_this( filled_shared ).should_be_equal_to( filled_shared );
	Cule_this( filled_shared ).should_not_be_equal_to( filled_shared_1 );
	Cule_this( filled_shared_1 ).should_not_be_equal_to( filled_shared );
	Cule_this( filled_shared_1 ).should_be_equal_to( filled_shared_1 );
}

CULE_TEST( Shared, should_copy ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();

	{
		Shared< testing::Pointing_testing_class > filled_shared_1;
		filled_shared_1 = filled_shared;

		this_object_should_not_be_empty( filled_shared );
		this_object_should_not_be_empty( filled_shared_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared_1.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared_1.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_nil, filled_shared_1.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_strong_connectivity() );
}

CULE_TEST( Shared, should_copy_construct ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();

	{
		Shared< testing::Pointing_testing_class > filled_shared_1 = filled_shared;

		this_object_should_not_be_empty( filled_shared );
		this_object_should_not_be_empty( filled_shared_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared_1.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared_1.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_nil, filled_shared_1.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_strong_connectivity() );
}

CULE_TEST( Shared, should_copy_itself_and_same ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
	filled_shared = filled_shared;

	{
		Shared< testing::Pointing_testing_class > filled_shared_1 = filled_shared;
		filled_shared_1 = filled_shared;

		this_object_should_not_be_empty( filled_shared );
		this_object_should_not_be_empty( filled_shared_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared_1.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared_1.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_nil, filled_shared_1.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_strong_connectivity() );
}

CULE_TEST( Shared, should_clear_itself_on_copy ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();

	{
		Shared< testing::Pointing_testing_class > filled_shared_1 = testing::Pointing_testing_class::create_shared_testing_object();
		filled_shared_1 = filled_shared;

		this_object_should_not_be_empty( filled_shared );
		this_object_should_not_be_empty( filled_shared_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared_1.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared_1.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_nil, filled_shared_1.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_strong_connectivity() );
}


CULE_TEST( Shared, should_dereference ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
	*filled_shared;
}

CULE_TEST( Shared, should_share_to_paired ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
	Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();

	this_object_should_not_be_empty( filled_weak );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared->get_object_number_value() );
	these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_weak.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_weak.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_weak.get_connectivity().get_weak_connectivity() );
}

CULE_TEST( Shared, should_correctly_share_emptied_to_empty_paired ) {
	Shared< testing::Pointing_testing_class > emptied_shared = testing::Pointing_testing_class::create_shared_testing_object();
	emptied_shared = Shared< testing::Pointing_testing_class >();

	this_object_should_be_empty( emptied_shared );

	Weak< testing::Pointing_testing_class > empty_weak = emptied_shared.get_as_weak();

	this_object_should_be_empty( empty_weak );
}

CULE_TEST( Shared, should_share_to_constant ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
	cShared< testing::Pointing_testing_class > filled_cshared = filled_shared.get_as_cshared();

	this_object_should_not_be_empty( filled_cshared );
	this_should_be( filled_cshared.is_not_empty() );

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cshared->get_object_counter_value() );
	these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, filled_shared.get_connectivity().get_weak_connectivity() );
}

CULE_TEST( Shared, should_correctly_share_emptied_to_empty_constant ) {
	Shared< testing::Pointing_testing_class > emptied_shared = testing::Pointing_testing_class::create_shared_testing_object();
	emptied_shared = Shared< testing::Pointing_testing_class >();

	this_object_should_be_empty( emptied_shared );

	cShared< testing::Pointing_testing_class > empty_cshared = emptied_shared.get_as_cshared();

	this_object_should_be_empty( empty_cshared );
}


} // namespace pointing
} // namespace jmsf
