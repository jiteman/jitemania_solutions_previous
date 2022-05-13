#pragma once

#include <vector>


#include "tpa_poco_cppunit_adapter.h"


namespace CppUnit {
	class Test;
} // namespabe CppUnit


namespace jmsd {
namespace tpa {
namespace poco {


int JMSD_TPA_POCO_CPPUNIT_ADAPTER_SHARED_INTERFACE tpa_poco_cppunit_adapter_main(
	int const arc,
	char const *const argv[],
	::std::vector< ::CppUnit::Test * > const &test_suite_list );


} // namespace poco
} // namespace tpa
} // namespace jmsd

