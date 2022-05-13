#include "Ansii_stream.hin"


#include "jmsf/texting/String_literal.h"
#include "jmsf/structing/containing/List.hin"

//#include "jmsf/pointing/Constant_pointer.hin"
//#include "jmsf/pointing/Pointer.hin"
#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Allocator.h"
#include "jmsf/typeing/Naturals.hin"
#include "jmsf/typeing/Aso.hin"
#include "Ansii_text.h"

#include "jmsf/validating/macroses_Should.h"

#include <cstdio>


namespace jmsf {
namespace texting {


void Ansii_stream::put( const pointing::cShared< Ansii_text > &ansii_text ) {
	if ( ansii_text.is_empty() ) return;

	_ansii_text_list.append_to_end( _list_node_allocator, ansii_text );
}

void Ansii_stream::put( const typeing::Boolean a_boolean ) {
	this->put( create_boolean( a_boolean ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::cShared< Ansii_text > Ansii_stream::create_consolidated_ansii_text(
	const memorying::Womp< memorying::Allocator > &ansii_text_reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
	const memorying::Womp< memorying::Allocator > &character_array_allocator ) const
{
	return
		Ansii_text::create_from_list(
			ansii_text_reference_counters_allocator,
			ansii_text_allocator,
			character_array_allocator,
			_ansii_text_list );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Ansii_stream::~Ansii_stream() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_stream::Ansii_stream(
	const memorying::Womp< memorying::Allocator > &ansii_text_reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
	const memorying::Womp< memorying::Allocator > &character_array_allocator,
	const memorying::Womp< memorying::Allocator > &list_node_allocator) noexcept
	:
		_reference_counters_allocator( ansii_text_reference_counters_allocator ),
		_ansii_text_allocator( ansii_text_allocator ),
		_character_array_allocator( character_array_allocator ),
		_list_node_allocator( list_node_allocator )
{}

// static
pointing::Shared< Ansii_stream > Ansii_stream::create(
	const memorying::Womp< memorying::Allocator > &ansii_stream_reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &ansii_stream_allocator,
	const memorying::Womp< memorying::Allocator > &ansii_text_reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
	const memorying::Womp< memorying::Allocator > &character_array_allocator,
	const memorying::Womp< memorying::Allocator > &list_node_allocator  )
{
	jmsf_Should_never_be_empty( ansii_stream_reference_counters_allocator );
	jmsf_Should_never_be_empty( ansii_stream_allocator );
	jmsf_Should_never_be_empty( ansii_text_reference_counters_allocator );
	jmsf_Should_never_be_empty( ansii_text_allocator );
	jmsf_Should_never_be_empty( character_array_allocator );
	jmsf_Should_never_be_empty( list_node_allocator );

	return
		pointing::Shared< Ansii_stream >::create(
			ansii_stream_reference_counters_allocator,
			memorying::Constructor< Ansii_stream, Ansii_stream >::construct(
				ansii_stream_allocator,
				ansii_text_reference_counters_allocator,
				ansii_text_allocator,
				character_array_allocator,
				list_node_allocator ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_stream::Ansii_stream( const Ansii_stream &another ) noexcept
	:
		_reference_counters_allocator( another._reference_counters_allocator ),
		_ansii_text_allocator( another._ansii_text_allocator ),
		_character_array_allocator( another._character_array_allocator ),
		_list_node_allocator( another._list_node_allocator )
{}

const Ansii_stream &Ansii_stream::operator =( const Ansii_stream &another ) noexcept {
	if ( &another == this ) return *this;

	_reference_counters_allocator = another._reference_counters_allocator;
	_ansii_text_allocator = another._ansii_text_allocator;
	_character_array_allocator = another._character_array_allocator;
	_list_node_allocator = another._list_node_allocator;
	return *this;
}

Ansii_stream::Ansii_stream( Ansii_stream &&another ) noexcept
	:
		_reference_counters_allocator( another._reference_counters_allocator ),
		_ansii_text_allocator( another._ansii_text_allocator ),
		_character_array_allocator( another._character_array_allocator ),
		_list_node_allocator( another._list_node_allocator )
{
	another._reference_counters_allocator = memorying::Womp< memorying::Allocator >();
	another._ansii_text_allocator = memorying::Womp< memorying::Allocator >();
	another._character_array_allocator = memorying::Womp< memorying::Allocator >();
	another._list_node_allocator = memorying::Womp< memorying::Allocator >();
}

Ansii_stream &Ansii_stream::operator =( Ansii_stream &&another ) noexcept {
	if ( &another == this ) return *this;

	_reference_counters_allocator = another._reference_counters_allocator;
	_ansii_text_allocator = another._ansii_text_allocator;
	_character_array_allocator = another._character_array_allocator;
	_list_node_allocator = another._list_node_allocator;
	another._reference_counters_allocator = memorying::Womp< memorying::Allocator >();
	another._ansii_text_allocator = memorying::Womp< memorying::Allocator >();
	another._character_array_allocator = memorying::Womp< memorying::Allocator >();
	another._list_node_allocator = memorying::Womp< memorying::Allocator >();
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::cShared< Ansii_text > Ansii_stream::create_boolean( const typeing::Boolean a_boolean ) {
	return
		Ansii_text::create_from_string_literal(
			_reference_counters_allocator,
			_ansii_text_allocator,
			_character_array_allocator,
			a_boolean ? JMSF_SL( "True" ) : JMSF_SL( "False" ) );
}

const pointing::cShared< Ansii_text > Ansii_stream::create_natural_1(
	const typeing::shortest_fast_natural_value_type shortest_natural,
	const typeing::Boolean as_hexadecimal )
{
	if ( typeing::size_of( shortest_natural ) <= typeing::size_of< typeing::internals::platform_fast_natural >() ) {
		return create_natural_4( static_cast< typeing::internals::platform_fast_natural >( shortest_natural ), as_hexadecimal );
	} else if ( typeing::size_of( shortest_natural ) == typeing::size_of< typeing::internals::platform_long_fast_natural >()  ) {
		return create_natural_8( static_cast< typeing::internals::platform_long_fast_natural >( shortest_natural ), as_hexadecimal );
	} else {
		// throw exception
		return pointing::cShared< Ansii_text >();
	}
}

const pointing::cShared< Ansii_text > Ansii_stream::create_natural_2(
	const typeing::short_fast_natural_value_type short_natural,
	const typeing::Boolean as_hexadecimal )
{
	if ( typeing::size_of( short_natural ) <= typeing::size_of< typeing::internals::platform_fast_natural >() ) {
		return create_natural_4( static_cast< typeing::internals::platform_fast_natural >( short_natural ), as_hexadecimal );
	} else if ( typeing::size_of( short_natural ) == typeing::size_of< typeing::internals::platform_long_fast_natural >() ) {
		return create_natural_8( static_cast< typeing::internals::platform_long_fast_natural >( short_natural ), as_hexadecimal );
	} else {
		// throw exception
		return pointing::cShared< Ansii_text >();
	}
}

const pointing::cShared< Ansii_text > Ansii_stream::create_natural_4(
	const typeing::fast_natural_value_type natural,
	const typeing::Boolean as_hexadecimal )
{
	char *output_buffer = new char[ BUFFER_SIZE.get_native_value() ];

#if defined( JMSD_MEMORY_MODEL_IS_LP64 )
	if ( as_hexadecimal ) {
		::sprintf( output_buffer, "%lX", natural );
	} else {
		::sprintf( output_buffer, "%lu", natural );
	}

#elif defined( JMSD_MEMORY_MODEL_IS_ILP32 ) || defined( JMSD_MEMORY_MODEL_IS_LLP64 )
	if ( as_hexadecimal ) {
		::sprintf( output_buffer, "%X", natural );
	} else {
		::sprintf( output_buffer, "%u", natural );
	}

#else
	#error This file "jmsf/texting/Ansii_stream.cpp" - no supported memory model detected.

#endif

	const pointing::cShared< Ansii_text > textual_number =
		Ansii_text::create_from_string_literal(
			_reference_counters_allocator,
			_ansii_text_allocator,
			_character_array_allocator,
			JMSF_SL( output_buffer ) );

	delete[] output_buffer;
	return textual_number;
}

const pointing::cShared< Ansii_text > Ansii_stream::create_natural_8(
	const typeing::long_fast_natural_value_type long_natural,
	const typeing::Boolean as_hexadecimal )
{
	char *output_buffer = new char[ BUFFER_SIZE.get_native_value() ];

#if defined( JMSD_MEMORY_MODEL_IS_LP64 )
	if ( as_hexadecimal ) {
		::sprintf( output_buffer, "%lX", long_natural );
	} else {
		::sprintf( output_buffer, "%lu", long_natural );
	}

#elif defined( JMSD_MEMORY_MODEL_IS_ILP32 ) || defined( JMSD_MEMORY_MODEL_IS_LLP64 )
	if ( as_hexadecimal ) {
		::sprintf( output_buffer, "%llX", long_natural );
	} else {
		::sprintf( output_buffer, "%llu", long_natural );
	}

#else
	#error This file "jmsf/texting/Ansii_stream.cpp" - no supported memory model detected.

#endif

	const pointing::cShared< Ansii_text > textual_number =
		Ansii_text::create_from_string_literal(
			_reference_counters_allocator,
			_ansii_text_allocator,
			_character_array_allocator,
			JMSF_SL( output_buffer ) );

	delete[] output_buffer;
	return textual_number;
}

const pointing::cShared< Ansii_text > Ansii_stream::create_integer_1( const typeing::shortest_fast_integer_value_type shortest_integer ) {
	if ( typeing::size_of( shortest_integer ) <= typeing::size_of< typeing::internals::platform_fast_integer >() ) {
		return create_integer_4( static_cast< typeing::internals::platform_fast_integer >( shortest_integer ) );
	} else if ( typeing::size_of( shortest_integer ) == typeing::size_of< typeing::internals::platform_long_fast_natural >()  ) {
		return create_integer_8( static_cast< typeing::internals::platform_long_fast_integer >( shortest_integer ) );
	} else {
		// throw exception
		return pointing::cShared< Ansii_text >();
	}
}

const pointing::cShared< Ansii_text > Ansii_stream::create_integer_2( const typeing::short_fast_integer_value_type short_integer ) {
	if ( typeing::size_of( short_integer ) <= typeing::size_of< typeing::internals::platform_fast_integer >() ) {
		return create_integer_4( static_cast< typeing::internals::platform_fast_integer >( short_integer ) );
	} else if ( typeing::size_of( short_integer ) == typeing::size_of< typeing::internals::platform_long_fast_natural >()  ) {
		return create_integer_8( static_cast< typeing::internals::platform_long_fast_integer >( short_integer ) );
	} else {
		// throw exception
		return pointing::cShared< Ansii_text >();
	}
}

const pointing::cShared< Ansii_text > Ansii_stream::create_integer_4( const typeing::fast_integer_value_type integer ) {
	char *output_buffer = new char[ BUFFER_SIZE.get_native_value() ];

#if defined( JMSD_MEMORY_MODEL_IS_LP64 )
	::sprintf( output_buffer, "%ld", integer );

#elif defined( JMSD_MEMORY_MODEL_IS_ILP32 ) || defined( JMSD_MEMORY_MODEL_IS_LLP64 )
	::sprintf( output_buffer, "%d", integer );

#else
	#error This file "jmsf/typeing/Ansii_stream.cpp" - no supported memory model detected.

#endif

	const pointing::cShared< Ansii_text > textual_number =
		Ansii_text::create_from_string_literal(
			_reference_counters_allocator,
			_ansii_text_allocator,
			_character_array_allocator,
			JMSF_SL( output_buffer ) );

	delete[] output_buffer;
	return textual_number;
}

const pointing::cShared< Ansii_text > Ansii_stream::create_integer_8( const typeing::long_fast_integer_value_type long_integer ) {
	char *output_buffer = new char[ BUFFER_SIZE.get_native_value() ];

#if defined( JMSD_MEMORY_MODEL_IS_LP64 )
	::sprintf( output_buffer, "%ld", long_integer );

#elif defined( JMSD_MEMORY_MODEL_IS_ILP32 ) || defined( JMSD_MEMORY_MODEL_IS_LLP64 )
	::sprintf( output_buffer, "%lld", long_integer );

#else
	#error This file "jmsf/typeing/Ansii_stream.cpp" - no supported memory model detected.

#endif

	const pointing::cShared< Ansii_text > textual_number =
		Ansii_text::create_from_string_literal(
			_reference_counters_allocator,
			_ansii_text_allocator,
			_character_array_allocator,
			JMSF_SL( output_buffer ) );

	delete[] output_buffer;
	return textual_number;
}

const pointing::cShared< Ansii_text > Ansii_stream::create_real_4( const typeing::short_real_value_type short_real ) {
	return create_real_8( static_cast< typeing::internals::platform_real >( short_real ) );
}

const pointing::cShared< Ansii_text > Ansii_stream::create_real_8( const typeing::real_value_type real ) {
	char *output_buffer = new char[ BUFFER_SIZE.get_native_value() ];
	::sprintf( output_buffer, "%G", real );

	const pointing::cShared< Ansii_text > textual_number =
		Ansii_text::create_from_string_literal(
			_reference_counters_allocator,
			_ansii_text_allocator,
			_character_array_allocator,
			JMSF_SL( output_buffer ) );

	delete[] output_buffer;
	return textual_number;
}

const pointing::cShared< Ansii_text > Ansii_stream::create_real_12( const typeing::long_real_value_type long_real ) {
	char *output_buffer = new char[ BUFFER_SIZE.get_native_value() ];
	::sprintf( output_buffer, "%LG", long_real );

	const pointing::cShared< Ansii_text > textual_number =
		Ansii_text::create_from_string_literal(
			_reference_counters_allocator,
			_ansii_text_allocator,
			_character_array_allocator,
			JMSF_SL( output_buffer ) );

	delete[] output_buffer;
	return textual_number;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
const typeing::Memory_natural Ansii_stream::BUFFER_SIZE = typeing::Memory_natural::create( 64 );

} // namespace texting
} // namespace jmsf


#include "jmsf/typeing/Integers.hin"
#include "jmsf/typeing/Reals.hin"


namespace jmsf {
namespace texting {


void put_text_to_stream_from_native(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	const typeing::Boolean::my_boolean_integral_type a_boolean_value )
{
	put_text_to_stream_from_native_boolean( an_out_ansii_stream, a_boolean_value );
}

void put_text_to_stream_from_native(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	const typeing::Memory_integer::my_integer_integral_type a_integer_value )
{
	put_text_to_stream_from_native_integer( an_out_ansii_stream, a_integer_value );
}

void put_text_to_stream_from_native(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	const typeing::Memory_natural::my_natural_integral_type a_natural_value )
{
	put_text_to_stream_from_native_natural( an_out_ansii_stream, a_natural_value );
}

void put_text_to_stream_from_native(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	const typeing::Long_real::my_real_integral_type a_real_value )
{
	put_text_to_stream_from_native_real( an_out_ansii_stream, a_real_value );
}


void put_text_to_stream_from_native_boolean(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	const typeing::Boolean::my_boolean_integral_type a_boolean_value )
{
	jmsf_Should_never_be_empty( an_out_ansii_stream );
	an_out_ansii_stream->put( typeing::Boolean::create( a_boolean_value ) );
}

void put_text_to_stream_from_native_integer(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	const typeing::Memory_integer::my_integer_integral_type a_integer_value )
{
	jmsf_Should_never_be_empty( an_out_ansii_stream );
	an_out_ansii_stream->put( typeing::Memory_integer::create( a_integer_value ) );
}

void put_text_to_stream_from_native_natural(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	const typeing::Memory_natural::my_natural_integral_type a_natural_value )
{
	jmsf_Should_never_be_empty( an_out_ansii_stream );
	an_out_ansii_stream->put( typeing::Memory_natural::create( a_natural_value ) );
}


void put_text_to_stream_from_native_real(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	const typeing::Long_real::my_real_integral_type a_real_value )
{
	jmsf_Should_never_be_empty( an_out_ansii_stream );
	an_out_ansii_stream->put( typeing::Long_real::create( a_real_value ) );
}


} // namespace texting
} // namespace jmsf

