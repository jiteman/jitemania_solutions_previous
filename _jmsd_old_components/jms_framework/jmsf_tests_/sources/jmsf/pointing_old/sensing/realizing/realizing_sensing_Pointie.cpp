#include "realizing_sensing_Pointie.h"


//#include "jmsf/pointing/Pointer.hin"

#include "jmsf/pointing/Shared.hin"

#include "jmsf/memorying/Constructor.hin"
//#include "jmsf/memorying/temporary_Allocator.h"


namespace jmsf {
namespace pointing {
namespace sensing {
namespace realizing {


void realizing_sensing_Pointie::registerDestruction() noexcept {
	_destructionCounter += typeing::Memory_natural_one;
}

void realizing_sensing_Pointie::registerConstruction() noexcept {
	_constructionCounter += typeing::Memory_natural_one;
}

typeing::Memory_natural realizing_sensing_Pointie::getDestrutionCounter() const noexcept {
	return _destructionCounter;
}

typeing::Memory_natural realizing_sensing_Pointie::getConstructionCounter() const noexcept {
	return _constructionCounter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realizing_sensing_Pointie::~realizing_sensing_Pointie() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realizing_sensing_Pointie::realizing_sensing_Pointie() noexcept
{}

// static
pointing::Shared< sensing_Pointie > realizing_sensing_Pointie::create(
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &sensing_pointie_allocator ) noexcept
{
	return
		pointing::Shared< sensing_Pointie >::create(
			reference_counters_allocator,
			memorying::Constructor< sensing_Pointie, realizing_sensing_Pointie >::construct(
				sensing_pointie_allocator ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//pointing::Pointer< sensing_Pointie > realizing_sensing_Pointie::createClone() const noexcept {
//	memorying::temporary_Allocator temporary_allocator;
//	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );

//	return
//		pointing::Pointer< sensing_Pointie >::create_unique(
//			memorying::Constructor< sensing_Pointie, realizing_sensing_Pointie >::construct( the_temporary_allocator ) );

//////	sensing_Pointie *sensingPointie = new realization_sensing_Pointie( *this );
//////	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( sensingPointie, MACROS_FILE_AND_LINE ) );
//////	return ::jmsf::pointing::Pointer< sensing_Pointie >::create_unique( sensingPointie );
//}

realizing_sensing_Pointie::realizing_sensing_Pointie( const realizing_sensing_Pointie &other ) noexcept
	:
		sensing_Pointie( other )
{}

const realizing_sensing_Pointie &realizing_sensing_Pointie::operator =( const realizing_sensing_Pointie &other ) noexcept {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace sensing
} // namespace pointing
} // namespace jmsf
