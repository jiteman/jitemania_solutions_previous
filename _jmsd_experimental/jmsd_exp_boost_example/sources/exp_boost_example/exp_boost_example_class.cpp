#include "exp_boost_example_class.h"


namespace jmsd {
namespace exp_executable {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
char const *Exp_executable_class::say_executable_hello() const noexcept {
	return "Exp_executable_class::say_executable_hello";
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Exp_executable_class::~Exp_executable_class() noexcept = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Exp_executable_class::Exp_executable_class() noexcept = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Exp_executable_class::Exp_executable_class( Exp_executable_class const &/*another*/ ) noexcept = default;

Exp_executable_class &Exp_executable_class::operator =( Exp_executable_class const &another ) noexcept = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Exp_executable_class::Exp_executable_class( Exp_executable_class &&/*another*/ ) noexcept = default;

Exp_executable_class &Exp_executable_class::operator =( Exp_executable_class &&another ) noexcept = default;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace exp_executable
} // namespace jmsd
