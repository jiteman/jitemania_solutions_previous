#pragma once

#include "native_Object_with_reference_counters.hxx"


#include "jmsf/encodebuba/nativing/native_types.h"

#include "native_Reference_counters.hxx"


namespace jmsf {
namespace encodebuba {
namespace nativing {
namespace internalling {


template< class A_type >
class native_Object_with_reference_counters {

public:
	native_boolean is_empty() const noexcept;
	native_boolean is_not_empty() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~native_Object_with_reference_counters() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	native_Object_with_reference_counters( native_boolean an_is_true = true ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	//	native_Object_with_reference_counters() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static native_Object_with_reference_counters create(
		native_Reference_counters *a_reference_counters,
		A_type *an_object_pointer );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	native_Object_with_reference_counters( const native_Object_with_reference_counters &another ) noexcept = delete;
	native_Object_with_reference_counters &operator =( const native_Object_with_reference_counters &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	native_Object_with_reference_counters( native_Object_with_reference_counters &&another ) noexcept = default;

private:
	native_Object_with_reference_counters &operator =( native_Object_with_reference_counters &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	native_boolean _is_empty;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace internalling
} // namespace nativing
} // namespace encodebuba
} // namespace jmsf
