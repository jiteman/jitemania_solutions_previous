#include "realizing_testing_Pointie.h"


#include "jmsf/pointing_old/sensing/sensing_Pointie.h"

#include "jmsf/pointing/Weak.hin"
#include "jmsf/pointing/Shared.hin"


namespace jmsf {
namespace pointing {
namespace testing {
namespace realizing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realizing_testing_Pointie::~realizing_testing_Pointie() noexcept {
	if ( _sensing_pointer.is_empty() ) return;

	_sensing_pointer->registerDestruction();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realizing_testing_Pointie::realizing_testing_Pointie(
	const pointing::Shared< sensing::sensing_Pointie > &sensing_pointer ) noexcept
	:
		_sensing_pointer( sensing_pointer )
{
	if ( _sensing_pointer.is_empty() ) return;

	_sensing_pointer->registerConstruction();
}

// static
pointing::Shared< testing_Pointie > realizing_testing_Pointie::create(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &sensing_pointie_allocator,
		const pointing::Weak< sensing::sensing_Pointie > &sensing_pointer ) noexcept
{
	if ( sensing_pointer.is_empty() ) return pointing::Shared< testing_Pointie >();

	return
		pointing::Shared< testing_Pointie >::create(
			reference_counters_allocator,
			memorying::Constructor< testing_Pointie, realizing_testing_Pointie >::construct(
				sensing_pointie_allocator,
				const_cast< pointing::Weak< sensing::sensing_Pointie > & >( sensing_pointer ).get_as_shared() ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// ::jmsf::pointing::Pointer< testing_Pointie > realization_testing_Pointie::createClone() const noexcept {
// 	memorying::temporary_Allocator temporary_allocator;
// 	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );
//
// 	return
// 		pointing::Pointer< testing_Pointie >::create_unique(
// 			memorying::Constructor< testing_Pointie, realization_testing_Pointie >::construct( the_temporary_allocator ) );
//
// ////	testing_Pointie *testingPointie = new realization_testing_Pointie( *this );
// ////	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( testingPointie, MACROS_FILE_AND_LINE ) );
// ////	return ::jmsf::Pointer< testing_Pointie >::createUnique( testingPointie );
// }

realizing_testing_Pointie::realizing_testing_Pointie( const realizing_testing_Pointie & ) noexcept // other
{}

const realizing_testing_Pointie &realizing_testing_Pointie::operator =( const realizing_testing_Pointie &other ) noexcept {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace testing
} // namespace pointing
} // jmsf
