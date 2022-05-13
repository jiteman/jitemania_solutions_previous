#pragma once

#include "Test_result_collector.hxx"


#include "jmsf/pointing/Shared.hpp"

#include "../user_interfacing/Ui_output.hxx"
#include "Test_fault.hxx"
#include "Test_result_collection.hxx"

#include "jmsf/pointing/cShared.hxx"

#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Womp.hxx"


namespace jmsf {
namespace cule {
namespace resulting {


class Test_result_collector {

public:
	const pointing::cWeak< Test_result_collection > get_collected_results() const;

public:
	void testing_started();
	void testing_finished();

	void one_more_test_running();

	void add_test_failure( const pointing::cShared< Test_fault > &test_fault );
	void add_test_error( const pointing::cShared< Test_fault > &test_fault );
	void add_test_foreign_error( const pointing::cShared< Test_fault > &test_fault );
	void add_disabled_test( const pointing::cShared< Test_fault > &disabled_test );

private: friend memorying::Destructor< Test_result_collector >;
	~Test_result_collector();

private: friend memorying::Constructor< Test_result_collector, Test_result_collector >;
	Test_result_collector(
		const pointing::Shared< user_interfaces::Ui_output > &uiOutput,
		const pointing::Shared< Test_result_collection > &new_test_result_collection ) noexcept;

public:
	static pointing::Shared< Test_result_collector > create(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &test_result_collector_allocator,
		const pointing::Shared< user_interfaces::Ui_output > &ui_output,
		const pointing::Shared< Test_result_collection > &test_result_collection );

private:
	Test_result_collector( const Test_result_collector &another );
	const Test_result_collector &operator=( const Test_result_collector &another );

private:
	pointing::Shared< Test_result_collection > _test_result_collection;
	pointing::Shared< user_interfaces::Ui_output > _ui_output;


};


} // namespace results
} // namespace cule
} // namespace jmsf
