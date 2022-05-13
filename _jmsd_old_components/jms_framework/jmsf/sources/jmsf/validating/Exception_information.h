#pragma once

#include "Exception_information.hxx"


#include "Exception.h"

#include "jmsf/pointing/cShared.hpp"
#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Constructor.hxx"

#include "File_and_line.hxx"

#include "jmsf/encodebuba/validating/native_Exception.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {


class JMSF_SHARED_INTERFACE Exception_information :
	public Exception
{

public:
	// virtuals Exception
	const pointing::cWeak< texting::Ansii_text > get_reason_description() const noexcept;
	const pointing::cWeak< texting::Ansii_text > get_detailed_description() const noexcept;
	const pointing::cWeak< texting::Ansii_text > get_type_information() const noexcept;
	const pointing::cWeak< texting::Ansii_text > get_filename() const noexcept;
	typeing::Memory_natural get_line_number() const noexcept;
	//~virtuals Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Exception
	const pointing::cWeak< texting::Ansii_text > get_exception_name() const noexcept;
	const pointing::cWeak< texting::Ansii_text > get_exception_category() const noexcept;
	const pointing::cWeak< texting::Ansii_text > get_exception_subsystem() const noexcept;
	//~virtuals Exception

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< Exception_information >;
	~Exception_information() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Exception_information() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Exception_information, Exception_information >;
	Exception_information(
		const pointing::cShared< texting::Ansii_text > &reason_description,
		const pointing::cShared< texting::Ansii_text > &detailed_description,
		const pointing::cShared< texting::Ansii_text > &type_information,
		const pointing::cShared< texting::Ansii_text > &filename,
		typeing::Memory_natural line_number,
		const pointing::cShared< texting::Ansii_text > &exception_name,
		const pointing::cShared< texting::Ansii_text > &exception_category,
		const pointing::cShared< texting::Ansii_text > &exception_subsystem ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static const pointing::cShared< Exception_information > create_from_exception(
		const memorying::Womp< memorying::Allocator > &reference_counted_omp_allocator,
		const memorying::Womp< memorying::Allocator > &exception_information_allocator,
		const Exception &original_exception );

	static const pointing::cShared< Exception_information > create_from_native_exception(
		const memorying::Womp< memorying::Allocator > &reference_counted_omp_allocator,
		const memorying::Womp< memorying::Allocator > &exception_information_allocator,
		const memorying::Womp< texting::Ansii_allocating_assistor > &ansii_allocating_assistor,
		const encodebuba::validating::native_Exception &original_native_exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Exception_information( const Exception_information &another ) noexcept = delete;
	const Exception_information &operator =( const Exception_information &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Exception_information( Exception_information &&another ) noexcept = delete;
	Exception_information &operator =( Exception_information &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::cShared< texting::Ansii_text > _reason_description;
	pointing::cShared< texting::Ansii_text > _detailed_description;
	pointing::cShared< texting::Ansii_text > _type_information;
	pointing::cShared< texting::Ansii_text > _filename;
	typeing::Memory_natural _line_number;
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	pointing::cShared< texting::Ansii_text > _exception_name;
	pointing::cShared< texting::Ansii_text > _exception_category;
	pointing::cShared< texting::Ansii_text > _exception_subsystem;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace validating
} // namespace jmsf
