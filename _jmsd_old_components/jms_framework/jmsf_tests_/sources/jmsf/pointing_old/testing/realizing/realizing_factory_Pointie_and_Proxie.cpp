#include "realizing_factory_Pointie_and_Proxie.h"


//#include "realization_testing_Pointie.h"
//#include "realization_testing_Proxie.h"


#include "realizing_testing_Pointie.h"
//#include "realizing_testing_Proxie.h"

#include "jmsf/pointing/Weak.hin"
#include "jmsf/pointing/Shared.hin"

#include "jmsf/pointing/xWeak.hin"
#include "jmsf/pointing/xShared.hin"

#include "jmsf/patterning/Singleton.hin"
#include "jmsf/memorying/Constructor.hin"
//#include "jmsf/memorying/temporary_Allocator.h"

////#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace pointing {
namespace testing {
namespace realizing {


pointing::Shared< testing_Pointie > realizing_factory_Pointie_and_Proxie::create_pointie(
	const pointing::Weak< sensing::sensing_Pointie > &sensing_pointer ) const noexcept
{
	return realizing_testing_Pointie::create(
		_reference_counters_allocator,
		_testing_pointie_allocator,
		sensing_pointer );
}

//pointing::xShared< testing_Proxie > realizing_factory_Pointie_and_Proxie::create_proxie(
//	const pointing::xWeak< sensing::sensing_Pointie > &sensing_pointer ) const noexcept
//{
//	return realizing_testing_Proxie::create(
//		_reference_counters_allocator,
//		_testing_proxie_allocator,
//		sensing_pointer );
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realizing_factory_Pointie_and_Proxie::~realizing_factory_Pointie_and_Proxie() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realizing_factory_Pointie_and_Proxie::realizing_factory_Pointie_and_Proxie(
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &testing_pointie_allocator,
	const memorying::Womp< memorying::Allocator > &testing_proxie_allocator ) noexcept
	:
		_reference_counters_allocator( reference_counters_allocator ),
		_testing_pointie_allocator( testing_pointie_allocator ),
		_testing_proxie_allocator( testing_proxie_allocator )
{}

// static
void realizing_factory_Pointie_and_Proxie::create_instance(
	const memorying::Womp< memorying::Allocator > &factory_pointie_and_proxie_allocator,
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &testing_pointie_allocator,
	const memorying::Womp< memorying::Allocator > &testing_proxie_allocator ) noexcept
{
	set_instance(
		memorying::Constructor< factory_Pointie_and_Proxie, realizing_factory_Pointie_and_Proxie >::construct(
			factory_pointie_and_proxie_allocator,
			reference_counters_allocator,
			testing_pointie_allocator,
			testing_proxie_allocator
		)
	);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//realizing_factory_Pointie_and_Proxie::realizing_factory_Pointie_and_Proxie( const realizing_factory_Pointie_and_Proxie &another ) noexcept
//	:
//		factory_Pointie_and_Proxie( another )
//{}

//const realizing_factory_Pointie_and_Proxie &realizing_factory_Pointie_and_Proxie::operator =( const realizing_factory_Pointie_and_Proxie &another ) noexcept {
//	if ( this == &another ) return *this;

//	// copy
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace testing
} // namespace pointing
} // namespace jmsf
