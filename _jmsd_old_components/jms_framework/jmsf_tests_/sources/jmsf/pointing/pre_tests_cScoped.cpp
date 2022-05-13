#include "pre_tests_cScoped.hxx"


#include "testing/Pointing_testing_class.h"
#include "jmsf/pointing/cScoped.hin"


#include "jmsf/memorying/Constructor.hin"
#include "jmsf/testing/testing_Allocators.h"


#include <string>
#include <iostream>


namespace jmsf {
namespace pointing {
namespace pre_tests_cscoped {
	cScoped< testing::Pointing_testing_class > create_testing_object();

	typeing::Boolean should_create_empty() noexcept;
	typeing::Boolean should_delete_empty() noexcept;
	typeing::Boolean should_not_dereference_empty() noexcept;
	typeing::Boolean should_share_empty_to_paired() noexcept;

	typeing::Boolean should_create() noexcept;
	typeing::Boolean should_delete() noexcept;
	typeing::Boolean should_dereference() noexcept;
	typeing::Boolean should_share_to_paired() noexcept;
} // namespace tests_cscoped
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_cscoped {


void pre_tests_cScoped() noexcept {
	typeing::Boolean test_result = typeing::True;
	encodebuba::nativing::native_memory_natural test_line = 0;

	try {
		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cScoped: should create empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_delete_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cScoped: should delete empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_not_dereference_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cScoped: should not dereference empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cScoped: should create - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_delete() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cScoped: should not delete the object - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_dereference() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cScoped: should dereference empty - failed" << ::std::endl;
		}
	} catch( ... ) {
		::std::cout << "Exception in file: " << JMSF_ENCODEBUBA_FILE << ::std::endl;
		::std::cout << "at line: " << test_line << ::std::endl;
		test_result = typeing::False;
	}

	if ( !test_result ) {
		::std::cout << "pre_tests_cScoped - failed" << ::std::endl;
	} else {
		::std::cout << "pre_tests_cScoped - successful" << ::std::endl;
	}
}


} // namespace tests_cscoped
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_cscoped {


cScoped< testing::Pointing_testing_class > create_testing_object() {
	return
		cScoped< testing::Pointing_testing_class >::create(
			memorying::Constructor< testing::Pointing_testing_class, testing::Pointing_testing_class >::construct(
				::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator () ) );
}

typeing::Boolean should_create_empty() noexcept {
	cScoped< testing::Pointing_testing_class > empty_cscoped;

	if ( empty_cscoped.is_not_empty() ) return typeing::False;
	if ( !empty_cscoped.is_empty() ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_delete_empty() noexcept {
	{
		cScoped< testing::Pointing_testing_class > empty_cscoped;
	}

	return typeing::True;
}

typeing::Boolean should_not_dereference_empty() noexcept {
	cScoped< testing::Pointing_testing_class > empty_cscoped;

	try {
		*empty_cscoped;
	} catch ( ... ) {
		return typeing::True;
	}

	return typeing::False;
}

typeing::Boolean should_create() noexcept {
	cScoped< testing::Pointing_testing_class > filled_cscoped = create_testing_object();

	if ( filled_cscoped.is_empty() ) return typeing::False;
	if ( !filled_cscoped.is_not_empty() ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_delete() noexcept {
	{
		cScoped< testing::Pointing_testing_class > filled_cscoped = create_testing_object();
	}

	if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_nil ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_dereference() noexcept {
	cScoped< testing::Pointing_testing_class > filled_cscoped = create_testing_object();

	try {
		*filled_cscoped;
	} catch ( ... ) {
		return typeing::False;
	}

	return typeing::True;
}


} // namespace tests_cscoped
} // namespace pointing
} // namespace jmsf
