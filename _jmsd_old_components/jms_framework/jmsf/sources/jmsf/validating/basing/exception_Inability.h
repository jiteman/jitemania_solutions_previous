#pragma once

#include "exception_Inability.hxx"


#include "jmsf/validating/Exception.h"

#include "jmsf/pointing/cShared.hpp"


namespace jmsf {
namespace validating {
namespace basing {


class exception_Inability :
	public virtual Exception
{

public:
	// virtuals Exception
	//~virtuals Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Exception
	const pointing::cWeak< texting::Ansii_text > get_exception_category() const noexcept;
	//~virtuals Exception

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Exception
//	~exception_Inability() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_Inability() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	exception_Inability( const exception_Inability &another ) noexcept;
//	const exception_Inability &operator =( const exception_Inability &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::cShared< texting::Ansii_text > _inability_exception_type;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace basing
} // namespace validating
} // namespace jmsf
