#include "jmsdl/nutfield/nutfield_test_lib_class.h"


#include <iostream>


int main( int const /*argc*/, char const *const * /*argv*/ ) {
	auto *example = new ::jmsdl::nutfield::Nutfield_test_lib_class;

	::std::cout << example->say_nutfield_lib_hello() << ::std::endl;
	::std::cout << example->say_nutfield_test_lib_hello() << ::std::endl;

	delete example;

	return 0;
}
