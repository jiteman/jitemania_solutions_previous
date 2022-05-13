#include "realizing_factory_Sensing.h"


#include "realizing_sensing_Pointie.h"
////#include "jmsf/Pointers.hpp"
////#include "jmsf/debugging/ObjectCreationLogging.h"

#include "jmsf/patterning/Singleton.hin"
//#include "jmsf/pointing/Pointer.hin"

#include "jmsf/pointing/Shared.hin"

#include "jmsf/memorying/Allocator.h"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Constructor.hin"


namespace jmsf {
namespace pointing {
namespace sensing {
namespace realizing {


pointing::Shared< sensing_Pointie > realizing_factory_Sensing::create_pointie() const noexcept {
	return realizing_sensing_Pointie::create( _reference_counters_allocator, _sensing_pointie_allocator );
//	return pointing::Pointer< sensing_Pointie >::create_unique( memorying::Constructor< sensing_Pointie, realizing_sensing_Pointie >::construct( pointie_allocator ) );
//	sensing_Pointie *sensingPointie = new realization_sensing_Pointie;
////	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( sensingPointie, MACROS_FILE_AND_LINE ) );
//	return Pointer< sensing_Pointie >::createUnique( sensingPointie );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realizing_factory_Sensing::~realizing_factory_Sensing() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realizing_factory_Sensing::realizing_factory_Sensing(
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &sensing_pointie_allocator ) noexcept
	:
		_reference_counters_allocator( reference_counters_allocator ),
		_sensing_pointie_allocator( sensing_pointie_allocator )
{}

// static
void realizing_factory_Sensing::create_instance(
	const memorying::Womp< memorying::Allocator > &sensing_factory_allocator,
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &sensing_pointie_allocator ) noexcept
{
	set_instance(
		memorying::Constructor< factory_Sensing, realizing_factory_Sensing >::construct(
			sensing_factory_allocator,
			reference_counters_allocator,
			sensing_pointie_allocator ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//realizing_factory_Sensing::realizing_factory_Sensing( const realizing_factory_Sensing &other ) noexcept
//	:
//		factory_Sensing( other )
//{}

//const realizing_factory_Sensing &realizing_factory_Sensing::operator =( const realizing_factory_Sensing &other ) noexcept {
//	if ( this == &other ) return *this;

//	// copy
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizing
} // namespace sensing
} // namespace pointing
} // namespace jmsf
