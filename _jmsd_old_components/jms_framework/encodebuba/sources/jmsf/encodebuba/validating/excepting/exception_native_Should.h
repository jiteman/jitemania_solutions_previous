#pragma once


#include "jmsf/encodebuba/validating/mixing/mixin_native_Exception.h"


namespace jmsf {
namespace encodebuba {
namespace validating {
namespace excepting {


class exception_native_Should :
	public mixing::mixin_native_Exception
{

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // virtuals native_Exception
	const nativing::native_character *const &get_exception_name() const noexcept override final;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_native_Should() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_native_Should(
		const nativing::native_character *const a_reason_description,
		native_File_and_line &&a_file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_native_Should( const exception_native_Should &another ) noexcept = delete;
	exception_native_Should &operator =( const exception_native_Should &another ) noexcept = delete;

public:
	exception_native_Should( exception_native_Should &&another ) noexcept = default;

private:
	exception_native_Should &operator =( exception_native_Should &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const nativing::native_character *const _native_should_exception_typename;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace excepting
} // namespace validating
} // namespace encodebuba
} // namespace jmsf
