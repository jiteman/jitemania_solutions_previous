#include "exp_boost_example_class.h"

#include "exp_boost_example_function.h"


#include <iostream>

#include "boost/program_options/options_description.hpp"
#include "boost/program_options/option.hpp"

using namespace std;
#include <iostream>

void boost_main();

void boost_main() {
    ::boost::program_options::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ;
}


int main( int const /*argc*/, char const *const * /*argv*/ ) {
	auto *example = new ::jmsd::exp_executable::Exp_executable_class;

	::std::cout << example->say_executable_hello() << ::std::endl;

	::std::cout << jmsd_exp_executable_function_say_executable_hello() << ::std::endl;

	delete example;

	boost_main();

	return 0;
}
