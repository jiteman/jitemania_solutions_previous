#pragma once

#include "Ansii_text.hxx"


#include "jmsf/memorying/Awamp.hpp"
#include "jmsf/typeing/internals/internal_types.h"

#include "Ansii_stream.hxx"
#include "Native_C_string.hxx"
#include "String_literal.hxx"
#include "jmsf/structing/containing/List.hxx"

//#include "jmsf/pointing/Constant_pointer.hxx"
#include "jmsf/pointing/cWeak.hxx"
#include "jmsf/pointing/cShared.hxx"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Amp.hxx"
#include "jmsf/memorying/Wamp.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/typeing/Naturals.hxx"
#include "jmsf/typeing/Boolean.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace texting {


// Seinsei: nextodo - create null objects, make proxiable
class JMSF_SHARED_INTERFACE Ansii_text {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;
	typeing::Memory_natural get_quantity() const noexcept;

	pointing::cShared< Native_C_string > get_as_native(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &native_c_string_allocator,
		const memorying::Womp< memorying::Allocator > &character_array_allocator ) const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean operator ==( const Ansii_text &another ) const noexcept;
	typeing::Boolean operator !=( const Ansii_text &another ) const noexcept;

public:
//	pointing::cShared< Ansii_text > to_ansii_text( const memorying::Womp< Ansii_allocating_assistor > &an_aaa ) const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< Ansii_text >;
	~Ansii_text() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Ansii_text, Ansii_text >;
	Ansii_text( const memorying::Amp< typeing::internals::platform_character > &character_array_memory_pointer ) noexcept;

public:
	static pointing::cShared< Ansii_text > create() noexcept;

	static pointing::cShared< Ansii_text > create_from_string_literal(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
		const memorying::Womp< memorying::Allocator > &character_array_allocator,
		const String_literal &string_literal );

	static pointing::cShared< Ansii_text > create_from_another(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
		const memorying::Womp< memorying::Allocator > &character_array_allocator,
		const pointing::cShared< Ansii_text > &another );

private: friend Ansii_stream;
	static pointing::cShared< Ansii_text > create_from_list(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
		const memorying::Womp< memorying::Allocator > &character_array_allocator,
		const structing::containing::List< pointing::cShared< Ansii_text > > &ansii_text_list );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Ansii_text( const Ansii_text &another ) noexcept;

private:
	const Ansii_text &operator =( const Ansii_text &another ) noexcept;

public:
	Ansii_text( Ansii_text &&another ) noexcept;

private:
	Ansii_text &operator =( Ansii_text && ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Awamp< typeing::internals::platform_character > _character_array_memory_pointer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static typeing::Memory_natural count_quantity_of_characters( const String_literal &string_literal ) noexcept;
	static typeing::Memory_natural count_total_size_of_texts( const structing::containing::List< pointing::cShared< Ansii_text > > &ansii_text_list );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace texting
} // namespace jmsf
