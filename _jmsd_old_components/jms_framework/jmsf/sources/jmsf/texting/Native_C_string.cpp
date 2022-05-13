#include "Native_C_string.h"


//#include "jmsf/pointing/Constant_pointer.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Awamp.hin"
#include "jmsf/memorying/Amp.hin"
#include "jmsf/memorying/Awa_iterator.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/memorying/Allocator.h"
#include "jmsf/typeing/Naturals.hin"
#include "jmsf/typeing/Boolean.h"


namespace jmsf {
namespace texting {


typeing::Boolean Native_C_string::is_empty() const noexcept {
	return _character_array.is_empty();
}

typeing::Boolean Native_C_string::is_not_empty() const noexcept {
	return _character_array.is_not_empty();
}

memorying::Awa_iterator< typeing::internals::platform_character > Native_C_string::get() const {
	return _character_array.get_wamp().get();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Native_C_string::~Native_C_string() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Native_C_string::Native_C_string() noexcept
{}

Native_C_string::Native_C_string( const memorying::Amp< typeing::internals::platform_character > &character_array ) noexcept
	:
		_character_array( memorying::Awamp< typeing::internals::platform_character >::create( character_array ) )
{}

// static
const pointing::cShared< Native_C_string > Native_C_string::create(
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &native_c_string_allocator,
	const memorying::Amp< typeing::internals::platform_character > &character_array )
{
	return
		pointing::cShared< Native_C_string >::create(
			reference_counters_allocator,
			memorying::Constructor< Native_C_string, Native_C_string >::construct(
				native_c_string_allocator,
				character_array ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Native_C_string::Native_C_string( const Native_C_string &/*another*/ ) noexcept {
}

const Native_C_string &Native_C_string::operator =( const Native_C_string &another ) noexcept {
	if ( &another == this ) return *this;

	return *this;
}

Native_C_string::Native_C_string( Native_C_string &&another ) noexcept
	:
		_character_array( another._character_array )
{
	another._character_array = memorying::Awamp< typeing::internals::platform_character >();
}

Native_C_string &Native_C_string::operator =( Native_C_string &&another ) noexcept {
	if ( &another == this ) return *this;

	_character_array = another._character_array;
	another._character_array = memorying::Awamp< typeing::internals::platform_character >();
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace texting
} // namespace jmsf

