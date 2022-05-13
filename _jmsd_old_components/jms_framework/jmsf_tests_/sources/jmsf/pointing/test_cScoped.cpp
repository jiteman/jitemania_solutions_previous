#include "jmsf/cule/macroses_Test.h"


#include "testing/Pointing_testing_class.h"

#include "jmsf/pointing/cScoped.hin"

#include "jmsf/validating/excepting/exception_Should_with_type_information.h"


namespace jmsf {
namespace pointing {


CULE_TEST( test_cScoped, should_create_empty ) {
	cScoped< testing::Pointing_testing_class > empty_scoped;

	Cule_this( empty_scoped ).should_be_empty();
	Cule_this( empty_scoped.is_not_empty() ).should_not_be();
//	this_object_should_be_empty( empty_scoped );
//	this_should_not_be( empty_scoped.is_not_empty() );
}

CULE_TEST( test_cScoped, should_delete_empty ) {
	{
		cScoped< testing::Pointing_testing_class > empty_scoped;
	}
}

CULE_TEST_E( test_cScoped, should_not_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	cScoped< testing::Pointing_testing_class > empty_scoped;
	*empty_scoped;
}

CULE_TEST( test_cScoped, should_create ) {
	cScoped< testing::Pointing_testing_class > filled_scoped = testing::Pointing_testing_class::create_cscoped_testing_object();

	this_object_should_not_be_empty( filled_scoped );
	this_should_not_be( filled_scoped.is_empty() );
}

CULE_TEST( test_cScoped, should_delete ) {
	{
		cScoped< testing::Pointing_testing_class > filled_scoped = testing::Pointing_testing_class::create_cscoped_testing_object();
	}

	these_solids_should_be_equal( typeing::Memory_natural_nil, testing::Pointing_testing_class::get_object_counter_value() );
}

CULE_TEST( test_cScoped, should_dereference ) {
	cScoped< testing::Pointing_testing_class > filled_scoped = testing::Pointing_testing_class::create_cscoped_testing_object();
	*filled_scoped;
}


} // namespace pointing
} // namespace jmsf
