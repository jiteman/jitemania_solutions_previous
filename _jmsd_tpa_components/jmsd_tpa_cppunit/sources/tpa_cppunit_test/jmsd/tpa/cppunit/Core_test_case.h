#pragma once

#include "cppunit/extensions/HelperMacros.h"


namespace jmsd {
namespace tpa {
namespace cppunit {


class Core_test_case :
	public CPPUNIT_NS::TestCase
{
	CPPUNIT_TEST_SUITE( Core_test_case );
	CPPUNIT_TEST( testSuccessful );
	CPPUNIT_TEST( testUnsuccessful );
	CPPUNIT_TEST( testFailed );
	CPPUNIT_TEST_SUITE_END();

public:
	Core_test_case();
	virtual ~Core_test_case();

	void testSuccessful();
	void testUnsuccessful();
	void testFailed();

private:
	Core_test_case( Core_test_case const &copy ) = delete;
	void operator =( Core_test_case const &copy ) = delete;

private:

};


} // namespace cppunit
} // namespace tpa
} // namespace jmsd
