#pragma once

#include "jmsf/algorithming/Comparator.hpp"

#include "../Memory_block_descriptor.hxx"

#include "jmsf/typeing/Comparison_result.hxx"


namespace jmsf {
namespace memorying {
namespace allocating {
namespace comparing {


class Mbd_address_comparator :
	public algorithming::Comparator< Memory_block_descriptor >
{

public:
	// virtuals assisting::Comparator< Memory_block_descriptor >
	typeing::Comparison_result compare( const Memory_block_descriptor &first, const Memory_block_descriptor &second ) const override;
	//~virtuals assisting::Comparator< Memory_block_descriptor >

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual assisting::Comparator< Memory_block_descriptor >
	~Mbd_address_comparator() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Mbd_address_comparator() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Mbd_address_comparator( const Mbd_address_comparator &another ) noexcept;
	const Mbd_address_comparator &operator =( const Mbd_address_comparator &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace comparing
} // namespace allocating
} // namespace memorying
} // namespace jmsf
