#include "pre_tests_cNonlinked.hxx"


#include "testing/Pointing_testing_class.h"
#include "jmsf/pointing/cScoped.hin"
//#include "jmsf/pointing/Nonlinked.hin"

#include "jmsf/testing/testing_Allocators.h"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Destructor.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/typeing/Boolean.h"

#include <string>
#include <iostream>


namespace jmsf {
namespace pointing {
namespace pre_tests_cnonlinked {
	memorying::Omp< testing::Pointing_testing_class > create_testing_object();
	void destroy_testing_object( const memorying::Omp< testing::Pointing_testing_class > &testing_object_omp ) noexcept;

	typeing::Boolean should_create_empty() noexcept;
	typeing::Boolean should_delete_empty() noexcept;
	typeing::Boolean should_copy_empty() noexcept;
	typeing::Boolean should_not_dereference_empty() noexcept;
	typeing::Boolean should_share_empty_to_constant() noexcept;

	typeing::Boolean should_create() noexcept;
	typeing::Boolean should_not_delete_the_object() noexcept;
	typeing::Boolean should_copy() noexcept;
	typeing::Boolean should_dereference() noexcept;
	typeing::Boolean should_share_to_constant() noexcept;
} // namespace tests_cnonlinked
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_cnonlinked {


void pre_tests_cNonlinked() noexcept {
	typeing::Boolean test_result = typeing::True;
	encodebuba::nativing::native_memory_natural test_line = 0;

	try {
		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cNonlinked: should create empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_delete_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cNonlinked: should delete empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_copy_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cNonlinked: should copy empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_not_dereference_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cNonlinked: should not dereference empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cNonlinked: should create - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_not_delete_the_object() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cNonlinked: should not delete the object - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_copy() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cNonlinked: should copy - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_dereference() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_cNonlinked: should dereference empty - failed" << ::std::endl;
		}
	} catch( ... ) {
		::std::cout << "Exception in file: " << JMSF_ENCODEBUBA_FILE << ::std::endl;
		::std::cout << "at line: " << test_line << ::std::endl;
		test_result = typeing::False;
	}

	if ( !test_result ) {
		::std::cout << "pre_tests_cNonlinked - failed" << ::std::endl;
	} else {
		::std::cout << "pre_tests_cNonlinked - successful" << ::std::endl;
	}
}


} // namespace tests_cnonlinked
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_cnonlinked {


memorying::Omp< testing::Pointing_testing_class > create_testing_object() {
	return
		memorying::Constructor< testing::Pointing_testing_class, testing::Pointing_testing_class >::construct(
			::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator() );
}

void destroy_testing_object( const memorying::Omp< testing::Pointing_testing_class > &testing_object_omp ) noexcept {
	memorying::Destructor< testing::Pointing_testing_class >::destruct(
		testing_object_omp );
}

typeing::Boolean should_create_empty() noexcept {
	cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;

	if ( empty_cnonlinked.is_not_empty() ) return typeing::False;
	if ( !empty_cnonlinked.is_empty() ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_delete_empty() noexcept {
	{
		cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;
	}

	return typeing::True;
}

typeing::Boolean should_copy_empty() noexcept {
	// copy
	{
		cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;
		cNonlinked< testing::Pointing_testing_class > empty_cnonlinked_1;
		empty_cnonlinked_1 = empty_cnonlinked;

		if ( empty_cnonlinked.is_not_empty() ) return typeing::False;
		if ( !empty_cnonlinked.is_empty() ) return typeing::False;
		if ( empty_cnonlinked_1.is_not_empty() ) return typeing::False;
		if ( !empty_cnonlinked_1.is_empty() ) return typeing::False;
	}

	// copy construct
	{
		cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;
		cNonlinked< testing::Pointing_testing_class > empty_cnonlinked_1 = empty_cnonlinked;

		if ( empty_cnonlinked.is_not_empty() ) return typeing::False;
		if ( !empty_cnonlinked.is_empty() ) return typeing::False;
		if ( empty_cnonlinked_1.is_not_empty() ) return typeing::False;
		if ( !empty_cnonlinked_1.is_empty() ) return typeing::False;
	}

	return typeing::True;
}

typeing::Boolean should_not_dereference_empty() noexcept {
	cNonlinked< testing::Pointing_testing_class > empty_cnonlinked;

	try {
		*empty_cnonlinked;
	} catch ( ... ) {
		return typeing::True;
	}

	return typeing::False;
}

typeing::Boolean should_create() noexcept {
	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();
	cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );

	typeing::Boolean test_result = typeing::True;

	if ( filled_cnonlinked.is_empty() ) test_result = typeing::False;
	if ( !filled_cnonlinked.is_not_empty() ) test_result = typeing::False;

	destroy_testing_object( testing_object_omp );
	return test_result;
}

typeing::Boolean should_not_delete_the_object() noexcept {
	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();

	typeing::Boolean test_result = typeing::True;

	{
		cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );
	}

	if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) test_result = typeing::False;

	destroy_testing_object( testing_object_omp );
	return test_result;
}

typeing::Boolean should_copy() noexcept {
	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();

	typeing::Boolean test_result = typeing::True;

	// copy
	{
		cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );
		cNonlinked< testing::Pointing_testing_class > filled_cnonlinked_1;
		filled_cnonlinked_1 = filled_cnonlinked;

		if ( filled_cnonlinked.is_empty() ) test_result = typeing::False;
		if ( !filled_cnonlinked.is_not_empty() ) test_result = typeing::False;
		if ( filled_cnonlinked_1.is_empty() ) test_result = typeing::False;
		if ( !filled_cnonlinked_1.is_not_empty() ) test_result = typeing::False;
		if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) test_result = typeing::False;
	}

	// copy construct
	{
		cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );
		cNonlinked< testing::Pointing_testing_class > filled_cnonlinked_1 = filled_cnonlinked;

		if ( filled_cnonlinked.is_empty() ) test_result = typeing::False;
		if ( !filled_cnonlinked.is_not_empty() ) test_result = typeing::False;
		if ( filled_cnonlinked_1.is_empty() ) test_result = typeing::False;
		if ( !filled_cnonlinked_1.is_not_empty() ) test_result = typeing::False;
		if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) test_result = typeing::False;
	}

	destroy_testing_object( testing_object_omp );
	return test_result;
}

typeing::Boolean should_dereference() noexcept {
	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();
	cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = cNonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );

	typeing::Boolean test_result = typeing::True;

	try {
		*filled_cnonlinked;
	} catch ( ... ) {
		return test_result = typeing::False;
	}

	destroy_testing_object( testing_object_omp );
	return test_result;
}


} // namespace tests_cnonlinked
} // namespace pointing
} // namespace jmsf
