#include "Mixin_parent.h"


#include "sensing_mipa/sensation_of_mipa_Construction_and_destruction.h"

#include "jmsf/pointing/Shared.hin"


namespace jmsf {
namespace memorying {
namespace testing_mipa {


int Mixin_parent::virtual_get_integer() const {
	return _integer;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Mixin_parent::~Mixin_parent() noexcept {
	_the_mixin_parent_sensor->register_mixin_destruction();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mixin_parent::Mixin_parent(
	const int integer,
	const pointing::Shared< sensing_mipa::sensation_of_mipa_Construction_and_destruction > &a_sensor ) noexcept
	:
		Virtual_parent( a_sensor ),
		_integer( integer ),
		_the_mixin_parent_sensor( a_sensor )
{
	_the_mixin_parent_sensor->register_mixin_construction();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mixin_parent::Mixin_parent( const Mixin_parent &another ) noexcept
	:
		Virtual_parent( another ),
		_integer( another._integer )
{}

const Mixin_parent &Mixin_parent::operator =( const Mixin_parent &another ) noexcept {
	if ( &another == this ) return *this;

	_integer = another._integer;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mixin_parent::Mixin_parent( Mixin_parent &&another ) noexcept
	:
		Virtual_parent( ::std::move( static_cast< Virtual_parent & >( another ) ) ),
		_integer( another._integer )
{
	another._integer = 0;
}

Mixin_parent &Mixin_parent::operator =( Mixin_parent &&another ) noexcept {
	if ( &another == this ) return *this;

	_integer = another._integer;
	another._integer = 0;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



} // namespace testing_mipa
} // namespace memorying
} // namespace jmsf
