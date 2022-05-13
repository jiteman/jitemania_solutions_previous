#pragma once

#include "realization_al_qt_Environment.hxx"


#include "jmsf/al_qt/al_qt_Environment.h"
#include "jmsf/encodebuba/mixing/mixin_Environment.h"

#include "jmsf/encodebuba/nativing/native_Scoped.hpp"


namespace jmsf {
namespace al_qt {
namespace realizing {


class realization_al_qt_Environment :
	public al_qt_Environment,
	public encodebuba::mixing::mixin_Environment
{

public:
	// virtuals al_qt_Environment
	//~virtuals al_qt_Environment

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	// virtuals mixin_Environment
	void initialize_status_text_messages();
	int initialize_environment();
	void terminate_environment() noexcept;
	//~virtuals mixin_Environment

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~realization_al_qt_Environment() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_al_qt_Environment() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	realization_al_qt_Environment() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static realization_al_qt_Environment *create();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_al_qt_Environment( const realization_al_qt_Environment &another ) noexcept;
	const realization_al_qt_Environment &operator =( const realization_al_qt_Environment &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_al_qt_Environment( realization_al_qt_Environment &&another ) noexcept;
	realization_al_qt_Environment &operator =( realization_al_qt_Environment &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace al_qt
} // namespace jmsf

