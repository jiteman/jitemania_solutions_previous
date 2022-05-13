#pragma once


#include "../Exception.h"
#include "jmsf/validating/File_and_line.hxx"

//#include "jmsf/texting/Ansii_text.h"
//#include "jmsf/pointing/Constant_pointer.hpp"
#include "jmsf/pointing/cShared.hpp"

#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/pointing/cWeak.hxx"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {
namespace mixing {


// Seinsei: detailed description and type infromation data (as well as methods) here are for default behaviour only.
// These should be redefined in childs to use its own provided data (see exception_Should_with_type_information for example).

class JMSF_SHARED_INTERFACE mixin_Exception :
	public virtual Exception
{

public:
	// virtuals Exception
	const pointing::cWeak< texting::Ansii_text > get_reason_description() const noexcept;
	const pointing::cWeak< texting::Ansii_text > get_detailed_description() const noexcept;
	const pointing::cWeak< texting::Ansii_text > get_type_information() const noexcept;
	const pointing::cWeak< texting::Ansii_text > get_filename() const noexcept;
	typeing::Memory_natural get_line_number() const noexcept;
	//~virtuals Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Exception
	//~virtuals Exception

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~mixin_Exception() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Exception( const pointing::cShared< texting::Ansii_text > &a_reason_description, const File_and_line &a_file_and_line ) noexcept;

	mixin_Exception(
		const pointing::cShared< texting::Ansii_text > &a_reason_description,
		const pointing::cShared< texting::Ansii_text > &a_detailed_description,
		const pointing::cShared< texting::Ansii_text > &a_type_information,
		const File_and_line &a_file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Exception( const mixin_Exception &other ) noexcept;

protected:
	const mixin_Exception &operator =( const mixin_Exception &other );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::cShared< texting::Ansii_text > _the_reason_description;
	pointing::cShared< texting::Ansii_text > _mixins_detailed_description;
	pointing::cShared< texting::Ansii_text > _mixins_type_information;
	pointing::cShared< texting::Ansii_text > _the_file_name;
	typeing::Memory_natural _the_line_number;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace mixing
} // namespace validating
} // namespace jmsf
