#include "mixin_native_Exception.h"


#include <utility>


namespace jmsf {
namespace encodebuba {
namespace validating {
namespace mixing {


const nativing::native_character *const &mixin_native_Exception::get_reason_description() const noexcept {
	return
		this->_the_reason_description != nullptr ?
			this->_the_reason_description :
			mixin_native_Exception::EMPTY_STRING;
}

const nativing::native_character *const &mixin_native_Exception::get_type_information() const noexcept {
	return
		this->_the_type_information != nullptr ?
			this->_the_type_information :
			mixin_native_Exception::EMPTY_STRING;
}

const nativing::native_character *const &mixin_native_Exception::get_filename() const noexcept {
	return
		this->_the_file_and_line.get_filename() != nullptr ?
			this->_the_file_and_line.get_filename() :
			mixin_native_Exception::EMPTY_STRING;
}

nativing::native_memory_natural mixin_native_Exception::get_line_number() const noexcept {
	return this->_the_file_and_line.get_line_number();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const nativing::native_character *const &mixin_native_Exception::get_exception_category() const noexcept {
	return mixin_native_Exception::EXCEPTION_CATEGORY;
}

const nativing::native_character *const &mixin_native_Exception::get_exception_subsystem() const noexcept {
	return mixin_native_Exception::EXCEPTION_SUBSYSTEM;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_native_Exception::~mixin_native_Exception() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_native_Exception::mixin_native_Exception(
	native_File_and_line &&a_file_and_line ) noexcept
	:
		mixin_native_Exception(
			mixin_native_Exception::EMPTY_STRING,
			mixin_native_Exception::EMPTY_STRING,
			::std::move( a_file_and_line ) )
{}

mixin_native_Exception::mixin_native_Exception(
	const nativing::native_character *const a_reason_description,
	native_File_and_line &&a_file_and_line ) noexcept
	:
		mixin_native_Exception(
			a_reason_description,
			mixin_native_Exception::EMPTY_STRING,
			::std::move( a_file_and_line ) )
{}

mixin_native_Exception::mixin_native_Exception(
	const nativing::native_character *const a_reason_description,
	const nativing::native_character *const a_type_information,
	native_File_and_line &&a_file_and_line ) noexcept
	:
		_the_file_and_line( ::std::move( a_file_and_line ) ),
		_the_exception_category( mixin_native_Exception::EXCEPTION_CATEGORY ),
		_the_exception_subsystem( mixin_native_Exception::EXCEPTION_SUBSYSTEM ),
		_the_reason_description( a_reason_description ),
		_the_type_information( a_type_information )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_native_Exception::mixin_native_Exception( mixin_native_Exception &&another ) noexcept
	:
		_the_file_and_line( ::std::move( const_cast< native_File_and_line & >( another._the_file_and_line ) ) ),
		_the_reason_description( another._the_reason_description ),
		_the_type_information( another._the_type_information ),
		_the_exception_category( another._the_exception_category ),
		_the_exception_subsystem( another._the_exception_subsystem )

{}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// static
const char *const mixin_native_Exception::EMPTY_STRING = "";

// static
const char *const mixin_native_Exception::EXCEPTION_CATEGORY = "Error";

// static
const char *const mixin_native_Exception::EXCEPTION_SUBSYSTEM = "ENCODEBUBA";


} // namespace mixing
} // namespace validating
} // namespace encodebuba
} // namespace jmsf

