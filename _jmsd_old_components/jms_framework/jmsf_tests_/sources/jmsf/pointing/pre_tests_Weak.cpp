#include "pre_tests_Weak.hxx"

#include "testing/Pointing_testing_class.h"
#include "jmsf/pointing/Weak.hin"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/testing/testing_Allocators.h"


#include <string>
#include <iostream>


namespace jmsf {
namespace pointing {
namespace pre_tests_weak {
	Shared< testing::Pointing_testing_class > create_testing_object();

	typeing::Boolean should_create_empty() noexcept;
	typeing::Boolean should_delete_empty() noexcept;
	typeing::Boolean should_copy_empty() noexcept;
	typeing::Boolean should_not_dereference_empty() noexcept;
	typeing::Boolean should_share_empty_to_paired() noexcept;
	typeing::Boolean should_share_empty_to_constant() noexcept;

	typeing::Boolean should_create();
	typeing::Boolean should_not_delete_the_object();
	typeing::Boolean should_copy();
	typeing::Boolean should_dereference();
	typeing::Boolean should_share_to_paired();
	typeing::Boolean should_share_to_constant();
} // namespace pre_tests_weak
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_weak {


void pre_tests_Weak() noexcept {
	typeing::Boolean test_result = typeing::True;
	encodebuba::nativing::native_memory_natural test_line = 0;

	try {
		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Weak: should create empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_delete_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Weak: should delete empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_copy_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Weak: should copy empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_not_dereference_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Weak: should not dereference empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_empty_to_paired() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Weak: should share empty to paired - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_empty_to_constant() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Weak: should share empty to contant - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Weak: should create - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_not_delete_the_object() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Weak: should not delete the object - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_copy() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Weak: should copy - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_dereference() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Weak: should dereference empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_to_paired() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Weak: should share to paired - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_to_constant() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Weak: should share to contant - failed" << ::std::endl;
		}
	} catch( ... ) {
		::std::cout << "Exception in file: " << JMSF_ENCODEBUBA_FILE << ::std::endl;
		::std::cout << "at line: " << test_line << ::std::endl;
		test_result = typeing::False;
	}

	if ( !test_result ) {
		::std::cout << "pre_tests_Weak - failed" << ::std::endl;
	} else {
		::std::cout << "pre_tests_Weak - successful" << ::std::endl;
	}
}


} // namespace pre_tests_weak
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_weak {


Shared< testing::Pointing_testing_class > create_testing_object() {
	return
		Shared< testing::Pointing_testing_class >::create(
			::jmsf::testing::testing_Allocators::instance()->get_reference_counters_allocator(),
			memorying::Constructor< testing::Pointing_testing_class, testing::Pointing_testing_class >::construct(
				::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator () ) );
}

typeing::Boolean should_create_empty() noexcept {
	Weak< testing::Pointing_testing_class > empty_weak;

	if ( empty_weak.is_not_empty() ) return typeing::False;
	if ( !empty_weak.is_empty() ) return typeing::False;
	if ( empty_weak.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_delete_empty() noexcept {
	{
		Weak< testing::Pointing_testing_class > empty_weak;
	}

	return typeing::True;
}

typeing::Boolean should_copy_empty() noexcept {
	// copy
	{
		Weak< testing::Pointing_testing_class > empty_weak;
		Weak< testing::Pointing_testing_class > empty_weak_1;
		empty_weak_1 = empty_weak;

		if ( empty_weak.is_not_empty() ) return typeing::False;
		if ( !empty_weak.is_empty() ) return typeing::False;
		if ( empty_weak_1.is_not_empty() ) return typeing::False;
		if ( !empty_weak_1.is_empty() ) return typeing::False;
		if ( empty_weak.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	}

	// copy construct
	{
		Weak< testing::Pointing_testing_class > empty_weak;
		Weak< testing::Pointing_testing_class > empty_weak_1 = empty_weak;

		if ( empty_weak.is_not_empty() ) return typeing::False;
		if ( !empty_weak.is_empty() ) return typeing::False;
		if ( empty_weak_1.is_not_empty() ) return typeing::False;
		if ( !empty_weak_1.is_empty() ) return typeing::False;
		if ( empty_weak.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	}

	return typeing::True;
}

typeing::Boolean should_not_dereference_empty() noexcept {
	Weak< testing::Pointing_testing_class > empty_weak;

	try {
		*empty_weak.get_as_shared();
	} catch ( ... ) {
		return typeing::True;
	}

	return typeing::False;
}

typeing::Boolean should_share_empty_to_paired() noexcept {
	Weak< testing::Pointing_testing_class > empty_weak;

	Shared< testing::Pointing_testing_class > empty_shared = empty_weak.get_as_shared();

	if ( empty_weak.is_not_empty() ) return typeing::False;
	if ( !empty_shared.is_empty() ) return typeing::False;
	if ( empty_weak.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;
	if ( empty_shared.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_share_empty_to_constant() noexcept {
	Weak< testing::Pointing_testing_class > empty_weak;

	cWeak< testing::Pointing_testing_class > empty_cweak = empty_weak.get_as_cweak();

	if ( empty_cweak.is_not_empty() ) return typeing::False;
	if ( !empty_cweak.is_empty() ) return typeing::False;
	if ( empty_weak.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;
	if ( empty_cweak.get_connectivity().get_total_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_create() {
	Shared< testing::Pointing_testing_class > filled_shared = create_testing_object();
	Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();

	if ( filled_weak.is_empty() ) return typeing::False;
	if ( !filled_weak.is_not_empty() ) return typeing::False;
	if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) return typeing::False;

	if ( filled_shared.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 2 ) ) return typeing::False;
	if ( filled_weak.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 2 ) ) return typeing::False;

	if ( filled_shared.get_connectivity().get_strong_connectivity() != typeing::Memory_natural_one ) return typeing::False;
	if ( filled_shared.get_connectivity().get_weak_connectivity() != typeing::Memory_natural_one ) return typeing::False;
	if ( filled_weak.get_connectivity().get_strong_connectivity() != typeing::Memory_natural_one ) return typeing::False;
	if ( filled_weak.get_connectivity().get_weak_connectivity() != typeing::Memory_natural_one ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_not_delete_the_object() {
//	testing_dev::Shared_class *filled_shared_reference = nullptr;
	Shared< testing::Pointing_testing_class > filled_shared = create_testing_object();

	{
		Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
	}

	if ( filled_shared.get_connectivity().get_total_connectivity() != typeing::Memory_natural_one ) return typeing::False;
	if ( filled_shared.get_connectivity().get_strong_connectivity() != typeing::Memory_natural_one ) return typeing::False;
	if ( filled_shared.get_connectivity().get_weak_connectivity() != typeing::Memory_natural_nil ) return typeing::False;

	try {
		*filled_shared;
		return testing::Pointing_testing_class::get_object_counter_value() == typeing::Memory_natural_one;
	} catch ( ... ) {
		return typeing::False;
	}
}

typeing::Boolean should_copy() {
	Shared< testing::Pointing_testing_class > filled_shared = create_testing_object();

	// copy
	{
		Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
		Weak< testing::Pointing_testing_class > filled_weak_1;
		filled_weak_1 = filled_weak;

		if ( filled_weak.is_empty() ) return typeing::False;
		if ( !filled_weak.is_not_empty() ) return typeing::False;
		if ( filled_weak_1.is_empty() ) return typeing::False;
		if ( !filled_weak_1.is_not_empty() ) return typeing::False;
		if ( filled_weak.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_weak.get_connectivity().get_strong_connectivity() != typeing::Memory_natural_one ) return typeing::False;
		if ( filled_weak.get_connectivity().get_weak_connectivity() != typeing::Memory_natural::create( 2 ) ) return typeing::False;

	}

	if ( filled_shared.get_connectivity().get_total_connectivity() != typeing::Memory_natural_one ) return typeing::False;

	// copy construct
	{
		Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
		Weak< testing::Pointing_testing_class > filled_weak_1 = filled_weak;

		if ( filled_weak.is_empty() ) return typeing::False;
		if ( !filled_weak.is_not_empty() ) return typeing::False;
		if ( filled_weak_1.is_empty() ) return typeing::False;
		if ( !filled_weak_1.is_not_empty() ) return typeing::False;
		if ( filled_weak.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_weak.get_connectivity().get_strong_connectivity() != typeing::Memory_natural_one ) return typeing::False;
		if ( filled_weak.get_connectivity().get_weak_connectivity() != typeing::Memory_natural::create( 2 ) ) return typeing::False;

	}

	if ( filled_shared.get_connectivity().get_total_connectivity() != typeing::Memory_natural_one ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_dereference() {
	Shared< testing::Pointing_testing_class > filled_shared = create_testing_object();
	Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();

	try {
		*filled_weak.get_as_shared();
	} catch ( ... ) {
		return typeing::False;
	}

	return typeing::True;
}

typeing::Boolean should_share_to_paired() {
	{
		Shared< testing::Pointing_testing_class > filled_shared = create_testing_object();
		Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();

		if ( filled_weak.is_empty() ) return typeing::False;
		if ( !filled_weak.is_not_empty() ) return typeing::False;

		Shared< testing::Pointing_testing_class > filled_shared_2 = filled_weak.get_as_shared();

		if ( filled_shared_2->get_object_number_value() != typeing::Memory_natural_one ) return typeing::False;

		if ( filled_shared.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
		if ( filled_shared.get_connectivity().get_strong_connectivity() != typeing::Memory_natural::create( 2 ) ) return typeing::False;
		if ( filled_shared.get_connectivity().get_weak_connectivity() != typeing::Memory_natural_one ) return typeing::False;
	}

	{
		Weak< testing::Pointing_testing_class > filled_weak_1;
		{
			Shared< testing::Pointing_testing_class > filled_shared_1 = create_testing_object();
			filled_weak_1 = filled_shared_1.get_as_weak();
		}

		Shared< testing::Pointing_testing_class > empty_shared = filled_weak_1.get_as_shared();

		if ( empty_shared.is_not_empty() ) return typeing::False;
		if ( !empty_shared.is_empty() ) return typeing::False;

		if ( filled_weak_1.is_not_empty() ) return typeing::False;
		if ( filled_weak_1.get_connectivity().get_total_connectivity() != typeing::Memory_natural_one ) return typeing::False;
		if ( filled_weak_1.get_connectivity().get_strong_connectivity() != typeing::Memory_natural_nil ) return typeing::False;
		if ( filled_weak_1.get_connectivity().get_weak_connectivity() != typeing::Memory_natural_one ) return typeing::False;
	}

	return typeing::True;
}

typeing::Boolean should_share_to_constant() {
	Shared< testing::Pointing_testing_class > filled_shared = create_testing_object();
	Weak< testing::Pointing_testing_class > filled_weak = filled_shared.get_as_weak();
	cWeak< testing::Pointing_testing_class > filled_cweak = filled_weak.get_as_cweak();

	if ( filled_cweak.is_empty() ) return typeing::False;
	if ( !filled_cweak.is_not_empty() ) return typeing::False;
	if ( filled_cweak.get_as_cshared()->get_object_number_value() != typeing::Memory_natural_one ) return typeing::False;

	if ( filled_shared.get_connectivity().get_total_connectivity() != typeing::Memory_natural::create( 3 ) ) return typeing::False;
	if ( filled_shared.get_connectivity().get_strong_connectivity() != typeing::Memory_natural_one ) return typeing::False;
	if ( filled_shared.get_connectivity().get_weak_connectivity() != typeing::Memory_natural::create( 2 ) ) return typeing::False;

	return typeing::True;
}


} // namespace pre_tests_weak
} // namespace pointing
} // namespace jmsf
