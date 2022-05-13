#include "jmsf/cule/macroses_Test.h"


#include "testing/Pointing_testing_class.h"

#include "jmsf/pointing/Scoped.hin"
#include "jmsf/pointing/cScoped.hin"

#include "jmsf/validating/excepting/exception_Should_with_type_information.h"


namespace jmsf {
namespace pointing {


CULE_TEST( test_Scoped, should_create_empty ) {
	Scoped< testing::Pointing_testing_class > empty_scoped;

	this_object_should_be_empty( empty_scoped );
	this_should_not_be( empty_scoped.is_not_empty() );
}

CULE_TEST( test_Scoped, should_delete_empty ) {
	{
		Scoped< testing::Pointing_testing_class > empty_scoped;
	}
}

CULE_TEST_E( test_Scoped, should_not_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	Scoped< testing::Pointing_testing_class > empty_scoped;
	*empty_scoped;
}

CULE_TEST( test_Scoped, should_move_empty_to_constant ) {
	Scoped< testing::Pointing_testing_class > empty_scoped;
	cScoped< testing::Pointing_testing_class > empty_cScoped = empty_scoped.move_as_cscoped();

	this_object_should_be_empty( empty_cScoped );
	this_should_not_be( empty_cScoped.is_not_empty() );
}

CULE_TEST( test_Scoped, should_create ) {
	Scoped< testing::Pointing_testing_class > filled_scoped = testing::Pointing_testing_class::create_scoped_testing_object();

	this_object_should_not_be_empty( filled_scoped );
	this_should_not_be( filled_scoped.is_empty() );
}

CULE_TEST( test_Scoped, should_delete ) {
	{
		Scoped< testing::Pointing_testing_class > filled_scoped = testing::Pointing_testing_class::create_scoped_testing_object();
	}

	these_solids_should_be_equal( typeing::Memory_natural_nil, testing::Pointing_testing_class::get_object_counter_value() );
}

CULE_TEST( test_Scoped, should_dereference ) {
	Scoped< testing::Pointing_testing_class > filled_scoped = testing::Pointing_testing_class::create_scoped_testing_object();
	*filled_scoped;
}

CULE_TEST( test_Scoped, should_move_to_constant ) {
	Scoped< testing::Pointing_testing_class > filled_scoped = testing::Pointing_testing_class::create_scoped_testing_object();
	cScoped< testing::Pointing_testing_class > filled_cscoped = filled_scoped.move_as_cscoped();

	this_object_should_not_be_empty( filled_cscoped );
	this_object_should_be_empty( filled_scoped );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cscoped->get_object_number_value() );
}


} // namespace pointing
} // namespace jmsf
