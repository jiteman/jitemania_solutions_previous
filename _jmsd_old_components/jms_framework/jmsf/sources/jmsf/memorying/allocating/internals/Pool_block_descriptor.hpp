#pragma once


#include "jmsf/typeing/Naturals.hpp"
#include "jmsf/typeing/internals/internal_types.h"

#include "jmsf/typeing/Bitwise.hxx"


namespace jmsf {
namespace memorying {
namespace allocating {


template< class A_type >
class Pool_block_descriptor {

	static const typeing::memory_natural_value_type _object_memory_block_quantity_constant = 8 * sizeof( typeing::memory_natural_value_type ); // typeing::MAXIMUM_INTEGRAL_BIT_SIZE;
	static const typeing::Memory_natural _block_size;
// #if defined( JMSF_64 )
// 		64;
// #elif defined( JMSF_32 )
// 		32;
// #else
// 	#error Pool_block_descriptor.h - neither of JMSF_32 or JMSF_64 is defined
// #endif

public:
//	typeing::Memory_natural get_usage_indicator() const noexcept;
	typeing::Memory_natural get_first_free_index() const noexcept;
	typeing::Boolean is_not_used() const noexcept;
	typeing::Boolean is_not_full() const noexcept;
	typeing::Boolean is_used( typeing::Memory_natural object_memory_block_index ) const;
	typeing::Boolean is_free( typeing::Memory_natural object_memory_block_index ) const;
	const A_type *get_object_memory_block_by( typeing::Shortest_natural object_memory_block_index ) const noexcept;
	typeing::Memory_natural get_object_memory_block_index( const A_type *object_memory_block ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	void set_usage_indicator( typeing::Memory_natural using_indicator ) noexcept;
	void set_as_used( typeing::Memory_natural object_memory_block_index );
	void set_as_free( typeing::Memory_natural object_memory_block_index );
	A_type *take_object_memory_block_by( typeing::Memory_natural object_memory_block_index ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static typeing::Memory_natural get_max_quantity_of_desctriptors() noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Pool_block_descriptor() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pool_block_descriptor() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pool_block_descriptor( const Pool_block_descriptor &another ) noexcept;
	const Pool_block_descriptor &operator =( const Pool_block_descriptor &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typeing::Memory_natural _usage_indicator;

	A_type _object_memory_blocks[ _object_memory_block_quantity_constant ];

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	typeing::Bitwise< typeing::Memory_natural > get_bitwise_usage_indicator() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:


};


} // namespace allocating
} // namespace memorying
} // namespace jmsf
