#pragma once

#include "String_literal.hxx"


#include "jmsf/typeing/internals/internal_types.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace texting {


class JMSF_SHARED_INTERFACE String_literal {

public:
	const typeing::internals::platform_character *get() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~String_literal() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	String_literal() noexcept;

private:
	String_literal( const typeing::internals::platform_character *c_string_literal ) noexcept;

public:
	static String_literal create( const typeing::internals::platform_character *c_string_literal ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	String_literal( const String_literal &another ) noexcept;
	const String_literal &operator =( const String_literal &another ) noexcept;

public:
	String_literal( String_literal &&another ) noexcept;
	String_literal &operator =( String_literal &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const typeing::internals::platform_character *_c_string_literal;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace texting
} // namespace jmsf
