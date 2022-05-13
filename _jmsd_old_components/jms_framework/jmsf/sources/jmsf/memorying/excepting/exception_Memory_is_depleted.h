#pragma once


#include "jmsf/validating/mixing/mixin_Exception.h"
#include "jmsf/validating/jmsf_Error_exception.h"

#include "jmsf/pointing/cShared.hpp"


namespace jmsf {
namespace memorying {
namespace excepting {


class exception_Memory_is_depleted :
	public validating::jmsf_Error_exception,
	public validating::mixing::mixin_Exception
{

public:
	// virtuals validating::mixing::mixin_Exception
	//~virtuals validating::mixing::mixin_Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals validating::Exception
	const pointing::cWeak< texting::Ansii_text > get_exception_name() const noexcept;
	//~virtuals validating::Exception

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual validating::Exception
	~exception_Memory_is_depleted() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_Memory_is_depleted( const pointing::cShared< texting::Ansii_text > &a_reason, const validating::File_and_line &file_and_line ) noexcept;

	exception_Memory_is_depleted(
		const pointing::cShared< texting::Ansii_text > &a_reason,
		const pointing::cShared< texting::Ansii_text > &a_detailed_description,
		const pointing::cShared< texting::Ansii_text > &a_type_information,
		const validating::File_and_line &file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_Memory_is_depleted( const exception_Memory_is_depleted &another ) noexcept;
	const exception_Memory_is_depleted &operator =( const exception_Memory_is_depleted &another ) noexcept;

public:
	exception_Memory_is_depleted( const exception_Memory_is_depleted &&another ) noexcept;
	const exception_Memory_is_depleted &operator =( const exception_Memory_is_depleted &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::cShared< texting::Ansii_text > _exception_Memory_is_depleted_typename;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace excepting
} // namespace memorying
} // namespace jmsf
