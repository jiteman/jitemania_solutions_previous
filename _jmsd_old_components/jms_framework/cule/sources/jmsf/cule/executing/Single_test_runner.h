#pragma once


#include "jmsf/pointing/cNonlinked.hpp"
#include "jmsf/pointing/Shared.hpp"

#include "jmsf/cule/testing/Test.hxx"
#include "jmsf/cule/resulting/Test_result_collector.hxx"
#include "jmsf/cule/resulting/Test_fault.hxx"

#include "jmsf/pointing/cShared.hxx"
#include "jmsf/validating/Exception.hxx"
#include "jmsf/validating/Exception_information.hxx"

#include "jmsf/encodebuba/validating/native_Exception.hxx"


namespace jmsf {
namespace cule {
namespace executing { // Seinsei: todonext - police namespace name


class Single_rest_runner {

public:
	void run_the_test();

public:
	virtual ~Single_rest_runner() noexcept;

	Single_rest_runner(
		const pointing::Shared< resulting::Test_result_collector > &test_result_collector,
		const pointing::cNonlinked< testing::Test > &a_test );

private:
	Single_rest_runner( const Single_rest_runner &another );
	const Single_rest_runner &operator=( const Single_rest_runner &another );

private:
	pointing::cShared< resulting::Test_fault > create_new_test_failure_from_native_exception(
		const ::jmsf::encodebuba::validating::native_Exception &a_native_exception );

	pointing::cShared< resulting::Test_fault > create_new_test_failure_from_exception(
		const ::jmsf::validating::Exception &an_exception );

	pointing::cShared< resulting::Test_fault > create_new_test_failure_from_exception_information(
		const pointing::cShared< ::jmsf::validating::Exception_information > &an_exception_information );

private:
	pointing::Shared< resulting::Test_result_collector > _test_fault_collector;
	pointing::cNonlinked< testing::Test > _the_test;

};


} // namespace execution
} // namespace cule
} // namespace jmsf
