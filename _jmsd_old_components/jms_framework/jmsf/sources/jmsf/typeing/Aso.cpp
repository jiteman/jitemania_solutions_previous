#include "Aso.h"

#include "Naturals.hin"


namespace jmsf {
namespace typeing {


//~alignment
Memory_natural align_up( const Memory_natural an_address, const Memory_natural an_alignment ) noexcept {
	const Memory_natural the_alignment = an_alignment - Memory_natural_one;
	return ( an_address + the_alignment ) & ~the_alignment;
}

Memory_natural align_down( const Memory_natural an_address, const Memory_natural an_alignment ) noexcept {
	const Memory_natural the_alignment = an_alignment - Memory_natural_one;
	return an_address & ~the_alignment;
}

Memory_natural get_alignment_up_value( const Memory_natural an_address, const Memory_natural an_alignment ) noexcept {
	return align_up( an_address, an_alignment ) - an_address;
}

Memory_natural get_alignment_down_value( const Memory_natural an_address, const Memory_natural an_alignment ) noexcept {
	return an_address - align_down( an_address, an_alignment );
}

Boolean is_aligned( const Memory_natural an_address, const Memory_natural an_alignment ) noexcept {
	return ( an_address & ( an_alignment - Memory_natural_one ) ).is_nil();
}

Boolean is_not_aligned( const Memory_natural an_address, const Memory_natural an_alignment ) noexcept {
	return ( an_address & ( an_alignment - Memory_natural_one ) ).is_not_nil();
}
//~alignment


} // namespace typeing
} // namespace jmsf
