#include "Foreign_exception.h"


#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/String_literal.h"
#include "jmsf/jmsf_Allocators.h"
#include "jmsf/pointing/cShared.hin"


namespace jmsf {
namespace validating {


const pointing::cWeak< texting::Ansii_text > Foreign_exception::get_exception_name() const noexcept {
	return _foreign_exception_name.get_as_cweak();
}

const pointing::cWeak< texting::Ansii_text > Foreign_exception::get_exception_category() const noexcept {
	return _foreign_exception_category.get_as_cweak();
}

const pointing::cWeak< texting::Ansii_text > Foreign_exception::get_exception_subsystem() const noexcept {
	return _foreign_exception_subsystem.get_as_cweak();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Foreign_exception::~Foreign_exception() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Foreign_exception::Foreign_exception(
	const texting::String_literal &a_subsystem_name,
	const texting::String_literal &a_category_name,
	const texting::String_literal &a_reason,
	const validating::File_and_line &a_file_and_line) noexcept
	:
		mixin_Exception(
			texting::Aaa_sl( jmsf_Allocators::instance()->get_ansii_allocating_assistor(), a_reason ),
			a_file_and_line ),
		_foreign_exception_name( texting::Aaa_sl( jmsf_Allocators::instance()->get_ansii_allocating_assistor(), JMSF_SL( "Foreign_exception" ) ) ),
		_foreign_exception_subsystem( texting::Aaa_sl( jmsf_Allocators::instance()->get_ansii_allocating_assistor(), a_subsystem_name ) ),
		_foreign_exception_category( texting::Aaa_sl( jmsf_Allocators::instance()->get_ansii_allocating_assistor(), a_category_name ) )

{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Foreign_exception::Foreign_exception( const Foreign_exception &another ) noexcept
	:
		mixin_Exception( another )
{}

const Foreign_exception &Foreign_exception::operator =( const Foreign_exception &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Foreign_exception::Foreign_exception( Foreign_exception &&another ) noexcept
	:
		mixin_Exception( another )
{}

Foreign_exception &Foreign_exception::operator =( Foreign_exception &&another ) noexcept {
	if ( &another == this ) return *this;

	// move
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace validating
} // namespace jmsf

