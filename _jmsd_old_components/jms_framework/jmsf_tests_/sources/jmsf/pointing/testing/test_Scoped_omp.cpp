#include "gmock/gmock.h"


#include "Scoped_omp.hin"

#include "Pointing_testing_class.h"

#include "jmsf/testing/testing_Allocators.h"
#include "jmsf/pointing/Nonlinked.hin"


#include <exception>

namespace jmsf {
namespace pointing {
namespace testing {


GTEST_TEST( Scoped_omp, should_be_empty_when_created ) {
	Scoped_omp< Pointing_testing_class > empty_scoped_omp;

	ASSERT_TRUE( empty_scoped_omp.is_empty() );
}

GTEST_TEST( Scoped_omp, should_not_be_not_empty_when_empty ) {
	Scoped_omp< Pointing_testing_class > empty_scoped_omp;

	ASSERT_TRUE( empty_scoped_omp.is_empty() );
	ASSERT_FALSE( empty_scoped_omp.is_not_empty() );
}

GTEST_TEST( Scoped_omp, should_not_be_empty_when_holds_an_object ) {
	auto filled_scoped_omp =
		Scoped_omp< Pointing_testing_class >::create(
			Pointing_testing_class::create_omp(
				::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator() ) );

	ASSERT_TRUE( filled_scoped_omp.is_not_empty() );
}


} // namespace testing
} // namespace pointing
} // namespace jmsf

