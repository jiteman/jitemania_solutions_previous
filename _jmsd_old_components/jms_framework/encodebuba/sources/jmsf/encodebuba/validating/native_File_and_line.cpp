#include "native_File_and_line.h"


namespace jmsf {
namespace encodebuba {
namespace validating {


const nativing::native_character *const &native_File_and_line::get_filename() const noexcept {
	return this->_the_filename;
}

nativing::native_memory_natural native_File_and_line::get_line_number() const noexcept {
	return this->_the_line_number;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
native_File_and_line::~native_File_and_line() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//native_File_and_line::native_File_and_line() noexcept
//{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
native_File_and_line::native_File_and_line(
	const nativing::native_character *const a_filename,
	const nativing::native_memory_natural a_line_number ) noexcept
	:
		_the_filename( a_filename ),
		_the_line_number( a_line_number )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
native_File_and_line native_File_and_line::create(
	const nativing::native_character *const a_filename,
	const nativing::native_memory_natural a_line_number )
{
	return native_File_and_line( a_filename, a_line_number );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
native_File_and_line::native_File_and_line( native_File_and_line &&another ) noexcept
	:
		_the_filename( another._the_filename ),
		_the_line_number( another._the_line_number )
{}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace validating
} // namespace encodebuba
} // namespace jmsf

