#include "exp_executable_class.h"

#include "exp_executable_function.h"
#include "exp_derived_function.h"
#include "exp_base_function.h"


#include <iostream>


int main( int const /*argc*/, char const *const * /*argv*/ ) {
	auto *example = new ::jmsd::exp_executable::Exp_executable_class;

	::std::cout << example->say_base_hello() << ::std::endl;
	::std::cout << example->say_derived_hello() << ::std::endl;
	::std::cout << example->say_executable_hello() << ::std::endl;

	::std::cout << jmsd_exp_base_function_say_executable_hello() << ::std::endl;
	::std::cout << jmsd_exp_derived_function_say_executable_hello() << ::std::endl;
	::std::cout << jmsd_exp_executable_function_say_executable_hello() << ::std::endl;

	delete example;

	return 0;
}
