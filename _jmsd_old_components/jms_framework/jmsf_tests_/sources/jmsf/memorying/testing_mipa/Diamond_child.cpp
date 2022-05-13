#include "Diamond_child.h"


#include "Template_parent.hin"

#include "sensing_mipa/sensation_of_mipa_Construction_and_destruction.h"

#include "jmsf/pointing/Shared.hin"

#include <utility>


namespace jmsf {
namespace memorying {
namespace testing_mipa {


int Diamond_child::interface_get_integer_sum() const {
	return virtual_get_integer() + _another_integer + template_get_integer();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int Diamond_child::mixin_get_another_integer() const {
	return _another_integer;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Diamond_child::~Diamond_child() noexcept {
	_the_diamond_child_sensor->register_diamond_destruction();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Diamond_child::Diamond_child(
	const int integer,
	const int another_integer,
	const int template_integer,
	const pointing::Shared< sensing_mipa::sensation_of_mipa_Construction_and_destruction > &a_sensor ) noexcept
	:
		Mixin_parent( integer, a_sensor ),
		Interface_parent( template_integer, a_sensor ),
		Virtual_parent( a_sensor ),
		_another_integer( another_integer ),
		_the_diamond_child_sensor( a_sensor )
{
	_the_diamond_child_sensor->register_diamond_construction();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Diamond_child::Diamond_child( const Diamond_child &another ) noexcept
	:
		Mixin_parent( another ),
		Interface_parent( another ),
		Virtual_parent( another ),
		_another_integer( another._another_integer )
{}

const Diamond_child &Diamond_child::operator =( const Diamond_child &another ) noexcept {
	if ( &another == this ) return *this;

	Mixin_parent::operator =( another );
	_another_integer = another._another_integer;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Diamond_child::Diamond_child( Diamond_child &&another ) noexcept
	:
		Mixin_parent( ::std::move( static_cast< Mixin_parent & >( another ) ) ),
		Interface_parent( ::std::move( static_cast< Interface_parent & >( another ) ) ),
		Virtual_parent( ::std::move( static_cast< Virtual_parent & >( another ) ) ),
		_another_integer( another._another_integer )
{
	_another_integer = 0;
}

Diamond_child &Diamond_child::operator =( Diamond_child &&another ) noexcept {
	if ( &another == this ) return *this;

	Mixin_parent::operator =( another );
	_another_integer = another._another_integer;
	another._another_integer = 0;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



} // namespace testing_mipa
} // namespace memorying
} // namespace jmsf
