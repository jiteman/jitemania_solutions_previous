#include "Mbd_size_fit_comparator.h"


#include "../Memory_block_descriptor.h"

#include "jmsf/algorithming/Comparator.hin"
#include "jmsf/typeing/Comparison_result.h"
#include "jmsf/typeing/Naturals.hin"
#include "jmsf/typeing/Boolean.h"

#include "jmsf/typeing/Aso.h"


namespace jmsf {
namespace memorying {
namespace allocating {
namespace comparing {


typeing::Comparison_result Mbd_size_fit_comparator::compare( const Memory_block_descriptor &first, const Memory_block_descriptor &second ) const {
	const typeing::Memory_natural address_of_the_block = second.get_memory_block_address();
	const typeing::Memory_natural size_of_the_block = second.get_size();
	const typeing::Memory_natural size_to_allocate = first.get_size();
	const typeing::Memory_natural an_alignment = first.get_returned_address(); // - first.get_memory_block_address();

	const typeing::Memory_natural new_start_address = typeing::align_up( address_of_the_block, an_alignment );
	const typeing::Memory_natural total_size_to_allocate = size_to_allocate + ( new_start_address - address_of_the_block );

	return typeing::Comparison_result::create( size_to_allocate, total_size_to_allocate );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Mbd_size_fit_comparator::~Mbd_size_fit_comparator() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mbd_size_fit_comparator::Mbd_size_fit_comparator() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mbd_size_fit_comparator::Mbd_size_fit_comparator( const Mbd_size_fit_comparator & ) noexcept { // another
}

const Mbd_size_fit_comparator &Mbd_size_fit_comparator::operator =( const Mbd_size_fit_comparator &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace comparing
} // namespace allocating
} // namespace memorying
} // namespace jmsf
