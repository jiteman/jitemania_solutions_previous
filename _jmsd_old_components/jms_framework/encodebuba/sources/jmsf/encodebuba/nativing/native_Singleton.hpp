#pragma once

#include "native_Singleton.hxx"


#include "internalling/internal_native_Scoped.hpp"

#include "native_Nonlinked.hxx"


namespace jmsf {
namespace encodebuba {
namespace nativing {


template< class A_type >
class native_Singleton {

public:
	static bool is_empty() noexcept;
	static bool is_not_empty() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: // friend memorying::Destructor< Singleton< A_type > >;
	virtual ~native_Singleton() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static native_Nonlinked< A_type > instance();
	static void set_instance( A_type *an_object_pointer ) noexcept;
//	static  A_type *take_instance() noexcept;
	static void destroy_instance();

protected:
	native_Singleton() noexcept;

// protected:
// 	static A_type *testing_setInstance( A_type *testingInstance );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	native_Singleton( const native_Singleton &other ) noexcept = delete;
	native_Singleton &operator =( const native_Singleton &other ) noexcept = delete;
	native_Singleton( native_Singleton &&other ) noexcept = delete;
	native_Singleton &operator =( native_Singleton &&other ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static internalling::internal_native_Scoped< A_type > static_scoped_instance;

};


} // namespace nativing
} // namespace encodebuba
} // namespace jmsf
