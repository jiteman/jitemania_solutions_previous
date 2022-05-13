#pragma once


#include "Naturals.hxx"
#include "Boolean.hxx"


namespace jmsf {
namespace typeing {


template< class A_type >
class Bitwise {

public:
	A_type get_bits( Memory_natural source_start_bit, Memory_natural a_quantity ) const;
	Bitwise &set_bits( Memory_natural destination_start_bit, Memory_natural a_quantity );
	Bitwise &reset_bits( Memory_natural destination_start_bit, Memory_natural a_quantity );

	Bitwise &copy_bits_from( Memory_natural destination_start_bit, A_type a_value, Memory_natural source_start_bit, Memory_natural a_quantity );

	Boolean is_set( Memory_natural bit_index ) const;
	Bitwise &set( Memory_natural bit_index );
	Boolean is_reset( Memory_natural bit_index ) const;
	Bitwise &reset( Memory_natural bit_index );
	Boolean get_status( Memory_natural bit_index ) const;
	Bitwise &set_status( Memory_natural bit_index, Boolean a_status ) const;

	Memory_natural get_first_set_bit_index() const noexcept;
	Memory_natural get_last_set_bit_index() const noexcept;
	Memory_natural get_first_reset_bit_index() const noexcept;
	Memory_natural get_last_reset_bit_index() const noexcept;

	Memory_natural get_quantity_of_bits() const noexcept;

	Bitwise &clear() noexcept;
	Bitwise &fill() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_type get_value() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Bitwise() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Bitwise() noexcept;
	static Bitwise create( A_type a_value ) noexcept;

private:
	Bitwise( A_type a_value ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Bitwise( const Bitwise &another ) noexcept;
	const Bitwise &operator =( const Bitwise &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _the_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static Boolean isInRange( Memory_natural start_bit_index, Memory_natural a_qiantity ) noexcept;
	static A_type create_value_mask( Memory_natural a_quantity ) noexcept;
	static A_type create_bit_mask_from_value_mask( A_type a_value, Memory_natural start_bit_index ) noexcept;
};


} // namespace typeing
} // namespace jmsf
