#include "Ansii_allocating_assistor.h"


#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/Native_C_string.h"
#include "jmsf/texting/String_literal.h"

//#include "jmsf/pointing/Pointer.hin"
//#include "jmsf/pointing/Constant_pointer.hin"
#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/Shared.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/memorying/Allocator.h"

#include "jmsf/validating/macroses_Should.h"


namespace jmsf {
namespace texting {


const pointing::cShared< texting::Ansii_text > Ansii_allocating_assistor::create_ansii_text_from_string_literal(
	const texting::String_literal &string_literal ) const
{
	return
		texting::Ansii_text::create_from_string_literal(
			_reference_counters_allocator,
			_ansii_text_allocator,
			_character_array_allocator,
			string_literal );
}

//const pointing::cShared< texting::Ansii_text > Ansii_allocating_assistor::create_ansii_text_from_another(
//	const pointing::cShared< texting::Ansii_text > &another_ansii_text ) const
//{
//	return
//		texting::Ansii_text::create_from_another(
//			_reference_counters_allocator,
//			_ansii_text_allocator,
//			_character_array_allocator,
//			another_ansii_text );
//}

const pointing::cShared< texting::Native_C_string > Ansii_allocating_assistor::create_native_from_ansii_text(
	const pointing::cShared< texting::Ansii_text > &ansii_text ) const
{
	jmsf_Should_never_be_empty( ansii_text );

	return
		ansii_text->get_as_native(
			_reference_counters_allocator,
			_native_C_string_allocator,
			_character_array_allocator );
}


const pointing::cShared< texting::Ansii_text > Ansii_allocating_assistor::create_consolidated_ansii_text_from_stream(
		const pointing::Shared< texting::Ansii_stream > &ansii_stream ) const
{
	jmsf_Should_never_be_empty( ansii_stream );

	return
		ansii_stream->create_consolidated_ansii_text(
			_reference_counters_allocator,
			_ansii_text_allocator,
			_character_array_allocator );
}

const pointing::Shared< texting::Ansii_stream > Ansii_allocating_assistor::create_ansii_stream() const {
	return
		texting::Ansii_stream::create(
			_reference_counters_allocator,
			_ansii_stream_allocator,
			_reference_counters_allocator,
			_ansii_text_allocator,
			_character_array_allocator,
			_constant_pointer_list_node_allocator );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Ansii_allocating_assistor::~Ansii_allocating_assistor() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_allocating_assistor::Ansii_allocating_assistor(
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
	const memorying::Womp< memorying::Allocator > &ansii_stream_allocator,
	const memorying::Womp< memorying::Allocator > &native_C_string_allocator,
	const memorying::Womp< memorying::Allocator > &character_array_allocator,
	const memorying::Womp< memorying::Allocator > &constant_pointer_list_node_allocator ) noexcept
	:
		_reference_counters_allocator( reference_counters_allocator ),
		_ansii_text_allocator( ansii_text_allocator ),
		_ansii_stream_allocator( ansii_stream_allocator ),
		_native_C_string_allocator( native_C_string_allocator ),
		_character_array_allocator( character_array_allocator ),
		_constant_pointer_list_node_allocator( constant_pointer_list_node_allocator )
{}

// static
memorying::Omp< Ansii_allocating_assistor > Ansii_allocating_assistor::create(
	const memorying::Womp< memorying::Allocator > &ansii_allocating_assistor_allocator,
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
	const memorying::Womp< memorying::Allocator > &ansii_stream_allocator,
	const memorying::Womp< memorying::Allocator > &native_C_string_allocator,
	const memorying::Womp< memorying::Allocator > &character_array_allocator,
	const memorying::Womp< memorying::Allocator > &constant_pointer_list_node_allocator )
{
	jmsf_Should_never_be_empty( reference_counters_allocator );
	jmsf_Should_never_be_empty( ansii_text_allocator );
	jmsf_Should_never_be_empty( ansii_stream_allocator );
	jmsf_Should_never_be_empty( native_C_string_allocator );
	jmsf_Should_never_be_empty( character_array_allocator );
	jmsf_Should_never_be_empty( constant_pointer_list_node_allocator );

	return
		memorying::Constructor< Ansii_allocating_assistor, Ansii_allocating_assistor >::construct(
			ansii_allocating_assistor_allocator,
			reference_counters_allocator,
			ansii_text_allocator,
			ansii_stream_allocator,
			native_C_string_allocator,
			character_array_allocator,
			constant_pointer_list_node_allocator );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_allocating_assistor::Ansii_allocating_assistor( const Ansii_allocating_assistor &another ) noexcept
	:
		_reference_counters_allocator( another._reference_counters_allocator ),
		_ansii_text_allocator( another._ansii_text_allocator ),
		_ansii_stream_allocator( another._ansii_stream_allocator ),
		_native_C_string_allocator( another._native_C_string_allocator ),
		_character_array_allocator( another._character_array_allocator ),
		_constant_pointer_list_node_allocator( another._constant_pointer_list_node_allocator )
{}

const Ansii_allocating_assistor &Ansii_allocating_assistor::operator =( const Ansii_allocating_assistor &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	_reference_counters_allocator = another._reference_counters_allocator;
	_ansii_text_allocator = another._ansii_text_allocator;
	_ansii_stream_allocator = another._ansii_stream_allocator;
	_native_C_string_allocator = another._native_C_string_allocator;
	_character_array_allocator = another._character_array_allocator;
	_constant_pointer_list_node_allocator = another._constant_pointer_list_node_allocator;
	return *this;
}

Ansii_allocating_assistor::Ansii_allocating_assistor( Ansii_allocating_assistor &&another ) noexcept
	:
		_reference_counters_allocator( another._reference_counters_allocator ),
		_ansii_text_allocator( another._ansii_text_allocator ),
		_ansii_stream_allocator( another._ansii_stream_allocator ),
		_native_C_string_allocator( another._native_C_string_allocator ),
		_character_array_allocator( another._character_array_allocator ),
		_constant_pointer_list_node_allocator( another._constant_pointer_list_node_allocator )
{
	another._reference_counters_allocator = memorying::Womp< memorying::Allocator >();
	another._ansii_text_allocator = memorying::Womp< memorying::Allocator >();
	another._ansii_stream_allocator = memorying::Womp< memorying::Allocator >();
	another._native_C_string_allocator = memorying::Womp< memorying::Allocator >();
	another._character_array_allocator = memorying::Womp< memorying::Allocator >();
	another._constant_pointer_list_node_allocator = memorying::Womp< memorying::Allocator >();
}

Ansii_allocating_assistor &Ansii_allocating_assistor::operator =( Ansii_allocating_assistor &&another ) noexcept {
	if ( &another == this ) return *this;

	_reference_counters_allocator = another._reference_counters_allocator;
	_ansii_text_allocator = another._ansii_text_allocator;
	_ansii_stream_allocator = another._ansii_stream_allocator;
	_native_C_string_allocator = another._native_C_string_allocator;
	_character_array_allocator = another._character_array_allocator;
	_constant_pointer_list_node_allocator = another._constant_pointer_list_node_allocator;
	another._reference_counters_allocator = memorying::Womp< memorying::Allocator >();
	another._ansii_text_allocator = memorying::Womp< memorying::Allocator >();
	another._ansii_stream_allocator = memorying::Womp< memorying::Allocator >();
	another._native_C_string_allocator = memorying::Womp< memorying::Allocator >();
	another._character_array_allocator = memorying::Womp< memorying::Allocator >();
	another._constant_pointer_list_node_allocator = memorying::Womp< memorying::Allocator >();
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace texting
} // namespace jmsf


namespace jmsf {
namespace texting {


const pointing::cShared< texting::Ansii_text > Aaa_sl(
	const memorying::Womp< texting::Ansii_allocating_assistor > an_aaa,
	const String_literal &a_string_literal )
{
	jmsf_Should_never_be_empty( an_aaa );

	// Seinsei: todonext - decide to check a_string_literal for emptyness

	return an_aaa->create_ansii_text_from_string_literal( a_string_literal );
}

const pointing::cShared< texting::Ansii_text > Aaa_cs(
	const memorying::Womp< texting::Ansii_allocating_assistor > an_aaa,
	const pointing::Shared< texting::Ansii_stream > &an_ansii_stream )
{
	jmsf_Should_never_be_empty( an_aaa );
	jmsf_Should_never_be_empty( an_ansii_stream );

	return an_aaa->create_consolidated_ansii_text_from_stream( an_ansii_stream );
}


} // namespace texting
} // namespace jmsf
