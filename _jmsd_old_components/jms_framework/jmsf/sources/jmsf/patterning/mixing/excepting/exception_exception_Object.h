#pragma once


#include "jmsf/validating/mixing/mixin_Exception.h"
#include "jmsf/validating/jmsf_Error_exception.h"

#include "jmsf/pointing/cShared.hpp"


namespace jmsf {
namespace patterning {
namespace mixing {
namespace exceptions { // Seinsei: todonext - rename to excepting


class exception_exception_Object :
	public validating::jmsf_Error_exception,
	public validating::mixing::mixin_Exception
{

public:
	// virtuals
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals validating::Exception
	const pointing::cWeak< texting::Ansii_text > get_exception_name() const noexcept;
	//~virtuals validating::Exception

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_exception_Object() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_exception_Object( const pointing::cShared< texting::Ansii_text > &a_reason, const validating::File_and_line &file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_exception_Object( const exception_exception_Object &another ) noexcept;

private:
	const exception_exception_Object &operator =( const exception_exception_Object &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::cShared< texting::Ansii_text > _exception_typename;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace exceptions
} // namespace mixing
} // namespace patterning
} // namespace jmsf
