#pragma once

#include "File_and_line.hxx"


#include "jmsf/texting/String_literal.h"
#include "jmsf/typeing/Naturals.hpp"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {


// Seinsei: key idea - creating/using speed tradeoff - desided to use fast creation and slow using
// (storing as pointer to char, returning as Ansii_string
// reason - quantity of calls to validating::Should is maxed out, while using the contents of File_and_line
// happens in case of error only (several times)
class JMSF_SHARED_INTERFACE File_and_line {

public:
	const texting::String_literal &get_filename() const;
	typeing::Memory_natural get_line_number() const noexcept;
//	const typeing::internals::platform_character *get_debug_filename() const noexcept;
//	typeing::memory_natural_value_type get_debug_line_number() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~File_and_line() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	File_and_line() noexcept;

public:
	static File_and_line create( const texting::String_literal &a_filename, typeing::memory_natural_value_type line_number ) noexcept;

private:
	File_and_line( const texting::String_literal &a_filename, typeing::Memory_natural line_number ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	File_and_line( const File_and_line &other ) noexcept;

private:
	const File_and_line &operator =( const File_and_line &other ) noexcept;


public:
	File_and_line( File_and_line &&other ) noexcept;

private:
	File_and_line &operator =( File_and_line &&other ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
//	const typeing::internals::platform_character *_filename;
//	typeing::memory_natural_value_type _line_number;
	texting::String_literal _file_name;
	typeing::Memory_natural _line_number;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	static const typeing::internals::platform_character *const UNKNOWN_FILENAME;
	static const texting::String_literal UNKNOWN_FILENAME;

public:
	static const File_and_line EMPTY_FILE_AND_LINE; // optimization (for the case if we don't realy need file and line)

};


} // namespace debugging
} // namespace jmsf
