#include "jmsf/cule/macroses_Test.h"


#include "testing/Pointing_testing_class.h"

#include "jmsf/pointing/Nonlinked.hin"
#include "jmsf/pointing/cNonlinked.hin"
#include "jmsf/pointing/Scoped.hin"

#include "jmsf/validating/excepting/exception_Should_with_type_information.h"


namespace jmsf {
namespace pointing {


CULE_TEST( Nonlinked, should_create_empty ) {
	const Nonlinked< testing::Pointing_testing_class > empty_nonlinked;

	this_object_should_be_empty( empty_nonlinked );
	this_should_not_be( empty_nonlinked.is_not_empty() );
}

CULE_TEST( Nonlinked, should_delete_empty ) {
	{
		const Nonlinked< testing::Pointing_testing_class > empty_nonlinked;
	}
}

CULE_TEST( Nonlinked, should_be_equal_empty_empty ) {
	const Nonlinked< testing::Pointing_testing_class > empty_nonlinked;
	these_solids_should_be_equal( Nonlinked< testing::Pointing_testing_class >(), Nonlinked< testing::Pointing_testing_class >() );
	these_solids_should_be_equal( empty_nonlinked, empty_nonlinked );
	these_solids_should_be_equal( empty_nonlinked, Nonlinked< testing::Pointing_testing_class >() );
	these_solids_should_be_equal( Nonlinked< testing::Pointing_testing_class >(), empty_nonlinked );
}

CULE_TEST_E( Nonlinked, should_not_const_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	const Nonlinked< testing::Pointing_testing_class > empty_nonlinked;
	*empty_nonlinked;
}

CULE_TEST_E( Nonlinked, should_not_dereference_empty, validating::excepting::exception_Should_with_type_information ) {
	Nonlinked< testing::Pointing_testing_class > empty_nonlinked;
	*empty_nonlinked;
}

CULE_TEST( Nonlinked, should_share_empty_to_constant ) {
	const Nonlinked< testing::Pointing_testing_class > empty_nonlinked;
	const cNonlinked< testing::Pointing_testing_class > empty_cnonlinked = empty_nonlinked.get_as_cnonlinked();

	this_object_should_be_empty( empty_cnonlinked );
	this_should_not_be( empty_cnonlinked.is_not_empty() );
}

CULE_TEST( Nonlinked, should_create ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	const Scoped< testing::Pointing_testing_class > filled_scoped = Scoped< testing::Pointing_testing_class >::create( testing_class_omp );
	const Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );

	this_object_should_not_be_empty( filled_nonlinked );
	this_should_not_be( filled_nonlinked.is_empty() );
}

CULE_TEST( Nonlinked, should_not_delete_the_object ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	const Scoped< testing::Pointing_testing_class > filled_scoped = Scoped< testing::Pointing_testing_class >::create( testing_class_omp );

	{
		const Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );
	}

	these_solids_should_be_equal( typeing::Memory_natural_one, testing::Pointing_testing_class::get_object_counter_value() );
}

CULE_TEST( Nonlinked, should_be_equal_filled_filled ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	const Scoped< testing::Pointing_testing_class > filled_scoped = Scoped< testing::Pointing_testing_class >::create( testing_class_omp );

	const Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );
	const Nonlinked< testing::Pointing_testing_class > filled_nonlinked_1 = filled_nonlinked;
	these_solids_should_be_equal( filled_nonlinked, filled_nonlinked );
	these_solids_should_be_equal( filled_nonlinked, filled_nonlinked_1 );
	these_solids_should_be_equal( filled_nonlinked_1, filled_nonlinked );
	these_solids_should_be_equal( filled_nonlinked_1, filled_nonlinked_1 );
}

CULE_TEST( Nonlinked, should_be_equal_equally_filled ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	const Scoped< testing::Pointing_testing_class > filled_scoped = Scoped< testing::Pointing_testing_class >::create( testing_class_omp );

	const Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );
	const Nonlinked< testing::Pointing_testing_class > filled_nonlinked_1 = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );
	these_solids_should_be_equal( filled_nonlinked, filled_nonlinked );
	these_solids_should_be_equal( filled_nonlinked, filled_nonlinked_1 );
	these_solids_should_be_equal( filled_nonlinked_1, filled_nonlinked );
	these_solids_should_be_equal( filled_nonlinked_1, filled_nonlinked_1 );
}

CULE_TEST( Nonlinked, should_not_be_equal_filled_empty ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	const Scoped< testing::Pointing_testing_class > filled_scoped = Scoped< testing::Pointing_testing_class >::create( testing_class_omp );

	const Nonlinked< testing::Pointing_testing_class > empty_nonlinked;
	const Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );
	these_solids_should_not_be_equal( filled_nonlinked, Nonlinked< testing::Pointing_testing_class >() );
	these_solids_should_not_be_equal( Nonlinked< testing::Pointing_testing_class >(), filled_nonlinked );
	these_solids_should_not_be_equal( filled_nonlinked, empty_nonlinked );
	these_solids_should_not_be_equal( empty_nonlinked, filled_nonlinked );
}

CULE_TEST( Nonlinked, should_dereference ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	Scoped< testing::Pointing_testing_class > filled_scoped = Scoped< testing::Pointing_testing_class >::create( testing_class_omp );
	Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );

	*filled_nonlinked;
}

CULE_TEST( Nonlinked, should_share_to_constant ) {
	const memorying::Omp< testing::Pointing_testing_class > testing_class_omp( testing::Pointing_testing_class::create_testing_object_omp() );
	Scoped< testing::Pointing_testing_class > filled_scoped = Scoped< testing::Pointing_testing_class >::create( testing_class_omp );
	Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_class_omp.get_as_womp() );
	cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = filled_nonlinked.get_as_cnonlinked();

	this_object_should_not_be_empty( filled_cnonlinked );
	this_object_should_not_be_empty( filled_nonlinked );
	these_solids_should_be_equal( typeing::Memory_natural_one, filled_cnonlinked->get_object_number_value() );
}


} // namespace pointing
} // namespace jmsf
