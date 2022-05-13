#include "pre_tests_Nonlinked.hxx"

#include "testing/Pointing_testing_class.h"
#include "jmsf/pointing/Nonlinked.hin"
//#include "jmsf/pointing/Scoped.hin"

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
namespace pre_tests_nonlinked {
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
} // namespace tests_nonlinked
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_nonlinked {


void pre_tests_Nonlinked() noexcept {
	typeing::Boolean test_result = typeing::True;
	encodebuba::nativing::native_memory_natural test_line = 0;

	try {
		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Nonlinked: should create empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_delete_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Nonlinked: should delete empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_copy_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Nonlinked: should copy empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_not_dereference_empty() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Nonlinked: should not dereference empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_empty_to_constant() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Nonlinked: should share empty to contant - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_create() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Nonlinked: should create - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_not_delete_the_object() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Nonlinked: should not delete the object - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_copy() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Nonlinked: should copy empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_dereference() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Nonlinked: should dereference empty - failed" << ::std::endl;
		}

		test_line = JMSF_ENCODEBUBA_LINE;
		if ( !should_share_to_constant() ) {
			test_result = typeing::False;
			::std::cout << "pre_tests_Nonlinked: should share to contant - failed" << ::std::endl;
		}
	} catch( ... ) {
		::std::cout << "Exception in file: " << JMSF_ENCODEBUBA_FILE << ::std::endl;
		::std::cout << "at line: " << test_line << ::std::endl;
		test_result = typeing::False;
	}

	if ( !test_result ) {
		::std::cout << "pre_tests_Nonlinked - failed" << ::std::endl;
	} else {
		::std::cout << "pre_tests_Nonlinked - successful" << ::std::endl;
	}
}


} // namespace tests_nonlinked
} // namespace pointing
} // namespace jmsf


namespace jmsf {
namespace pointing {
namespace pre_tests_nonlinked {


memorying::Omp< testing::Pointing_testing_class > create_testing_object() {
	return
		memorying::Constructor< testing::Pointing_testing_class, testing::Pointing_testing_class >::construct(
			::jmsf::testing::testing_Allocators::instance()->get_testing_object_allocator () );
}

void destroy_testing_object( const memorying::Omp< testing::Pointing_testing_class > &testing_object_omp ) noexcept {
	memorying::Destructor< testing::Pointing_testing_class >::destruct( testing_object_omp );
}

typeing::Boolean should_create_empty() noexcept {
	Nonlinked< testing::Pointing_testing_class > empty_nonlinked;

	if ( empty_nonlinked.is_not_empty() ) return typeing::False;
	if ( !empty_nonlinked.is_empty() ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_delete_empty() noexcept {
	{
		Nonlinked< testing::Pointing_testing_class > empty_nonlinked;
	}

	return typeing::True;
}

typeing::Boolean should_copy_empty() noexcept {
	// copy
	{
		Nonlinked< testing::Pointing_testing_class > empty_nonlinked;
		Nonlinked< testing::Pointing_testing_class > empty_nonlinked_1;
		empty_nonlinked_1 = empty_nonlinked;

		if ( empty_nonlinked.is_not_empty() ) return typeing::False;
		if ( !empty_nonlinked.is_empty() ) return typeing::False;
		if ( empty_nonlinked_1.is_not_empty() ) return typeing::False;
		if ( !empty_nonlinked_1.is_empty() ) return typeing::False;
	}

	// copy construct
	{
		Nonlinked< testing::Pointing_testing_class > empty_nonlinked;
		Nonlinked< testing::Pointing_testing_class > empty_nonlinked_1 = empty_nonlinked;

		if ( empty_nonlinked.is_not_empty() ) return typeing::False;
		if ( !empty_nonlinked.is_empty() ) return typeing::False;
		if ( empty_nonlinked_1.is_not_empty() ) return typeing::False;
		if ( !empty_nonlinked_1.is_empty() ) return typeing::False;
	}

	return typeing::True;
}

typeing::Boolean should_not_dereference_empty() noexcept {
	Nonlinked< testing::Pointing_testing_class > empty_nonlinked;

	try {
		*empty_nonlinked;
	} catch ( ... ) {
		return typeing::True;
	}

	return typeing::False;
}

typeing::Boolean should_share_empty_to_constant() noexcept {
	Nonlinked< testing::Pointing_testing_class > empty_nonlinked;

	cNonlinked< testing::Pointing_testing_class > empty_cnonlinked = empty_nonlinked.get_as_cnonlinked();

	if ( empty_cnonlinked.is_not_empty() ) return typeing::False;
	if ( !empty_cnonlinked.is_empty() ) return typeing::False;

	return typeing::True;
}

typeing::Boolean should_create() noexcept {
	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();
	Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );

	typeing::Boolean test_result = typeing::True;

	if ( filled_nonlinked.is_empty() ) test_result = typeing::False;
	if ( !filled_nonlinked.is_not_empty() ) test_result = typeing::False;

	destroy_testing_object( testing_object_omp );
	return test_result;
}

typeing::Boolean should_not_delete_the_object() noexcept {
	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();

	{
		Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );
	}

	typeing::Boolean test_result = typeing::True;

	if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) test_result = typeing::False;

