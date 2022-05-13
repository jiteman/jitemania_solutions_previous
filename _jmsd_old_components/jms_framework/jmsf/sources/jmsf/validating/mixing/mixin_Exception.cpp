#include "mixin_Exception.h"


#include "jmsf/jmsf_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/String_literal.h"

//#include "jmsf/pointing/Constant_pointer.hin"
#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Womp.hin"
#include "jmsf/typeing/Naturals.hin"
#include "jmsf/validating/Should.h"

#include "jmsf/encodebuba/encodebuba_logging_macroses_.h"


namespace jmsf {
namespace validating {
namespace mixing {


const pointing::cWeak< texting::Ansii_text > mixin_Exception::get_reason_description() const noexcept {
	return _the_reason_description.get_as_cweak();
}

const pointing::cWeak< texting::Ansii_text > mixin_Exception::get_detailed_description() const noexcept {
	return _mixins_detailed_description.get_as_cweak();
}

const pointing::cWeak< texting::Ansii_text > mixin_Exception::get_type_information() const noexcept {
	return _mixins_type_information.get_as_cweak();
}

const pointing::cWeak< texting::Ansii_text > mixin_Exception::get_filename() const noexcept {
	return _the_file_name.get_as_cweak();
}

typeing::Memory_natural mixin_Exception::get_line_number() const noexcept {
	return _the_line_number;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_Exception::~mixin_Exception() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Exception::mixin_Exception( const pointing::cShared< texting::Ansii_text > &a_reason_description, const File_and_line &a_file_and_line ) noexcept
	:
		_the_reason_description( a_reason_description ),
		_the_file_name(
			texting::Aaa_sl( jmsf_Allocators::instance()->get_ansii_allocating_assistor(), a_file_and_line.get_filename() ) ),
		_the_line_number( a_file_and_line.get_line_number() )
{}

mixin_Exception::mixin_Exception(
	const pointing::cShared< texting::Ansii_text > &a_reason_description,
	const pointing::cShared< texting::Ansii_text > &a_detailed_description,
	const pointing::cShared< texting::Ansii_text > &a_type_information,
	const File_and_line &a_file_and_line ) noexcept
	:
		_the_reason_description( a_reason_description ),
		_mixins_detailed_description( a_detailed_description ),
		_mixins_type_information( a_type_information ),
		_the_file_name(
			texting::Aaa_sl( jmsf_Allocators::instance()->get_ansii_allocating_assistor(), a_file_and_line.get_filename() ) ),
		_the_line_number( a_file_and_line.get_line_number() )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Exception::mixin_Exception( const mixin_Exception &another ) noexcept
	:
		_the_reason_description( another._the_reason_description ),
		_mixins_detailed_description( another._mixins_detailed_description ),
		_mixins_type_information( another._mixins_type_information ),
		_the_file_name( another._the_file_name ),
		_the_line_number( another._the_line_number )
{}

const mixin_Exception &mixin_Exception::operator =( const mixin_Exception &another ) {
	if ( this == &another ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace mixing
} // namespace validating
} // namespace jmsf
