#include "realization_Memory_model.h"

#include "jmsd/platform_support/platform_detection/memory_model_detection.h"

#include <sstream>


namespace jmsf {
namespace encodebuba {
namespace informing {
namespace realizing {


bool realization_Memory_model::is_detected() const noexcept {
	return _is_detected;
}

const ::std::string &realization_Memory_model::get_name() const noexcept {
	return _name;
}

const ::std::string &realization_Memory_model::get_test_result() const noexcept {
	return _test_result;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_Memory_model::~realization_Memory_model() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Memory_model::realization_Memory_model() noexcept
	:
		_name( JMSD_MEMORY_MODEL_NAME )
{
	_is_detected = JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED == JMSD_CPP_TRUE;

	::std::stringstream stringstream;

	{

	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Memory_model::realization_Memory_model( const realization_Memory_model & ) noexcept { // another
}

const realization_Memory_model &realization_Memory_model::operator =( const realization_Memory_model &another ) noexcept {
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
