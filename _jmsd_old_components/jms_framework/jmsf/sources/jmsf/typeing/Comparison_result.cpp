#include "Comparison_result.h"

#include "Integers.hin"
#include "Boolean.h"


namespace jmsf {
namespace typeing {


Boolean Comparison_result::is_empty() const noexcept {
	return _the_value.is_min();
}

Boolean Comparison_result::is_not_empty() const noexcept {
	return !is_empty();
}

Boolean Comparison_result::is_less() const noexcept {
	if ( is_empty() ) return False;

	return _the_value.is_negative();
}

Boolean Comparison_result::is_equal() const noexcept {
	if ( is_empty() ) return False;

	return _the_value.is_nil();
}

Boolean Comparison_result::is_greater() const noexcept {
	if ( is_empty() ) return False;

	return _the_value.is_positive();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean Comparison_result::is_not_less() const noexcept {
	if ( is_empty() ) return False;

	return is_less().inversion();
}

Boolean Comparison_result::is_not_equal() const noexcept {
	if ( is_empty() ) return False;

	return is_equal().inversion();
}

Boolean Comparison_result::is_not_greater() const noexcept {
	if ( is_empty() ) return False;

	return is_greater().inversion();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean Comparison_result::operator ==( const Comparison_result &another ) const noexcept {
	return Boolean::create( _the_value == another._the_value );
}

Boolean Comparison_result::operator !=( const Comparison_result &another ) const noexcept {
	return Boolean::create( _the_value != another._the_value );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Comparison_result::~Comparison_result() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Comparison_result::Comparison_result() noexcept
	:
		_the_value( Integer_min )
{}

// static
Comparison_result Comparison_result::create_less() noexcept {
	return Comparison_result( Integer_minus );
}

// static
Comparison_result Comparison_result::create_equal() noexcept {
	return Comparison_result( Integer() );
}

// static
Comparison_result Comparison_result::create_greater() noexcept {
	return Comparison_result( Integer_one );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Comparison_result::Comparison_result( const Integer a_value ) noexcept
	:
		_the_value( a_value )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Comparison_result::Comparison_result( const Comparison_result &another ) noexcept
//	:
//		_the_value( another._the_value )
//{}

//const Comparison_result &Comparison_result::operator =( const Comparison_result &another ) noexcept {
//	if ( &another == this ) return *this;

//	_the_value = another._the_value;
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace typeing
} // namespace jmsf
