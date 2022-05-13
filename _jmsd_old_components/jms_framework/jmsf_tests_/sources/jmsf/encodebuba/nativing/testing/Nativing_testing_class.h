#pragma once

#include "Nativing_testing_class.hxx"


#include "jmsf/encodebuba/nativing/native_types.h"

#include "jmsf/encodebuba/nativing/native_Scoped.hxx"


namespace jmsf {
namespace encodebuba {
namespace nativing {
namespace testing {


class Nativing_testing_class {

public:
	native_memory_natural get_object_number_value() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static native_memory_natural get_object_counter_value() noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend nativing::native_Scoped< Nativing_testing_class >;
	~Nativing_testing_class() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Nativing_testing_class() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Nativing_testing_class *create_new();

//	static Scoped< Nativing_testing_class > create_scoped(
//		const memorying::Womp< memorying::Allocator > &shared_class_allocator );

public:
	void destroy() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Nativing_testing_class( const Nativing_testing_class &another ) noexcept = delete;
	Nativing_testing_class &operator =( const Nativing_testing_class &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Nativing_testing_class( Nativing_testing_class &&another ) noexcept = delete;
	Nativing_testing_class &operator =( Nativing_testing_class &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	native_memory_natural _object_number;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static native_memory_natural _STATIC_object_counter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace testing
} // namespace nativing
} // namespace encodebuba
} // namespace jmsf
