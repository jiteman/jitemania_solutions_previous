#include "pre_tests_cShared.hxx"

#include "testing/Pointing_testing_class.h"
#include "jmsf/pointing/Shared.hin"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/testing/testing_Allocators.h"


#include <string>
#include <iostream>


namespace jmsf {
namespace pointing {
namespace pre_tests_cshared {
	cShared< testing::Pointing_testing_class > create_testing_object();

	typeing::Boolean should_create_empty() noexcept;
	typeing::Boolean should_delete_empty() noexcept;
	typeing::Boolean should_copy_empty() noexcept;
	typeing::Boolean should_not_dereference_empty() noexcept;
	typeing::Boolean should_share_empty_to_paired() noexcept;

	typeing::Boolean should_create() noexcept;
	typeing::Boolean should_delete() noexcept;
	typeing::Boolean should_copy() noexcept;
	typeing::Boolean should_dereference() noexcept;
	typeing::Boolean should_share_to_paired() noexcept;
} // namespace tests_cshared
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_cshared {


void pre_tests_cShared() noexcept {
	typeing::Boolean test_result = typeing::True;
	encodebuba::nativing::native_memory_natural test_line = 0;

	try {
		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cShared: should create empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_delete_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cShared: should delete empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_copy_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cShared: should copy empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_not_dereference_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cShared: should not dereference empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_empty_to_paired() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cShared: should share empty to paired - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cShared: should create - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_delete() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cShared: should delete - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_copy() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cShared: should delete - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_dereference() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cShared: should dereference empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_to_paired() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cShared: should share to paired - failed" << ::std::endl;
		}
	} catch( ... ) {
		::std::cout << "Exception in file: " << JMSF_ENCODEBUBA_FILE << ::std::endl;
		::std::cout << "at line: " << test_line << ::std::endl;
		test_result = typeing::False;
	}

	if ( !test_result ) {
		::std::cout << "pre_tests_cShared - failed" << ::std::endl;
	} else {
		::std::cout << "pre_tests_cShared - successful" << ::std::endl;
	}
}


} // namespace tests_cshared
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_cshared {


cShared< testing::Pointing_testing_class > create_testing_object() {
	return
		cShared< testing::Pointing_testing_class >::create(
			::jmsf::testing::testing_Allocators::instance()->get_reference_counters_allocator(),
			memorying::Constructor< testing::Pointing_testing_class, testing::Pointing_testing_class >::construct(
				::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator () ) );
}

typeing::Boolean should_create_empty() noexcept {
	cShared< testing::Pointing_testing_class > empty_cshared;

	if ( empty_cshared.is_not_empty() ) return typeing::False;
	if ( !empty_cshared.is_empty() ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_delete_empty() noexcept {
	{
		cShared< testing::Pointing_testing_class > empty_cshared;
	}

	return typeing::True;
}

typeing::Boolean should_copy_empty() noexcept {
	// copy
	{
		cShared< testing::Pointing_testing_class > empty_cshared;
		cShared< testing::Pointing_testing_class > empty_cshared_1;
		empty_cshared_1 = empty_cshared;

		if ( empty_cshared.is_not_empty() ) return typeing::False;
		if ( !empty_cshared.is_empty() ) return typeing::False;
		if ( empty_cshared_1.is_not_empty() ) return typeing::False;
		if ( !empty_cshared_1.is_empty() ) return typeing::False;
		if ( empty_cshared.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	}

	// copy construct
	{
		cShared< testing::Pointing_testing_class > empty_cshared;
		cShared< testing::Pointing_testing_class > empty_cshared_1 = empty_cshared;

		if ( empty_cshared.is_not_empty() ) return typeing::False;
		if ( !empty_cshared.is_empty() ) return typeing::False;
		if ( empty_cshared_1.is_not_empty() ) return typeing::False;
		if ( !empty_cshared_1.is_empty() ) return typeing::False;
		if ( empty_cshared.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	}

	return typeing::True;
}

typeing::Boolean should_not_dereference_empty() noexcept {
	cShared< testing::Pointing_testing_class > empty_cshared;

	try {
		*empty_cshared;
	} catch ( ... ) {
		return typeing::True;
	}

	return typeing::False;
}

typeing::Boolean should_share_empty_to_paired() noexcept {
	cShared< testing::Pointing_testing_class > empty_cshared;

	cWeak< testing::Pointing_testing_class > empty_cweak = empty_cshared.get_as_cweak();

	if ( empty_cweak.is_not_empty() ) return typeing::False;
	if ( !empty_cweak.is_empty() ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_create() noexcept {
	cShared< testing::Pointing_testing_class > filled_cshared = create_testing_object();

	if ( filled_cshared.is_empty() ) return typeing::False;
	if ( !filled_cshared.is_not_empty() ) return typeing::False;
	if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_delete() noexcept {
	{
		cShared< testing::Pointing_testing_class > filled_cshared = create_testing_object();
	}

	if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_nil ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_copy() noexcept {
	cShared< testing::Pointing_testing_class > filled_cshared_0 = create_testing_object();

	// copy
	{
		cShared< testing::Pointing_testing_class > filled_cshared = filled_cshared_0;
		cShared< testing::Pointing_testing_class > filled_cshared_1;
		filled_cshared_1 = filled_cshared;

		if ( filled_cshared.is_empty() ) return typeing::False;
		if ( !filled_cshared.is_not_empty() ) return typeing::False;
		if ( filled_cshared_1.is_empty() ) return typeing::False;
		if ( !filled_cshared_1.is_not_empty() ) return typeing::False;
		if ( filled_cshared.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_cshared.get_connectivity().get_strong_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_cshared.get_connectivity().get_weak_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	}

	if ( filled_cshared_0.get_connectivity().get_total_connectivity() != typeing::Memory_natural_one ) return typeing::False;

	// copy construct
	{
		cShared< testing::Pointing_testing_class > filled_cshared = filled_cshared_0;
		cShared< testing::Pointing_testing_class > filled_cshared_1 = filled_cshared;

		if ( filled_cshared.is_empty() ) return typeing::False;
		if ( !filled_cshared.is_not_empty() ) return typeing::False;
		if ( filled_cshared_1.is_empty() ) return typeing::False;
		if ( !filled_cshared_1.is_not_empty() ) return typeing::False;
		if ( filled_cshared.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_cshared.get_connectivity().get_strong_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_cshared.get_connectivity().get_weak_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	}

	if ( filled_cshared_0.get_connectivity().get_total_connectivity() != typeing::Memory_natural_one ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_dereference() noexcept {
	cShared< testing::Pointing_testing_class > filled_cshared = create_testing_object();

	try {
		*filled_cshared;
	} catch ( ... ) {
		return typeing::False;
	}

	return typeing::True;
}

typeing::Boolean should_share_to_paired() noexcept {
	cShared< testing::Pointing_testing_class > filled_shared = create_testing_object();
	cWeak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_cweak();

	if ( filled_weak.is_empty() ) return typeing::False;
	if ( !filled_weak.is_not_empty() ) return typeing::False;
	if ( filled_weak.get_as_cshared()->get_object_number_value() != typeing::Memory_natural_one ) return typeing::False;

	return typeing::True;
}


} // namespace tests_cshared
} // namespace pointing
} // namespace jmsf
