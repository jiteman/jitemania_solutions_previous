#pragma once


#include "jmsf/algorithming/Comparator.hpp"

#include "../Memory_block_descriptor.hxx"
#include "jmsf/typeing/Comparison_result.hxx"


namespace jmsf {
namespace memorying {
namespace allocating {
namespace comparing {


class Mbd_size_comparator :
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
	~Mbd_size_comparator() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Mbd_size_comparator() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Mbd_size_comparator( const Mbd_size_comparator &another ) noexcept;
	const Mbd_size_comparator &operator =( const Mbd_size_comparator &another ) noexcept;

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
