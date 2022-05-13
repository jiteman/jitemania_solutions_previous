#include "Core_test_case.h"

#include "cppunit/Exception.h"

#include "tpa_cppunit_core_suite_name.h"

#include <memory>


namespace jmsd {
namespace tpa {
namespace cppunit {


CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( Core_test_case, get_tpa_cppunit_core_suite_name() );


Core_test_case::Core_test_case()
{}


Core_test_case::~Core_test_case()
{}


void Core_test_case::testSuccessful() {
	CPPUNIT_ASSERT( true );
}


void Core_test_case::testUnsuccessful() {
	CPPUNIT_ASSERT( false );
}


void Core_test_case::testFailed() {
	CPPUNIT_FAIL( "deliberately" );
}


} // namespace cppunit
} // namespace tpa
} // namespace jmsd
