#pragma once

#include "Singleton.hxx"


#include "internalling/Scoped_for_singleton.hpp"

#include "jmsf/pointing/Nonlinked.hxx"
#include "jmsf/memorying/Omp.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace patterning {


template< class A_type >
class Singleton {

public:
	static typeing::Boolean is_empty() noexcept;
	static typeing::Boolean is_not_empty() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: // friend memorying::Destructor< Singleton< A_type > >;
	virtual ~Singleton() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static pointing::Nonlinked< A_type > instance();
	static void set_instance( const memorying::Omp< A_type > &an_instance_omp ) noexcept;
//	static memorying::Omp< A_type > &take_instance() noexcept;
	static void destroy_instance();

protected:
	Singleton() noexcept;

// protected:
// 	static A_type *testing_setInstance( A_type *testingInstance );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Singleton( const Singleton &other ) noexcept = delete;
	Singleton &operator =( const Singleton &other ) noexcept = delete;
	Singleton( Singleton &&other ) noexcept = delete;
	Singleton &operator =( Singleton &&other ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	static memorying::Owomp< A_type > _owomp_singleton_instance;
	static internalling::Scoped_for_singleton< A_type > static_scoped_instance;

};


} // namespace patterning
} // namespace jmsf
