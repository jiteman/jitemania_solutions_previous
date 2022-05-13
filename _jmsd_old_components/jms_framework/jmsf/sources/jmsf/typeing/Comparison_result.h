#pragma once

#include "Integers.hpp"
#include "Boolean.hxx"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace typeing {


class JMSF_SHARED_INTERFACE Comparison_result {

public:
	Boolean is_empty() const noexcept;
	Boolean is_not_empty() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean is_less() const noexcept;
	Boolean is_equal() const noexcept;
	Boolean is_greater() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean is_not_less() const noexcept; // equal or greater
	Boolean is_not_equal() const noexcept; // lower or greater
	Boolean is_not_greater() const noexcept; // equal or lower

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean operator ==( const Comparison_result &another ) const noexcept;
	Boolean operator !=( const Comparison_result &another ) const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Comparison_result() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Comparison_result() noexcept;

	template< class A_type >
	static Comparison_result create( const A_type &first, const A_type &second ) noexcept;

	static Comparison_result create_less() noexcept;
	static Comparison_result create_equal() noexcept;
	static Comparison_result create_greater() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Comparison_result( Integer a_value ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Comparison_result( const Comparison_result &another ) noexcept = default;
	Comparison_result &operator =( const Comparison_result &another ) noexcept = default;

	Comparison_result( Comparison_result &&another ) noexcept = default;
	Comparison_result &operator =( Comparison_result &&another ) noexcept = default;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Integer _the_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


// static
template< class A_type >
Comparison_result Comparison_result::create( const A_type &first, const A_type &second ) noexcept {
	if ( first < second ) return create_less();

	if ( first > second ) return create_greater();

	return create_equal();
}


} // namespace typeing
} // namespace jmsf
