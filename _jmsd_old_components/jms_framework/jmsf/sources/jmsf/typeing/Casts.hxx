#pragma once


namespace jmsf {
namespace runtiming {


template< template< class A_proxy_type > class, class A_target_type, class A_source_type >
typename A_proxy_type< A_target_type > downcast( const typename A_proxy_type< A_source_type > &a_source_object ) {
	return
		typename A_proxy_type< A_target_type >::create( a_source_object );
}


template< class A_derived_type, class A_base_type_with_placeholder >
const pointing::ConstantPointer< A_derived_type > constantDowncast( const A_base_type_with_placeholder &baseObject, const pointing::ConstantProxy< texting::TextString > &typenames );

template< class A_derived_type, class A_base_type_with_placeholder >
pointing::Pointer< A_derived_type > downcast( A_base_type_with_placeholder &baseObject, const pointing::ConstantProxy< texting::TextString > &typenames );

template< class A_target_type, class A_source_type_with_placeholder >
const pointing::ConstantPointer< A_target_type > constantAdjacentCast( const A_source_type_with_placeholder &sourceObject );

template< class A_target_type, class A_base_type_with_placeholder >
pointing::Pointer< A_target_type > adjacentCast( A_base_type_with_placeholder sourceObject );


} // namespace runtiming
} // namespace jmsf
