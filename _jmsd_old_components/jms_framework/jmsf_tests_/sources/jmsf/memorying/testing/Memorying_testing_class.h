#pragma once

#include "Memorying_testing_class.hxx"


#include "jmsf/typeing/Naturals.hpp"

//#include "jmsf/pointing/Shared.hxx"
//#include "jmsf/pointing/cShared.hxx"
//#include "jmsf/pointing/Scoped.hxx"
//#include "jmsf/pointing/cScoped.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Omp.hxx"


namespace jmsf {
namespace memorying {
namespace testing {


class Memorying_testing_class {

public:
	typeing::Memory_natural get_object_number_value() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static typeing::Memory_natural get_object_counter_value() noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< Memorying_testing_class >;
	~Memorying_testing_class() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Memorying_testing_class, Memorying_testing_class >;
	Memorying_testing_class() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static const memorying::Omp< Memorying_testing_class > create_omp(
		const memorying::Womp< memorying::Allocator > &shared_class_allocator );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static const memorying::Omp< Memorying_testing_class > create_testing_object_omp();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memorying_testing_class( const Memorying_testing_class &another ) noexcept;
	const Memorying_testing_class &operator =( const Memorying_testing_class &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memorying_testing_class( Memorying_testing_class &&another ) noexcept;
	Memorying_testing_class &operator =( Memorying_testing_class &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typeing::Memory_natural _object_number;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static typeing::Memory_natural _STATIC_object_counter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace testing_dev
} // namespace memorying
} // namespace jmsf
