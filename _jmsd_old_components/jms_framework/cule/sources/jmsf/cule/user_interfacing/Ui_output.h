#pragma once

#include "Ui_output.hxx"


#include "jmsf/texting/Ansii_text.hxx"
#include "jmsf/texting/String_literal.hxx"
#include "jmsf/pointing/cWeak.hxx"
#include "jmsf/pointing/cShared.hxx"
#include "jmsf/typeing/Naturals.hxx"
#include "jmsf/typeing/Reals.hxx"


namespace jmsf {
namespace cule {
namespace user_interfaces { // Seinsei: todonext - police all the stuff


class Ui_output {

	static const texting::String_literal TEST_START_INDICATOR;
	static const texting::String_literal FAILURE_INDICATOR;
	static const texting::String_literal ERROR_INDICATOR;
	static const texting::String_literal UNKNOWN_ERROR_INDICATOR;
	static const texting::String_literal BLANK_LINE;

public:
	virtual ~Ui_output() noexcept = 0;
	Ui_output() noexcept;

	void indicate_testing_started();

	void indicate_test_start();
	void indicate_failure();
	void indicate_error();
	void indicate_unknown_error();

	void print_blank_line();
	void print_test_failure_caption( typeing::Natural quantity_of_runned_tests, const pointing::cShared< texting::Ansii_text > &name );

	void print_test_failure(
		typeing::Memory_natural number,
		const pointing::cShared< texting::Ansii_text > &file_and_line_summary,
		const pointing::cShared< texting::Ansii_text > &message );

	void print_no_fault();
	void print_total_testing_duration( typeing::Natural number, typeing::Natural duration_in_ms );

protected: // Seinsei: todonext - make private
	virtual void print( const pointing::cShared< texting::Ansii_text > &a_string ) const = 0;
	virtual void print( const texting::String_literal &a_string ) const = 0;

};


} // namespace
}
}
