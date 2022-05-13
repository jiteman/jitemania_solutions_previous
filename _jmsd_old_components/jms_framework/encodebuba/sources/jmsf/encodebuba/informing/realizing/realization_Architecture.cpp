#include "realization_Architecture.h"

#include "jmsd/platform_support/platform_detection/architecture_detection.h"


namespace jmsf {
namespace encodebuba {
namespace informing {
namespace realizing {


bool realization_Architecture::is_detected() const noexcept {
	return _is_detected;
}

const ::std::string &realization_Architecture::get_name() const noexcept {
	return _name;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_Architecture::~realization_Architecture() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Architecture::realization_Architecture() noexcept
	:
		_name( JMSD_ARCHITECTURE_NAME )
{
	_is_detected = JMSD_ARCHITECTURE_DETECTION_IS_COMPLETED == JMSD_CPP_TRUE;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Architecture::realization_Architecture( const realization_Architecture & ) noexcept { // another
}

const realization_Architecture &realization_Architecture::operator =( const realization_Architecture &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace informing
} // namespace encodebuba
} // namespace jmsf
