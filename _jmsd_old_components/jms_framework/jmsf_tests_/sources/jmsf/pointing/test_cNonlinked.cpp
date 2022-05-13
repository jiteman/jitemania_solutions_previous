#include "jmsf/cule/macroses_Test.h"


#include "testing/Pointing_testing_class.h"

#include "jmsf/pointing/cNonlinked.hin"
#include "jmsf/pointing/cScoped.hin"

#include "jmsf/validating/excepting/exception_Should_with_type_information.h"


namespace jmsf {
namespace pointing {


CULE_TEST( cNonlinked, should_create_empty ) {
	const cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;

	this_object_should_be_empty( empty_cnonlinked );
	this_should_not_be( empty_cnonlinked.is_not_empty() );
}

CULE_TEST( cNonlinked, should_delete_empty ) {
	{
		const cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;
	}
}

CULE_TEST( cNonlinked, should_be_equal_empty_empty ) {
	const cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;
	these_solids_should_be_equal( cNonlinked< testing::Pointing_testing_class >(), cNonlinked< testing::Pointing_testing_class >() );
	these_solids_should_be_equal( empty_cnonlinked, empty_cnonlinked );
	these_solids_should_be_equal( empty_cnonlinked, cNonlinked< testing::Pointing_testing_class >() );
	these_solids_should_be_equal( cNonlinked< testing::Pointing_testing_class >(), empty_cnonlinked );
}

CULE_TEST_E( cNonlinked, should_not_const_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	const cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;
	*empty_cnonlinked;
}

CULE_TEST_E( cNonlinked, should_not_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;
	*empty_cnonlinked;
}

CULE_TEST( cNonlinked, should_create ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	cScoped< testing::Pointing_testing_class > filled_cscoped = cScoped< testing::Pointing_testing_class >::create( testing_class_omp );
	cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );

	this_object_should_not_be_empty( filled_cnonlinked );
	this_should_not_be( filled_cnonlinked.is_empty() );
}

CULE_TEST( cNonlinked, should_be_equal_filled_filled ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	const cScoped< testing::Pointing_testing_class > filled_cscoped = cScoped< testing::Pointing_testing_class >::create( testing_class_omp );

	const cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );;
	const cNonlinked< testing::Pointing_testing_class > filled_cnonlinked_1 = filled_cnonlinked;
	these_solids_should_be_equal( filled_cnonlinked, filled_cnonlinked );
	these_solids_should_be_equal( filled_cnonlinked, filled_cnonlinked_1 );
	these_solids_should_be_equal( filled_cnonlinked, filled_cnonlinked );
	these_solids_should_be_equal( filled_cnonlinked, filled_cnonlinked_1 );
}

CULE_TEST( cNonlinked, should_be_equal_equally_filled ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	const cScoped< testing::Pointing_testing_class > filled_cscoped = cScoped< testing::Pointing_testing_class >::create( testing_class_omp );

	const cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );
	const cNonlinked< testing::Pointing_testing_class > filled_cnonlinked_1 = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );
	these_solids_should_be_equal( filled_cnonlinked, filled_cnonlinked );
	these_solids_should_be_equal( filled_cnonlinked, filled_cnonlinked_1 );
}

CULE_TEST( cNonlinked, should_not_be_equal_filled_empty ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	const cScoped< testing::Pointing_testing_class > filled_cscoped = cScoped< testing::Pointing_testing_class >::create( testing_class_omp );

	const cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;
	const cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );
	these_solids_should_not_be_equal( filled_cnonlinked, cNonlinked< testing::Pointing_testing_class >() );
	these_solids_should_not_be_equal( cNonlinked< testing::Pointing_testing_class >(), filled_cnonlinked );
	these_solids_should_not_be_equal( filled_cnonlinked, empty_cnonlinked );
	these_solids_should_not_be_equal( empty_cnonlinked, filled_cnonlinked );
}

CULE_TEST( cNonlinked, should_not_delete_the_object ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	cScoped< testing::Pointing_testing_class > filled_cscoped = cScoped< testing::Pointing_testing_class >::create( testing_class_omp );

	{
		cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, testing::Pointing_testing_class::get_object_counter_value() );
}

CULE_TEST( cNonlinked, should_dereference ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	cScoped< testing::Pointing_testing_class > filled_cscoped = cScoped< testing::Pointing_testing_class >::create( testing_class_omp );
	cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );
	*filled_cnonlinked;
}


} // namespace pointing
} // namespace jmsf
