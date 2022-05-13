#include "Heap_status_descriptor.h"


#include "jmsf/typeing/Naturals.hin"


namespace jmsf {
namespace memorying {
namespace allocating {


typeing::Memory_natural Heap_status_descriptor::get_memory_heap_start() const noexcept {
	return _memory_heap_start;
}

typeing::Memory_natural Heap_status_descriptor::get_memory_heap_end() const noexcept {
	return _memory_heap_end;
}

typeing::Memory_natural Heap_status_descriptor::get_memory_heap_size() const noexcept {
	return ++( _memory_heap_end - _memory_heap_start );
}

typeing::Memory_natural Heap_status_descriptor::get_middle_block_start() const noexcept {
	return _middle_block_start;
}

typeing::Memory_natural Heap_status_descriptor::get_middle_block_end() const noexcept {
	return _middle_block_end;
}

typeing::Memory_natural Heap_status_descriptor::get_middle_block_size() const noexcept {
	return ++( _middle_block_end - _middle_block_start );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Heap_status_descriptor::set_middle_block_start( const typeing::Memory_natural an_address ) {
	_middle_block_start = an_address;
}

void Heap_status_descriptor::set_middle_block_end( const typeing::Memory_natural an_address ) {
	_middle_block_end = an_address;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Heap_status_descriptor::~Heap_status_descriptor() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Heap_status_descriptor::Heap_status_descriptor() noexcept
{}

Heap_status_descriptor::Heap_status_descriptor( const typeing::Memory_natural memory_heap_start, const typeing::Memory_natural memory_heap_size ) noexcept
	:
		_memory_heap_start( memory_heap_start ),
		_memory_heap_end( --( memory_heap_start + memory_heap_size ) ),
		_middle_block_start( memory_heap_start ),
		_middle_block_end( --( memory_heap_start + memory_heap_size ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Heap_status_descriptor::Heap_status_descriptor( const Heap_status_descriptor &another ) noexcept
	:
		_memory_heap_start( another._memory_heap_start ),
		_memory_heap_end( another._memory_heap_end ),
		_middle_block_start( another._middle_block_start ),
		_middle_block_end( another._middle_block_end )
{}

const Heap_status_descriptor &Heap_status_descriptor::operator =( const Heap_status_descriptor &another ) noexcept {
	if ( &another == this ) return *this;

	_memory_heap_start = another._memory_heap_start;
	_memory_heap_end = another._memory_heap_end;
	_middle_block_start = another._middle_block_start;
	_middle_block_end = another._middle_block_end;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace allocating
} // namespace memorying
} // namespace jmsf
