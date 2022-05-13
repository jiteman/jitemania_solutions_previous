#include "realization_System_information.h"

#include "../informing/realizing/realization_Compiler.h"
#include "../informing/realizing/realization_Operating_system.h"
#include "../informing/realizing/realization_Architecture.h"
#include "../informing/realizing/realization_Memory_model.h"


namespace jmsf {
namespace encodebuba {
namespace realizing {


const informing::Compiler &realization_System_information::get_compiler_information() const noexcept {
	return *_compiler;
}

const informing::Operating_system &realization_System_information::get_operating_system_information() const noexcept {
	return *_operating_system;
}

const informing::Architecture &realization_System_information::get_architecture_information() const noexcept {
	return *_architecture;
}

const informing::Memory_model &realization_System_information::get_memory_model_information() const noexcept {
	return *_memory_model;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_System_information::~realization_System_information() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_System_information::realization_System_information() noexcept
	:
		_compiler( new informing::realizing::realization_Compiler ),
		_operating_system( new informing::realizing::realization_Operating_system ),
		_architecture( new informing::realizing::realization_Architecture ),
		_memory_model( new informing::realizing::realization_Memory_model )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_System_information::realization_System_information( const realization_System_information & ) noexcept { // another
}

const realization_System_information &realization_System_information::operator =( const realization_System_information &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace encodebuba
} // namespace jmsf
