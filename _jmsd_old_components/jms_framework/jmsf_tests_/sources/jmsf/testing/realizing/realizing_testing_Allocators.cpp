#include "realizing_testing_Allocators.h"


#include "jmsf/memorying/realizing/realization_Subsystem_allocator.h"

#include "jmsf/texting/Ansii_allocating_assistor.h"

#include "jmsf/patterning/Singleton.hin"
#include "jmsf/memorying/Owomp.hin"
#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Destructor.hin"

#include "jmsf/validating/macroses_Should.h"


namespace jmsf {
namespace testing {
namespace realizing {


const memorying::Womp< memorying::Allocator > &realizing_testing_Allocators::get_subsystem_allocator() const noexcept {
	return _subsystem_allocator.get_womp();
}

const memorying::Womp< memorying::Allocator > &realizing_testing_Allocators::get_character_array_allocator() const noexcept {
	return get_subsystem_allocator();
}

const memorying::Womp< memorying::Allocator > &realizing_testing_Allocators::get_constant_pointer_list_node_allocator() const noexcept {
	return get_subsystem_allocator();
}

const memorying::Womp< memorying::Allocator > &realizing_testing_Allocators::get_reference_counters_allocator() const noexcept {
	return get_subsystem_allocator();
}

const memorying::Womp< memorying::Allocator > &realizing_testing_Allocators::get_testing_object_allocator() const noexcept {
	return get_subsystem_allocator();
}

const memorying::Womp< texting::Ansii_allocating_assistor > &realizing_testing_Allocators::get_ansii_allocating_assistor() const noexcept {
	return _ansii_allocating_assistor.get_womp();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realizing_testing_Allocators::~realizing_testing_Allocators() noexcept {
	memorying::Destructor< memorying::Allocator >::destruct( _subsystem_allocator.get_omp() );
//	_global_allocator = memorying::Omp< memorying::Allocator >();
//	_global_allocator_reference = memorying::Womp< memorying::Allocator >();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realizing_testing_Allocators::realizing_testing_Allocators(
	const memorying::Omp< memorying::Allocator > &subsystem_allocator,
	const memorying::Omp< texting::Ansii_allocating_assistor > &ansii_allocating_assistor ) noexcept
	:
		_subsystem_allocator( memorying::Owomp< memorying::Allocator >::create( subsystem_allocator ) ),
		_ansii_allocating_assistor( memorying::Owomp< texting::Ansii_allocating_assistor >::create( ansii_allocating_assistor ) )
//		_global_allocator( global_allocator ),
//		_global_allocator_reference( global_allocator.get_as_weak() )
{}

// static
void realizing_testing_Allocators::create_instance(
	const memorying::Womp< memorying::Allocator > &application_allocator )
{
	jmsf_Should_never_be_empty( application_allocator );

	memorying::Omp< memorying::Allocator > subsystem_allocator =
		memorying::realizing::realization_Subsystem_allocator::create( application_allocator );

	// Seinsei: todonext - complete allocators, use appropriate allocators
	memorying::Omp< texting::Ansii_allocating_assistor > ansii_allocating_assistor =
		texting::Ansii_allocating_assistor::create(
			subsystem_allocator.get_as_womp(),
			subsystem_allocator.get_as_womp(),
			subsystem_allocator.get_as_womp(),
			subsystem_allocator.get_as_womp(),
			subsystem_allocator.get_as_womp(),
			subsystem_allocator.get_as_womp(),
			subsystem_allocator.get_as_womp() );


	set_instance(
		memorying::Constructor< testing_Allocators, realizing_testing_Allocators >::construct(
			application_allocator,
			subsystem_allocator,
			ansii_allocating_assistor ) );

//	set_instance(
//		memorying::Constructor< tests_Allocators, realization_tests_Allocators >::construct(
//			application_allocator,
//			memorying::realizing::realizing_Subsystem_allocator::create( application_allocator ) ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realizing_testing_Allocators::realizing_testing_Allocators( const realizing_testing_Allocators &another ) noexcept
	:
		testing_Allocators( another )
{}

const realizing_testing_Allocators &realizing_testing_Allocators::operator =( const realizing_testing_Allocators &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace testing
} // namespace jmsf
