#pragma once

#include "realization_encodebuba_Environment.hxx"


#include "jmsf/encodebuba/encodebuba_Environment.h"
#include "jmsf/encodebuba/mixing/mixin_Environment.h"

#include "jmsf/encodebuba/nativing/native_Scoped.hpp"


namespace jmsf {
namespace encodebuba {
namespace realizing {


class realization_encodebuba_Environment :
	public encodebuba_Environment,
	public mixing::mixin_Environment
{

public:
	// virtuals encodebuba_Environment
	nativing::native_Nonlinked< System_information > get_system_information() const noexcept;
	//~virtuals encodebuba_Environment

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	// virtuals mixin_Environment
	void initialize_status_text_messages();
	int initialize_environment();
	void terminate_environment() noexcept;
	//~virtuals mixin_Environment

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~realization_encodebuba_Environment() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	realization_encodebuba_Environment() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_encodebuba_Environment( const System_information *a_system_information ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend bool encodebuba_Environment::initialize();
	static realization_encodebuba_Environment *create();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_encodebuba_Environment( const realization_encodebuba_Environment &another ) noexcept;
	const realization_encodebuba_Environment &operator =( const realization_encodebuba_Environment &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_encodebuba_Environment( realization_encodebuba_Environment &&another ) noexcept;
	realization_encodebuba_Environment &operator =( realization_encodebuba_Environment &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	nativing::native_Scoped< System_information > _system_information;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace encodebuba
} // namespace jmsf

