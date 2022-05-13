#include "exception_exception_Object.h"


#include "jmsf/jmsf_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/String_literal.h"

#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/cShared.hin"


namespace jmsf {
namespace patterning {
namespace mixing {
namespace exceptions {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::cWeak< texting::Ansii_text > exception_exception_Object::get_exception_name() const noexcept {
	return _exception_typename.get_as_cweak();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_exception_Object::~exception_exception_Object() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_exception_Object::exception_exception_Object(
	const pointing::cShared< texting::Ansii_text > &a_reason,
	const validating::File_and_line &file_and_line ) noexcept
	:
		mixin_Exception( a_reason, file_and_line ),
			_exception_typename(
				texting::Aaa_sl(
					jmsf_Allocators::instance()->get_ansii_allocating_assistor(),
					JMSF_SL( "exception_exception_Object" ) ) )

{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_exception_Object::exception_exception_Object( const exception_exception_Object &another ) noexcept
	:
		mixin_Exception( another )
{}

const exception_exception_Object &exception_exception_Object::operator =( const exception_exception_Object &another ) noexcept {
	if ( &another == this ) return *this;

	mixin_Exception::operator =( another );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace exceptions
} // namespace mixing
} // namespace patterning
} // namespace jmsf
