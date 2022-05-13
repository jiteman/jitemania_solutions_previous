#pragma once

#include "Fixture_set_up_exception.hxx"


#include "jmsf/cule/validating/cule_Failure_exception.h"
#include "jmsf/pointing/cShared.hpp"
#include "jmsf/validating/mixing/mixin_Exception.h"

#include "jmsf/validating/File_and_line.hxx"


namespace jmsf {
namespace cule {
namespace excepting {


class Fixture_set_up_exception :
	public validating::cule_Failure_exception,
	public ::jmsf::validating::mixing::mixin_Exception
{

public:
	// virtuals Exception
	//~virtuals Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Exception
	const pointing::cWeak< texting::Ansii_text > get_exception_name() const noexcept override;
	//~virtuals Exception

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Exception
	~Fixture_set_up_exception() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Fixture_set_up_exception( const pointing::cShared< texting::Ansii_text > &reason, const ::jmsf::validating::File_and_line &file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	Fixture_set_up_exception( const Fixture_set_up_exception &another ) noexcept = delete;
//	const Fixture_set_up_exception &operator =( const Fixture_set_up_exception &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	Fixture_set_up_exception( Fixture_set_up_exception &&another ) noexcept = delete;
//	Fixture_set_up_exception &operator =( Fixture_set_up_exception &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::cShared< texting::Ansii_text > _exception_typename;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace excepting
} // namespace cule
} // namespace jmsf
