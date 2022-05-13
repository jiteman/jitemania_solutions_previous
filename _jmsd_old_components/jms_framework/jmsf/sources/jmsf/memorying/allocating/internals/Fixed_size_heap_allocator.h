#pragma once


#include "jmsf/memorying/Allocator.h"

#include "jmsf/typeing/Naturals.hpp"

#include "Heap_status_descriptor.h"
#include "Top_pool_allocator.hpp"

#include "Memory_block_descriptor.hxx"
#include "jmsf/structing/noding/Doubly_linked_node.hxx"
#include "jmsf/structing/containing/List.hpp"


//#include "jmsf/encodebuba/common_suppress_compilation_warnings.h"


namespace jmsf {
namespace memorying {
namespace allocating {


//class Memory_block_descriptor;


// Maintains fixed size heap (used for stack allocated memory or as granularity member of variable size heap maintainer)
class Fixed_size_heap_allocator :
	public Allocator
{

public:
	// virtuals Allocator
	Memory_address allocate_memory( typeing::Memory_natural a_size, typeing::Memory_natural an_alignment );
	void deallocate_memory( const Memory_address &a_memory, typeing::Memory_natural an_alignment );
	//~virtuals Allocator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Allocator
	~Fixed_size_heap_allocator() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Fixed_size_heap_allocator( const Memory_address &memory_heap, typeing::Memory_natural heap_size );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Fixed_size_heap_allocator( const Fixed_size_heap_allocator &another ) noexcept;
	const Fixed_size_heap_allocator &operator =( const Fixed_size_heap_allocator &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Heap_status_descriptor _heap_status_descriptor;
	Top_pool_allocator< structing::noding::Doubly_linked_node< Memory_block_descriptor > > _list_nodes_allocator;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	structing::containing::List< Memory_block_descriptor > _empty_memory_list_sorted_by_address;
	structing::containing::List< Memory_block_descriptor > _empty_memory_list_sorted_by_size;
	structing::containing::List< Memory_block_descriptor > _used_memory_list; // sorted by address

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Memory_address try_to_allocate_memory( typeing::Memory_natural size_to_allocate, typeing::Memory_natural an_alignment ) noexcept;
	void consolidate_and_add( const Memory_block_descriptor &new_empty_memory_block ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static typeing::Boolean isFit( typeing::Memory_natural address_of_the_block, typeing::Memory_natural size_of_the_block, typeing::Memory_natural size_to_allocate, typeing::Memory_natural an_alignment ) noexcept;

};


} // namespace allocating
} // namespace memorying
} // namespace jmsf
