#pragma once

#include "realization_cule_Environment.hxx"


#include "jmsf/cule/cule_Environment.h"
#include "jmsf/encodebuba/mixing/mixin_Environment.h"

#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace cule {
namespace realizing {


class realization_cule_Environment :
	public cule_Environment,
	public encodebuba::mixing::mixin_Environment

{

public:
	// virtuals cule_Environment
	int run_all_tests() const;

//	void initialize_mixin() noexcept;
//	void terminate_mixin() noexcept;
	//~virtuals cule_Environment

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	// virtuals mixin_Environment
	void initialize_status_text_messages();
	int initialize_environment();
	void terminate_environment() noexcept;
	//~virtuals mixin_Environment

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~realization_cule_Environment() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_cule_Environment() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< cule_Environment, realization_cule_Environment >;
	realization_cule_Environment( const memorying::Womp< memorying::Allocator > &application_allocator ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static memorying::Omp< cule_Environment > create( const memorying::Womp< memorying::Allocator > &application_allocator );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_cule_Environment( const realization_cule_Environment &another ) noexcept;
	const realization_cule_Environment &operator =( const realization_cule_Environment &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_cule_Environment( realization_cule_Environment &&another ) noexcept;
	realization_cule_Environment &operator =( realization_cule_Environment &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Womp< memorying::Allocator > _application_allocator;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace cule
} // namespace jmsf

