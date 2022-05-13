#pragma once


#include "jmsf/memorying/Allocator.h"

#include "jmsf/memorying/Womp.hpp"
#include "jmsf/typeing/Naturals.hpp"

#include "Heap_status_descriptor.hxx"
#include "Pool_block_descriptor.hxx"
#include "Memory_block_descriptor.hxx"

#include "jmsf/memorying/Memory_address.hxx"

#include "jmsf/structing/noding/Doubly_linked_node.hxx"


namespace jmsf {
namespace memorying {
namespace allocating {


// Allocates fixed sized ( sizeof( A_type ) ) blocks on the top of heap downwards
template< class A_type >
class Top_pool_allocator :
	public Allocator 
{

public:
	// virtuals
	Memory_address allocate_memory( typeing::Memory_natural a_size, typeing::Memory_natural an_alignment );
	void deallocate_memory( const Memory_address &a_memory, typeing::Memory_natural an_alignment );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Top_pool_allocator() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Top_pool_allocator() noexcept;

	Top_pool_allocator( const memorying::Womp< Heap_status_descriptor > &heap_status_descriptor ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Top_pool_allocator( const Top_pool_allocator &another ) noexcept;
	const Top_pool_allocator &operator =( const Top_pool_allocator &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Womp< Heap_status_descriptor > _heap_status_descriptor;
	typeing::Memory_natural _quantity_of_pool_blocks_allocated;
	typeing::Memory_natural _aligned_heap_end_address;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	typeing::Memory_natural get_first_pool_block_address() noexcept;
	typeing::Memory_natural get_pool_block_address( typeing::Memory_natural pool_block_index ) noexcept;
	Memory_address get_empty_memory_block() noexcept;	
	Womp< Pool_block_descriptor< A_type > > take_pool_block_with_empty_memory_block() noexcept;
	Womp< Pool_block_descriptor< A_type > > create_new_pool_block() noexcept;
	void release_unused_pool_block_descriptors( const Womp< Pool_block_descriptor< A_type >  > &pool_block_descriptor, typeing::Memory_natural pool_block_address ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static A_type *get_empty_object_memory_block( Womp< Pool_block_descriptor< A_type > > &pool_block_descriptor ) noexcept;

};



} // namespace allocating
} // namespace memorying
} // namespace jmsf
