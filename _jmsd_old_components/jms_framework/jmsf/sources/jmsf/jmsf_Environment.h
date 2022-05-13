#pragma once

#include "jmsf_Environment.hxx"


#include "jmsf/encodebuba/Environment.h"
#include "jmsf/encodebuba/nativing/native_Singleton.hpp"

#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"

#include "jmsf/typeing/Boolean.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {


class JMSF_SHARED_INTERFACE jmsf_Environment :
	virtual public encodebuba::Environment,
	public encodebuba::nativing::native_Singleton< jmsf_Environment >
{

public:
	static typeing::Boolean initialize();
	static typeing::Boolean deinitialize();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual memorying::Womp< memorying::Allocator > get_application_allocator() const noexcept = 0;
//	virtual memorying::Womp< memorying::Allocator > get_subsystem_allocator() const noexcept = 0;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace jmsf
