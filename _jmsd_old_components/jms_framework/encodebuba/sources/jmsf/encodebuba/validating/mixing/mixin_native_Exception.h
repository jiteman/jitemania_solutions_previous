#pragma once

#include "mixin_native_Exception.hxx"


#include "jmsf/encodebuba/validating/native_Exception.h"
#include "jmsf/encodebuba/validating/native_File_and_line.h"


#include "jmsf/encodebuba/encodebuba.h"

namespace jmsf {
namespace encodebuba {
namespace validating {
namespace mixing {


class JMSF_ENCODEBUBA_SHARED_INTERFACE mixin_native_Exception :
	public native_Exception
{

public:	// virtuals native_Exception
	const nativing::native_character *const &get_reason_description() const noexcept override final;
	const nativing::native_character *const &get_type_information() const noexcept override final;
	const nativing::native_character *const &get_filename() const noexcept override final;
	nativing::native_memory_natural get_line_number() const noexcept override final;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // virtuals native_Exception
	// realization should be done in final exception class
//	virtual const nativing::native_character *&get_exception_name() const noexcept = 0;

	// realization is done in ::jmsf::validating::basing::exception_<Category> classes
	const nativing::native_character *const &get_exception_category() const noexcept override final;

	// realization should be done in subsystem root exception class (i.e., ::jmsf::cule::validating::cule_Exception )
	const nativing::native_character *const &get_exception_subsystem() const noexcept override final;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual native_Exception
	~mixin_native_Exception() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	mixin_native_Exception(
		native_File_and_line &&a_file_and_line ) noexcept;

	mixin_native_Exception(
		const nativing::native_character *const a_reason_description,
		native_File_and_line &&a_file_and_line ) noexcept;

	mixin_native_Exception(
		const nativing::native_character *const a_reason_description,
		const nativing::native_character *const a_type_information,
		native_File_and_line &&a_file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	mixin_native_Exception( const mixin_native_Exception &another ) noexcept = delete;
	mixin_native_Exception &operator =( const mixin_native_Exception &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	mixin_native_Exception( mixin_native_Exception &&another ) noexcept;

private:
	mixin_native_Exception &operator =( mixin_native_Exception &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const nativing::native_character *const _the_reason_description;
	const nativing::native_character *const _the_type_information;
	const native_File_and_line _the_file_and_line;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	const nativing::native_character *const _the_exception_category;
	const nativing::native_character *const _the_exception_subsystem;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const char *const EMPTY_STRING;
	static const char *const EXCEPTION_CATEGORY;
	static const char *const EXCEPTION_SUBSYSTEM;

};


} // namespace mixing
} // namespace validating
} // namespace encodebuba
} // namespace jmsf
