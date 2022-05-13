#include "Memory_block_descriptor.h"


#include "jmsf/typeing/Naturals.hin"


namespace jmsf {
namespace memorying {
namespace allocating {


// statics
// const typeing::ShortestNatural Memory_block_descriptor::type_empty_constant = typeing::ShortestNaturalZero;
// const typeing::ShortestNatural Memory_block_descriptor::type_empty_memory_constant = typeing::ShortestNaturalOne;
// const typeing::ShortestNatural Memory_block_descriptor::type_used_memory_constant = typeing::ShortestNaturalTwo;
//~statics


// typeing::ShortestNatural Memory_block_descriptor::get_type() const noexcept {
// 	return _type;
// }

typeing::Memory_natural Memory_block_descriptor::get_memory_block_address() const noexcept {
	return _memory_block_address;
}

typeing::Memory_natural Memory_block_descriptor::get_returned_address() const noexcept {
	return _returned_address;
}

// Memory_pointer Memory_block_descriptor::take_memory_block() noexcept {
// 	return _memory_block;
// }
//
// Memory_pointer Memory_block_descriptor::take_returned_address() noexcept {
// 	return _returned_address;
// }

typeing::Memory_natural Memory_block_descriptor::get_size() const noexcept {
	return _the_size;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// void Memory_block_descriptor::set_type( const typeing::ShortestNatural aType ) noexcept {
// 	_type = aType;
// }

// void Memory_block_descriptor::set_memory_block( const Memory_pointer memory_block ) noexcept {
// 	_memory_block = memory_block;
// }
//
// void Memory_block_descriptor::set_returned_address( const Memory_pointer returned_address ) noexcept {
// 	_returned_address = returned_address;
// }
void Memory_block_descriptor::set_memory_block_address( const typeing::Memory_natural memory_block_address ) noexcept {
	_memory_block_address = memory_block_address;
}

void Memory_block_descriptor::set_returned_address( const typeing::Memory_natural returned_address ) noexcept {
	_returned_address = returned_address;
}

void Memory_block_descriptor::set_size( typeing::Memory_natural a_size ) noexcept {
	_the_size = a_size;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Memory_block_descriptor::~Memory_block_descriptor() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memory_block_descriptor::Memory_block_descriptor() noexcept
{}

Memory_block_descriptor::Memory_block_descriptor( const typeing::Memory_natural memory_block_address, const typeing::Memory_natural returned_address, const typeing::Memory_natural a_size ) noexcept
	:
		_memory_block_address( memory_block_address ),
		_returned_address( returned_address ),
		_the_size( a_size )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memory_block_descriptor::Memory_block_descriptor( const Memory_block_descriptor &another ) noexcept
	:
		_memory_block_address( another._memory_block_address ),
		_returned_address( another._returned_address ),
		_the_size( another._the_size )
{}

const Memory_block_descriptor &Memory_block_descriptor::operator =( const Memory_block_descriptor &another ) noexcept {
	if ( &another == this ) return *this;

	_memory_block_address = another._memory_block_address;
	_returned_address = another._returned_address;
	_the_size = another._the_size;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace allocating
} // namespace memorying
} // namespace jmsf
