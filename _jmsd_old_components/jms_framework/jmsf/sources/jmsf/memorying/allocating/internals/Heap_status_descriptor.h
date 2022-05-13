#pragma once


#include "jmsf/typeing/Naturals.hpp"


namespace jmsf {
namespace memorying {
namespace allocating {


class Heap_status_descriptor {

public:
	typeing::Memory_natural get_memory_heap_start() const noexcept;
	typeing::Memory_natural get_memory_heap_end() const noexcept;
	typeing::Memory_natural get_memory_heap_size() const noexcept;
	typeing::Memory_natural get_middle_block_start() const noexcept;
	typeing::Memory_natural get_middle_block_end() const noexcept;
	typeing::Memory_natural get_middle_block_size() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void set_middle_block_start( typeing::Memory_natural an_address );
	void set_middle_block_end( typeing::Memory_natural an_address );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Heap_status_descriptor() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Heap_status_descriptor() noexcept;

	Heap_status_descriptor( typeing::Memory_natural memory_heap_start, typeing::Memory_natural memory_heap_size ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Heap_status_descriptor( const Heap_status_descriptor &another ) noexcept;
	const Heap_status_descriptor &operator =( const Heap_status_descriptor &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typeing::Memory_natural _memory_heap_start;
	typeing::Memory_natural _memory_heap_end;
	typeing::Memory_natural _middle_block_start;
	typeing::Memory_natural _middle_block_end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace allocating
} // namespace memorying
} // namespace jmsf
