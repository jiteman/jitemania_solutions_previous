#pragma once


#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/memorying/Memory_address.h"


namespace jmsf {
namespace memorying {
namespace allocating {


// static const typeing::ShortestNatural MEMORY_BLOCK_TYPE_LIMIT = typeing::ShortestNatural::create( 3 );


class Memory_block_descriptor {

// public:
// 	static const typeing::ShortestNatural type_empty_constant;
// 	static const typeing::ShortestNatural type_empty_memory_constant;
// 	static const typeing::ShortestNatural type_used_memory_constant;

public:
	typeing::Memory_natural get_memory_block_address() const noexcept;
	typeing::Memory_natural get_returned_address() const noexcept;
//	typeing::ShortestNatural get_type() const noexcept;
// 	Memory_pointer take_memory_block() noexcept;
// 	Memory_pointer take_returned_address() noexcept;
	typeing::Memory_natural get_size() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	void set_type( typeing::ShortestNatural aType ) noexcept;
// 	void set_memory_block( Memory_pointer memoryBlock ) noexcept;
// 	void set_returned_address( Memory_pointer returnedAddress ) noexcept;
	void set_memory_block_address( typeing::Memory_natural memoryBlock ) noexcept;
	void set_returned_address( typeing::Memory_natural returnedAddress ) noexcept;
	void set_size( typeing::Memory_natural a_size ) noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Memory_block_descriptor() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_block_descriptor() noexcept;

	Memory_block_descriptor( typeing::Memory_natural memory_block_address, typeing::Memory_natural returned_address, typeing::Memory_natural a_size ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_block_descriptor( const Memory_block_descriptor &another ) noexcept;
	const Memory_block_descriptor &operator =( const Memory_block_descriptor &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
//	typeing::ShortestNatural _type;
//	Memory_pointer _memory_block;
//	Memory_pointer _returned_address;
	typeing::Memory_natural _memory_block_address;
	typeing::Memory_natural _returned_address;
	typeing::Memory_natural _the_size;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace allocating
} // namespace memorying
} // namespace jmsf
