#include "exception_Memory_is_depleted.h"


#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/cShared.hpp"


namespace jmsf {
namespace memorying {
namespace excepting {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::cWeak< texting::Ansii_text > exception_Memory_is_depleted::get_exception_name() const noexcept {
	return _exception_Memory_is_depleted_typename.get_as_cweak();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_Memory_is_depleted::~exception_Memory_is_depleted() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Memory_is_depleted::exception_Memory_is_depleted(
	const pointing::cShared< texting::Ansii_text > &a_reason,
	const validating::File_and_line &file_and_line ) noexcept
	:
		mixin_Exception( a_reason, file_and_line ),
		_exception_Memory_is_depleted_typename(
			texting::Aaa_sl(
				jmsf_Allocators::instance()->get_ansii_allocating_assistor(),
				JMSF_SL( "exception_Memory_is_depleted" ) ) )
{}

exception_Memory_is_depleted::exception_Memory_is_depleted(
	const pointing::cShared< texting::Ansii_text > &a_reason,
	const pointing::cShared< texting::Ansii_text > &a_detailed_description,
	const pointing::cShared< texting::Ansii_text > &a_type_information,
	const validating::File_and_line &file_and_line ) noexcept
	:
		mixin_Exception( a_reason, a_detailed_description, a_type_information, file_and_line ),
		_exception_Memory_is_depleted_typename(
			texting::Aaa_sl(
				jmsf_Allocators::instance()->get_ansii_allocating_assistor(),
				JMSF_SL( "exception_Memory_is_depleted" ) ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Memory_is_depleted::exception_Memory_is_depleted( const exception_Memory_is_depleted &another ) noexcept
	:
		mixin_Exception( another )
{}

const exception_Memory_is_depleted &exception_Memory_is_depleted::operator =( const exception_Memory_is_depleted &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Memory_is_depleted::exception_Memory_is_depleted( const exception_Memory_is_depleted &&another ) noexcept
	:
		mixin_Exception( another )
{}

const exception_Memory_is_depleted &exception_Memory_is_depleted::operator =( const exception_Memory_is_depleted &&another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace excepting
} // namespace memorying
} // namespace jmsf
