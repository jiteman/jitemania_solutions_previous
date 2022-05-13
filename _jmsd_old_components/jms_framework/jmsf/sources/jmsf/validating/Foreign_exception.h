#pragma once

#include "Foreign_exception.hxx"


#include "jmsf/validating/mixing/mixin_Exception.h"


#include "jmsf/texting/String_literal.h"
#include "jmsf/validating/File_and_line.h"


#include <exception>

#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {


class JMSF_SHARED_INTERFACE Foreign_exception :
	public validating::mixing::mixin_Exception
{

public:
	// virtuals Exception
	const pointing::cWeak< texting::Ansii_text > get_exception_name() const noexcept override;
	const pointing::cWeak< texting::Ansii_text > get_exception_category() const noexcept override;
	const pointing::cWeak< texting::Ansii_text > get_exception_subsystem() const noexcept override;
	//~virtuals Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Exception
	~Foreign_exception() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Foreign_exception(
		const texting::String_literal &a_subsystem_name,
		const texting::String_literal &a_category_name,
		const texting::String_literal &a_reason,
		const validating::File_and_line &a_file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Foreign_exception( const Foreign_exception &another ) noexcept;
	const Foreign_exception &operator =( const Foreign_exception &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Foreign_exception( Foreign_exception &&another ) noexcept;
	Foreign_exception &operator =( Foreign_exception &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const pointing::cShared< texting::Ansii_text > _foreign_exception_name;
	const pointing::cShared< texting::Ansii_text > _foreign_exception_category;
	const pointing::cShared< texting::Ansii_text > _foreign_exception_subsystem;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace validating
} // namespace jmsf


#define JMSF_CATCH_FOREIGN_EXCEPTIONS( subsystem_name ) \
	catch ( const ::std::exception &an_std_exception ) { \
		throw \
			::jmsf::validating::Foreign_exception( \
				JMSF_SL( subsystem_name ), \
				JMSF_SL( "Standard" ), \
				JMSF_SL( an_std_exception.what() ), \
				JMSF_FILE_AND_LINE ); \
	} catch ( ... ) { \
		throw \
			::jmsf::validating::Foreign_exception( \
				JMSF_SL( subsystem_name ), \
				JMSF_SL( "Unknown" ), \
				JMSF_SL( "unknown" ), \
				JMSF_FILE_AND_LINE ); \
	}
