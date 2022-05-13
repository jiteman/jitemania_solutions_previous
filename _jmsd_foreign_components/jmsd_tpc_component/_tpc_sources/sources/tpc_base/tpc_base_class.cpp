#include "tpc_base_class.h"


namespace jmsd {
namespace tpc_base {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
char const *Tpc_base_class::say_base_hello() const noexcept {
	return "Tpc_base_class::say_base_hello";
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Tpc_base_class::~Tpc_base_class() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Tpc_base_class::Tpc_base_class() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Tpc_base_class::Tpc_base_class( const Tpc_base_class &/*another*/ ) noexcept {
}

const Tpc_base_class &Tpc_base_class::operator =( const Tpc_base_class &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Tpc_base_class::Tpc_base_class( Tpc_base_class &&/*another*/ ) noexcept {
}

Tpc_base_class &Tpc_base_class::operator =( Tpc_base_class &&another ) noexcept {
	if ( &another == this ) return *this;

	// move
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace tpc_base
} // namespace jmsd
