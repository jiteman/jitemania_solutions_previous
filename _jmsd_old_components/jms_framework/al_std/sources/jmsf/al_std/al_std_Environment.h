#pragma once

#include "al_std_Environment.hxx"


#include "jmsf/encodebuba/nativing/native_Singleton.hpp"
#include "jmsf/encodebuba/Environment.h"

#include "al_std.h"


namespace jmsf {
namespace al_std {


class JMSF_AL_STD_SHARED_INTERFACE al_std_Environment :
	virtual public encodebuba::Environment,
	public encodebuba::nativing::native_Singleton< al_std_Environment >
{

public:
	static bool initialize();
	static bool deinitialize();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
//	virtual ~encodebuba_Environment() noexcept = 0;

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


//class JMSF_AL_STD_SHARED_INTERFACE al_std_Environment :
//	public encodebuba::mixing::mixin_Environment
//{

//public:
//	static bool initialize();

//	static bool is_empty() noexcept;
//	static bool is_not_empty() noexcept;

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//public:
//	static const al_std_Environment *instance() noexcept;

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//private:
//	// virtuals mixin_Environment
//	void initialize_status_text_messages();
//	int initialize_environment();
//	void terminate_environment() noexcept;
//	//~virtuals mixin_Environment

//// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//private: friend encodebuba::nativing::native_Scoped< al_std_Environment >;
//	~al_std_Environment() noexcept;

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//private:
//	al_std_Environment() noexcept;

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//private:
//	al_std_Environment( const al_std_Environment &another ) noexcept;
//	const al_std_Environment &operator =( const al_std_Environment &another ) noexcept;

//// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//private:
////	::std::auto_ptr< System_information > _system_information;

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//private:
//	static encodebuba::nativing::native_Scoped< al_std_Environment > static_al_std_environment;

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//private:

//};


} // namespace al_std
} // namespace jmsf
