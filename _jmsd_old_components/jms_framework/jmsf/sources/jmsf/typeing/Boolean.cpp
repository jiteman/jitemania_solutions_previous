#include "Boolean.h"


#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"


namespace jmsf {
namespace typeing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical
Boolean Boolean::operator !() const noexcept {
	return Boolean( !_boolean_value );
}

Boolean Boolean::operator &&( const Boolean &other ) const noexcept {
	return Boolean( _boolean_value && other._boolean_value );
}

Boolean Boolean::operator ||( const Boolean &other ) const noexcept {
	return Boolean( _boolean_value || other._boolean_value );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical synonyms
Boolean Boolean::inversion() const noexcept {
	return operator !();
}

Boolean Boolean::equal( const Boolean other ) const noexcept {
	return operator ==( other );
}

Boolean Boolean::notEqual( const Boolean other ) const noexcept {
	return operator !=( other );
}

Boolean Boolean::conjunction( const Boolean other ) const noexcept {
	return operator &&( other );
}

Boolean Boolean::disjunction( const Boolean other ) const noexcept {
	return operator ||( other );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
Boolean Boolean::operator ==( const Boolean &other ) const noexcept {
	return Boolean( _boolean_value == other._boolean_value );
}

Boolean Boolean::operator !=( const Boolean &other ) const noexcept {
	return operator ==( other ).inversion();
}

Boolean Boolean::operator <( const Boolean &other ) const noexcept {
	return Boolean( _boolean_value < other._boolean_value );
}

Boolean Boolean::operator <=( const Boolean &other ) const noexcept {
	return Boolean( _boolean_value <= other._boolean_value );
}

Boolean Boolean::operator >( const Boolean &other ) const noexcept {
	return Boolean( _boolean_value > other._boolean_value );
}

Boolean Boolean::operator >=( const Boolean &other ) const noexcept {
	return Boolean( _boolean_value >= other._boolean_value );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// new/delete
//	void *operator new( Unsigned sizeToAllocate ) throw( validating::Exception );
//	void *operator new[]( Unsigned quantityToAllocate ) throw( validating::Exception );
//	void operator delete( void *memoryToDeallocate );
//	void operator delete[]( void *memoryToDeallocate );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean::operator internals::platform_boolean() const noexcept {
	return _boolean_value;
}

internals::platform_boolean Boolean::get_native_value() const noexcept {
	return _boolean_value;
}

const pointing::cShared< texting::Ansii_text > Boolean::to_ansii_text(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const
{
	pointing::Shared< texting::Ansii_stream > ansii_stream = an_aaa->create_ansii_stream();
	ansii_stream->put( *this );
	return texting::Aaa_cs( an_aaa, ansii_stream );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Boolean::~Boolean() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean::Boolean() noexcept {
	_boolean_value = internals::platform_boolean( 0 );
}

// static
Boolean Boolean::create( const internals::platform_boolean boolean_value /*= default*/ ) {
	return Boolean( boolean_value );
}


Boolean::Boolean( const internals::platform_boolean boolean_value ) noexcept
	:
		_boolean_value( boolean_value )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean::Boolean( const Boolean &other ) noexcept {
	_boolean_value = other._boolean_value;
}

const Boolean &Boolean::operator =( const Boolean &other ) noexcept {
	if ( &other != this ) {
		_boolean_value = other._boolean_value;
	}

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// extern
const Boolean True = Boolean::create( true );

// extern
const Boolean False = Boolean::create( false );


} // namespace typeing
} // namespace jmsf
