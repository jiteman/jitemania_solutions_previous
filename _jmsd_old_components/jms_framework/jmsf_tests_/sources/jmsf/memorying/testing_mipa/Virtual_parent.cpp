#include "Virtual_parent.h"


#include "sensing_mipa/sensation_of_mipa_Construction_and_destruction.h"

#include "jmsf/pointing/Shared.hin"


namespace jmsf {
namespace memorying {
namespace testing_mipa {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Virtual_parent::~Virtual_parent() noexcept {
	_the_virtual_parent_sensor->register_virtual_destruction();
}

Virtual_parent::Virtual_parent(
	const pointing::Shared< sensing_mipa::sensation_of_mipa_Construction_and_destruction > &a_sensor ) noexcept
	:
		_the_virtual_parent_sensor( a_sensor )
{
	_the_virtual_parent_sensor->register_virtual_construction();
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



} // namespace testing_mipa
} // namespace memorying
} // namespace jmsf
