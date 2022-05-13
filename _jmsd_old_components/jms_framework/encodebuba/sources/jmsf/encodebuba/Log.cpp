#include "Log.h"


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


namespace jmsf {
namespace encodebuba {


// static
void Log::write(
	const char *const a_log_name,
	const char *const a_message,
	const char *const file_name,
	const size_t file_line ) noexcept
{
	// Seinsei: todonext - check parameters
	::std::stringstream char_stream;
	char_stream << a_message << " in " << file_name << " at " << file_line << ::std::endl;
	::std::ofstream error_log_file( ( ::std::string( a_log_name ) + ".log" ).c_str(), ( ::std::ios_base::out | ::std::ios_base::app ) );
	error_log_file << ::std::endl << char_stream.str();
}

// static
void Log::write(
	const char *const a_log_name,
	const char *const a_message,
	const char *const a_type,
	const char *const file_name,
	const size_t file_line ) noexcept
{
	// Seinsei: todonext - check parameters
	::std::stringstream char_stream;
	char_stream << a_message << " in " << file_name << " at " << file_line << " for " << a_type << ::std::endl;
	::std::ofstream error_log_file( ( ::std::string( a_log_name ) + ".log" ).c_str(), ( ::std::ios_base::out | ::std::ios_base::app ) );
	error_log_file << ::std::endl << char_stream.str();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Log::~Log() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Log::Log() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Log::Log( const Log &/*another*/ ) noexcept {
}

const Log &Log::operator =( const Log &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace encodebuba
} // namespace jmsf
