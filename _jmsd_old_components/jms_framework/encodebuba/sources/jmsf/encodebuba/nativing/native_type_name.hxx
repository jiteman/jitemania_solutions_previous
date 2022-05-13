#pragma once


#include <cstddef>


namespace jmsf {
namespace encodebuba {
namespace nativing {


template< class A_type >
const char *get_type_name_literal() noexcept;

template< class A_type >
const char *get_type_name_literal( const A_type &type_object ) noexcept;

template< class A_type >
size_t get_type_identifier() noexcept;

template< class A_type >
size_t get_type_identifier( const A_type &type_object ) noexcept;


} // namespace nativing
} // namespace encodebuba
} // namespace jmsf
