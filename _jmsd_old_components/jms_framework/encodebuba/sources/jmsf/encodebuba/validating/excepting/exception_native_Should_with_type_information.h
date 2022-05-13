#pragma once


#include "jmsf/encodebuba/validating/mixing/mixin_native_Exception.h"


namespace jmsf {
namespace encodebuba {
namespace validating {
namespace excepting {


class exception_native_Should_with_type_information :
	public mixing::mixin_native_Exception
{

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // virtuals native_Exception
	const nativing::native_character *const &get_exception_name() const noexcept override final;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_native_Should_with_type_information() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_native_Should_with_type_information(
		const nativing::native_character *const a_reason_description,
		const nativing::native_character *const a_type_information,
		native_File_and_line &&a_file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_native_Should_with_type_information( const exception_native_Should_with_type_information &other ) noexcept = delete;
	exception_native_Should_with_type_information &operator =( const exception_native_Should_with_type_information &other ) noexcept = delete;

public:
	exception_native_Should_with_type_information( exception_native_Should_with_type_information &&other ) noexcept = default;

private:
	exception_native_Should_with_type_information &operator =( exception_native_Should_with_type_information &&other ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const nativing::native_character *const _native_should_with_type_information_exception_typename;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace excepting
} // namespace validating
} // namespace encodebuba
} // namespace jmsf
