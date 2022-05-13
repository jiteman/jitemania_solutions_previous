#pragma once

#include "Fixture_tear_down_exception.hxx"


#include "jmsf/cule/validating/cule_Failure_exception.h"
#include "jmsf/pointing/cShared.hpp"
#include "jmsf/validating/mixing/mixin_Exception.h"

#include "jmsf/validating/File_and_line.hxx"


namespace jmsf {
namespace cule {
namespace excepting {


class Fixture_tear_down_exception :
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
	~Fixture_tear_down_exception() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Fixture_tear_down_exception( const pointing::cShared< texting::Ansii_text > &reason, const ::jmsf::validating::File_and_line &file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	Fixture_tear_down_exception( const Fixture_tear_down_exception &another ) noexcept = delete;
//	const Fixture_tear_down_exception &operator =( const Fixture_tear_down_exception &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	Fixture_tear_down_exception( Fixture_tear_down_exception &&another ) noexcept = delete;
//	Fixture_tear_down_exception &operator =( Fixture_tear_down_exception &&another ) noexcept = delete;

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
