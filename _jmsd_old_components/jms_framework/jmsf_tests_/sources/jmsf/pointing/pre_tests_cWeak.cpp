#include "pre_tests_cWeak.hxx"

#include "testing/Pointing_testing_class.h"
#include "jmsf/pointing/cWeak.hin"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/testing/testing_Allocators.h"


#include <string>
#include <iostream>


namespace jmsf {
namespace pointing {
namespace pre_tests_cweak {
	cShared< testing::Pointing_testing_class > create_testing_object();

	typeing::Boolean should_create_empty() noexcept;
	typeing::Boolean should_delete_empty() noexcept;
	typeing::Boolean should_copy_empty() noexcept;
	typeing::Boolean should_not_dereference_empty() noexcept;
	typeing::Boolean should_share_empty_to_paired() noexcept;

	typeing::Boolean should_create() noexcept;
	typeing::Boolean should_not_delete_the_object() noexcept;
	typeing::Boolean should_copy() noexcept;
	typeing::Boolean should_dereference() noexcept;
	typeing::Boolean should_share_to_paired() noexcept;
} // namespace tests_cweak
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_cweak {


void pre_tests_cWeak() noexcept {
	typeing::Boolean test_result = typeing::True;
	encodebuba::nativing::native_memory_natural test_line = 0;

	try {
		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cWeak: should create empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_delete_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cWeak: should delete empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_copy_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cWeak: should copy empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_not_dereference_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cWeak: should not dereference empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_empty_to_paired() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cWeak: should share empty to paired - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cWeak: should create - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_not_delete_the_object() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cWeak: should not delete the object - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_copy() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cWeak: should copy - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_dereference() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cWeak: should dereference empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_to_paired() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cWeak: should share to paired - failed" << ::std::endl;
		}
	} catch( ... ) {
		::std::cout << "Exception in file: " << JMSF_ENCODEBUBA_FILE << ::std::endl;
		::std::cout << "at line: " << test_line << ::std::endl;
		test_result = typeing::False;
	}

	if ( !test_result ) {
		::std::cout << "pre_tests_cWeak - failed" << ::std::endl;
	} else {
		::std::cout << "pre_tests_cWeak - successful" << ::std::endl;
	}
}


} // namespace tests_cweak
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_cweak {


cShared< testing::Pointing_testing_class > create_testing_object() {
	return
		cShared< testing::Pointing_testing_class >::create(
			::jmsf::testing::testing_Allocators::instance()->get_reference_counters_allocator(),
			memorying::Constructor< testing::Pointing_testing_class, testing::Pointing_testing_class >::construct(
				::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator () ) );
}

typeing::Boolean should_create_empty() noexcept {
	cWeak< testing::Pointing_testing_class > empty_cweak;

	if ( empty_cweak.is_not_empty() ) return typeing::False;
	if ( !empty_cweak.is_empty() ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_delete_empty() noexcept {
	{
		cWeak< testing::Pointing_testing_class > empty_cweak;
	}

	return typeing::True;
}

typeing::Boolean should_copy_empty() noexcept {
	// copy
	{
		cWeak< testing::Pointing_testing_class > empty_cweak;
		cWeak< testing::Pointing_testing_class > empty_cweak_1;
		empty_cweak_1 = empty_cweak;

		if ( empty_cweak.is_not_empty() ) return typeing::False;
		if ( !empty_cweak.is_empty() ) return typeing::False;
		if ( empty_cweak_1.is_not_empty() ) return typeing::False;
		if ( !empty_cweak_1.is_empty() ) return typeing::False;
		if ( empty_cweak.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	}

	// copy construct
	{
		cWeak< testing::Pointing_testing_class > empty_cweak;
		cWeak< testing::Pointing_testing_class > empty_cweak_1 = empty_cweak;

		if ( empty_cweak.is_not_empty() ) return typeing::False;
		if ( !empty_cweak.is_empty() ) return typeing::False;
		if ( empty_cweak_1.is_not_empty() ) return typeing::False;
		if ( !empty_cweak_1.is_empty() ) return typeing::False;
		if ( empty_cweak.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	}

	return typeing::True;
}

typeing::Boolean should_not_dereference_empty() noexcept {
	cWeak< testing::Pointing_testing_class > empty_cweak;

	try {
		*empty_cweak.get_as_cshared();
	} catch ( ... ) {
		return typeing::True;
	}

	return typeing::False;
}

typeing::Boolean should_share_empty_to_paired() noexcept {
	cWeak< testing::Pointing_testing_class > empty_cweak;

	cShared< testing::Pointing_testing_class > empty_cshared = empty_cweak.get_as_cshared();

	if ( empty_cweak.is_not_empty() ) return typeing::False;
	if ( !empty_cshared.is_empty() ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_create() noexcept {
	cShared< testing::Pointing_testing_class > filled_cshared = create_testing_object();
	cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();

	if ( filled_cweak.is_empty() ) return typeing::False;
	if ( !filled_cweak.is_not_empty() ) return typeing::False;
	if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_not_delete_the_object() noexcept {
	cShared< testing::Pointing_testing_class > filled_cshared = create_testing_object();

	{
		cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
	}

	try {
		*filled_cshared;
		return testing::Pointing_testing_class::get_object_counter_value() == typeing::Memory_natural_one;
	} catch ( ... ) {
		return typeing::False;
	}
}

typeing::Boolean should_copy() noexcept {
	cShared< testing::Pointing_testing_class > filled_cshared = create_testing_object();

	// copy
	{
		cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
		cWeak< testing::Pointing_testing_class > filled_cweak_1;
		filled_cweak_1 = filled_cweak;

		if ( filled_cweak.is_empty() ) return typeing::False;
		if ( !filled_cweak.is_not_empty() ) return typeing::False;
		if ( filled_cweak_1.is_empty() ) return typeing::False;
		if ( !filled_cweak_1.is_not_empty() ) return typeing::False;
		if ( filled_cweak.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_cweak.get_connectivity().get_strong_connectivity() != typeing::Memory_natural_one ) return typeing::False;
		if ( filled_cweak.get_connectivity().get_weak_connectivity() != typeing::Memory_natural::create( 2 ) ) return typeing::False;

	}

	if ( filled_cshared.get_connectivity().get_total_connectivity() != typeing::Memory_natural_one ) return typeing::False;

	// copy construct
	{
		cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();
		cWeak< testing::Pointing_testing_class > filled_cweak_1 = filled_cweak;

		if ( filled_cweak.is_empty() ) return typeing::False;
		if ( !filled_cweak.is_not_empty() ) return typeing::False;
		if ( filled_cweak_1.is_empty() ) return typeing::False;
		if ( !filled_cweak_1.is_not_empty() ) return typeing::False;
		if ( filled_cweak.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_cweak.get_connectivity().get_strong_connectivity() != typeing::Memory_natural_one ) return typeing::False;
		if ( filled_cweak.get_connectivity().get_weak_connectivity() != typeing::Memory_natural::create( 2 ) ) return typeing::False;

	}

	if ( filled_cshared.get_connectivity().get_total_connectivity() != typeing::Memory_natural_one ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_dereference() noexcept {
	cShared< testing::Pointing_testing_class > filled_cshared = create_testing_object();
	cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();

	try {
		*filled_cweak.get_as_cshared();
	} catch ( ... ) {
		return typeing::False;
	}

	return typeing::True;
}

typeing::Boolean should_share_to_paired() noexcept {
	cShared< testing::Pointing_testing_class > filled_cshared = create_testing_object();
	cWeak< testing::Pointing_testing_class > filled_cweak = filled_cshared.get_as_cweak();

	if ( filled_cweak.is_empty() ) return typeing::False;
	if ( !filled_cweak.is_not_empty() ) return typeing::False;
	if ( filled_cweak.get_as_cshared()->get_object_number_value() != typeing::Memory_natural_one ) return typeing::False;

	cShared< testing::Pointing_testing_class > filled_cshared_2 = filled_cweak.get_as_cshared();

	if ( filled_cshared_2->get_object_number_value() != typeing::Memory_natural_one ) return typeing::False;

	if ( filled_cshared.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
	if ( filled_cshared.get_connectivity().get_strong_connectivity() != typeing::Memory_natural::create( 2 ) ) return typeing::False;
	if ( filled_cshared.get_connectivity().get_weak_connectivity() != typeing::Memory_natural_one ) return typeing::False;

	{
		cWeak< testing::Pointing_testing_class > filled_cweak_1;
		{
			cShared< testing::Pointing_testing_class > filled_cshared_1 = create_testing_object();
			filled_cweak_1 = filled_cshared_1.get_as_cweak();
		}


		cShared< testing::Pointing_testing_class > empty_cshared = filled_cweak_1.get_as_cshared();

		if ( empty_cshared.is_not_empty() ) return typeing::False;
		if ( !empty_cshared.is_empty() ) return typeing::False;

		if ( filled_cweak_1.is_not_empty() ) return typeing::False;
		if ( filled_cweak_1.get_connectivity().get_total_connectivity() != typeing::Memory_natural_one ) return typeing::False;
		if ( filled_cweak_1.get_connectivity().get_strong_connectivity() != typeing::Memory_natural_nil ) return typeing::False;
		if ( filled_cweak_1.get_connectivity().get_weak_connectivity() != typeing::Memory_natural_one ) return typeing::False;
	}

	return typeing::True;
}


} // namespace tests_cweak
} // namespace pointing
} // namespace jmsf
