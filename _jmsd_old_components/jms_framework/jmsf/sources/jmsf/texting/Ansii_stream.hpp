#pragma once

#include "Ansii_stream.hxx"


#include "jmsf/structing/containing/List.hpp"
#include "jmsf/memorying/Womp.hpp"
#include "jmsf/typeing/Naturals.hpp"

#include "Ansii_text.hxx"

//#include "jmsf/pointing/Constant_pointer.hxx"
//#include "jmsf/pointing/Pointer.hxx"
#include "jmsf/pointing/Shared.hxx"
#include "jmsf/pointing/cShared.hxx"
#include "jmsf/pointing/cWeak.hxx"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/typeing/Integers.hxx"
#include "jmsf/typeing/Reals.hxx"
#include "jmsf/typeing/Boolean.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace texting {


// Seinsei: todonext - remove "new/delete" for temporary buffer, use (add) allocator for this reason (stack allocator, for example)
class JMSF_SHARED_INTERFACE Ansii_stream {

public:
	void put( const pointing::cShared< Ansii_text > &ansii_text );

	void put( typeing::Boolean a_boolean );

	template< class A_typeing_type, int dummy >
	void put( typeing::Naturals< A_typeing_type, dummy > natural );

	template< class A_typeing_type, int dummy >
	void put( typeing::Naturals< A_typeing_type, dummy > natural, typeing::Boolean as_hexadecimal );

	template< class A_typeing_type, int dummy >
	void put( typeing::Integers< A_typeing_type, dummy > integer );

	template< class A_typeing_type, int dummy >
	void put( typeing::Reals< A_typeing_type, dummy > real );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const pointing::cShared< Ansii_text > create_consolidated_ansii_text(
		const memorying::Womp< memorying::Allocator > &ansii_text_reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
		const memorying::Womp< memorying::Allocator > &character_array_allocator ) const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< Ansii_stream >;
	~Ansii_stream() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Ansii_stream, Ansii_stream >;
	Ansii_stream(
		const memorying::Womp< memorying::Allocator > &ansii_text_reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
		const memorying::Womp< memorying::Allocator > &character_array_allocator,
		const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexcept;

public:
	static pointing::Shared< Ansii_stream > create(
		const memorying::Womp< memorying::Allocator > &ansii_stream_reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &ansii_stream_allocator,
		const memorying::Womp< memorying::Allocator > &ansii_text_reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
		const memorying::Womp< memorying::Allocator > &character_array_allocator,
		const memorying::Womp< memorying::Allocator > &list_node_allocator );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Ansii_stream( const Ansii_stream &another ) noexcept;
	const Ansii_stream &operator =( const Ansii_stream &another ) noexcept;

	Ansii_stream( Ansii_stream &&another ) noexcept;
	Ansii_stream &operator =( Ansii_stream &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Womp< memorying::Allocator > _reference_counters_allocator;
	memorying::Womp< memorying::Allocator > _ansii_text_allocator;
	memorying::Womp< memorying::Allocator > _character_array_allocator;
	memorying::Womp< memorying::Allocator > _list_node_allocator;
	structing::containing::List< pointing::cShared< Ansii_text > > _ansii_text_list;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	const pointing::cShared< Ansii_text > create_boolean( typeing::Boolean a_boolean );
	const pointing::cShared< Ansii_text > create_natural_1( typeing::shortest_fast_natural_value_type shortest_natural, typeing::Boolean as_hexadecimal );
	const pointing::cShared< Ansii_text > create_natural_2( typeing::short_fast_natural_value_type short_natural, typeing::Boolean as_hexadecimal );
	const pointing::cShared< Ansii_text > create_natural_4( typeing::fast_natural_value_type natural, typeing::Boolean as_hexadecimal );
	const pointing::cShared< Ansii_text > create_natural_8( typeing::long_fast_natural_value_type long_natural, typeing::Boolean as_hexadecimal );
	const pointing::cShared< Ansii_text > create_integer_1( typeing::shortest_fast_integer_value_type shortest_integer );
	const pointing::cShared< Ansii_text > create_integer_2( typeing::short_fast_integer_value_type short_integer );
	const pointing::cShared< Ansii_text > create_integer_4( typeing::fast_integer_value_type integer );
	const pointing::cShared< Ansii_text > create_integer_8( typeing::long_fast_integer_value_type long_integer );
	const pointing::cShared< Ansii_text > create_real_4( typeing::short_real_value_type short_real );
	const pointing::cShared< Ansii_text > create_real_8( typeing::real_value_type real );
	const pointing::cShared< Ansii_text > create_real_12( typeing::long_real_value_type long_real );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const typeing::Memory_natural BUFFER_SIZE;

};


} // namespace texting
} // namespace jmsf


#include "jmsf/typeing/Integers.hpp"
#include "jmsf/typeing/Reals.hpp"


namespace jmsf {
namespace texting {


void JMSF_SHARED_INTERFACE put_text_to_stream_from_native(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	typeing::Boolean::my_boolean_integral_type a_boolean_value );

void JMSF_SHARED_INTERFACE put_text_to_stream_from_native(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	typeing::Memory_integer::my_integer_integral_type a_natural_value );

void JMSF_SHARED_INTERFACE put_text_to_stream_from_native(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	typeing::Memory_natural::my_natural_integral_type a_natural_value );

void JMSF_SHARED_INTERFACE put_text_to_stream_from_native(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	typeing::Long_real::my_real_integral_type a_real_value );


void JMSF_SHARED_INTERFACE put_text_to_stream_from_native_boolean(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	typeing::Boolean::my_boolean_integral_type a_boolean_value );

void JMSF_SHARED_INTERFACE put_text_to_stream_from_native_integer(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	typeing::Memory_integer::my_integer_integral_type a_natural_value );

void JMSF_SHARED_INTERFACE put_text_to_stream_from_native_natural(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	typeing::Memory_natural::my_natural_integral_type a_natural_value );

void JMSF_SHARED_INTERFACE put_text_to_stream_from_native_real(
	pointing::Shared< Ansii_stream > &an_out_ansii_stream,
	typeing::Long_real::my_real_integral_type a_real_value );


} // namespace texting
} // namespace jmsf
