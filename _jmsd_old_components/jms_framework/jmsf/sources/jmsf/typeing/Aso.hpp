#pragma once

#include "Aso.hxx"


#include "Naturals.hxx"
#include "Boolean.hxx"


namespace jmsf {
namespace typeing {


// alignments
template< class A_type >
Memory_natural alignment_of() noexcept;

// template< class A_type >
// Memory_natural alignment_of( const A_type & )noexcept;

template< class A_type >
Memory_natural align_up( Memory_natural an_address ) noexcept;

template< class A_type >
Memory_natural align_down( Memory_natural an_address ) noexcept;

template< class A_type >
Memory_natural get_alignment_up_value( Memory_natural an_address ) noexcept;

template< class A_type >
Memory_natural get_alignment_down_value( Memory_natural an_address ) noexcept;

template< class A_type >
Boolean is_aligned( Memory_natural an_address ) noexcept;

template< class A_type >
Boolean is_not_aligned( Memory_natural an_address ) noexcept;
//~alignments


// size of
template< class A_type >
Memory_natural size_of() noexcept;

template< class A_type >
Memory_natural size_of( const A_type & );
//~size of


// displacement of
template< class A_type, class A_creating_type >
Memory_natural displacement_of();
//~displacement of

// bits
template< class A_type >
Memory_natural bit_size_of() noexcept;

 template< class A_type >
 Memory_natural bit_size_of( const A_type & );
//~bits


} // namespace typeing
} // namespace jmsf
