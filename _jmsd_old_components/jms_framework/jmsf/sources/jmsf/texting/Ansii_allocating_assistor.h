#pragma once

#include "Ansii_allocating_assistor.hxx"


#include "jmsf/memorying/Womp.hpp"

#include "Ansii_stream.hxx"
#include "Ansii_text.hxx"
#include "Native_C_string.hxx"
#include "String_literal.hxx"
#include "Ansii_constants.hxx"

//#include "jmsf/pointing/Pointer.hxx"
//#include "jmsf/pointing/Constant_pointer.hxx"
#include "jmsf/pointing/cWeak.hxx"
#include "jmsf/pointing/Shared.hxx"
#include "jmsf/pointing/cShared.hxx"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Allocator.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace texting {


class JMSF_SHARED_INTERFACE Ansii_allocating_assistor {

public:
	const pointing::cShared< texting::Ansii_text > create_ansii_text_from_string_literal(
		const texting::String_literal &string_literal ) const;

	// Seinsei: todonext - make decision about creating ansii_constants: it should be close to Singleton in context of current
	//	allocating assistor
	//	Should contain useful constant, like comma_and_space, brackets, etc.
//	const pointing::cShared< texting::Ansii_constants > create_ansii_constants() const;

	// Seinsei: todonext - make decision about use of this method
	//	Could be usefull to transfer text to another allocator, i.e. in multithreading environment
//	const pointing::cShared< texting::Ansii_text > create_ansii_text_from_another(
//		const pointing::cShared< texting::Ansii_text > &another_ansii_text ) const;

	const pointing::cShared< texting::Native_C_string > create_native_from_ansii_text(
		const pointing::cShared< texting::Ansii_text > & ansii_text ) const;

	const pointing::cShared< texting::Ansii_text > create_consolidated_ansii_text_from_stream(
		const pointing::Shared< texting::Ansii_stream > &ansii_stream ) const;

	const pointing::Shared< texting::Ansii_stream > create_ansii_stream() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Ansii_allocating_assistor() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Ansii_allocating_assistor, Ansii_allocating_assistor >;
	Ansii_allocating_assistor(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
		const memorying::Womp< memorying::Allocator > &ansii_stream_allocator,
		const memorying::Womp< memorying::Allocator > &native_C_string_allocator,
		const memorying::Womp< memorying::Allocator > &character_array_allocator,
		const memorying::Womp< memorying::Allocator > &constant_pointer_list_node_allocator) noexcept;

public:
	static memorying::Omp< Ansii_allocating_assistor > create(
		const memorying::Womp< memorying::Allocator > &ansii_allocating_assistor_allocator,
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &ansii_text_allocator,
		const memorying::Womp< memorying::Allocator > &ansii_stream_allocator,
		const memorying::Womp< memorying::Allocator > &native_C_string_allocator,
		const memorying::Womp< memorying::Allocator > &character_array_allocator,
		const memorying::Womp< memorying::Allocator > &constant_pointer_list_node_allocator );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Ansii_allocating_assistor( const Ansii_allocating_assistor &another ) noexcept;
	const Ansii_allocating_assistor &operator =( const Ansii_allocating_assistor &another ) noexcept;

	Ansii_allocating_assistor( Ansii_allocating_assistor &&another ) noexcept;
	Ansii_allocating_assistor &operator =( Ansii_allocating_assistor &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Womp< memorying::Allocator > _reference_counters_allocator;
	memorying::Womp< memorying::Allocator > _ansii_text_allocator;
	memorying::Womp< memorying::Allocator > _ansii_stream_allocator;
	memorying::Womp< memorying::Allocator > _native_C_string_allocator;
	memorying::Womp< memorying::Allocator > _character_array_allocator;
	memorying::Womp< memorying::Allocator > _constant_pointer_list_node_allocator;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace texting
} // namespace jmsf


namespace jmsf {
namespace texting {


// create [S]tring [L]iteral using [A]nsii [A]llocating [A]ssistor (or Ansii_allocating_assistor creates String_literal)
const pointing::cShared< texting::Ansii_text > JMSF_SHARED_INTERFACE Aaa_sl(
	const memorying::Womp< texting::Ansii_allocating_assistor > an_aaa,
	const String_literal &a_string_literal );

// create [C]onsolidated [S]tring using [A]nsii [A]llocating [A]ssistor (or Ansii_allocating_assistor creates consolidated string)
const pointing::cShared< texting::Ansii_text > JMSF_SHARED_INTERFACE Aaa_cs(
	const memorying::Womp< texting::Ansii_allocating_assistor > an_aaa,
	const pointing::Shared< texting::Ansii_stream > &an_ansii_stream );


} // namespace texting
} // namespace jmsf
