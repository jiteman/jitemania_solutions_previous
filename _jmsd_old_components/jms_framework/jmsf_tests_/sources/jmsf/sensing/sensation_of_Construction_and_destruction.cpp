#include "sensation_of_Construction_and_destruction.h"


#include "jmsf/typeing/Naturals.hin"


namespace jmsf {
namespace sensing {



void sensation_of_Construction_and_destruction::register_destruction() noexcept {
	_destruction_counter += typeing::Memory_natural_one;
}

void sensation_of_Construction_and_destruction::register_construction() noexcept {
	_the_construction_counter += typeing::Memory_natural_one;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
typeing::Memory_natural sensation_of_Construction_and_destruction::get_destrution_counter() const noexcept {
	return _destruction_counter;
}

typeing::Memory_natural sensation_of_Construction_and_destruction::get_construction_counter() const noexcept {
	return _the_construction_counter;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
sensation_of_Construction_and_destruction::~sensation_of_Construction_and_destruction() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
sensation_of_Construction_and_destruction::sensation_of_Construction_and_destruction() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//sencation_of_Construction_and_destruction::sencation_of_Construction_and_destruction() noexcept
//{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
sensation_of_Construction_and_destruction sensation_of_Construction_and_destruction::create() {
	return sensation_of_Construction_and_destruction();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
sensation_of_Construction_and_destruction::sensation_of_Construction_and_destruction( const sensation_of_Construction_and_destruction &/*another*/ ) noexcept {
}

const sensation_of_Construction_and_destruction &sensation_of_Construction_and_destruction::operator =( const sensation_of_Construction_and_destruction &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
sensation_of_Construction_and_destruction::sensation_of_Construction_and_destruction( sensation_of_Construction_and_destruction &&/*another*/ ) noexcept {
}

sensation_of_Construction_and_destruction &sensation_of_Construction_and_destruction::operator =( sensation_of_Construction_and_destruction &&another ) noexcept {
	if ( &another == this ) return *this;

	// move
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace sensing
} // namespace jmsf
