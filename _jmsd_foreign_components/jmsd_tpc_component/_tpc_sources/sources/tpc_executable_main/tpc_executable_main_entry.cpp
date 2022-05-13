#include "tpc_executable_class.h"

#include "tpc_executable_function.h"
#include "tpc_derived_function.h"
#include "tpc_base_function.h"


#include <iostream>


int main( int const /*argc*/, char const *const * /*argv*/ ) {
	auto *example = new ::jmsd::tpc_executable::Tpc_executable_class;

	::std::cout << example->say_base_hello() << ::std::endl;
	::std::cout << example->say_derived_hello() << ::std::endl;
	::std::cout << example->say_executable_hello() << ::std::endl;

	::std::cout << jmsd_tpc_base_function_say_executable_hello() << ::std::endl;
	::std::cout << jmsd_tpc_derived_function_say_executable_hello() << ::std::endl;
	::std::cout << jmsd_tpc_executable_function_say_executable_hello() << ::std::endl;

	delete example;

	return 0;
}
