#pragma once

#include "cule_Environment.hxx"


#include "jmsf/encodebuba/Environment.h"
#include "jmsf/patterning/Singleton.hpp"

#include "jmsf/cule/cule.h"


namespace jmsf {
namespace cule {


class JMSF_CULE_SHARED_INTERFACE cule_Environment :
	virtual public encodebuba::Environment,
	public patterning::Singleton< cule_Environment >
{

public:
	static typeing::Boolean initialize();
	static typeing::Boolean deinitialize();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual int run_all_tests() const = 0;

//	virtual void initialize_mixin() noexcept = 0;
//	virtual void terminate_mixin() noexcept = 0;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
//	virtual ~cule_Environment :() noexcept = 0;

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

//class JMSF_CULE_SHARED_INTERFACE cule_Environment :
//	public encodebuba::mixing::mixin_Environment,
//	public patterning::Singleton< cule_Environment >
//{

//public:
//	static typeing::Boolean initialize();
//	static typeing::Boolean deinitialize();

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//public:
//	int run_all_tests() const;

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//private:
//	// virtuals mixin_Environment
//	void initialize_status_text_messages();
//	int initialize_environment();
//	void terminate_environment() noexcept;
//	//~virtuals mixin_Environment

//// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//private: friend memorying::Destructor< cule_Environment >;
//	~cule_Environment() noexcept;

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//private: friend memorying::Constructor< cule_Environment, cule_Environment >;
//	cule_Environment( const memorying::Womp< memorying::Allocator > &application_allocator ) noexcept;

//public:
//	static void create_instance( const memorying::Womp< memorying::Allocator > &application_allocator );

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//private:
//	cule_Environment( const cule_Environment &another ) noexcept;
//	const cule_Environment &operator =( const cule_Environment &another ) noexcept;

//// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//private:
//	memorying::Womp< memorying::Allocator > _application_allocator;

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//private:

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//private:

//};


} // namespace cule
} // namespace jmsf
