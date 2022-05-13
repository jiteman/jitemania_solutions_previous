#pragma once


#include "Aso.hxx"


#include "Naturals.hxx"
#include "Boolean.hxx"


namespace jmsf {
namespace typeing {


// alignments
Memory_natural align_up( Memory_natural an_address, Memory_natural an_alignment ) noexcept;
Memory_natural align_down( Memory_natural an_address, Memory_natural an_alignment ) noexcept;
Memory_natural get_alignment_up_value( Memory_natural an_address, Memory_natural an_alignment ) noexcept;
Memory_natural get_alignment_down_value( Memory_natural an_address, Memory_natural an_alignment ) noexcept;
Boolean is_aligned( Memory_natural an_address, Memory_natural an_alignment ) noexcept;
Boolean is_not_aligned( Memory_natural an_address, Memory_natural an_alignment ) noexcept;
//~alignments


} // namespace typeing
} // namespace jmsf
