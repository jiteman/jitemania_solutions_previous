#include "realization_Operating_system.h"

#include "jmsd/platform_support/platform_detection/operating_system_information.h"


namespace jmsf {
namespace encodebuba {
namespace informing {
namespace realizing {


// bool realization_Operating_system::is_detected() const noexcept {
// 	return _is_detected;
// }

const ::std::string &realization_Operating_system::get_name() const noexcept {
	return _name;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_Operating_system::~realization_Operating_system() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Operating_system::realization_Operating_system() noexcept
	:
		_name( JMSD_OPERATING_SYSTEM_NAME )
{
//	_is_detected = JMSF_OPERATING_SYSTEM_DETECTION_IS_COMPLETED == JMSF_CPP_TRUE;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Operating_system::realization_Operating_system( const realization_Operating_system & ) noexcept { // another
}

const realization_Operating_system &realization_Operating_system::operator =( const realization_Operating_system &another ) noexcept {
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
