#pragma once


#include "jmsdl/nutfield/nutfield_lib_class.h"


#include "nutfield_test_lib.h"


namespace jmsdl {
namespace nutfield {


class JMSD_NUTFIELD_TEST_LIBRARY_TEMPLATE_SHARED_INTERFACE Nutfield_test_lib_class :
	public Nutfield_lib_class
{

public:
	// virtuals Nutfield_lib_class
	//~virtuals Nutfield_lib_class

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	char const *say_nutfield_test_lib_hello() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Tpc_base_class
	~Nutfield_test_lib_class() noexcept override = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Nutfield_test_lib_class() noexcept = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Nutfield_test_lib_class( const Nutfield_test_lib_class &another ) noexcept = delete;
	Nutfield_test_lib_class &operator =( const Nutfield_test_lib_class &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Nutfield_test_lib_class( Nutfield_test_lib_class &&another ) noexcept = delete;
	Nutfield_test_lib_class &operator =( Nutfield_test_lib_class &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace nutfield
} // namespace jmsdl
