#include "c_executable_class.h"

#include "c_executable_function.h"
#include "c_derived_function.h"
#include "c_base_function.h"


#include <iostream>


int main( int const /*argc*/, char const *const * /*argv*/ ) {
	auto *example = new ::jmsd::c_executable::C_executable_class;

	::std::cout << example->say_base_hello() << ::std::endl;
	::std::cout << example->say_derived_hello() << ::std::endl;
	::std::cout << example->say_executable_hello() << ::std::endl;

	::std::cout << jmsd_c_base_function_say_hello() << ::std::endl;
	::std::cout << jmsd_c_derived_function_say_hello() << ::std::endl;
	::std::cout << jmsd_c_executable_function_say_hello() << ::std::endl;

	delete example;

	return 0;
}
