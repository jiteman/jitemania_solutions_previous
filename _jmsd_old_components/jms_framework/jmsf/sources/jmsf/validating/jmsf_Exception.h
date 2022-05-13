#pragma once

#include "jmsf_Exception.hxx"


#include "Exception.h"

#include "jmsf/pointing/cShared.hpp"


namespace jmsf {
namespace validating {


class jmsf_Exception :
	public virtual Exception
{

public:
	// virtuals Exception
	//~virtuals Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Exception
	const pointing::cWeak< texting::Ansii_text > get_exception_subsystem() const noexcept;
	//~virtuals Exception

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Exception
//	~jmsf_Exception() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	jmsf_Exception() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	jmsf_Exception( const jmsf_Exception &another ) noexcept;
//	const jmsf_Exception &operator =( const jmsf_Exception &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::cShared< texting::Ansii_text > _jmsf_exception_subsystem;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace validating
} // namespace jmsf
