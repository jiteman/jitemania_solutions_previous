#pragma once

#include "native_Assertion.hxx"


#include "jmsf/typeing/Boolean.h"
#include "jmsf/validating/File_and_line.h"

#include "jmsf/texting/String_literal.hxx"


namespace jmsf {
namespace cule {
namespace asserting {


template< class A_type >
class native_Assertion {

public:
	void should_be() const;
	void should_not_be() const;

	void should_be_equal_to( const A_type &expected_value ) const;
	void should_not_be_equal_to( const A_type &undesirable_value ) const;

	void should_be_empty() const;
	void should_not_be_empty() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~native_Assertion() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	native_Assertion() noexcept;

	native_Assertion( const A_type &actual_value, const ::jmsf::validating::File_and_line &file_and_line ) noexcept;

public:
	static native_Assertion create( const A_type &actual_value, const ::jmsf::validating::File_and_line &file_and_line );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	native_Assertion( const native_Assertion &another ) noexcept = delete;
	native_Assertion &operator =( const native_Assertion &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	native_Assertion( native_Assertion &&another ) noexcept = default;

private:
	native_Assertion &operator =( native_Assertion &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const A_type &_actual_value;
	const ::jmsf::validating::File_and_line _file_and_line;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace asserting
} // namespace cule
} // namespace jmsf


namespace jmsf {
namespace cule {
namespace asserting {


template< class A_type >
native_Assertion< A_type > create_native_assertion( const A_type &actual_value, const ::jmsf::validating::File_and_line &file_and_line ) noexcept;


} // namespace asserting
} // namespace cule
} // namespace jmsf
