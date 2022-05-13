#pragma once


#include "realization_System_information.hxx"

#include "../System_information.h"


#include <memory>


namespace jmsf {
namespace encodebuba {
namespace realizing {


class realization_System_information :
	public System_information
{

public:
	// virtuals System_information
	const informing::Compiler &get_compiler_information() const noexcept;
	const informing::Operating_system &get_operating_system_information() const noexcept;
	const informing::Architecture &get_architecture_information() const noexcept;
	const informing::Memory_model &get_memory_model_information() const noexcept;
	//~virtuals System_information

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual System_information
	~realization_System_information() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_System_information() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_System_information( const realization_System_information &another ) noexcept;
	const realization_System_information &operator =( const realization_System_information &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::std::unique_ptr< informing::Compiler > _compiler;
	::std::unique_ptr< informing::Operating_system > _operating_system;
	::std::unique_ptr< informing::Architecture > _architecture;
	::std::unique_ptr< informing::Memory_model > _memory_model;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace encodebuba
} // namespace jmsf
