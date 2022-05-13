#pragma once


#include "jmsdl/catch_tf/catch_lib_class.h"


#include "catch_test_lib.h"


namespace jmsdl {
namespace catch_ts {


class JMSD_CATCH_TEST_LIBRARY_SHARED_INTERFACE Catch_test_lib_class :
	public Catch_lib_class
{

public:
	// virtuals Catch_lib_class
	//~virtuals Catch_lib_class

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	char const *say_catch_test_lib_hello() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Tpc_base_class
	~Catch_test_lib_class() noexcept override = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Catch_test_lib_class() noexcept = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Catch_test_lib_class( const Catch_test_lib_class &another ) noexcept = delete;
	Catch_test_lib_class &operator =( const Catch_test_lib_class &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Catch_test_lib_class( Catch_test_lib_class &&another ) noexcept = delete;
	Catch_test_lib_class &operator =( Catch_test_lib_class &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace catch_ts
} // namespace jmsdl
