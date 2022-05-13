#pragma once


#include "jmsf/validating/mixing/mixin_Exception.h"
#include "jmsf/validating/jmsf_Error_exception.h"

#include "jmsf/pointing/cShared.hpp"


namespace jmsf {
namespace validating {
namespace excepting {


class exception_Should :
	public jmsf_Error_exception,
	public mixing::mixin_Exception
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
	~exception_Should() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_Should( const pointing::cShared< texting::Ansii_text > &a_reason, const File_and_line &file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_Should( const exception_Should &other ) noexcept;

private:
	const exception_Should &operator =( const exception_Should &other ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::cShared< texting::Ansii_text > _exception_Should_typename;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace excepting
} // namespace validating
} // namespace jmsf
