#include "exp_sfml_derived_class.h"


namespace jmsd {
namespace exp_derived {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
char const *Exp_sfml_derived_class::say_derived_hello() const noexcept {
	return "Exp_sfml_derived_class::say_derived_hello";
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Exp_sfml_derived_class::~Exp_sfml_derived_class() noexcept = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Exp_sfml_derived_class::Exp_sfml_derived_class() noexcept = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Exp_sfml_derived_class::Exp_sfml_derived_class( Exp_sfml_derived_class const &/*another*/ ) noexcept = default;

Exp_sfml_derived_class &Exp_sfml_derived_class::operator =( Exp_sfml_derived_class const &another ) noexcept = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Exp_sfml_derived_class::Exp_sfml_derived_class( Exp_sfml_derived_class &&/*another*/ ) noexcept = default;

Exp_sfml_derived_class &Exp_sfml_derived_class::operator =( Exp_sfml_derived_class &&another ) noexcept = default;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace exp_derived
} // namespace jmsd
