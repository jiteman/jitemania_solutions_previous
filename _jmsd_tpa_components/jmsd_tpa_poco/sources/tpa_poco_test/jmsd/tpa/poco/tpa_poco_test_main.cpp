#include "tpa_poco_test_main.h"

#include "jmsd/tpa/poco/tpa_poco_cppunit_adapter_main.h"

#include "FoundationTestSuite.h"
#include "JSONTestSuite.h"
#include "XMLTestSuite.h"
#include "UtilTestSuite.h"
#include "ZipTestSuite.h"

#include "cppunit/Test.h"

#include <vector>


namespace jmsd {
namespace tpa {
namespace poco {


int tpa_poco_test_main( int const argc, char const *const argv[] ) {
	::std::vector< ::CppUnit::Test * > test_suite_list = {
		FoundationTestSuite::suite(),
		JSONTestSuite::suite(),
		XMLTestSuite::suite(),
		UtilTestSuite::suite(),
		ZipTestSuite::suite()
	};

	return tpa_poco_cppunit_adapter_main( argc, argv, test_suite_list );
}


} // namespace poco
} // namespace tpa
} // namespace jmsd
