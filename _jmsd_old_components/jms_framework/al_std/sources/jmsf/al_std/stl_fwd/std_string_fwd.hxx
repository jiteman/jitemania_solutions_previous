#pragma once

#include "std_memory_fwd.hxx"


namespace std {


template< class _CharT > struct char_traits;

template< typename _CharT, typename _Traits, typename _Alloc > class basic_string;

template<> struct char_traits< char >;

/// A string of @c char
typedef basic_string< char, char_traits< char >, allocator< char > > string;


} // namespace std
