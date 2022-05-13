#include "jmsdl/component/component_test_lib_class.h"


#include "jmsdl/component/component_test_lib_function.h"
#include "jmsdl/component/component_lib_function.h"


#include <iostream>


int main( int const /*argc*/, char const *const * /*argv*/ ) {
	auto *example = new ::jmsdl::component::Component_test_lib_class;

	::std::cout << example->say_component_lib_hello() << ::std::endl;
	::std::cout << example->say_component_test_lib_hello() << ::std::endl;

	::std::cout << jmsdl_component_lib_function_say_executable_hello() << ::std::endl;
	::std::cout << jmsdl_component_test_lib_function_say_executable_hello() << ::std::endl;

	delete example;

	return 0;
}
