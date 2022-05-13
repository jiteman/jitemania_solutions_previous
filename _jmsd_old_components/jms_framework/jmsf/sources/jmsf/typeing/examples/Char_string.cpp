#include "Char_string.h"


#include "../Naturals.hin"
#include "../Integers.hin"
#include "../Bitwise.hin"

#include "jmsf/validating/Should.h"
#include "jmsf/validating/File_and_line.h"

#include <cstdio>
#include <cstring>


namespace jmsf {
namespace typeing {
namespace examples {


Char_string::Char_string() {
	init( Memory_natural::create( 20 ), Memory_natural::create( 10 ) );
}

Char_string::Char_string( const Memory_natural buffer_size, const Memory_natural buffer_size_granularity ) {
	init( buffer_size, buffer_size_granularity );
}

Char_string::Char_string( const char *const c_string ) {
	if ( c_string == nullptr ) {
		init( Memory_natural::create( 20 ), Memory_natural::create( 10 ) );
	} else {
		init( Memory_natural::create( ::strlen( c_string ) ), Memory_natural::create( 10 ) );
		copy( c_string );
	}
}

Char_string::Char_string( const Char_string &another ) {
	init( another._quantity_of_characters, another._buffer_size_granularity );
	copy( another._character_buffer );
}

// void Char_string::delete_pt( const Char_string *const pts ) {
// 	delete[] pts;
// }

//-------------------------------------------------------------------------

Char_string::~Char_string()  {
//	if (_character_buffer)
	delete[] _character_buffer; /*RA XTSce33189*/
}

//-------------------------------------------------------------------------

// Char_string::Char_string( const char *const filename, const char *const file_open_mode ) {
// 	if ( filename == nullptr || file_open_mode == nullptr ) {
// 		init( Memory_natural::create( 20 ), Memory_natural::create( 10 ) );
// 		return;
// 	}
//
// //	_operation_result_flags = 0;
//
// //	FILE* file_descriptor = fopen(filename, "rb");
// 	FILE *file_descriptor = fopen( filename, file_open_mode );
//
// 	if ( file_descriptor != nullptr ) {
// 		::fseek( file_descriptor, 0, 2 ); // eof
// 		const Integer readed_file_size = Integer::create( ::ftell( file_descriptor ) );
// 		const Memory_natural file_size = readed_file_size.is_negative() ? Memory_natural() : Memory_natural::create( static_cast< Memory_natural_value_type >( readed_file_size.get_value() ) );
//
// 		if ( file_size.is_not_nill() ) {
// 			::rewind( file_descriptor );
// 			init( file_size + Memory_natural_one, Memory_natural::create( 80 ) );
// 			const Memory_natural readed_size = Memory_natural::create( ::fread( _character_buffer, 1, file_size.get_value(), file_descriptor ) );
//
// 			if ( readed_size.is_nill() || readed_size > file_size ) {
// 				_operation_result_flags.set( _read_file_bit_constant ); // |= read_file;
// 				_character_buffer[ 0 ] = '\0';
// 			} else {
// 				_character_buffer[ readed_size.get_value() ] = '\0';
// 			}
//
// 			_quantity_of_characters = readed_size + Memory_natural_one; //strlen(_character_buffer); //XTSce85068
// 		} else {
// 			init( Memory_natural::create( 20 ), Memory_natural::create( 20 ) );
// 		}
//
// 		fclose(file_descriptor);
// 		file_descriptor = 0;
// 	} else {
// 		init( Memory_natural_nill, Memory_natural::create( 80 ) );
// 		_operation_result_flags.set( _open_file_bit_constant ); // |= open_file;
// 	}
// }

//-------------------------------------------------------------------------

void Char_string::dump() {
	::printf(
		"Char_string: _character_buffer_size %d, _buffer_size_granularity %d, len %d \n",
		static_cast< int >( _character_buffer_size.get_native_value() ),
		static_cast< int >( _buffer_size_granularity.get_native_value() ),
		static_cast< int >( _quantity_of_characters.get_native_value() ) );
}

//-------------------------------------------------------------------------

void Char_string::init( const Memory_natural buffer_size, const Memory_natural buffer_size_increment ) {
//	_quantity_of_characters = 0;
	_character_buffer_size = buffer_size + Memory_natural_one;
	_buffer_size_granularity = buffer_size_increment > Memory_natural::create( 7 ) ? _buffer_size_granularity = buffer_size_increment : Memory_natural::create( 20 );
	_character_buffer = new char[ _character_buffer_size.get_native_value() ];
	_character_buffer[ 0 ] = '\0';
//	_operation_result_flags = 0;
}

void Char_string::copy( const char *const c_string ) {
	if ( c_string == nullptr ) return;

	_quantity_of_characters = Memory_natural::create( ::strlen( c_string ) );
	jmsf_Should_always_be( _quantity_of_characters < _character_buffer_size );

	::strncpy( _character_buffer, c_string, _quantity_of_characters.get_native_value() );
	_character_buffer[ _quantity_of_characters.get_native_value() ] = '\0';
	_operation_result_flags.clear();
}

Char_string::operator const char *()  {
	if ( !_character_buffer ) {
		init( Memory_natural::create( 8 ), Memory_natural::create( 8 ) );
	}

	return _character_buffer;
}

Boolean Char_string::operator ==( const Char_string &s ) {
	return Boolean::create( ::strcmp( _character_buffer, s._character_buffer ) == 0 );
}

Boolean Char_string::operator ==( const char *const s ) {
	if ( s == nullptr ) return False;

	return Boolean::create( ::strcmp( _character_buffer, s ) == 0 );
}

Boolean Char_string::operator !=( const Char_string &s ) {
	return Boolean::create( ::strcmp( _character_buffer, s._character_buffer ) != 0 );
}

Boolean Char_string::operator !=( const char *const s ) {
	return !operator ==( s );
}

Boolean Char_string::operator >( const Char_string &s ) {
	return Boolean::create( ::strcmp( _character_buffer, s._character_buffer ) > 0 );
}

Boolean Char_string::operator >( const char *const s ) {
	if ( s == nullptr ) return False;

	return Boolean::create( ::strcmp( _character_buffer, s ) > 0 );
}

Boolean Char_string::operator <( const Char_string &s ) {
	return Boolean::create( ::strcmp( _character_buffer, s._character_buffer ) < 0 );
}

Boolean Char_string::operator <( const char *const s ) {
	if ( s == nullptr ) return False;

	return Boolean::create( ::strcmp( _character_buffer, s ) < 0 );
}

Boolean Char_string::operator >=( const Char_string &s ) {
	return Boolean::create( ::strcmp( _character_buffer, s._character_buffer ) >= 0 );
}

Boolean Char_string::operator >=( const char *const s ) {
	if ( s == nullptr ) return False;

	return Boolean::create( ::strcmp( _character_buffer, s ) >= 0 );
}

Boolean Char_string::operator <=( const Char_string &s ) {
	return Boolean::create( ::strcmp( _character_buffer, s._character_buffer ) <= 0 );
}

Boolean Char_string::operator <=( const char *const s ) {
	if ( s == nullptr ) return False;

	return Boolean::create( ::strcmp( _character_buffer, s ) <= 0 );
}

void Char_string::grow( const Memory_natural new_size ) {
	if ( _character_buffer && new_size <= _character_buffer_size ) return;

	char *pt = new char[ new_size.get_native_value() ];

	if ( _character_buffer != nullptr ) {
		::strcpy( pt, _character_buffer );
		delete[] _character_buffer;	/*RA XTSce33189*/
	} else {
		_buffer_size_granularity = Memory_natural::create( 80 );
		pt[ 0 ] = '\0';
	}
	_character_buffer = pt;
	_character_buffer_size = new_size;
}

void Char_string::operator =( const Char_string &another ) {
	if ( another._quantity_of_characters + Memory_natural_one > _character_buffer_size ) {
		delete[] _character_buffer;
		init( another._quantity_of_characters + Memory_natural::create( 10 ), _buffer_size_granularity );
	}

	copy( another._character_buffer );
}

void Char_string::operator =( const char *const c_string ) {
	if ( c_string == nullptr ) return;

	const Memory_natural c_string_length = Memory_natural::create( ::strlen( c_string ) );

	if ( c_string_length + Memory_natural_one > _character_buffer_size) {
		delete[] _character_buffer;
		init( c_string_length + Memory_natural::create( 10 ), _buffer_size_granularity );
	}

	copy( c_string );
}

void Char_string::operator =( const char a_character ) {
	if ( !_character_buffer ) {
		init( Memory_natural::create( 8 ), Memory_natural::create( 8 ) );
	}

	_character_buffer[ 0 ] = a_character;
	_character_buffer[ 1 ] = '\0';
	_quantity_of_characters = Memory_natural_one;
	_operation_result_flags.clear();
}

void Char_string::operator +=( const char a_character ) {
	if ( _quantity_of_characters + Memory_natural::create( 2 ) > _character_buffer_size ) {
		grow( _quantity_of_characters + _buffer_size_granularity );
	}

	_character_buffer[ _quantity_of_characters.get_native_value() ] = a_character;
	_character_buffer[ ( ++_quantity_of_characters ).get_native_value() ] = '\0';
}

void Char_string::operator +=( const Char_string &another ) {
	if ( _quantity_of_characters + another._quantity_of_characters + Memory_natural::create( 2 ) > _character_buffer_size ) {
		grow( another._quantity_of_characters + _quantity_of_characters + _buffer_size_granularity );
	}

	_quantity_of_characters += another._quantity_of_characters;
	jmsf_Should_never_be_empty_native_pointer( _character_buffer );
	jmsf_Should_never_be_empty_native_pointer( another._character_buffer );
	::strcat( _character_buffer, another._character_buffer );
}

void Char_string::operator +=( const char *c_string ) {
	if ( c_string == nullptr ) return;

	const Memory_natural c_string_length = Memory_natural::create( ::strlen( c_string ) );

	if ( _quantity_of_characters + c_string_length + Memory_natural::create( 2 ) > _character_buffer_size ) {
		grow( _quantity_of_characters + c_string_length + _buffer_size_granularity );
	}

	_quantity_of_characters += c_string_length;
	jmsf_Should_never_be_empty_native_pointer( _character_buffer );
	::strcat( _character_buffer, c_string );
}

void Char_string::upcase() {
	jmsf_Should_never_be_empty_native_pointer( _character_buffer );
	char *pointer_to_character = &_character_buffer[ 0 ];

	for ( Memory_natural counter = _quantity_of_characters; counter.is_not_nil(); --counter ) {
		char &reference_to_character = *pointer_to_character++;

		if ( reference_to_character >= 'a' && reference_to_character <= 'z' ) {
			reference_to_character = static_cast< char >( reference_to_character - ( 'a' - 'A' ) );
		}
	}
}

void Char_string::downcase() {
	jmsf_Should_never_be_empty_native_pointer( _character_buffer );
	char *pointer_to_character = &_character_buffer[ 0 ];

	for ( Memory_natural counter = _quantity_of_characters; counter.is_not_nil(); --counter ) {
		char &reference_to_character = *pointer_to_character++;

		if ( reference_to_character >= 'A' && reference_to_character <= 'Z' ) {
			reference_to_character = static_cast< char >( reference_to_character + ( 'a' - 'A' ) );
		}
	}
}

void Char_string::remove_blanks() {
	jmsf_Should_never_be_empty_native_pointer( _character_buffer );
	char *destination_pointer_to_character = &_character_buffer[ 0 ];
	const char *source_pointer_to_character = destination_pointer_to_character;

	for ( Memory_natural counter = _quantity_of_characters; counter.is_not_nil(); --counter ) {
		const char &source_reference_to_character = *source_pointer_to_character++;

		if ( source_reference_to_character != ' ' && source_reference_to_character != '\t' ) {
			*destination_pointer_to_character++ = source_reference_to_character;
		}
	}

	*destination_pointer_to_character = '\0';
	_quantity_of_characters = Memory_natural::create( static_cast< memory_natural_value_type >( destination_pointer_to_character - source_pointer_to_character ) );
}


Memory_natural Char_string::index( const char a_character, const Memory_natural start_position ) {
	if ( start_position >= _quantity_of_characters ) return Memory_natural_max;

	const char *const p = ::strchr( _character_buffer + start_position.get_native_value(), a_character );

	if ( p == nullptr ) return Memory_natural_max;

	return Memory_natural::create( static_cast< memory_natural_value_type >( p - _character_buffer ) );
}


Memory_natural Char_string::index( const char *const c_string, const Memory_natural start_position ) {
	if ( c_string == nullptr ) return Memory_natural_max;

	if ( start_position >= _quantity_of_characters ) return Memory_natural_max;

	const char *const p = ::strstr( _character_buffer + start_position.get_native_value(), c_string );

	if ( p == nullptr ) return Memory_natural_max;

	return Memory_natural::create( static_cast< memory_natural_value_type >( p - _character_buffer ) );
}

Memory_natural Char_string::index( const Char_string &a_string, const Memory_natural start_position ) {
	return index( a_string._character_buffer, start_position );
}

Boolean Char_string::contains( const char *const c_string ) {
	return Boolean::create( index( c_string ).is_not_max() );
}

Boolean Char_string::contains( const Char_string &a_string ) {
	return Boolean::create( index( a_string._character_buffer ).is_not_max() );
}

Char_string Char_string::from( const Memory_natural start_position ) {
	if ( start_position >= _quantity_of_characters ) return Char_string();

	return Char_string( &_character_buffer[ start_position.get_native_value() ] );
}

Char_string Char_string::before( const Memory_natural after_the_end_position ) {
	const Memory_natural position_to_get_from = after_the_end_position < _quantity_of_characters ? after_the_end_position : _quantity_of_characters;

	Char_string result_string = _character_buffer;

	result_string._quantity_of_characters = position_to_get_from;
	result_string._character_buffer[ position_to_get_from.get_native_value() ] = '\0';
	return result_string;
}

Char_string Char_string::fromAndBefore( const Memory_natural start_position, const Memory_natural after_the_end_position ) {
	const Memory_natural position_to_get_from = start_position < _quantity_of_characters ? start_position : Memory_natural_nil;
	const Memory_natural position_to_get_before = after_the_end_position < _quantity_of_characters ? after_the_end_position : _quantity_of_characters;

	if ( position_to_get_from >= position_to_get_before ) return Char_string();

	Char_string result_string = &_character_buffer[ position_to_get_from.get_native_value() ];
	result_string._quantity_of_characters = position_to_get_before - position_to_get_from;
	result_string._character_buffer[ result_string._quantity_of_characters.get_native_value() ] = '\0';
	return result_string;
}

Char_string Char_string::from( const char c ) {
	return from( index( c ) );
}

Char_string Char_string::before( const char c ) {
	return before( index( c ) );
}

Char_string Char_string::until( char c ) {
	return before( ++index( c ) );
}

// Jiteman: rewrite it
void Char_string::del( const Memory_natural posdeb, const Memory_natural quantity_to_delete ) {
	if ( posdeb >= _quantity_of_characters || posdeb + quantity_to_delete > _quantity_of_characters ) return;

	char *pdeb = _character_buffer + posdeb.get_native_value();
	char *pfin = pdeb + quantity_to_delete.get_native_value();
	pdeb[ 0 ] = '\0';
	const Memory_natural lg2 = Memory_natural::create( ::strlen( pfin ) );

	for ( Memory_natural counter; counter < lg2; ++counter ) {
		pdeb[ counter.get_native_value() ] = pfin[ counter.get_native_value() ];
	}

	pdeb[ lg2.get_native_value() ] = '\0';
	_quantity_of_characters = Memory_natural::create( ::strlen( _character_buffer ) );
}


void Char_string::gsub( const char *const c_string_replacable, const char *const c_string_to_replacement ) {
	if ( c_string_replacable == nullptr || c_string_to_replacement == nullptr ) return;

	const Memory_natural length_of_replacable = Memory_natural::create( ::strlen( c_string_replacable ) );
	const Memory_natural length_of_replacement = Memory_natural::create( ::strlen( c_string_to_replacement ) );

	Memory_natural occurence_quantity;
	{
		const char *pointer_to_c_string_to_replace_in = _character_buffer;

		while ( pointer_to_c_string_to_replace_in < _character_buffer + _quantity_of_characters.get_native_value() ) {
			pointer_to_c_string_to_replace_in = ::strstr( _character_buffer, c_string_replacable );

			if ( pointer_to_c_string_to_replace_in == nullptr ) {
				break;
			} else {
				pointer_to_c_string_to_replace_in += length_of_replacable.get_native_value();
				++occurence_quantity;
			}
		}
	}

	if ( occurence_quantity.is_nil() ) return;

	const Memory_natural quantity_of_characters_in_result_string = _quantity_of_characters + ( length_of_replacement - length_of_replacable ) * occurence_quantity;
	char *new_character_buffer = new char[ ( quantity_of_characters_in_result_string + Memory_natural_one ).get_native_value() ];

	{
		char *destination_pointer = new_character_buffer;
		const char *source_pointer = _character_buffer;

		for ( Memory_natural occurence_counter = occurence_quantity; occurence_counter.is_not_nil(); --occurence_counter ) {
			const char *occurence = ::strstr( source_pointer, c_string_replacable );

			while ( source_pointer != occurence ) {
				*destination_pointer++ = *source_pointer++;
			}

			const char *replacement_c_string = c_string_to_replacement;

			for ( Memory_natural replacement_character_counter = length_of_replacement; replacement_character_counter.is_not_nil(); ++replacement_character_counter ) {
				*destination_pointer++ = *replacement_c_string++;
			}

			source_pointer += length_of_replacable.get_native_value();
		}
	}

	delete _character_buffer;
	_character_buffer = new_character_buffer;
	_quantity_of_characters = quantity_of_characters_in_result_string;
}

const char *Char_string::chars() {
	return _character_buffer;
}

Bitwise< Memory_natural > Char_string::flags() {
	return _operation_result_flags;
}

void Char_string::reset_flags() {
	_operation_result_flags.clear();
}

//-----------------------------------------------------------------------
Char_string &Char_string::operator <<( const Char_string &another ) {
	operator +=( another );
	return *this;
}

Char_string &Char_string::operator <<( const char *const c_string ) {
	if ( c_string == nullptr ) return *this;
	if ( Memory_natural::create( ::strlen( c_string ) ).is_nil() ) return *this;

	operator +=( c_string );
	return *this;
}

Char_string&  Char_string::operator <<( const char a_character ) {
	operator +=( a_character );
	return *this;
}

Char_string &Char_string::operator <<( const unsigned char a_character) {
	operator +=( static_cast< char >( a_character ) );
	return *this;
}

Char_string &Char_string::operator <<( const int integer_number ) {
	char character_buffer[ 20 ];
	::sprintf( character_buffer, "%d", integer_number );
	operator +=( character_buffer );
	return *this;
}

Char_string &Char_string::operator <<( const unsigned int natural_number ) {
	char character_buffer[ 20 ];
	::sprintf( character_buffer, "%u", natural_number );
	operator +=( character_buffer );
	return *this;
}

Char_string &Char_string::operator <<( const short short_integer_number ) {
	operator <<( static_cast< int >( short_integer_number ) );
	return *this;
}

Char_string &Char_string::operator <<( const unsigned short short_interger_number ) {
	operator <<( static_cast< unsigned int >( short_interger_number ) );
	return *this;
}

Char_string &Char_string::operator <<( const long long_integer_number ) {
	operator <<( static_cast< int >( long_integer_number ) );
	return *this;
}

Char_string &Char_string::operator <<( const unsigned long long_natural_number ) {
	operator <<( static_cast< unsigned int >( long_natural_number ) );
	return *this;
}

Char_string &Char_string::operator <<( const float floating_point_number ) {
	char character_buffer[ 40 ];
	::sprintf( character_buffer, "%f", floating_point_number );
	operator +=( character_buffer );
	return *this;
}

Char_string &Char_string::fill( const char a_character, const Memory_natural a_quantity ) {
	while ( _quantity_of_characters < a_quantity ) {
		operator +=( a_character );
	}

	return *this;
}

//-----------------------------------------------------------------------
Char_string &Char_string::operator >>( char *const output_c_string ) {
	if ( output_c_string == nullptr ) return *this;

	int charstring_n = 0;
	::sscanf( _character_buffer, "%s%n", output_c_string, &charstring_n );

	if ( charstring_n <= 0 ) {
		_operation_result_flags.set( _read_character_bit_constant );
	} else {
		del( Memory_natural_nil, Memory_natural::create( static_cast< Memory_natural::my_natural_integral_type >( charstring_n ) ) );
	}

	return *this;
}

Char_string &Char_string::operator >>( char &output_character ) {
	int charstring_n = 0;
	::sscanf( _character_buffer, "%c%n", &output_character, &charstring_n );

	if ( charstring_n <= 0 ) {
		_operation_result_flags.set( _read_character_bit_constant );
	} else {
		del( Memory_natural_nil, Memory_natural::create( static_cast< Memory_natural::my_natural_integral_type >( charstring_n ) ) );
	}

	return *this;
}

Char_string &Char_string::operator >>( int &output_integer_number ) {
	int charstring_n = 0;
	::sscanf( _character_buffer, "%d%n", &output_integer_number, &charstring_n );

	if ( charstring_n <= 0 ) {
		_operation_result_flags.set( _read_character_bit_constant );
	} else {
		del( Memory_natural_nil, Memory_natural::create( static_cast< Memory_natural::my_natural_integral_type >( charstring_n ) ) );
	}

	return *this;
}

Char_string &Char_string::operator >>( unsigned int &output_natural_number ) {
	int charstring_n = 0;
	::sscanf( _character_buffer, "%u%n", &output_natural_number, &charstring_n );

	if ( charstring_n <= 0 ) {
		_operation_result_flags.set( _read_character_bit_constant );
	} else {
		del( Memory_natural_nil, Memory_natural::create( static_cast< Memory_natural::my_natural_integral_type >( charstring_n ) ) );
	}

	return *this;
}

Char_string &Char_string::operator >>( unsigned char &output_character ) {
	unsigned int integer_number;
	operator >>( integer_number );

	if ( _operation_result_flags.get_value().is_not_nil() ) return *this;

	output_character = static_cast< unsigned char >( integer_number );
	return *this;
}

Char_string &Char_string::operator >>( unsigned short &short_natural_number ) {
	unsigned int integer_number;
	operator >>( integer_number );

	if ( _operation_result_flags.get_value().is_not_nil() ) return *this;

	short_natural_number = static_cast< unsigned short >( integer_number );
	return *this;
}

Char_string &Char_string::operator >>( unsigned long &output_long_natural_number ) {
	unsigned int integer_number;
	operator >>( integer_number );

	if ( _operation_result_flags.get_value().is_not_nil() ) return *this;

	output_long_natural_number = integer_number;
	return *this;
}

Char_string &Char_string::operator >>( long &output_long_integer_number) {
	int charstring_n = 0;
	int integer_number = 0;
	::sscanf(_character_buffer, "%d%n", &integer_number, &charstring_n);
	output_long_integer_number = integer_number;

	if ( charstring_n <= 0 ) {
		_operation_result_flags.set( _read_character_bit_constant );
	} else {
		del( Memory_natural_nil, Memory_natural::create( static_cast< Memory_natural::my_natural_integral_type >( charstring_n ) ) );
	}

	return *this;
}


Char_string &Char_string::operator >>( float &output_floating_point_number ) {
	int charstring_n = 0;

	::sscanf( _character_buffer, "%f%n", &output_floating_point_number, &charstring_n );

	if ( charstring_n <= 0 ) {
		_operation_result_flags.set( _read_character_bit_constant );
	} else {
		del( Memory_natural_nil, Memory_natural::create( static_cast< Memory_natural::my_natural_integral_type >( charstring_n ) ) );
	}
	return *this;
}

Char_string &Char_string::operator >>( short &output_short_natural_number ) {
	int integer_number;
	operator >>( integer_number );

	if ( _operation_result_flags.get_value().is_not_nil() ) return *this;

	output_short_natural_number = static_cast< short >( integer_number );
	return *this;
}

Char_string &Char_string::get_line( char *output_character_buffer, const Memory_natural character_buffer_size, const char terminator ) {
	if ( output_character_buffer == nullptr ) return *this;

	if ( _quantity_of_characters.is_nil() ) {
		_operation_result_flags.set( _read_character_bit_constant );
		output_character_buffer[ 0 ] = '\0';
		return *this;
	}

	char *first_occurence_of_terminator = ::strchr( _character_buffer, terminator );

	const Memory_natural reading_string_length =
		first_occurence_of_terminator != nullptr ?
			Memory_natural::create( static_cast< Memory_natural::my_natural_integral_type >( first_occurence_of_terminator - _character_buffer ) ) :
			_quantity_of_characters;

	_character_buffer[ reading_string_length.get_native_value() ] = '\0';
	::strncpy( output_character_buffer, _character_buffer, character_buffer_size.get_native_value() );
	output_character_buffer[ character_buffer_size.get_native_value() ] = '\0';

	if ( reading_string_length == _quantity_of_characters ) {
		_character_buffer[ 0 ] = '\0';
		_quantity_of_characters = Memory_natural_nil;
	} else {
		::strncpy( _character_buffer, &_character_buffer[ ( reading_string_length + Memory_natural_one ).get_native_value() ], _character_buffer_size.get_native_value() );
	}

	return *this;
}


// Char_string &Char_string::get_sentence( char *output_character_buffer, const Memory_natural character_buffer_size, const char first_character, char second_character ) {
// 	if ( output_character_buffer == nullptr ) return *this;
//
// 	output_character_buffer[ 0 ] = '\0';
// 	int x1 = index( first_character );
// 	int x2 = index( second_character );
//
// 	if ( x1 >= 0 && x2 > x1 ) {
// 		Char_string s1 = from( x1 + 1 );
// 		x2 = s1.index( second_character );
// 		*this = s1.from( x2 + 1 );
//
// 		if ( x2 < s1.get_length() ) {
// 			s1[ x2 ] = '\0';
// 		}
//
// 		::strncpy( output_character_buffer, s1, character_buffer_size );
// 	} else {
// 		_operation_result_flags |= read_chars;
// 	}
//
// 	return *this;
// }

char Char_string::item( const Memory_natural character_index ) {
	jmsf_Should_always_be( character_index < _quantity_of_characters );
	return _character_buffer[ character_index.get_native_value() ];
}

char &Char_string::operator []( const Memory_natural character_index ) {
	jmsf_Should_always_be( character_index < _quantity_of_characters );
	return _character_buffer[ character_index.get_native_value() ];
}

Memory_natural Char_string::get_length() {
	return _quantity_of_characters;
}

Memory_natural Char_string::get_full_length() {
	return _quantity_of_characters + Memory_natural_one;
}

Boolean Char_string::empty() {
	return Boolean::create( _quantity_of_characters.is_nil() );
}

//--------------------------------------------------------------------------------
// Char_string* Char_string::split(short& nb_itemsRes, char sep) { /*MARYOCTOBRE*/
// 	int i;
// 	unsigned short nb_items = 0;/*MARYOCTOBRE*/
// 	nb_itemsRes = 0;/*MARYOCTOBRE*/
//
// 	if (_quantity_of_characters == 0)
// 		return NULL;
// 	Char_string s(*this);
// 	for (i=0; i< (int)_quantity_of_characters; i++) {
// 		if (s[i] == sep)
// 			nb_items++;
// 		if (i == (int)_quantity_of_characters-1)
// 			nb_items++;
// 	}
//
// 	if ( nb_items > 0 ) {
// 		/* JMP 251199 ++ */
// 		Char_string* pts = new Char_string[nb_items];
// 		for (i=0; i< (int)_quantity_of_characters; i++)
// 			if (_character_buffer[i] == sep)
// 				_character_buffer[i]= 0;
// 		char* pc = _character_buffer;
// 		for (i=0; i< nb_items && pc <= _character_buffer+_quantity_of_characters; i++) {
// 			pts[i] = pc;
// 			pc += strlen(pc)+1;
// 		}
// 		for (i=0; i< (int)_quantity_of_characters; i++)
// 			if (_character_buffer[i] == 0)
// 				_character_buffer[i]= sep;
// 		/* JMP 251199 -- */
// 		nb_itemsRes = nb_items; /*MARYOCTOBRE*/
// 		return pts;
// 	} else {
// 		return NULL;
// 	}
// }


//-------------------------------------------------------------------------------
//	Manipulation Functions stream or XML document in charstring
//--------------------------------------------------------------------------------


//-----------------------------------------------------
// get an XML element with empty content or attribute with or without back
//		Result:> 0: offset to research the following elt or 0 not found
//		XmlElement element = tag with start and end
//----------------------------------------------------

// int Char_string::getXMLElement(const char * xmlElementName, Char_string & xmlElement, int fromIndex) {
// 	if ( xmlElementName == NULL ) return -1;
//
// 	Char_string startOfElt, endOfElt;
// 	startOfElt = "<";
// 	endOfElt = "</";
// 	startOfElt << xmlElementName;
// 	endOfElt   << xmlElementName << ">";
//
// 	int posdeb = -1;
// 	int posfin = -1;
// 	int lengthOfEnd=0;
//
// 	posdeb = index(startOfElt, fromIndex);	// posdeb = '<' the beginning tag
//
// 	if (posdeb >= 0) {
// 		posdeb += startOfElt.get_length();
// 		posfin = index('>', posdeb);	// Search end elt empty
// 		if ((posfin <= 0) || ((*this)[posfin-1] != '/'))	// posfin = '>' end tag of the
// 			posfin = -1;
//
// 		if (posfin == -1) {	// otherwise end tag search
// 			posfin = index(endOfElt, posdeb);		// posfin = '<' end tag of the
// 			lengthOfEnd = strlen(endOfElt);
// 		}
// 		else
// 			lengthOfEnd = 1;
// 	}
//
// 	if (posfin > 0) {
// 		posfin+= lengthOfEnd;
// 		xmlElement = fromAndBefore(posdeb, posfin);
// 		return posfin;
// 	}
// 	return 0;
// }
//
// //-----------------------------------------------------
// // Get the contents of an XML element
// // return
// //		Result = true if the presence of the tag start and end
// //		xmlElementValue = content
// //----------------------------------------------------
//
// bool Char_string::getXMLElementValue(const char * xmlElementName, Char_string & xmlElementValue, int fromIndex) {
// 	if ( xmlElementName == NULL ) return false;
//
// 	Char_string startOfElt, endOfElt;
// 	startOfElt = "<";
// 	endOfElt = "</";
// 	startOfElt << xmlElementName;
// 	endOfElt   << xmlElementName << ">";
//
// 	int posdeb = -1;
// 	int posfin = -1;
//
// 	posdeb = index(startOfElt, fromIndex);
// 	if (posdeb >= 0) {
// 		posdeb = index('>', posdeb + startOfElt.get_length());
// 		if (posdeb >= 0) {
// 			posdeb++;								// posdeb = 1st character after the start tag
// 			posfin = index(endOfElt, posdeb);		// posfin = '<' the end tag
// 		}
// 	}
//
// 	if (posfin > 0) {
// 		xmlElementValue = fromAndBefore(posdeb, posfin);
// 		return true;
// 	}
// 	return false;
// }
//
// //-----------------------------------------------------
// // Get the value of an attribute of an XML element
// // return
// //		Result = true if the presence of the attribute
// //		xmlAttributValue = content
// //----------------------------------------------------
// bool Char_string::getXMLAttributeValue(const char * xmlAttributeName, Char_string & xmlAttributeValue, int fromIndex) {
// 	if ( xmlAttributeName == NULL ) return false;
//
// 	Char_string attribute;
// 	attribute  = xmlAttributeName;
// 	attribute << "=\"";
//
// 	int posdeb = -1;
// 	int posfin = -1;
//
// 	posdeb = index(attribute, fromIndex);
// 	if (posdeb >= 0) {
// 		posdeb += attribute.get_length();
// 		posfin = index('\"', posdeb);
// 	}
//
// 	if (posfin > 0) {
// 		xmlAttributeValue = fromAndBefore(posdeb, posfin);
// 		return true;
// 	}
// 	return false;
// }
//
//
// //-----------------------------------------------------
// // Nb counting occurrences of an XML element with or without content, with or without attribute
// // return
// //		Result = nbOccurence
// //----------------------------------------------------
//
// int Char_string::getNbXMLElement(const char * xmlElementName) {
// 	if ( xmlElementName == NULL ) return -1;
//
// 	Char_string startOfElt, endOfElt;
// 	startOfElt = "<";
// 	endOfElt = "</";
// 	startOfElt << xmlElementName ;
// 	endOfElt   << xmlElementName << ">";
//
// 	int nbOccur = -1;
// 	int posdeb = 0;
// 	int posfin = 0;
//
// 	int lengthOfStart = startOfElt.get_length();
// 	int lengthOfEnd=0;
//
// 	do {
// 		nbOccur++;
// 		posdeb = index(startOfElt, posfin+lengthOfEnd);
// 		if (posdeb >= 0) {
// 			posdeb += lengthOfStart;
// 			// Search end elt empty
// 			posfin = index('>', posdeb);
// 			if ((posfin <= 0) || ((*this)[posfin-1] != '/'))
// 				posfin = -1;
// 			else
// 				lengthOfEnd = 1;
//
// 			if (posfin == -1) {//otherwise search end with elt end tag
// 				posfin = index(endOfElt, posdeb);
// 				lengthOfEnd = endOfElt.get_length();
// 			}
//
// 		}
// 	} while ((posdeb >= 0) && (posfin > 0));
//
// 	return nbOccur;
// }
//
// //------------------------------------------
// // Encoding of an XML element
// // entry: the name of the element xmlElementName
// //			value of the element xmlElementValue
// //------------------------------------------
// void Char_string::setXMLElement (const char * xmlElementName, const char * xmlElementValue) {
// 	if ( xmlElementName != NULL && xmlElementValue != NULL ) {
// 		*this << "<" << xmlElementName << ">" << xmlElementValue << "</" << xmlElementName << ">";
// 	}
// }
//
// void Char_string::setXMLElement (const char * xmlElementName, long xmlElementValue) {
// 	if ( xmlElement != NULL ) {
// 		*this << "<" << xmlElementName << ">" << xmlElementValue << "</" << xmlElementName << ">";
// 	}
// }
//
// //------------------------------------------
// // Encoding tag beginning of an XML element
// // entry: the name of the element xmlElementName
// // result in xmlelement
// //------------------------------------------
// void Char_string::setBeginXMLElement (const char * xmlElementName) {
// 	if ( xmlElementName != NULL ) {
// 		*this << "<" << xmlElementName << ">";
// 	}
// }
//
// //------------------------------------------
// // Encoding end tag of an XML element
// // entry: the name of the element xmlElementName
// // result in xmlelement
// //------------------------------------------
// void Char_string::setEndXMLElement (const char * xmlElementName) {
// 	if ( xmlElementName != NULL ) {
// 		*this << "</" << xmlElementName << ">";
// 	}
// }

Boolean Char_string::ok() {
	return _operation_result_flags.get_value().is_nil();
}

Boolean Char_string::operator !() {
	return !ok();
}


// statics
const Memory_natural Char_string::_read_character_bit_constant = Memory_natural::create( 1 );
const Memory_natural Char_string::_read_integer_bit_constant = Memory_natural::create( 2 );
const Memory_natural Char_string::_read_floating_point_bit_constant = Memory_natural::create( 4 );
const Memory_natural Char_string::_read_multiple_characters_bit_constant = Memory_natural::create( 8 );
const Memory_natural Char_string::_open_file_bit_constant = Memory_natural::create( 16 );
const Memory_natural Char_string::_read_file_bit_constant = Memory_natural::create( 32 );
//~statics


} // namespace examples
} // namespace typeing
} // namespace jmsf
