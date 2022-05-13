#pragma once


#include "jmsf/validating/mixing/mixin_Exception.h"
#include "jmsf/validating/jmsf_Error_exception.h"

#include "jmsf/pointing/cShared.hpp"


namespace jmsf {
namespace validating {
namespace excepting {


class exception_Should_with_type_information :
	public jmsf_Error_exception,
	public mixing::mixin_Exception
{

public:
	// virtuals Exception
//	const pointing::cWeak< texting::Ansii_text > get_detailed_description() const noexcept;
//	const pointing::cWeak< texting::Ansii_text > get_type_information() const noexcept;
	//~virtuals Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals validating::Exception
	const pointing::cWeak< texting::Ansii_text > get_exception_name() const noexcept;
	//~virtuals validating::Exception

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_Should_with_type_information() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_Should_with_type_information(
		const pointing::cShared< texting::Ansii_text > &a_reason_description,
		const pointing::cShared< texting::Ansii_text > &a_detailed_description,
		const pointing::cShared< texting::Ansii_text > &a_type_information,
		const File_and_line &file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_Should_with_type_information( const exception_Should_with_type_information &other ) noexcept;

private:
	const exception_Should_with_type_information &operator =( const exception_Should_with_type_information &other ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
//	const pointing::cShared< texting::Ansii_text > _the_detailed_information;
//	const pointing::cShared< texting::Ansii_text > _the_type_information;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	pointing::cShared< texting::Ansii_text > _exception_Should_with_type_information_typename;

};


} // namespace excepting
} // namespace validating
} // namespace jmsf
