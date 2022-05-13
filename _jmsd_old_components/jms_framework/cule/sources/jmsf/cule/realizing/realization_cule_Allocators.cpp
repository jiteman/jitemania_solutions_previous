#include "realization_cule_Allocators.h"


#include "jmsf/memorying/realizing/realization_Subsystem_allocator.h"

#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/memorying/Owomp.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Destructor.hin"
#include "jmsf/patterning/Singleton.hin"

#include "jmsf/validating/macroses_Should.h"


namespace jmsf {
namespace cule {
namespace realizing {


// virtuals Cule_allocators
const memorying::Womp< memorying::Allocator > &realization_cule_Allocators::get_subsystem_allocator() const noexcept {
	return _subsystem_allocator.get_womp();
}

const memorying::Womp< memorying::Allocator > &realization_cule_Allocators::get_character_array_allocator() const noexcept {
	return get_subsystem_allocator();
}

const memorying::Womp< memorying::Allocator > &realization_cule_Allocators::get_constant_pointer_list_node_allocator() const noexcept {
	return get_subsystem_allocator();
}

const memorying::Womp< memorying::Allocator > &realization_cule_Allocators::get_reference_counters_allocator() const noexcept {
	return get_subsystem_allocator();
}

const memorying::Womp< texting::Ansii_allocating_assistor > &realization_cule_Allocators::get_ansii_allocating_assistor() const noexcept {
	return _ansii_allocating_assistor.get_womp();
}

//~virtuals Cule_allocators
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_cule_Allocators::~realization_cule_Allocators() noexcept {
	memorying::Destructor< memorying::Allocator >::destruct( _subsystem_allocator.get_omp() );
	_subsystem_allocator = memorying::Owomp< memorying::Allocator >();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_cule_Allocators::realization_cule_Allocators(
	const memorying::Omp< memorying::Allocator > &subsystem_allocator,
	const memorying::Omp< texting::Ansii_allocating_assistor > &ansii_allocating_assistor ) noexcept
	:
		_subsystem_allocator( memorying::Owomp< memorying::Allocator >::create( subsystem_allocator ) ),
		_ansii_allocating_assistor( memorying::Owomp< texting::Ansii_allocating_assistor >::create( ansii_allocating_assistor ) )
{}

// static
void realization_cule_Allocators::create_instance( const memorying::Womp< memorying::Allocator > &application_allocator ) {
	jmsf_Should_never_be_empty( application_allocator );

	memorying::Omp< memorying::Allocator > subsystem_allocator =
		memorying::realizing::realization_Subsystem_allocator::create( application_allocator );

	// Seinsei: todonext - after creating real allocators, refactor this to use appropriate allocators
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
		memorying::Constructor< cule_Allocators, realization_cule_Allocators >::construct(
			application_allocator,
			subsystem_allocator,
			ansii_allocating_assistor ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_cule_Allocators::realization_cule_Allocators( const realization_cule_Allocators &/*another*/ ) noexcept {
}

const realization_cule_Allocators &realization_cule_Allocators::operator =( const realization_cule_Allocators &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace cule
} // namespace jmsf

