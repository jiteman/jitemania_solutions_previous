#pragma once

#include "Native_C_string.hxx"


#include "jmsf/memorying/Awamp.hpp"

#include "jmsf/typeing/internals/internal_types.h"

//#include "jmsf/pointing/Constant_pointer.hxx"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Amp.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/typeing/Boolean.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace texting {


class JMSF_SHARED_INTERFACE Native_C_string {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;
	memorying::Awa_iterator< typeing::internals::platform_character > get() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< Native_C_string >;
	~Native_C_string() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Native_C_string() noexcept;

private: friend memorying::Constructor< Native_C_string, Native_C_string >;
	Native_C_string( const memorying::Amp< typeing::internals::platform_character > &character_array ) noexcept;

public:
	static const pointing::cShared< Native_C_string > create(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &native_c_string_allocator,
		const memorying::Amp< typeing::internals::platform_character > &character_array );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Native_C_string( const Native_C_string &another ) noexcept;
	const Native_C_string &operator =( const Native_C_string &another ) noexcept;

public:
	Native_C_string( Native_C_string &&another ) noexcept;
	Native_C_string &operator =( Native_C_string &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Awamp< typeing::internals::platform_character > _character_array;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace texting
} // namespace jmsf
