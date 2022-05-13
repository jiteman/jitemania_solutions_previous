#pragma once

#include "Test_result_collection.hxx"


#include "jmsf/typeing/Naturals.hpp"

#include "Test_fault.hxx"

#include "jmsf/pointing/Shared.hxx"
#include "jmsf/pointing/cShared.hxx"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"


#include "jmsf/al_std/stl_hin/vector_al_std.hin"


namespace jmsf {
namespace cule {
namespace resulting { // Seinsei: todonext - police namespace name


class Test_result_collection { // Seinsei: todonext - police class name and method names

public:
	const ::std::vector< pointing::cShared< Test_fault > > &get_test_failure_container() const;
	const ::std::vector< pointing::cShared< Test_fault > > &get_test_error_container() const;
	const ::std::vector< pointing::cShared< Test_fault > > &get_test_foreign_error_container() const;
	const ::std::vector< pointing::cShared< Test_fault > > &get_disabled_test_container() const;

	typeing::Natural get_total_testing_duration() const noexcept;
	typeing::Natural get_number_of_runned_tests() const noexcept;
	typeing::Natural get_number_of_disabled_tests() const noexcept;

public:
	void add_test();
	void increase_test_counter();

	void add_test_result_failure( const pointing::cShared< Test_fault > &test_fault );
	void add_test_result_error( const pointing::cShared< Test_fault > &test_fault );
	void add_test_result_foreign_error( const pointing::cShared< Test_fault > &test_fault );
	void add_disabled_test( const pointing::cShared< Test_fault > &disabled_test );

	void set_total_testing_duration( typeing::Natural total_test_duration_in_ms );

private: friend memorying::Destructor< Test_result_collection >;
	virtual ~Test_result_collection();

private: friend memorying::Constructor< Test_result_collection, Test_result_collection >;
	Test_result_collection();

public:
	static pointing::Shared< Test_result_collection > create(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &test_result_collection_allocator );

private:
	Test_result_collection( const Test_result_collection &another );
	const Test_result_collection &operator=( const Test_result_collection &another );

private:
	// Seinsei: todonext - transfer to ::jmsf::structing::containing::List
	// Seinsei: todonext - then create ::jmsf::structing::containing::Array and transfer to jmsf::structing::containing::Array
	::std::vector< pointing::cShared< Test_fault > > _test_failures;
	::std::vector< pointing::cShared< Test_fault > > _test_errors;
	::std::vector< pointing::cShared< Test_fault > > _test_foreign_errors;
	::std::vector< pointing::cShared< Test_fault > > _disabled_tests;

	typeing::Natural _numberOfRunnedTests;
	typeing::Natural _totalTestingDuration;
	typeing::Natural _number_of_disabled_tests;

};


} // namespace
}
}
