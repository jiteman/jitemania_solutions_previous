#include "exp_sfml_executable_class.h"

#include "exp_sfml_executable_function.h"
#include "exp_sfml_derived_function.h"
#include "exp_sfml_base_function.h"

#include "SFML/Graphics.hpp"


#include <iostream>

int main( int const /*argc*/, char const *const * /*argv*/ ) {
	{
		auto *example = new ::jmsd::exp_executable::Exp_sfml_executable_class;

		::std::cout << example->say_base_hello() << ::std::endl;
		::std::cout << example->say_derived_hello() << ::std::endl;
		::std::cout << example->say_executable_hello() << ::std::endl;

		::std::cout << jmsd_exp_sfml_base_function_say_executable_hello() << ::std::endl;
		::std::cout << jmsd_exp_sfml_derived_function_say_executable_hello() << ::std::endl;
		::std::cout << jmsd_exp_sfml_executable_function_say_executable_hello() << ::std::endl;

		delete example;
	}

	{
		::sf::Color green( 0, 255, 0 );
		::sf::RenderWindow window( ::sf::VideoMode( 200, 200 ), "SFML works!" );
		::sf::CircleShape shape( 100.f );
//		shape.setFillColor( ::sf::Color::Black );
//		shape.setFillColor( ::sf::Color::Red );
//		shape.setFillColor( ::sf::Color::Green );
		shape.setFillColor( green );

		while ( window.isOpen() ) {
			sf::Event event;

			while ( window.pollEvent( event ) ) {
				if ( event.type == sf::Event::Closed )
					window.close();
			}

			window.clear();
			window.draw( shape );
			window.display();
		}
	}

	return 0;
}
