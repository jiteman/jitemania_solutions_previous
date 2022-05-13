#include "FSHA_list_allocator.h"


#include "Fixed_size_heap_allocator.h"
#include "Memory_block_descriptor.h"

#include "jmsf/structing/containing/List.hin"
#include "jmsf/structing/traversing/List_traverser.hin"



namespace jmsf {
namespace memorying {
namespace allocating {


Memory_address FSHA_list_allocator::allocate_memory( const typeing::Memory_natural a_size, const typeing::Memory_natural an_alignment ) {
	if ( a_size.is_nil() ) {
		return Memory_address();
	}

	Memory_address result_memory_pointer;

	if ( _last_successfull_allocator.is_not_done() ) {
		// try to find enough amount of memory with last used allocator
		result_memory_pointer = _last_successfull_allocator.take_object().allocate_memory( a_size, an_alignment );
	}

	if ( result_memory_pointer.is_empty() ) {
		// try to find enough amount of memory with other allocators

		for (
			structing::traversing::List_traverser< Fixed_size_heap_allocator > list_traverser = _fsha_list.create_traverser_at_begin();
			list_traverser.is_not_done();
			list_traverser.move_one_step_to_end() )
		{
			// skip last successfull allocator
			if ( &_last_successfull_allocator.get_object() == &list_traverser.get_object() ) continue;

			result_memory_pointer = list_traverser.take_object().allocate_memory( a_size, an_alignment );

			if ( result_memory_pointer.is_not_empty() ) {
				_last_successfull_allocator = list_traverser;
				break;
			}
		}
	}

	return result_memory_pointer;
}

void FSHA_list_allocator::deallocate_memory( const Memory_address &/*a_memory*/, const typeing::Memory_natural /*an_alignment*/ ) {

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
FSHA_list_allocator::~FSHA_list_allocator() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
FSHA_list_allocator::FSHA_list_allocator() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
FSHA_list_allocator::FSHA_list_allocator( const FSHA_list_allocator & ) noexcept { // another
}

const FSHA_list_allocator &FSHA_list_allocator::operator =( const FSHA_list_allocator &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace allocating
} // namespace memorying
} // namespace jmsf
