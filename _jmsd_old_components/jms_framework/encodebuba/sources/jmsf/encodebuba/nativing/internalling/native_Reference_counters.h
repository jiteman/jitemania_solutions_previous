#pragma once

#include "native_Reference_counters.hxx"


#include "jmsf/encodebuba/nativing/native_types.h"

#include "jmsf/encodebuba/encodebuba.h"

#include "jmsf/encodebuba/nativing/native_Scoped.hxx"


namespace jmsf {
namespace encodebuba {
namespace nativing {
namespace internalling {


class JMSF_ENCODEBUBA_SHARED_INTERFACE native_Reference_counters {

public:
	native_memory_natural get_shared_counter() const noexcept;
	native_memory_natural get_total_counter() const noexcept;

	native_boolean is_shared_counter_nil() const noexcept;
	native_boolean is_total_counter_nil() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	/* virtual */ void increase_shared_counter();
	/* virtual */ void decrease_shared_counter();
	/* virtual */ void increase_weak_counter();
	/* virtual */ void decrease_weak_counter();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend nativing::native_Scoped< native_Reference_counters >;
	virtual ~native_Reference_counters() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	native_Reference_counters() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	//	native_Reference_counters() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static native_Reference_counters *create_new();

public:
	void destroy() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	native_Reference_counters( const native_Reference_counters &another ) noexcept = delete;
	native_Reference_counters &operator =( const native_Reference_counters &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	native_Reference_counters( native_Reference_counters &&another ) noexcept = default;

private:
	native_Reference_counters &operator =( native_Reference_counters &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	native_memory_natural _the_shared_counter;
	native_memory_natural _the_weak_counter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace internalling
} // namespace nativing
} // namespace encodebuba
} // namespace jmsf
