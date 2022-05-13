#include "pre_tests_Shared.hxx"

#include "testing/Pointing_testing_class.h"
#include "jmsf/pointing/Shared.hin"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/testing/testing_Allocators.h"


#include <string>
#include <iostream>


namespace jmsf {
namespace pointing {
namespace pre_tests_shared {
	Shared< testing::Pointing_testing_class > create_testing_object();

	typeing::Boolean should_create_empty() noexcept;
	typeing::Boolean should_delete_empty() noexcept;
	typeing::Boolean should_copy_empty() noexcept;
	typeing::Boolean should_not_dereference_empty() noexcept;
	typeing::Boolean should_share_empty_to_paired() noexcept;
	typeing::Boolean should_share_empty_to_constant() noexcept;

	typeing::Boolean should_create() noexcept;
	typeing::Boolean should_delete() noexcept;
	typeing::Boolean should_copy() noexcept;
	typeing::Boolean should_dereference() noexcept;
	typeing::Boolean should_share_to_paired() noexcept;
	typeing::Boolean should_share_to_constant() noexcept;
} // namespace tests_shared
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_shared {


void pre_tests_Shared() noexcept {
	typeing::Boolean test_result = typeing::True;
	encodebuba::nativing::native_memory_natural test_line = 0;

	try {
		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Shared: should create empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_delete_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Shared: should delete empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_copy_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Shared: should copy empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_not_dereference_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Shared: should not dereference empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_empty_to_paired() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Shared: should share empty to paired - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_empty_to_constant() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Shared: should share empty to contant - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Shared: should create - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_delete() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Shared: should delete - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_copy() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Shared: should copy - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_dereference() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Shared: should dereference empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_to_paired() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Shared: should share to paired - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_to_constant() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Shared: should share to contant - failed" << ::std::endl;
		}
	} catch( ... ) {
		::std::cout << "Exception in file: " << JMSF_ENCODEBUBA_FILE << ::std::endl;
		::std::cout << "at line: " << test_line << ::std::endl;
		test_result = typeing::False;
	}

	if ( !test_result ) {
		::std::cout << "pre_tests_Shared - failed" << ::std::endl;
	} else {
		::std::cout << "pre_tests_Shared - successful" << ::std::endl;
	}
}


} // namespace tests_shared
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_shared {


Shared< testing::Pointing_testing_class > create_testing_object() {
	return
		Shared< testing::Pointing_testing_class >::create(
			::jmsf::testing::testing_Allocators::instance()->get_reference_counters_allocator(),
			memorying::Constructor< testing::Pointing_testing_class, testing::Pointing_testing_class >::construct(
				::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator () ) );
}

typeing::Boolean should_create_empty() noexcept {
	Shared< testing::Pointing_testing_class > empty_shared;

	if ( empty_shared.is_not_empty() ) return typeing::False;
	if ( !empty_shared.is_empty() ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_delete_empty() noexcept {
	{
		Shared< testing::Pointing_testing_class > empty_shared;
	}

	return typeing::True;
}

typeing::Boolean should_copy_empty() noexcept {
	// copy
	{
		Shared< testing::Pointing_testing_class > empty_shared;
		Shared< testing::Pointing_testing_class > empty_shared_1;
		empty_shared_1 = empty_shared;

		if ( empty_shared.is_not_empty() ) return typeing::False;
		if ( !empty_shared.is_empty() ) return typeing::False;
		if ( empty_shared_1.is_not_empty() ) return typeing::False;
		if ( !empty_shared_1.is_empty() ) return typeing::False;
		if ( empty_shared.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	}

	// copy construct
	{
		Shared< testing::Pointing_testing_class > empty_shared;
		Shared< testing::Pointing_testing_class > empty_shared_1 = empty_shared;

		if ( empty_shared.is_not_empty() ) return typeing::False;
		if ( !empty_shared.is_empty() ) return typeing::False;
		if ( empty_shared_1.is_not_empty() ) return typeing::False;
		if ( !empty_shared_1.is_empty() ) return typeing::False;
		if ( empty_shared.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	}

	return typeing::True;
}

typeing::Boolean should_not_dereference_empty() noexcept {
	Shared< testing::Pointing_testing_class > empty_shared;

	try {
		*empty_shared;
	} catch ( ... ) {
		return typeing::True;
	}

	return typeing::False;
}

typeing::Boolean should_share_empty_to_paired() noexcept {
	Shared< testing::Pointing_testing_class > empty_shared;

	Weak< testing::Pointing_testing_class > empty_cshared = empty_shared.get_as_weak();

	if ( empty_cshared.is_not_empty() ) return typeing::False;
	if ( !empty_cshared.is_empty() ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_share_empty_to_constant() noexcept {
	Shared< testing::Pointing_testing_class > empty_shared;

	cShared< testing::Pointing_testing_class > empty_cshared = empty_shared.get_as_cshared();

	if ( empty_cshared.is_not_empty() ) return typeing::False;
	if ( !empty_cshared.is_empty() ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_create() noexcept {
	Shared< testing::Pointing_testing_class > filled_shared = create_testing_object();

	if ( filled_shared.is_empty() ) return typeing::False;
	if ( !filled_shared.is_not_empty() ) return typeing::False;
	if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_delete() noexcept {
	{
		Shared< testing::Pointing_testing_class > filled_shared = create_testing_object();
	}

	if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_nil ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_copy() noexcept {
	Shared< testing::Pointing_testing_class > filled_shared_0 = create_testing_object();

	// copy
	{
		Shared< testing::Pointing_testing_class > filled_shared = filled_shared_0;
		Shared< testing::Pointing_testing_class > filled_shared_1;
		filled_shared_1 = filled_shared;

		if ( filled_shared.is_empty() ) return typeing::False;
		if ( !filled_shared.is_not_empty() ) return typeing::False;
		if ( filled_shared_1.is_empty() ) return typeing::False;
		if ( !filled_shared_1.is_not_empty() ) return typeing::False;
		if ( filled_shared.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_shared.get_connectivity().get_strong_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_shared.get_connectivity().get_weak_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	}

	if ( filled_shared_0.get_connectivity().get_total_connectivity() != typeing::Memory_natural_one ) return typeing::False;

	// copy construct
	{
		Shared< testing::Pointing_testing_class > filled_shared = filled_shared_0;
		Shared< testing::Pointing_testing_class > filled_shared_1 = filled_shared;

		if ( filled_shared.is_empty() ) return typeing::False;
		if ( !filled_shared.is_not_empty() ) return typeing::False;
		if ( filled_shared_1.is_empty() ) return typeing::False;
		if ( !filled_shared_1.is_not_empty() ) return typeing::False;
		if ( filled_shared.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_shared.get_connectivity().get_strong_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_shared.get_connectivity().get_weak_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	}

	if ( filled_shared_0.get_connectivity().get_total_connectivity() != typeing::Memory_natural_one ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_dereference() noexcept {
	Shared< testing::Pointing_testing_class > filled_shared = create_testing_object();

	try {
		*filled_shared;
	} catch ( ... ) {
		return typeing::False;
	}

	return typeing::True;
}

typeing::Boolean should_share_to_paired() noexcept {
	Shared< testing::Pointing_testing_class > filled_shared = create_testing_object();
	Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();

	if ( filled_weak.is_empty() ) return typeing::False;
	if ( !filled_weak.is_not_empty() ) return typeing::False;
	if ( filled_weak.get_as_shared()->get_object_number_value() != typeing::Memory_natural_one ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_share_to_constant() noexcept {
	Shared< testing::Pointing_testing_class > filled_shared = create_testing_object();
	Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
	cWeak< testing::Pointing_testing_class > filled_cweak = filled_weak.get_as_cweak();

	if ( filled_cweak.is_empty() ) return typeing::False;
	if ( !filled_cweak.is_not_empty() ) return typeing::False;
	if ( filled_cweak.get_as_cshared()->get_object_number_value() != typeing::Memory_natural_one ) return typeing::False;

	return typeing::True;
}


} // namespace tests_shared
} // namespace pointing
} // namespace jmsf
