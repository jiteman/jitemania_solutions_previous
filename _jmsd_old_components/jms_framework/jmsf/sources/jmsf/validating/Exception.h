#pragma once


#include "jmsf/texting/Ansii_text.hxx"
#include "jmsf/texting/String_literal.hxx"
#include "jmsf/pointing/cWeak.hxx"
#include "jmsf/typeing/Naturals.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {


class JMSF_SHARED_INTERFACE Exception {

public:
	// realization is done in mixin_Exception
	virtual const pointing::cWeak< texting::Ansii_text > get_reason_description() const noexcept = 0;
	virtual const pointing::cWeak< texting::Ansii_text > get_detailed_description() const noexcept = 0;
	virtual const pointing::cWeak< texting::Ansii_text > get_type_information() const noexcept = 0;
	virtual const pointing::cWeak< texting::Ansii_text > get_filename() const noexcept = 0;
	virtual typeing::Memory_natural get_line_number() const noexcept = 0;
	//~realization is done in mixin_Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// realization should be done in final exception class
	virtual const pointing::cWeak< texting::Ansii_text > get_exception_name() const noexcept = 0;

	// realization is done in ::jmsf::validating::basing::exception_<Category> classes
	virtual const pointing::cWeak< texting::Ansii_text > get_exception_category() const noexcept = 0;

	// realization should be done in subsystem root exception class (i.e., ::jmsf::cule::validating::cule_Exception )
	virtual const pointing::cWeak< texting::Ansii_text > get_exception_subsystem() const noexcept = 0;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	virtual ~Exception() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace validating
} // namespace jmsf
