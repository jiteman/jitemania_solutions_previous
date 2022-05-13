#include "Interface_parent.h"


#include "Template_parent.hin"

#include "sensing_mipa/sensation_of_mipa_Construction_and_destruction.h"

#include "jmsf/pointing/Shared.hin"


namespace jmsf {
namespace memorying {
namespace testing_mipa {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Interface_parent::~Interface_parent() noexcept {
	_the_interface_parent_sensor->register_interface_destruction();
}

Interface_parent::Interface_parent(
	const int template_integer,
	const pointing::Shared< sensing_mipa::sensation_of_mipa_Construction_and_destruction > &a_sensor )
	:
		Template_parent( template_integer, a_sensor ),
		Virtual_parent( a_sensor ),
		_the_interface_parent_sensor( a_sensor )
{
	_the_interface_parent_sensor->register_interface_construction();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



} // namespace testing_mipa
} // namespace memorying
} // namespace jmsf
