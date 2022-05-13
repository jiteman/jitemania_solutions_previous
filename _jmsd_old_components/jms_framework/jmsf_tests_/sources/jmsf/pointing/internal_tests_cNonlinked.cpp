#include "gmock/gmock.h"
//#include "pre_tests_cNonlinked.hxx"


#include "jmsf/pointing/cNonlinked.hin"

#include "testing/Pointing_testing_class.h"
//#include "jmsf/pointing/cScoped.hin"
////#include "jmsf/pointing/Nonlinked.hin"

#include "jmsf/testing/testing_Allocators.h"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Destructor.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/typeing/Boolean.h"

#include "jmsf/validating/excepting/exception_Should_with_type_information.h"

//#include <string>
//#include <iostream>


namespace jmsf {
namespace pointing {


pointing::cScoped< testing::Pointing_testing_class > create_testing_object();


} // namespace pointing
} // namespace jmsf




namespace jmsf {
namespace pointing {


GTEST_TEST( cNonlinked, should_empty_when_created ) {
	cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;

	EXPECT_TRUE( empty_cnonlinked.is_empty() );
}

GTEST_TEST( cNonlinked, should_not_be_not_empty_when_created ) {
	cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;

	EXPECT_FALSE( empty_cnonlinked.is_not_empty() );
}

GTEST_TEST( cNonlinked, should_not_be_not_empty_when_is_empty ) {
	cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;

	EXPECT_TRUE( empty_cnonlinked.is_empty() );
	EXPECT_FALSE( empty_cnonlinked.is_not_empty() );
}

//GOOGLE_TEST( cNonlinked, should_not_be_empty_when_is_not_empty ) {
//	auto scoped_test_object = create_testing_object();

//	cNonlinked< testing::Pointing_testing_class > filled_cnonlinked =
//		cNonlinked< testing::Pointing_testing_class >::create_from_static(
//			scoped_test_object.operator->() );

//	EXPECT_TRUE( filled_cnonlinked.is_not_empty() );
//	EXPECT_FALSE( filled_cnonlinked.is_empty() );
//}

GTEST_TEST( cNonlinked, should_not_dereference_when_empty ) {
	cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;

	EXPECT_THROW( *empty_cnonlinked, validating::excepting::exception_Should_with_type_information );
}

} // namespace pointing
} // namespace jmsf




namespace jmsf {
namespace pointing {


pointing::cScoped< testing::Pointing_testing_class > create_testing_object() {
	return
		pointing::cScoped< testing::Pointing_testing_class >::create(
			memorying::Constructor< testing::Pointing_testing_class, testing::Pointing_testing_class >::construct(
				::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator() ) );
}


} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_cnonlinked {


//typeing::Boolean should_copy_empty() noexcept {
//	// copy
//	{
//		cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;
//		cNonlinked< testing::Pointing_testing_class > empty_cnonlinked_1;
//		empty_cnonlinked_1 = empty_cnonlinked;

//		if ( empty_cnonlinked.is_not_empty() ) return typeing::False;
//		if ( !empty_cnonlinked.is_empty() ) return typeing::False;
//		if ( empty_cnonlinked_1.is_not_empty() ) return typeing::False;
//		if ( !empty_cnonlinked_1.is_empty() ) return typeing::False;
//	}

//	// copy construct
//	{
//		cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;
//		cNonlinked< testing::Pointing_testing_class > empty_cnonlinked_1 = empty_cnonlinked;

//		if ( empty_cnonlinked.is_not_empty() ) return typeing::False;
//		if ( !empty_cnonlinked.is_empty() ) return typeing::False;
//		if ( empty_cnonlinked_1.is_not_empty() ) return typeing::False;
//		if ( !empty_cnonlinked_1.is_empty() ) return typeing::False;
//	}

//	return typeing::True;
//}

//typeing::Boolean should_create() noexcept {
//	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();
//	cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );

//	typeing::Boolean test_result = typeing::True;

//	if ( filled_cnonlinked.is_empty() ) test_result = typeing::False;
//	if ( !filled_cnonlinked.is_not_empty() ) test_result = typeing::False;

//	destroy_testing_object( testing_object_omp );
//	return test_result;
//}

//typeing::Boolean should_not_delete_the_object() noexcept {
//	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();

//	typeing::Boolean test_result = typeing::True;

//	{
//		cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );
//	}

//	if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) test_result = typeing::False;

//	destroy_testing_object( testing_object_omp );
//	return test_result;
//}

//typeing::Boolean should_copy() noexcept {
//	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();

//	typeing::Boolean test_result = typeing::True;

//	// copy
//	{
//		cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );
//		cNonlinked< testing::Pointing_testing_class > filled_cnonlinked_1;
//		filled_cnonlinked_1 = filled_cnonlinked;

//		if ( filled_cnonlinked.is_empty() ) test_result = typeing::False;
//		if ( !filled_cnonlinked.is_not_empty() ) test_result = typeing::False;
//		if ( filled_cnonlinked_1.is_empty() ) test_result = typeing::False;
//		if ( !filled_cnonlinked_1.is_not_empty() ) test_result = typeing::False;
//		if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) test_result = typeing::False;
//	}

//	// copy construct
//	{
//		cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );
//		cNonlinked< testing::Pointing_testing_class > filled_cnonlinked_1 = filled_cnonlinked;

//		if ( filled_cnonlinked.is_empty() ) test_result = typeing::False;
//		if ( !filled_cnonlinked.is_not_empty() ) test_result = typeing::False;
//		if ( filled_cnonlinked_1.is_empty() ) test_result = typeing::False;
//		if ( !filled_cnonlinked_1.is_not_empty() ) test_result = typeing::False;
//		if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) test_result = typeing::False;
//	}

//	destroy_testing_object( testing_object_omp );
//	return test_result;
//}

//typeing::Boolean should_dereference() noexcept {
//	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();
//	cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );

//	typeing::Boolean test_result = typeing::True;

//	try {
//		*filled_cnonlinked;
//	} catch ( ... ) {
//		return test_result = typeing::False;
//	}

//	destroy_testing_object( testing_object_omp );
//	return test_result;
//}


} // namespace tests_cnonlinked
} // namespace pointing
} // namespace jmsf
