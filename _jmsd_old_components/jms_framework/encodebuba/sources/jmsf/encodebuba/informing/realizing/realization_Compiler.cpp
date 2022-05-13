#include "realization_Compiler.h"

#include "jmsd/platform_support/platform_detection/compiler_information.h"


namespace jmsf {
namespace encodebuba {
namespace informing {
namespace realizing {


// bool realization_Compiler::is_detected() const noexcept {
// 	return _is_detected;
// }

const ::std::string &realization_Compiler::get_name() const noexcept {
	return _name;
}

const ::std::string &realization_Compiler::get_version() const noexcept {
	return _version;
}

bool realization_Compiler::is_gcc() const noexcept {
	return _is_gcc;
}

bool realization_Compiler::is_visual_cpp() const noexcept {
	return _is_visual_cpp;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_Compiler::~realization_Compiler() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Compiler::realization_Compiler() noexcept
	:
		_name( JMSD_COMPILER_NAME ),
		_version( ::std::to_string( JMSD_COMPILER_VERSION ) )
{
//	_is_detected = JMSF_COMPILER_INFORMATION_IS_COMPLETED == JMSF_CPP_TRUE;
	_is_gcc = JMSD_COMPILER_TYPE == JMSD_COMPILER_TYPE_GCC_CCPP;
	_is_visual_cpp = JMSD_COMPILER_TYPE == JMSD_COMPILER_TYPE_MICROSOFT_VISUAL_CPP;

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Compiler::realization_Compiler( const realization_Compiler & ) noexcept { // another
}

const realization_Compiler &realization_Compiler::operator =( const realization_Compiler &another ) noexcept {
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
