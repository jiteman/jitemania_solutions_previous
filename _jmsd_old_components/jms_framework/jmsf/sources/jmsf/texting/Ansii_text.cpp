#include "Ansii_text.h"


#include "Native_C_string.h"
#include "String_literal.h"
#include "jmsf/structing/containing/List.hin"
#include "jmsf/structing/traversing/List_traverser.hin"
#include "jmsf/memorying/Awamp.hin"

//#include "jmsf/pointing/Constant_pointer.hin"
#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Destructor.hin"
#include "jmsf/memorying/Awa_iterator.hin"
#include "jmsf/memorying/Amp.hin"
#include "jmsf/memorying/Wamp.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Allocator.h"
#include "jmsf/typeing/Naturals.hin"
#include "jmsf/typeing/Boolean.h"
#include "jmsf/typeing/internals/internal_types.h"

#include "jmsf/validating/macroses_Should.h"


namespace jmsf {
namespace texting {


typeing::Boolean Ansii_text::is_empty() const noexcept {
	return _character_array_memory_pointer.is_empty();
}

typeing::Boolean Ansii_text::is_not_empty() const noexcept {
	return _character_array_memory_pointer.is_not_empty();
}

typeing::Memory_natural Ansii_text::get_quantity() const noexcept {
	return _character_array_memory_pointer.get_wamp().get_quantity();
}

pointing::cShared< Native_C_string > Ansii_text::get_as_native(
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &native_c_string_allocator,
	const memorying::Womp< memorying::Allocator > &character_array_allocator ) const
{
	jmsf_Should_never_be_empty( reference_counters_allocator );
	jmsf_Should_never_be_empty( native_c_string_allocator );
	jmsf_Should_never_be_empty( character_array_allocator );
	jmsf_Should_never_be_empty( _character_array_memory_pointer );

	memorying::Amp< typeing::internals::platform_character > character_array =
		memorying::Constructor< typeing::internals::platform_character, typeing::internals::platform_character >::construct_default_as_array(
			character_array_allocator,
			_character_array_memory_pointer.get_wamp().get_quantity() + typeing::Memory_natural_one );

	{
		memorying::Awa_iterator< typeing::internals::platform_character > source = _character_array_memory_pointer.get_wamp().get();
		memorying::Awa_iterator< typeing::internals::platform_character > destination = character_array.take();

		for ( typeing::Memory_natural counter = _character_array_memory_pointer.get_wamp().get_quantity(); counter.is_not_nil(); --counter ) {
			*destination++ = *source++;
		}

//		*destination = '\0';
	}

	return
		Native_C_string::create(
			reference_counters_allocator,
			native_c_string_allocator,
			character_array );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
typeing::Boolean Ansii_text::operator ==( const Ansii_text &another ) const noexcept {
	if ( is_empty() && another.is_empty() ) return typeing::True;
	if ( is_empty() || another.is_empty() ) return typeing::False;

	if ( _character_array_memory_pointer.get_wamp().get_quantity() != another._character_array_memory_pointer.get_wamp().get_quantity() ) return typeing::False;

	memorying::Awa_iterator< typeing::internals::platform_character > this_character_array = _character_array_memory_pointer.get_wamp().get();
	memorying::Awa_iterator< typeing::internals::platform_character > another_character_array = another._character_array_memory_pointer.get_wamp().get();

	for ( typeing::Memory_natural quantity = _character_array_memory_pointer.get_wamp().get_quantity(); quantity.is_not_nil(); quantity -= typeing::Memory_natural_one ) {
		if ( *this_character_array++ != *another_character_array++ ) {
			return typeing::False;
		}
	}

	return typeing::True;
}

typeing::Boolean Ansii_text::operator !=( const Ansii_text &another ) const noexcept {
	return !( *this == another );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//pointing::cShared< Ansii_text > Ansii_text::to_ansii_text( const memorying::Womp< Ansii_allocating_assistor > &an_aaa ) const {
//	if ( is_empty() ) return pointing::cShared< Ansii_text >();

//	memorying::Amp< typeing::internals::platform_character > new_character_array_memory_pointer =
//		memorying::Constructor<	typeing::internals::platform_character, typeing::internals::platform_character >::construct_default_as_array(
//			jmsf_Allocators::instance()->get_character_array_allocator(),
//			get_quantity() );

//	{
//		memorying::Awa_iterator< typeing::internals::platform_character > source = _character_array_memory_pointer.get_wamp().get();
//		memorying::Awa_iterator< typeing::internals::platform_character > destination = new_character_array_memory_pointer.take();

//		for ( typeing::Memory_natural counter = new_character_array_memory_pointer.get_quantity(); counter.is_not_nill(); --counter ) {
//			*destination++ = *source++;
//		}
//	}

//	return
//		pointing::cShared< Ansii_text >::create(
//			jmsf_Allocators::instance()->get_reference_counters_allocator(),
//			memorying::Constructor< Ansii_text, Ansii_text >::construct(
//				jmsf_Allocators::instance()->get_subsystem_allocator(),
//				new_character_array_memory_pointer ) );
//}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Ansii_text::~Ansii_text() noexcept {
	memorying::Destructor< typeing::internals::platform_character >::destruct( _character_array_memory_pointer.get_amp() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_text::Ansii_text(  const memorying::Amp< typeing::internals::platform_character > &character_array_memory_pointer ) noexcept
	:
		_character_array_memory_pointer( memorying::Awamp< typeing::internals::platform_character >::create( character_array_memory_pointer ) )
{}

// static
pointing::cShared< Ansii_text > Ansii_text::create() noexcept {
	return pointing::cShared< Ansii_text >();
}

// static
pointing::cShared< Ansii_text > Ansii_text::create_from_string_literal(
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
	const memorying::Womp< memorying::Allocator > &character_array_allocator,
	const String_literal &string_literal )
{
	jmsf_Should_never_be_empty( reference_counters_allocator );
	jmsf_Should_never_be_empty( ansii_text_allocator );
	jmsf_Should_never_be_empty( character_array_allocator );

	const typeing::Memory_natural quantity_of_characters = Ansii_text::count_quantity_of_characters( string_literal );

	if ( quantity_of_characters.is_nil() ) return pointing::cShared< Ansii_text >();

	memorying::Amp< typeing::internals::platform_character > new_character_array_memory_pointer =
		memorying::Constructor<	typeing::internals::platform_character, typeing::internals::platform_character >::construct_default_as_array(
			character_array_allocator,
			quantity_of_characters );

	{
		const typeing::internals::platform_character *source = string_literal.get();
		memorying::Awa_iterator< typeing::internals::platform_character > destination = new_character_array_memory_pointer.take();

		for ( typeing::Memory_natural counter = new_character_array_memory_pointer.get_quantity(); counter.is_not_nil(); --counter ) {
			*destination++ = *source++;
		}
	}

	return
		pointing::cShared< Ansii_text >::create(
			reference_counters_allocator,
			memorying::Constructor< Ansii_text, Ansii_text >::construct(
				ansii_text_allocator,
				new_character_array_memory_pointer ) );
}

// static
pointing::cShared< Ansii_text > Ansii_text::create_from_another(
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
	const memorying::Womp< memorying::Allocator > &character_array_allocator,
	const pointing::cShared< Ansii_text > &another )
{
	jmsf_Should_never_be_empty( another );
	jmsf_Should_never_be_empty( another->_character_array_memory_pointer );
	jmsf_Should_never_be_empty( reference_counters_allocator );
	jmsf_Should_never_be_empty( ansii_text_allocator );
	jmsf_Should_never_be_empty( character_array_allocator );

	memorying::Amp< typeing::internals::platform_character > new_character_array_memory_pointer =
		memorying::Constructor<	typeing::internals::platform_character, typeing::internals::platform_character >::construct_default_as_array(
			character_array_allocator,
			another->_character_array_memory_pointer.get_wamp().get_quantity() );

	{
		memorying::Awa_iterator< typeing::internals::platform_character > source = another->_character_array_memory_pointer.get_wamp().get();
		memorying::Awa_iterator< typeing::internals::platform_character > destination = new_character_array_memory_pointer.take();

		for ( typeing::Memory_natural counter = new_character_array_memory_pointer.get_quantity(); counter.is_not_nil(); --counter ) {
			*destination++ = *source++;
		}
	}

	return
		pointing::cShared< Ansii_text >::create(
			reference_counters_allocator,
			memorying::Constructor< Ansii_text, Ansii_text >::construct(
				ansii_text_allocator,
				new_character_array_memory_pointer ) );
}

// static
pointing::cShared< Ansii_text > Ansii_text::create_from_list(
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
	const memorying::Womp< memorying::Allocator > &character_array_allocator,
	const structing::containing::List< pointing::cShared< Ansii_text > > &ansii_text_list )
{
	jmsf_Should_never_be( ansii_text_list.is_empty() );
//	typeing::Memory_natural total_count;

//	for (
//		auto list_traverser = ansii_text_list.create_traverser_at_begin();
//		list_traverser.is_not_done();
//		list_traverser.move_one_step_to_end() )
//	{
//		jmsf_Should_never_be_empty( list_traverser.get_object() ); // pointer
//		jmsf_Should_never_be_empty( list_traverser.get_object()->_character_array_memory_pointer ); // ansii_text
//		total_count += list_traverser.get_object()->get_quantity();
//	}

	jmsf_Should_never_be_empty( reference_counters_allocator );
	jmsf_Should_never_be_empty( ansii_text_allocator );
	jmsf_Should_never_be_empty( character_array_allocator );

	memorying::Amp< typeing::internals::platform_character > new_character_array_memory_pointer =
		memorying::Constructor<	typeing::internals::platform_character, typeing::internals::platform_character >::construct_default_as_array(
			character_array_allocator,
			/* total_count */ Ansii_text::count_total_size_of_texts( ansii_text_list ) );

	memorying::Awa_iterator< typeing::internals::platform_character > destination = new_character_array_memory_pointer.take();

	for (
		auto list_traverser = ansii_text_list.create_traverser_at_begin();
		list_traverser.is_not_done();
		list_traverser.move_one_step_to_end() )
	{
		memorying::Awa_iterator< typeing::internals::platform_character > source = list_traverser.get_object()->_character_array_memory_pointer.get_wamp().get();

		for ( typeing::Memory_natural counter = list_traverser.get_object()->get_quantity(); counter.is_not_nil(); --counter ) {
			*destination++ = *source++;
		}
	}

	return
		pointing::cShared< Ansii_text >::create(
			reference_counters_allocator,
			memorying::Constructor< Ansii_text, Ansii_text >::construct(
				ansii_text_allocator,
				new_character_array_memory_pointer ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_text::Ansii_text( const Ansii_text &another ) noexcept
	:
		_character_array_memory_pointer( another._character_array_memory_pointer )
{}

const Ansii_text &Ansii_text::operator =( const Ansii_text &another ) noexcept {
	if ( &another == this ) return *this;

	memorying::Destructor< typeing::internals::platform_character >::destruct( _character_array_memory_pointer.get_amp() );
	_character_array_memory_pointer = another._character_array_memory_pointer;
	return *this;
}

Ansii_text::Ansii_text( Ansii_text &&another ) noexcept
	:
		_character_array_memory_pointer( another._character_array_memory_pointer )
{
	another._character_array_memory_pointer = memorying::Awamp< typeing::internals::platform_character >();
}

Ansii_text &Ansii_text::operator =( Ansii_text &&another ) noexcept {
	if ( &another == this ) return *this;

	memorying::Destructor< typeing::internals::platform_character >::destruct( _character_array_memory_pointer.get_amp() );
	_character_array_memory_pointer = another._character_array_memory_pointer;
	another._character_array_memory_pointer = memorying::Awamp< typeing::internals::platform_character >();
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
typeing::Memory_natural Ansii_text::count_quantity_of_characters( const String_literal &string_literal ) noexcept {
	const typeing::internals::platform_character *pointer_to_characters = string_literal.get();
	typeing::Memory_natural quantity_of_characters;

	for ( ; *pointer_to_characters++ != '\0'; ++quantity_of_characters );

	return quantity_of_characters;
}

// static
typeing::Memory_natural Ansii_text::count_total_size_of_texts( const structing::containing::List< pointing::cShared< Ansii_text > > &ansii_text_list ) {
	jmsf_Should_never_be( ansii_text_list.is_empty() );
	typeing::Memory_natural total_count;

	for (
		auto list_traverser = ansii_text_list.create_traverser_at_begin();
		list_traverser.is_not_done();
		list_traverser.move_one_step_to_end() )
	{
		jmsf_Should_never_be_empty( list_traverser.get_object() ); // pointer
		jmsf_Should_never_be_empty( list_traverser.get_object()->_character_array_memory_pointer ); // ansii_text
		total_count += list_traverser.get_object()->get_quantity();
	}

	return total_count;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace texting
} // namespace jmsf
