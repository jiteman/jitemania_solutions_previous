#include "Memory_address.h"


#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/typeing/Aso.hin"
#include "jmsf/typeing/Naturals.hin"
#include "jmsf/typeing/Boolean.h"

#include "jmsf/jmsf_logging_macroses.h"
#include "jmsf/validating/macroses_Type_name.h"
#include "jmsf/validating/macroses_Should.h"

#include <utility>


namespace jmsf {
namespace memorying {


typeing::Boolean Memory_address::is_empty() const noexcept {
	return typeing::Boolean::create( _the_address.is_nil() || _the_address.is_max() );
}

typeing::Boolean Memory_address::is_not_empty() const noexcept {
	return !is_empty();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//typeing::internals::platform_byte *Memory_pointer::take() {
//	JMSF_PRE_ERROR_LOG_CONDITIONAL_OUTPUT( _the_memory == nullptr, "Memory_pointer::take()" );
//	jmsf_Should_never_be_empty_native_pointer( _the_memory );
////	validating::Should::never_be_null_native_pointer( _the_memory, JMSF_FILE_AND_LINE );
//	return _the_memory;
//}

//const typeing::internals::platform_byte *Memory_pointer::get() const {
//	JMSF_PRE_ERROR_LOG_CONDITIONAL_OUTPUT( _the_memory == nullptr, "Memory_pointer::take()" );
//	jmsf_Should_never_be_empty_native_pointer( _the_memory );
//	return _the_memory;
//}

typeing::Memory_natural Memory_address::get() const noexcept {
	return _the_address;
}

void Memory_address::set( const typeing::Memory_natural an_address ) noexcept {
	_the_address = an_address;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
typeing::Boolean Memory_address::operator ==( const Memory_address &another ) const noexcept {
	return typeing::Boolean::create( _the_address == another._the_address );
}

typeing::Boolean Memory_address::operator !=( const Memory_address &another ) const noexcept {
	return !operator ==( another );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::cShared< texting::Ansii_text > Memory_address::to_ansii_text( const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const {
	pointing::Shared< texting::Ansii_stream > ansii_stream = an_aaa->create_ansii_stream();
	ansii_stream->put( _the_address, typeing::True );
	return texting::Aaa_cs( an_aaa, ansii_stream );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Memory_address::~Memory_address() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memory_address::Memory_address() noexcept
{}

// static
// Memory_pointer Memory_pointer::create( typeing::internals::platform_byte *const a_memory ) noexcept {
// 	return Memory_pointer( a_memory );
// }

// static
Memory_address Memory_address::create_from_pointer( const void *const a_memory ) {
	JMSF_PRE_ERROR_LOG_CONDITIONAL_OUTPUT( a_memory == nullptr, "Memory_pointer::create_from_pointer( a_memory )" );
	jmsf_Should_never_be_empty_native_pointer( a_memory );

	return
		typeing::create_address_from_pointer( a_memory );
}

// static
Memory_address Memory_address::create_from_address( const typeing::Memory_natural an_address ) {
	JMSF_PRE_ERROR_LOG_CONDITIONAL_OUTPUT( an_address.is_nil(), "Memory_pointer::create_from_address( an_address )" );
	jmsf_Should_never_be( an_address.is_nil() );
	return Memory_address( an_address );
}

Memory_address::Memory_address( const typeing::Memory_natural an_address  ) noexcept
	:
		_the_address( an_address )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memory_address::Memory_address( const Memory_address &another ) noexcept
	:
		_the_address( another._the_address )
{}

const Memory_address &Memory_address::operator =( const Memory_address &another ) noexcept {
	if ( &another == this ) return *this;

	_the_address = another._the_address;
	return *this;
}

Memory_address::Memory_address( Memory_address &&another ) noexcept
	:
		_the_address( ::std::move( another._the_address ) )
{}

Memory_address &Memory_address::operator =( Memory_address &&another ) noexcept {
	if ( &another == this ) return *this;

	_the_address = ::std::move( another._the_address );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace memorying
} // namespace jmsf
