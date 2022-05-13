#pragma once

#include "Pointing_testing_class.hxx"


#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/pointing/Shared.hxx"
#include "jmsf/pointing/cShared.hxx"
#include "jmsf/pointing/Scoped.hxx"
#include "jmsf/pointing/cScoped.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Omp.hxx"


namespace jmsf {
namespace pointing {
namespace testing {


// Seinsei: todonext - make refactor-to-multithreaded:
//	replace static typeing::Memory_natural with Scoped_omp< typeing::Memory_natural >
class Pointing_testing_class {

public:
	typeing::Memory_natural get_object_number_value() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static typeing::Memory_natural get_object_counter_value() noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< Pointing_testing_class >;
	~Pointing_testing_class() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Pointing_testing_class, Pointing_testing_class >;
	Pointing_testing_class() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Shared< Pointing_testing_class > create_shared(
		memorying::Womp< memorying::Allocator > const &reference_counted_omp_allocator,
		memorying::Womp< memorying::Allocator > const &object_class_allocator );

	static cShared< Pointing_testing_class > create_cshared(
		memorying::Womp< memorying::Allocator > const &reference_counted_omp_allocator,
		memorying::Womp< memorying::Allocator > const &object_class_allocator );

	static Scoped< Pointing_testing_class > create_scoped(
		memorying::Womp< memorying::Allocator > const &object_class_allocator );

	static cScoped< Pointing_testing_class > create_cscoped(
		memorying::Womp< memorying::Allocator > const &object_class_allocator );

	static memorying::Omp< Pointing_testing_class > create_omp(
		memorying::Womp< memorying::Allocator > const &object_class_allocator );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Shared< Pointing_testing_class > create_shared_testing_object();
	static cShared< Pointing_testing_class > const create_cshared_testing_object();
	static Scoped< Pointing_testing_class > create_scoped_testing_object();
	static cScoped< Pointing_testing_class > const create_cscoped_testing_object();

	static memorying::Omp< Pointing_testing_class > const create_testing_object_omp();
	static void destroy_testing_object_omp( memorying::Omp< Pointing_testing_class > const &a_testing_object_omp ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pointing_testing_class( const Pointing_testing_class &another ) noexcept;
	const Pointing_testing_class &operator =( const Pointing_testing_class &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pointing_testing_class( Pointing_testing_class &&another ) noexcept;
	Pointing_testing_class &operator =( Pointing_testing_class &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typeing::Memory_natural _object_number;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static typeing::Memory_natural _STATIC_object_counter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace testing
} // namespace pointing
} // namespace jmsf
