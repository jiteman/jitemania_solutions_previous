#pragma once

#include "native_Exception.hxx"


#include "jmsf/encodebuba/nativing/native_types.h"

#include "jmsf/encodebuba/encodebuba.h"


namespace jmsf {
namespace encodebuba {
namespace validating {


class JMSF_ENCODEBUBA_SHARED_INTERFACE native_Exception {

public:
	// realization is done in mixin_Exception
	virtual const nativing::native_character *const &get_reason_description() const noexcept = 0;
	virtual const nativing::native_character *const &get_type_information() const noexcept = 0;
	virtual const nativing::native_character *const &get_filename() const noexcept = 0;
	virtual nativing::native_memory_natural get_line_number() const noexcept = 0;
	//~realization is done in mixin_Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// realization should be done in final exception class
	virtual const nativing::native_character *const &get_exception_name() const noexcept = 0;

	// realization is done in ::jmsf::validating::basing::exception_<Category> classes
	virtual const nativing::native_character *const &get_exception_category() const noexcept = 0;

	// realization should be done in subsystem root exception class (i.e., ::jmsf::cule::validating::cule_Exception )
	virtual const nativing::native_character *const &get_exception_subsystem() const noexcept = 0;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	virtual ~native_Exception() noexcept = 0;
	native_Exception() noexcept = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	native_Exception( const native_Exception &another ) noexcept = delete;
	native_Exception &operator =( const native_Exception &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	native_Exception( native_Exception &&another ) noexcept = delete;
	native_Exception &operator =( native_Exception &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace validating
} // namespace encodebuba
} // namespace jmsf