	destroy_testing_object( testing_object_omp );
	return test_result;
}

typeing::Boolean should_copy() noexcept {
	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();

	typeing::Boolean test_result = typeing::True;

	// copy
	{
		Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );
		Nonlinked< testing::Pointing_testing_class > filled_nonlinked_1;
		filled_nonlinked_1 = filled_nonlinked;

		if ( filled_nonlinked.is_empty() ) test_result = typeing::False;
		if ( !filled_nonlinked.is_not_empty() ) test_result = typeing::False;
		if ( filled_nonlinked_1.is_empty() ) test_result = typeing::False;
		if ( !filled_nonlinked_1.is_not_empty() ) test_result = typeing::False;
		if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) test_result = typeing::False;
	}

	// copy construct
	{
		Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );
		Nonlinked< testing::Pointing_testing_class > filled_nonlinked_1 = filled_nonlinked;

		if ( filled_nonlinked.is_empty() ) test_result = typeing::False;
		if ( !filled_nonlinked.is_not_empty() ) test_result = typeing::False;
		if ( filled_nonlinked_1.is_empty() ) test_result = typeing::False;
		if ( !filled_nonlinked_1.is_not_empty() ) test_result = typeing::False;
		if ( testing::Pointing_testing_class::get_object_counter_value() != typeing::Memory_natural_one ) test_result = typeing::False;
	}

	destroy_testing_object( testing_object_omp );
	return test_result;
}

typeing::Boolean should_dereference() noexcept {
	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();
	Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );

	typeing::Boolean test_result = typeing::True;

	try {
		*filled_nonlinked;
	} catch ( ... ) {
		return test_result = typeing::False;
	}

	destroy_testing_object( testing_object_omp );
	return test_result;
}

typeing::Boolean should_share_to_constant() noexcept {
	memorying::Omp< testing::Pointing_testing_class > testing_object_omp = create_testing_object();
	Nonlinked< testing::Pointing_testing_class > filled_nonlinked = Nonlinked< testing::Pointing_testing_class >::create_from_static( testing_object_omp.get_as_womp() );
	cNonlinked< testing::Pointing_testing_class > filled_cnonlinked = filled_nonlinked.get_as_cnonlinked();

	typeing::Boolean test_result = typeing::True;

	if ( filled_cnonlinked.is_empty() ) test_result = typeing::False;
	if ( !filled_cnonlinked.is_not_empty() ) test_result = typeing::False;
	if ( filled_cnonlinked->get_object_number_value() != typeing::Memory_natural_one ) test_result = typeing::False;

	destroy_testing_object( testing_object_omp );
	return test_result;
}


} // namespace tests_nonlinked
} // namespace pointing
} // namespace jmsf
