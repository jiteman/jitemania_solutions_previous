#include "Ansii_character.h"


namespace jmsf {
namespace typeing {


internals::platform_character Ansii_character::get_as_c() const noexcept {
	return _the_platform_character;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Ansii_character::~Ansii_character() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_character::Ansii_character() noexcept {
	_the_platform_character = internals::platform_character( 0 );
}

Ansii_character::Ansii_character( internals::platform_character a_platform_character ) noexcept {
	_the_platform_character = a_platform_character;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_character::Ansii_character( const Ansii_character &another ) noexcept {
	_the_platform_character = another._the_platform_character;
}

const Ansii_character &Ansii_character::operator =( const Ansii_character &another ) noexcept {
	if ( &another == this ) return *this;

	_the_platform_character = another._the_platform_character;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace typeing
} // namespace jmsf
