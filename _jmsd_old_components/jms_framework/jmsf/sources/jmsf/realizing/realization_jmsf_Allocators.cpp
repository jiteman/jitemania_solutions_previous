#include "realization_jmsf_Allocators.h"


#include "jmsf/memorying/realizing/realization_System_allocator.h"
#include "jmsf/memorying/realizing/realization_Application_allocator.h"
#include "jmsf/memorying/realizing/realization_Subsystem_allocator.h"

#include "jmsf/texting/Ansii_allocating_assistor.h"

#include "jmsf/patterning/Singleton.hin"
#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Destructor.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/memorying/Owomp.hin"

#include "jmsf/validating/macroses_Should.h"


namespace jmsf {
namespace realizing {


//const memorying::Womp< memorying::Allocator > &realizing_jmsf_Allocators::get_application_allocator() const noexcept {
//	return _application_allocator.get_womp();
//}

const memorying::Womp< memorying::Allocator > &realization_jmsf_Allocators::get_subsystem_allocator() const noexcept {
	return _subsystem_allocator.get_womp();
}

const memorying::Womp< memorying::Allocator > &realization_jmsf_Allocators::get_character_array_allocator() const noexcept {
	return get_subsystem_allocator();
}

const memorying::Womp< memorying::Allocator > &realization_jmsf_Allocators::get_constant_pointer_list_node_allocator() const noexcept {
	return get_subsystem_allocator();
}

const memorying::Womp< memorying::Allocator > &realization_jmsf_Allocators::get_reference_counters_allocator() const noexcept {
	return get_subsystem_allocator();
}

const memorying::Womp< texting::Ansii_allocating_assistor > &realization_jmsf_Allocators::get_ansii_allocating_assistor() const noexcept {
	return _ansii_allocating_assistor.get_womp();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_jmsf_Allocators::~realization_jmsf_Allocators() noexcept {
	memorying::Destructor< texting::Ansii_allocating_assistor >::destruct( _ansii_allocating_assistor.get_omp() );
	_ansii_allocating_assistor = memorying::Owomp< texting::Ansii_allocating_assistor >();
	memorying::Destructor< memorying::Allocator >::destruct( _subsystem_allocator.get_omp() );
	_subsystem_allocator = memorying::Owomp< memorying::Allocator >();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_jmsf_Allocators::realization_jmsf_Allocators(
	const memorying::Omp< memorying::Allocator > &subsystem_allocator,
	const memorying::Omp< texting::Ansii_allocating_assistor > &ansii_allocating_assistor ) noexcept
	:
		_subsystem_allocator( memorying::Owomp< memorying::Allocator >::create( subsystem_allocator ) ),
		_ansii_allocating_assistor( memorying::Owomp< texting::Ansii_allocating_assistor >::create( ansii_allocating_assistor ) )
{}

// static
void realization_jmsf_Allocators::create_instance(
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
		memorying::Constructor< jmsf_Allocators, realization_jmsf_Allocators >::construct(
			application_allocator,
			subsystem_allocator,
			ansii_allocating_assistor ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_jmsf_Allocators::realization_jmsf_Allocators( const realization_jmsf_Allocators &/*another*/ ) noexcept {
}

const realization_jmsf_Allocators &realization_jmsf_Allocators::operator =( const realization_jmsf_Allocators &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace jmsf
