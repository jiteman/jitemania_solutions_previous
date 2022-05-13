#include "exception_Should.h"


#include "jmsf/jmsf_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/String_literal.h"
//#include "jmsf/texting/Native_C_string.h"

#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Womp.hin"

#include "jmsf/patterning/Singleton.hin"

#include "jmsf/jmsf_logging_macroses.h"


//#include <iostream>


namespace jmsf {
namespace validating {
namespace excepting {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::cWeak< texting::Ansii_text > exception_Should::get_exception_name() const noexcept {
	return _exception_Should_typename.get_as_cweak();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_Should::~exception_Should() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Should::exception_Should(
	const pointing::cShared< texting::Ansii_text > &a_reason,
	const File_and_line &file_and_line ) noexcept
	:
		mixin_Exception( a_reason, file_and_line ),
		_exception_Should_typename(
			texting::Aaa_sl(
				jmsf_Allocators::instance()->get_ansii_allocating_assistor(),
				JMSF_SL( "exception_Should" ) ) )
{
//	::std::cout <<
//		"exception_Should::exception_Should() - " <<
//		file_and_line.get_filename().get() << " : ( " <<
//		file_and_line.get_line_number().get_native_value() << " ) - " <<
//		jmsf_Allocators::instance()->get_ansii_allocating_assistor()->create_native_from_ansii_text( a_reason )->get().operator ->() << ::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Should::exception_Should( const exception_Should &another ) noexcept
	:
		mixin_Exception( another )
{}

const exception_Should &exception_Should::operator =( const exception_Should &another ) noexcept {
	if ( this == &another ) return *this;

	mixin_Exception::operator =( another );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace excepting
} // namespace validating
} // namespace jmsf
