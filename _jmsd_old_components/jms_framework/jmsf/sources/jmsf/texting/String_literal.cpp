#include "String_literal.h"


namespace jmsf {
namespace texting {


const typeing::internals::platform_character *String_literal::get() const noexcept {
	if ( _c_string_literal == nullptr ) return "";

	return _c_string_literal;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
String_literal::~String_literal() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
String_literal::String_literal() noexcept {
	_c_string_literal = nullptr;
}

String_literal::String_literal( const typeing::internals::platform_character *c_string_literal ) noexcept {
	_c_string_literal = c_string_literal;
}

// static
String_literal String_literal::create( const typeing::internals::platform_character *c_string_literal ) noexcept {
	return String_literal( c_string_literal );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
String_literal::String_literal( const String_literal &another ) noexcept {
	_c_string_literal = another._c_string_literal;
}

const String_literal &String_literal::operator =( const String_literal &another ) noexcept {
	if ( &another == this ) return *this;

	_c_string_literal = another._c_string_literal;
	return *this;
}

String_literal::String_literal( String_literal &&another ) noexcept {
	_c_string_literal = another._c_string_literal;
}

String_literal &String_literal::operator =( String_literal &&another ) noexcept {
	if ( &another == this ) return *this;

	_c_string_literal = another._c_string_literal;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace texting
} // namespace jmsf
