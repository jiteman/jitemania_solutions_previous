#pragma once

#include "Imprecise_find_result.hxx"


namespace jmsf {
namespace algorithming {


template< class A_type >
class Imprecise_find_result {

public:
	const A_type &get_maximum_less() const noexcept;
	const A_type &get_minimum_greater() const noexcept;
	const A_type &get_exact() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void set_maximum_less( const A_type &an_object );
	void set_minimum_greater( const A_type &an_object );
	void set_exact( const A_type &an_object );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Imprecise_find_result() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Imprecise_find_result() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Imprecise_find_result( const Imprecise_find_result &another ) noexcept = default;
	Imprecise_find_result &operator =( const Imprecise_find_result &another ) noexcept = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Imprecise_find_result( Imprecise_find_result &&another ) noexcept = default;
	Imprecise_find_result &operator =( Imprecise_find_result &&another ) noexcept = default;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _maximum_less;
	A_type _minimum_greater;
	A_type _exact;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace algorithming
} // namespace jmsf
