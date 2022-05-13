#include "exception_native_Should_with_type_information.h"


#include <utility>
//#include <iostream>


namespace jmsf {
namespace encodebuba {
namespace validating {
namespace excepting {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const nativing::native_character *const &exception_native_Should_with_type_information::get_exception_name() const noexcept {
	return _native_should_with_type_information_exception_typename;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_native_Should_with_type_information::~exception_native_Should_with_type_information() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_native_Should_with_type_information::exception_native_Should_with_type_information(
	const nativing::native_character *const a_reason_description,
	const nativing::native_character *const a_type_information,
	native_File_and_line &&a_file_and_line ) noexcept
	:
		mixin_native_Exception( a_reason_description, a_type_information, ::std::move( a_file_and_line ) ),
		_native_should_with_type_information_exception_typename( "exception_native_Should_with_type_information" )
{
//	::std::cout <<
//		"exception_Should::exception_Should() - " <<
//		this->get_filename() << " : ( " <<
//		this->get_line_number() << " ) - " <<
//		a_reason_description << " with Type: " <<
//		a_type_information << ::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace excepting
} // namespace validating
} // namespace encodebuba
} // namespace jmsf

