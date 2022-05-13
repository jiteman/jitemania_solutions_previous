#include "exception_Should_with_type_information.h"


#include "jmsf/jmsf_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/String_literal.h"
#include "jmsf/texting/Native_C_string.h"

#include "jmsf/pointing/cWeak.hin"

#include "jmsf/memorying/Womp.hin"

#include "jmsf/patterning/Singleton.hin"

#include "jmsf/encodebuba/encodebuba_logging_macroses_.h"


//#include <iostream>


namespace jmsf {
namespace validating {
namespace excepting {


//const pointing::cWeak< texting::Ansii_text > exception_Should_with_type_information::get_detailed_description() const noexcept {
//	return _the_detailed_information.get_as_cweak();
//}

//const pointing::cWeak< texting::Ansii_text > exception_Should_with_type_information::get_type_information() const noexcept {
//	return _the_type_information.get_as_cweak();
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::cWeak< texting::Ansii_text > exception_Should_with_type_information::get_exception_name() const noexcept {
	return _exception_Should_with_type_information_typename.get_as_cweak();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_Should_with_type_information::~exception_Should_with_type_information() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Should_with_type_information::exception_Should_with_type_information(
	const pointing::cShared< texting::Ansii_text > &a_reason_description,
	const pointing::cShared< texting::Ansii_text > &a_detailed_description,
	const pointing::cShared< texting::Ansii_text > &a_type_information,
	const File_and_line &file_and_line ) noexcept
	:
		mixin_Exception( a_reason_description, a_detailed_description, a_type_information, file_and_line ),
		_exception_Should_with_type_information_typename(
			texting::Aaa_sl(
				jmsf_Allocators::instance()->get_ansii_allocating_assistor(),
				JMSF_SL( "exception_Should_with_type_information" ) ) )

{
//	::std::cout <<
//		"exception_Should_with_type_information::exception_Should_with_type_information() - " <<
//		file_and_line.get_filename().get() << " : ( " <<
//		file_and_line.get_line_number().get_native_value() << " ) - " <<
//		jmsf_Allocators::instance()->get_ansii_allocating_assistor()->create_native_from_ansii_text( a_reason_description )->get().operator ->() << ", Details: " <<
//		jmsf_Allocators::instance()->get_ansii_allocating_assistor()->create_native_from_ansii_text( a_detailed_description )->get().operator ->() << ", Type: " <<
//		jmsf_Allocators::instance()->get_ansii_allocating_assistor()->create_native_from_ansii_text( a_type_information )->get().operator ->() << ::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Should_with_type_information::exception_Should_with_type_information( const exception_Should_with_type_information &another ) noexcept
	:
		mixin_Exception( another )
{}

const exception_Should_with_type_information &exception_Should_with_type_information::operator =( const exception_Should_with_type_information &another ) noexcept {
	if ( this == &another ) return *this;

	mixin_Exception::operator =( another );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace excepting
} // namespace validating
} // namespace jmsf

