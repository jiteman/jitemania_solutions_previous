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


CULE_TEST( Weak, should_create_empty ) {
	const Weak< testing::Pointing_testing_class > empty_weak;

	this_object_should_be_empty( empty_weak );
	this_should_not_be( empty_weak.is_not_empty() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_weak.get_connectivity().get_total_connectivity() );
}

CULE_TEST( Weak, should_delete_empty ) {
	{
		const Weak< testing::Pointing_testing_class > empty_weak;
	}
}

CULE_TEST( Weak, should_be_equal_empty_empty ) {
	const Weak< testing::Pointing_testing_class > empty_weak;

	Cule_this( Weak< testing::Pointing_testing_class >() ).should_be_equal_to( Weak< testing::Pointing_testing_class >() );
	Cule_this( empty_weak ).should_be_equal_to( empty_weak );
	Cule_this( empty_weak ).should_be_equal_to( Weak< testing::Pointing_testing_class >() );
	Cule_this( Weak< testing::Pointing_testing_class >() ).should_be_equal_to( empty_weak );
}

CULE_TEST( Weak, should_copy_empty ) {
	const Weak< testing::Pointing_testing_class > empty_weak;
	Weak< testing::Pointing_testing_class > empty_weak_1;
	empty_weak_1 = empty_weak;

	this_object_should_be_empty( empty_weak );
	this_object_should_be_empty( empty_weak_1 );
	this_should_not_be( empty_weak_1.is_not_empty() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_weak_1.get_connectivity().get_total_connectivity() );
}

CULE_TEST( Weak, should_copy_construct_empty ) {
	const Weak< testing::Pointing_testing_class > empty_weak;
	Weak< testing::Pointing_testing_class > empty_weak_1 = empty_weak;

	this_object_should_be_empty( empty_weak );
	this_object_should_be_empty( empty_weak_1 );
	this_should_not_be( empty_weak_1.is_not_empty() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_weak_1.get_connectivity().get_total_connectivity() );
}

CULE_TEST_E( Weak, should_not_const_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	const Weak< testing::Pointing_testing_class > empty_weak;
	*empty_weak.get_as_cshared();
}

CULE_TEST_E( Weak, should_not_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	Weak< testing::Pointing_testing_class > empty_weak;
	*empty_weak.get_as_shared();
}

CULE_TEST_E( Weak, should_not_const_access_empty, validating::excepting::exception_Should_with_type_information ) {
	const Weak< testing::Pointing_testing_class > empty_weak;
	empty_weak.get_as_cshared().operator ->();
}

CULE_TEST_E( Weak, should_not_access_empty, validating::excepting::exception_Should_with_type_information ) {
	Weak< testing::Pointing_testing_class > empty_weak;
	empty_weak.get_as_shared().operator ->();
}

CULE_TEST( Weak, should_share_empty_to_paired ) {
	Weak< testing::Pointing_testing_class > empty_weak;
	Shared< testing::Pointing_testing_class > empty_shared = empty_weak.get_as_shared();

	this_object_should_be_empty( empty_shared );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_shared.get_connectivity().get_total_connectivity() );
}

CULE_TEST( Weak, should_share_empty_to_constant ) {
	const Weak< testing::Pointing_testing_class > empty_weak;
	cWeak< testing::Pointing_testing_class > empty_cweak = empty_weak.get_as_cweak();

	this_object_should_be_empty( empty_cweak );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_cweak.get_connectivity().get_total_connectivity() );
}

CULE_TEST( Weak, should_create ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
	const Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();

	this_object_should_not_be_empty( filled_weak );
	this_should_be( filled_weak.is_not_empty() );
	this_should_not_be( filled_weak.is_empty() );
	these_solids_should_be_equal( typeing::Memory_natural_one, testing::Pointing_testing_class::get_object_counter_value() );

	these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( filled_shared.get_connectivity().get_total_connectivity(), filled_weak.get_connectivity().get_total_connectivity() );

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_weak_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_weak.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_weak.get_connectivity().get_weak_connectivity() );
}

CULE_TEST( Weak, should_not_delete_the_object ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();

	{
		Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
	}

	*filled_shared;

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, filled_shared.get_connectivity().get_weak_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, testing::Pointing_testing_class::get_object_counter_value() );
}

CULE_TEST( Weak, should_be_equal_equally_filled ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();

	const Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
	const Weak< testing::Pointing_testing_class > filled_weak_1 = filled_shared.get_as_weak();
	these_solids_should_be_equal( filled_weak, filled_weak );
	these_solids_should_be_equal( filled_weak, filled_weak_1 );
	these_solids_should_be_equal( filled_weak_1, filled_weak );
	these_solids_should_be_equal( filled_weak_1, filled_weak_1 );
}

CULE_TEST( Weak, should_not_be_equal_differently_filled ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
	Shared< testing::Pointing_testing_class > filled_shared_1 = testing::Pointing_testing_class::create_shared_testing_object();

	const Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
	const Weak< testing::Pointing_testing_class > filled_weak_1 = filled_shared_1.get_as_weak();
	these_solids_should_be_equal( filled_weak, filled_weak );
	these_solids_should_not_be_equal( filled_weak, filled_weak_1 );
	these_solids_should_not_be_equal( filled_weak_1, filled_weak );
	these_solids_should_be_equal( filled_weak_1, filled_weak_1 );
}

