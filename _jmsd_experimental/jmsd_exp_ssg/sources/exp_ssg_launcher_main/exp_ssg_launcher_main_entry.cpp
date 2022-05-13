#include "exp_ssg_Game_launcher.h"


#include <iostream>


int main( int const /*argc*/, char const *const * /*argv*/ ) {
	::std::cout << ::std::endl << "Simple Strategy Game has been started" << ::std::endl;

	int const game_run_result = exp_ssg_Game_launcher();

	::std::cout << ::std::endl << "Simple Strategy Game has been ended" << ::std::endl;
	return game_run_result;
}
