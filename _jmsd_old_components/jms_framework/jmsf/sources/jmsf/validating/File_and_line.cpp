#include "File_and_line.h"

#include "jmsf/typeing/Naturals.hin"

#include "jmsf/encodebuba/encodebuba_logging_flags_.h"


#if defined( JMSF_LOG_INFORMING_PARANOIDAL_IS_ON )
	#include "jmsf/encodebuba/Log.h"

#endif


namespace jmsf {
namespace validating {


const texting::String_literal &File_and_line::get_filename() const {
	return _file_name;
}

typeing::Memory_natural File_and_line::get_line_number() const noexcept {
	return _line_number;
}

//const typeing::internals::platform_character *File_and_line::get_debug_filename() const noexcept {
//	return _filename;
//}

//typeing::memory_natural_value_type File_and_line::get_debug_line_number() const noexcept {
//	return _line_number;
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
File_and_line::~File_and_line() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
File_and_line::File_and_line() noexcept
	:
		_file_name( UNKNOWN_FILENAME )
{}

// static
File_and_line File_and_line::create( const texting::String_literal &a_filename, const typeing::memory_natural_value_type line_number ) noexcept {
//	JMSF_LOG_INFORMING_PARANOIDAL_OUTPUT( "File_and_line::create( %filename%, %line_number% )" );

#if defined( JMSF_LOG_INFORMING_PARANOIDAL_IS_ON )
	encodebuba::Log::write( "jmsf", "File_and_line::create( %filename%, %line_number% ) parameters", a_filename.get(), line_number );

#endif

	return File_and_line( a_filename, typeing::Memory_natural::create( line_number ) );
}

File_and_line::File_and_line( const texting::String_literal &a_filename, const typeing::Memory_natural line_number ) noexcept
	:
		_file_name( a_filename ),
		_line_number( line_number )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
File_and_line::File_and_line( const File_and_line &another ) noexcept
	:
		_file_name( another._file_name ),
		_line_number( another._line_number )
{}

const File_and_line &File_and_line::operator =( const File_and_line &another ) noexcept {
	if ( &another == this ) return *this;

	_file_name = another._file_name;
	_line_number = another._line_number;
	return *this;
}

File_and_line::File_and_line( File_and_line &&another ) noexcept
	:
		_file_name( another._file_name ),
		_line_number( another._line_number )
{
	another._file_name = texting::String_literal();
	_line_number = typeing::Memory_natural_nil;
}

File_and_line &File_and_line::operator =( File_and_line &&another ) noexcept {
	if ( &another == this ) return *this;

	_file_name = another._file_name;
	_line_number = another._line_number;
	another._file_name = texting::String_literal();
	_line_number = typeing::Memory_natural_nil;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
const texting::String_literal File_and_line::UNKNOWN_FILENAME = JMSF_SL( "Filename is unknown" );

// static
const File_and_line File_and_line::EMPTY_FILE_AND_LINE( JMSF_SL( __FILE__ ), typeing::Memory_natural::create( __LINE__ ) );


} // namespace validating
} // namespace jmsf
