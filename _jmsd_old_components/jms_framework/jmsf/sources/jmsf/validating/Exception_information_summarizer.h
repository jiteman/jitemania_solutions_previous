#pragma once

#include "Exception_information_summarizer.hxx"

#include "Exception_information.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {


// move realization from ::jmsf::cule::user_outputing::UiOutput
class JMSF_SHARED_INTERFACE Exception_information_summarizer {

public:
	static pointing::cShared< texting::Ansii_text > create_file_and_line_summary(
		const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa,
		const pointing::cShared< texting::Ansii_text > &a_filename,
		typeing::Memory_natural a_line_number ) noexcept;

	static pointing::cShared< texting::Ansii_text > create_reason_description_summary(
		const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa,
		const pointing::cShared< texting::Ansii_text > &a_reason_description ) noexcept;

	static pointing::cShared< texting::Ansii_text > create_detailed_description_summary(
		const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa,
		const pointing::cShared< texting::Ansii_text > &a_detailed_description ) noexcept;

	static pointing::cShared< texting::Ansii_text > create_type_information_summary(
		const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa,
		const pointing::cShared< texting::Ansii_text > &a_type_information ) noexcept;

	static pointing::cShared< texting::Ansii_text > create_exception_hierarchy_summary(
		const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa,
		const pointing::cShared< texting::Ansii_text > &a_subsystem,
		const pointing::cShared< texting::Ansii_text > &a_category,
		const pointing::cShared< texting::Ansii_text > &a_name ) noexcept;

	static pointing::cShared< texting::Ansii_text > create_all_summary(
		const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa,
		const pointing::cShared< texting::Ansii_text > &a_filename,
		typeing::Memory_natural a_line_number,
		const pointing::cShared< texting::Ansii_text > &a_reason_description,
		const pointing::cShared< texting::Ansii_text > &a_detailed_description,
		const pointing::cShared< texting::Ansii_text > &a_type_information,
		const pointing::cShared< texting::Ansii_text > &a_subsystem,
		const pointing::cShared< texting::Ansii_text > &a_category,
		const pointing::cShared< texting::Ansii_text > &a_name ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	pointing::cShared< texting::Ansii_text > get_file_and_line_summary(
		const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const noexcept;

	pointing::cShared< texting::Ansii_text > get_reason_description_summary(
		const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const noexcept;

	pointing::cShared< texting::Ansii_text > get_detailed_description_summary(
		const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const noexcept;

	pointing::cShared< texting::Ansii_text > get_type_information_summary(
		const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const noexcept;

	pointing::cShared< texting::Ansii_text > get_exception_hierarchy_summary(
		const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const noexcept;

	pointing::cShared< texting::Ansii_text > get_all_summary(
		const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Exception_information_summarizer() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Exception_information_summarizer(
		const memorying::Womp< memorying::Allocator > &a_reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &an_exception_information_allocator,
		const Exception &an_exception ) noexcept;

	Exception_information_summarizer( const pointing::cShared< Exception_information > &an_exception_information ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Exception_information_summarizer( const Exception_information_summarizer &another ) noexcept = delete;
	const Exception_information_summarizer &operator =( const Exception_information_summarizer &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Exception_information_summarizer( Exception_information_summarizer &&another ) noexcept = delete;
	Exception_information_summarizer &operator =( Exception_information_summarizer &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::cShared< Exception_information > _the_exception_information;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace validating
} // namespace jmsf