CULE_TEST( Weak, should_copy ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();

	{
		Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
		Weak< testing::Pointing_testing_class > filled_weak_1;
		filled_weak_1 = filled_weak;

		this_object_should_not_be_empty( filled_weak );
		this_object_should_not_be_empty( filled_weak_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_weak.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_weak.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_weak.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_total_connectivity() );
}

CULE_TEST( Weak, should_copy_construct ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();

	{
		Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
		Weak< testing::Pointing_testing_class > filled_weak_1 = filled_weak;

		this_object_should_not_be_empty( filled_weak );
		this_object_should_not_be_empty( filled_weak_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_weak.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_weak.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_weak.get_connectivity().get_weak_connectivity() );

	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_total_connectivity() );
}

CULE_TEST( Weak, should_copy_itself ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();

	{
		Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
		filled_weak = filled_weak;
		Weak< testing::Pointing_testing_class > filled_weak_1 = filled_weak;
		filled_weak_1 = filled_weak;

		this_object_should_not_be_empty( filled_weak );
		this_object_should_not_be_empty( filled_weak_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_weak.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_weak.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_weak.get_connectivity().get_weak_connectivity() );

	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_total_connectivity() );
}

CULE_TEST( Weak, should_clear_itself_on_copy ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
	Shared< testing::Pointing_testing_class > filled_shared_1 = testing::Pointing_testing_class::create_shared_testing_object();

	{
		Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
		Weak< testing::Pointing_testing_class > filled_weak_1 = filled_shared_1.get_as_weak();
		filled_weak_1 = filled_weak;

		this_object_should_not_be_empty( filled_weak );
		this_object_should_not_be_empty( filled_weak_1 );
		these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_weak.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_weak.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_weak.get_connectivity().get_weak_connectivity() );

		these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_shared.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared.get_connectivity().get_weak_connectivity() );

		these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared_1.get_connectivity().get_total_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared_1.get_connectivity().get_strong_connectivity() );
		these_solids_should_be_equal( typeing::Memory_natural_nil, filled_shared_1.get_connectivity().get_weak_connectivity() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_total_connectivity() );
}

CULE_TEST( Weak, should_dereference ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
	Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();

	*filled_weak.get_as_shared();
}

CULE_TEST( Weak, should_share_to_paired ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
	Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();

	this_object_should_not_be_empty( filled_weak );

	Shared< testing::Pointing_testing_class > filled_shared_2 = filled_weak.get_as_shared();

	this_object_should_not_be_empty( filled_shared_2 );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared_2->get_object_number_value() );
	these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_shared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_weak_connectivity() );
}

CULE_TEST( Weak, should_correctly_share_emptied_to_empty_paired ) {
	Weak< testing::Pointing_testing_class > empty_weak;

	{
		Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
		empty_weak = filled_shared.get_as_weak();

		this_object_should_not_be_empty( empty_weak );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared->get_object_number_value() );
		these_solids_should_be_equal( typeing::Memory_natural_one, testing::Pointing_testing_class::get_object_counter_value() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_nil, testing::Pointing_testing_class::get_object_counter_value() );

	Shared< testing::Pointing_testing_class > empty_shared = empty_weak.get_as_shared();

	this_object_should_be_empty( empty_shared );
	this_object_should_be_empty( empty_weak );

	these_solids_should_be_equal( typeing::Memory_natural_one, empty_weak.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, empty_weak.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, empty_weak.get_connectivity().get_weak_connectivity() );
}

CULE_TEST( Weak, should_share_to_constant ) {
	Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
	Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
	cWeak< testing::Pointing_testing_class > filled_cweak = filled_weak.get_as_cweak();

	this_object_should_not_be_empty( filled_cweak );
	this_should_be( filled_cweak.is_not_empty() );

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cweak.get_as_cshared()->get_object_counter_value() );
	these_solids_should_be_equal( typeing::Memory_natural::create( 3 ), filled_shared.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural::create( 2 ), filled_shared.get_connectivity().get_weak_connectivity() );
}

CULE_TEST( Weak, should_correctly_share_emptied_to_empty_constant ) {
	Weak< testing::Pointing_testing_class > filled_weak;

	{
		Shared< testing::Pointing_testing_class > filled_shared = testing::Pointing_testing_class::create_shared_testing_object();
		filled_weak = filled_shared.get_as_weak();

		this_object_should_not_be_empty( filled_weak );
		these_solids_should_be_equal( typeing::Memory_natural_one, filled_shared->get_object_number_value() );
		these_solids_should_be_equal( typeing::Memory_natural_one, testing::Pointing_testing_class::get_object_counter_value() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_nil, testing::Pointing_testing_class::get_object_counter_value() );

	cWeak< testing::Pointing_testing_class > empty_cweak = filled_weak.get_as_cweak();

	this_object_should_be_empty( empty_cweak );
	this_object_should_be_empty( filled_weak );

	these_solids_should_be_equal( typeing::Memory_natural_one, filled_weak.get_connectivity().get_total_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_nil, filled_weak.get_connectivity().get_strong_connectivity() );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_weak.get_connectivity().get_weak_connectivity() );
}


} // namespace pointing
} // namespace jmsf
