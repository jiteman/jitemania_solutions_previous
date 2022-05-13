#include "et/et_class.h"

#include "et/et_function.h"
#include "dlt/dlt_function.h"
#include "blt/blt_function.h"

#include <iostream>


int main( int const /*argc*/, char const *const * /*argv*/ ) {
	auto *example = new ::jmsd::et::Executable_class;

	::std::cout << example->say_base_hello() << ::std::endl;
	::std::cout << example->say_derived_hello() << ::std::endl;
	::std::cout << example->say_executable_hello() << ::std::endl;

	::std::cout << jmsd_blt_base_function_say_function_hello() << ::std::endl;
	::std::cout << jmsd_dlt_derived_function_say_executable_hello() << ::std::endl;
	::std::cout << jmsd_et_executable_function_say_executable_hello() << ::std::endl;

	delete example;

	return 0;
}
