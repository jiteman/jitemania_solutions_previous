#pragma once


namespace std {


template< typename > class allocator;

template<> class allocator< void >;

// Declare uses_allocator so it can be specialized in <queue> etc.
template< typename, typename > struct uses_allocator;


template< typename > class shared_ptr;
template< typename > class weak_ptr;


} // namespace std
