#include "exception_native_Should.h"


#include <utility>
//#include <iostream>


namespace jmsf {
namespace encodebuba {
namespace validating {
namespace excepting {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const nativing::native_character *const &exception_native_Should::get_exception_name() const noexcept {
	return _native_should_exception_typename;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_native_Should::~exception_native_Should() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_native_Should::exception_native_Should(
	const nativing::native_character *const a_reason_description,
	native_File_and_line &&a_file_and_line ) noexcept
	:
		mixin_native_Exception( a_reason_description, ::std::move( a_file_and_line ) ),
		_native_should_exception_typename( "exception_native_Should" )
{
//	::std::cout <<
//		"exception_Should::exception_Should() - " <<
//		this->get_filename() << " : ( " <<
//		this->get_line_number() << " ) - " <<
//		a_reason_description << ::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace excepting
} // namespace validating
} // namespace encodebuba
} // namespace jmsf
